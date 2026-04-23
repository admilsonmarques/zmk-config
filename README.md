# 🎹 Ade's Corne Dongle Configuration

A complete ZMK configuration for the Corne keyboard with **dongle support** using mixed boards.

## 🏗️ Hardware Setup

```
┌─────────────────┐    Bluetooth    ┌─────────────────┐
│   Corne Left    │◄──────────────►│   Corne Right   │
│   nice_nano_v2  │                │   nice_nano_v2  │
│   (Peripheral)  │                │   (Peripheral)  │
└─────────────────┘                └─────────────────┘
         │                                    │
         │            Bluetooth               │
         ▼                                    ▼
  ┌─────────────────────────────────────────────────────┐
  │              Corne Dongle                           │
  │           seeeduino_xiao_ble                        │
  │              (Central)                              │
  └─────────────────┬───────────────────────────────────┘
                    │
         ┌──────────┴──────────┐
         │                     │
         ▼                     ▼
    USB Cable              Bluetooth
   (Computer)             (5 Devices)
```

## ✨ Features

- 🔗 **Mixed Board Support**: nice_nano_v2 halves + seeeduino_xiao_ble dongle
- 🔄 **Dual Connectivity**: USB + Bluetooth (up to 5 BT profiles)
- 🔋 **Power Optimized**: Halves can sleep, dongle stays awake
- ⌨️ **7 Layers**: Base, Numbers, Symbols, Media, Navigation, Functions, System
- 🏠 **Homerow Mods**: GUI/Alt/Ctrl/Shift on home row
- 🎛️ **Layer Taps**: Multiple functions per thumb key

---

## 🗺️ Keyboard Layout

### 🏠 Base Layer (0)
```
╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮
│    -    │    Q    │    W    │    E    │    R    │    T    │   │    Y    │    U    │    I    │    O    │    P    │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │ GUI/A   │ ALT/S   │ CTL/D   │ SFT/F   │    G    │   │    H    │ SFT/J   │ CTL/K   │ ALT/L   │ GUI/;   │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │    Z    │    X    │    C    │    V    │    B    │   │    N    │    M    │    ,    │    .    │    /    │    -    │
╰─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────┴─────────╯
                              │ MED/BSP │ NUM/TAB │ NAV/SPC │   │ FUN/RET │ SYM/ESC │ SYS/DEL │
                              ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

### 🔢 Numbers Layer (1)
```
╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮
│    -    │    1    │    2    │    3    │    4    │    5    │   │    6    │    7    │    8    │    9    │    0    │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │ GUI/6   │ ALT/7   │ CTL/8   │ SFT/9   │    0    │   │    ;    │ SFT/←   │ CTL/↓   │ ALT/↑   │ GUI/→   │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │    -    │    -    │    -    │    -    │    -    │   │    -    │    -    │    ,    │    .    │    /    │    -    │
╰─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────┴─────────╯
                              │   BSP   │   ---   │   SPC   │   │   RET   │   ESC   │   DEL   │
                              ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

### 🔣 Symbols Layer (2)
```
╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮
│    -    │    !    │    @    │    #    │    $    │    %    │   │    ^    │    &    │    *    │    -    │    =    │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │ GUI/~   │ ALT/`   │ CTL/'   │ SFT/"   │    -    │   │    -    │ SFT/=   │ CTL/(   │ ALT/)   │ GUI/\   │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │    -    │    -    │    -    │    _    │    +    │   │    _    │    +    │    [    │    ]    │    /    │    -    │
╰─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────┴─────────╯
                              │   BSP   │   TAB   │   SPC   │   │   RET   │   ---   │   DEL   │
                              ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

### 🎵 Media Layer (3)
```
╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮
│    -    │    -    │  Vol-   │  Mute   │  Vol+   │    -    │   │    -    │  Prev   │  Play   │  Next   │    -    │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │    -    │  Prev   │  Play   │  Next   │    -    │   │    -    │  Vol-   │  Mute   │  Vol+   │    -    │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │    -    │    -    │  BT Nxt │    -    │    -    │   │ Soft Off│  Reset  │    -    │    -    │    -    │    -    │
╰─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────┴─────────╯
                              │   ---   │    -    │    -    │   │    -    │    -    │    -    │
                              ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

### 🧭 Navigation Layer (4)
```
╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮
│    -    │    ←    │    ↓    │    ↑    │    →    │    -    │   │    -    │  Home   │  PgDn   │  PgUp   │   End   │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │GUI/Home │ALT/PgDn │CTL/PgUp │ SFT/End │    -    │   │    -    │ SFT/←   │ CTL/↓   │ ALT/↑   │ GUI/→   │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │    -    │    -    │    -    │    -    │    -    │   │    -    │    -    │    -    │    -    │    -    │    -    │
╰─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────┴─────────╯
                              │    -    │    -    │   ---   │   │    -    │    -    │    -    │
                              ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

### ⚡ Functions Layer (5)
```
╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮
│    -    │   F6    │   F7    │   F8    │   F9    │  F10    │   │   F1    │   F2    │   F3    │   F4    │   F5    │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │   F1    │   F2    │   F3    │   F4    │   F5    │   │   F6    │   F7    │   F8    │   F9    │  F10    │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │    -    │    -    │    -    │   DEL   │  PrtSc  │   │    -    │    -    │    -    │  Reset  │ Soft Off│    -    │
╰─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────┴─────────╯
                              │    -    │    -    │    -    │   │   ---   │    -    │    -    │
                              ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

### ⚙️ System Layer (6) - **Connectivity Control**
```
╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────┬─────────╮
│    -    │OUT BLE  │  BT 0   │  BT 1   │  BT 2   │  BT 3   │   │ BT CLR  │  BT 4   │    -    │    -    │OUT USB  │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │RGB Spd+ │RGB Sat+ │RGB Bri+ │RGB Hue+ │RGB Eff+ │   │RGB Togg │    -    │    -    │    -    │ Studio  │    -    │
├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │RGB Spd- │RGB Sat- │RGB Bri- │RGB Hue- │RGB Eff- │   │    -    │    -    │    -    │    -    │ Soft Off│    -    │
╰─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────┴─────────╯
                              │    -    │    -    │    -    │   │    -    │    -    │   ---   │
                              ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

---

## 🔄 Connectivity Guide

### **Multiple Device Setup**
```
BT Profile 0 ──► 💻 Work Laptop
BT Profile 1 ──► 🖥️ Personal Computer  
BT Profile 2 ──► 📱 Phone
BT Profile 3 ──► 📲 Tablet
BT Profile 4 ──► 🖥️ Another Device
USB Cable   ──► 🖥️ Desktop (Direct)
```

### **Quick Switching**
| Action | Key Combination |
|--------|----------------|
| Switch to USB | `System Layer` + `OUT USB` |
| Switch to Bluetooth | `System Layer` + `OUT BLE` |
| Select BT Device 0-4 | `System Layer` + `BT 0-4` |
| Clear BT Connection | `System Layer` + `BT CLR` |

---

## 🚀 Getting Started

### **Flashing Firmware**
1. **Left Half**: Flash `corne_dongle_left.uf2` to nice_nano
2. **Right Half**: Flash `corne_dongle_right.uf2` to nice_nano  
3. **Dongle**: Flash `universal_dongle.uf2` to xiao_ble

### **Initial Setup**
1. Flash `settings_reset.uf2` to all three devices first
2. Power on dongle → left half → right half
3. Connect dongle to computer via USB or pair via Bluetooth

### **Pairing New Devices**
1. Press `System Layer` + `BT CLR` to clear if needed
2. Press `System Layer` + `BT X` (0-4) to select profile
3. Press `System Layer` + `OUT BLE` to enable Bluetooth
4. Put device in pairing mode and search for "Ade Corne Dongle"

---

## 📝 Layer Legend

| Symbol | Description |
|--------|-------------|
| `GUI/A` | Hold for GUI, Tap for A |
| `MED/BSP` | Hold for Media Layer, Tap for Backspace |
| `---` | Layer activation key |
| `RGB +/-` | RGB increase/decrease |
| `◄/►` | Navigation arrows |

## 🔋 Power Management

- **Dongle**: Always on (powered by USB/battery)
- **Halves**: Auto-sleep after inactivity
- **Wake**: Press any key on sleeping half
- **Soft Off**: Long press soft off key (5 seconds)

---

## 🎯 Why Dongle Setup?

✅ **Single USB connection** - no cable management  
✅ **Better battery life** - halves can sleep independently  
✅ **Multi-device support** - 5 Bluetooth profiles + USB  
✅ **Connection stability** - dongle maintains state  
✅ **Wireless freedom** - both halves wireless  

Enjoy your optimized Corne setup! 🎉

