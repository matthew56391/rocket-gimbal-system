#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(4, 2); // RX, TX

Servo panServo;
Servo pitchServo;
Servo esc;

#define MAX_BUFFER_SIZE 100
char btBuffer[MAX_BUFFER_SIZE];
uint8_t bufferIndex = 0;

int lastTargetX = 90;
int lastTargetY = 90;
int lastTargetT = 0;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  panServo.attach(9);
  pitchServo.attach(10);
  esc.attach(5);

  pinMode(6, INPUT);

  esc.writeMicroseconds(1000);  // Arm ESC
  delay(2000);

  panServo.write(90);
  pitchServo.write(90);
}

void processLine(const String& inputRaw) {
  String input = inputRaw;
  input.trim();

  int indexX = input.indexOf('X');
  int indexY = input.indexOf('Y');
  int indexT = input.indexOf('T');

  if (indexX != 0 || indexY <= indexX || indexT <= indexY ||
      input.indexOf('X', indexX + 1) != -1 ||
      input.indexOf('Y', indexY + 1) != -1 ||
      input.indexOf('T', indexT + 1) != -1) {
    return;
  }

  String xStr = input.substring(indexX + 1, indexY);
  String yStr = input.substring(indexY + 1, indexT);
  String tStr = input.substring(indexT + 1);

  int y = round(xStr.toFloat());
  int x = round(yStr.toFloat());
  int t = round(tStr.toFloat());

  // Flip and remap logic
  if (x == 90 && y == 90){
    y = 90;
    x = 90;
  } else if (x <= 90 && x >= 0 && y <= 90 && y >= 0) {
    y = 75;
  } else if (x >= 90 && x <= 180 && y >= 0 && y <= 90){
    y = 75;
  } else if (x <= 180 && x >= 90 && y <= 180 && y >= 90){
    y = 105;
    x = 180 - x;
  } else if (x >= 0 && x <= 90 && y <= 180 && y >= 90){
    y = 105;
    x = 180 - x;
  }

  bool ChangeX = (x != lastTargetX);
  bool ChangeY = (y != lastTargetY);
  bool ChangeT = (t != lastTargetT);

  if (ChangeX && abs(x - lastTargetX) > 5) {
  panServo.write(x);
  lastTargetX = x;
  }

  if (ChangeY && abs(y - lastTargetY) > 5) {
  pitchServo.write(y);
  lastTargetY = y;
  }

  if (ChangeT) {
    esc.writeMicroseconds(map(t, 0, 180, 1000, 2000));
    lastTargetT = t;
  }

}

void loop() {
  while (BT.available()) {
    char c = BT.read();

    if (c == '\n') {
      btBuffer[bufferIndex] = '\0';
      String rawLine = String(btBuffer);
      bufferIndex = 0;
      memset(btBuffer, 0, MAX_BUFFER_SIZE);

      int i = 0;
      while (i < rawLine.length()) {
        int start = rawLine.indexOf('X', i);
        if (start == -1) break;

        int next = rawLine.indexOf('X', start + 1);
        String chunk = (next == -1) ? rawLine.substring(start) : rawLine.substring(start, next);
        processLine(chunk);
        i = (next == -1) ? rawLine.length() : next;
      }
    } else if (bufferIndex < MAX_BUFFER_SIZE - 1) {
      btBuffer[bufferIndex++] = c;
    } else {
      bufferIndex = 0;
      memset(btBuffer, 0, MAX_BUFFER_SIZE);
    }
  }

  // Reset override
  if (digitalRead(6) == LOW) {
    lastTargetX = 90;
    lastTargetY = 90;
    lastTargetT = 0;

    panServo.write(90);
    pitchServo.write(90);
    esc.writeMicroseconds(1000);
  }

  delay(200);
}
