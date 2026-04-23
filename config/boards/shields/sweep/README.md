# 🎹 Ade's Sweep-Pro Configuration

A premium ZMK configuration for the Ferris Sweep-Pro, featuring an E-ink display, Cirque trackpad, and a custom "Corne-Hybrid" logical layout.

## 🏗️ Hardware Setup

```
┌─────────────────┐    Bluetooth    ┌─────────────────┐
│   Sweep Left    │◄──────────────►│   Sweep Right   │
│   (Peripheral)  │                │   (Peripheral)  │
│  ┌───────────┐  │                │  ┌───────────┐  │
│  │  E-Ink    │  │                │  │  Cirque   │  │
│  │  Display  │  │                │  │ Trackpad  │  │
│  └───────────┘  │                │  └───────────┘  │
└─────────────────┘                └─────────────────┘
         │                                  │
         └────────────────┬─────────────────┘
                          │
                 Bluetooth / USB HID
                    (5 Devices)
```

## ✨ Features

- 📄 **E-Ink Support**: 1.54" SSD1680 display for status and WPM
- 🖱️ **Trackpad Integration**: Cirque Pinnacle 2 support with dedicated Mouse layer
- 🎛️ **Smart Encoders**: Context-aware behavior that changes per layer
- 🧠 **Corne Muscle Memory**: 34-key adaptation of a 42-key workflow
- 🔗 **Dual Connectivity**: USB + Bluetooth (up to 5 profiles)
- 🏠 **Homerow Mods**: Balanced GUI/Alt/Ctrl/Shift on home row

---

## 🗺️ Keyboard Layout

### 🏠 Base Layer (0)
```
╭─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────╮
│    Q    │    W    │    E    │    R    │    T    │   │    Y    │    U    │    I    │    O    │    P    │
├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
│  GUI/A  │  ALT/S  │  CTL/D  │  SFT/F  │    G    │   │    H    │  SFT/J  │  CTL/K  │  ALT/L  │  GUI/;  │
├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
│    Z    │    X    │    C    │    V    │    B    │   │    N    │    M    │    ,    │    .    │    /    │
╰─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────╯
                    │ NUM/TAB │ NAV/SPC │ Encoder │   │ Encoder │ FUN/RET │ SYM/ESC │
                    ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

### 🔢 Numbers Layer (1)
```
╭─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────╮
│    1    │    2    │    3    │    4    │    5    │   │    6    │    7    │    8    │    9    │    0    │
├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
│  GUI/6  │  ALT/7  │  CTL/8  │  SFT/9  │    0    │   │    ;    │  SFT/←  │  CTL/↓  │  ALT/↑  │  GUI/→  │
├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │    -    │    -    │    -    │    -    │   │    -    │    -    │    ,    │    .    │    /    │
╰─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────╯
                    │   ---   │   BSP   │ Undo/Red│   │ Word Nav│   RET   │   ESC   │
                    ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

---

## 🎡 Smart Encoders

The encoders change behavior based on your active layer:

| Layer | Left Encoder (Rotation) | Right Encoder (Rotation) |
|-------|-------------------------|--------------------------|
| Base | 🔊 Volume Up / Down | 📜 Page Up / Down |
| Numbers | 🔄 Redo / Undo | ⏩ Next / Prev Word |
| Nav | ⬆️ Line Up / Down | ⬅️ Char Left / Right |
| Media | 🔊 Volume Up / Down | ⏭️ Next / Prev Track |
| Mouse | ↕️ Vertical Scroll | ↔️ Horizontal Scroll |

---

## 🧠 The "Corne" Caveats

Since the Sweep has fewer thumb keys than a Corne, the following logic is used:

- **Contextual BSPC**: When holding **NUMBERS**, the Left Outer thumb becomes **Backspace**.
- **Contextual DEL**: When holding **SYMBOLS**, the Right Inner thumb becomes **Delete**.
- **Tri-Layers**: 
    - `NUM` + `SYM` = **MEDIA LAYER**
    - `NAV` + `FUNC` = **SYSTEM LAYER**

---

## 🚀 Getting Started

### **Flashing Firmware**
1. **Left Half**: Flash `sweep_left.uf2`
2. **Right Half**: Flash `sweep_right.uf2`

### **Initial Setup**
1. Flash `settings_reset.uf2` to both halves
2. Power on left half (Central) → right half (Peripheral)
3. Connect left half via USB or pair via Bluetooth

---

## 📝 Layer Legend

| Symbol | Description |
|--------|-------------|
| `GUI/A` | Hold for GUI, Tap for A |
| `NUM/TAB`| Hold for Numbers, Tap for Tab |
| `---` | Layer activation key |
| `Studio` | ZMK Studio Unlock key |

Enjoy your optimized Sweep-Pro setup! 🎉
