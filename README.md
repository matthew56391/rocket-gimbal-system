# 🚀 Rocket Gimbal System
![GitHub repo size](https://img.shields.io/github/repo-size/matthew56391/rocket-gimbal-system)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

![Rocket Build](deskphoto.jpg)

This project is a **Bluetooth-controlled thrust-vectoring gimbal system** designed for a model rocket. It uses two servos for pitch and yaw control, an ESC-controlled brushless motor for thrust, and a fully custom 3D-printed baseplate to mount and protect the internal components.

> ✅ Designed and built from scratch for hands-on control and embedded systems practice.

---

## 🎯 Features
- 🎮 Real-time control via Bluetooth joystick (HC-05)
- 🧠 Smoothing + dead zone logic for stable servo movement
- 🛞 Thrust control via ESC with remapped microsecond ranges
- 🚨 Manual override switch for safety
- 🧩 Modular 3D-printed design for each mechanical part

---

## 📁 Included Files

| File | Description |
|------|-------------|
| `rocket_gimbal_system.ino` | Final Arduino sketch for gimbal + ESC control |
| `Final Schematic.drawio` / `.png` | Complete wiring schematic (editable + visual) |
| `*.stl` files | All final 3D printed parts (arms, mounts, baseplate) |
| Media | Videos and pictures demonstrating functionality |

---

## 🔧 Hardware Used

- **Arduino Uno**
- **MG996R Servos** (x2)
- **HC-05 Bluetooth module**
- **RS2205 2300KV Brushless Motor**
- **30A ESC with UBEC**
- **OVONIC 3S 11.1V 2200mAh LiPo**
- **Custom 3D-printed PLA parts**

---

## 🧪 Demo & Testing

- ✅ Gimbal responds to joystick X/Y input with remapped motion
- ✅ ESC thrust control adjusts motor speed based on T input
- ✅ Manual reset switch resets gimbal and throttle to idle

---

## 🛠️ Build Notes

- All parts are designed to fit inside a 3D-printed cone-style baseplate
- STL dimensions optimized for M3 hardware and RS2205 prop clearance
- Cone diameter: 200mm | Height: 82mm | Rocket body: 84mm diameter

- ## Getting Started

1. Open `Code_for_Rocket.ino` in the Arduino IDE.
2. Make sure you have these libraries installed:
   - Servo
   - SoftwareSerial
3. Upload the sketch to an Arduino Uno.
4. Connect the circuit according to the wiring schematic.
5. Send Bluetooth commands from your joystick app.

---

## 📸 Media

- 🔌 **Circuit & Bluetooth Demo** — (Watch on Google Drive) https://drive.google.com/file/d/1Ishrw4jyDEkL0xwUyqPzfaAfsIhkHsoV/view?usp=sharing
- 🎥 **Thrust + Gimbal Functionality** — (Watch on Google Drive) https://drive.google.com/file/d/1IoF2ARaRBi8Ify6LhGKEyqzEVtrOYgCz/view?usp=sharing

---

## 📜 License

MIT License — feel free to remix, improve, or build your own rocket gimbal.

---

## ✍️ Author

Matthew Cuebas 
Electrical Engineering @ UTSA  
Interested in embedded systems, aerospace, and defense R&D.

