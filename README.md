# 🔐 ESP32 Keypad Password Lock System

A password-based security system built using **ESP32** and a **4x4 Keypad**.  
The system allows users to enter a password of any length, verifies it, and provides access indication using LEDs and buzzer alerts.

## 🚀 Features

- 🔢 Password input using 4x4 keypad
- 🔐 Supports passwords of variable length
- 🔑 Default password: `1234A`
- ✅ Correct password detection
- ❌ Wrong password detection
- 🔁 5 attempts allowed for entering the password
- ⏳ After 5 wrong attempts, system locks input for 5 seconds
- 🔊 Door opening sound on successful authentication
- 🟡 Yellow LED blinks when access is granted
- 🔴 Red LED blinks when access is denied

## 🛠️ Components Used

- ESP32 Development Board
- 4x4 Matrix Keypad
- Buzzer
- Yellow LED
- Red LED
- Push Button
- Resistors
- Breadboard and Jumper Wires

## 💻 Technologies

- Arduino IDE
- Embedded C/C++
- ESP32 GPIO Programming

## ⚙️ Working Principle

1. User enters a password using the keypad.
2. The entered password is checked when the button is pressed.
3. If the password matches:
   - Access is granted
   - Yellow LED blinks
   - Door opening sound is played

4. If the password is incorrect:
   - Red LED blinks
   - Wrong attempt counter increases

5. After 5 incorrect attempts:
   - System waits for 5 seconds before allowing another attempt.

<img width="895" height="628" alt="image" src="https://github.com/user-attachments/assets/d7401c5b-2a5f-42fe-b015-741a2cad1460" />







