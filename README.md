# Ade's ZMK Multi-Keyboard Configuration

Three keyboards — one shared keymap, one shared dongle.

- **Corne** (nice_nano, 42 keys, RGB underglow)
- **Sweep Pro** (nice_nano, 36 keys, e-ink display + Cirque trackpad)
- **Totem** (xiao_ble, 38 keys)

All three can connect simultaneously to a single **universal dongle** (xiao_ble), or each can operate standalone over Bluetooth.

---

## Hardware Topology

```
  Corne Left        Corne Right       Sweep Left        Sweep Right
 (nice_nano)       (nice_nano)       (nice_nano)       (nice_nano)
 Peripheral         Peripheral        Peripheral         Peripheral
      │                  │           (+ e-ink)          (+ trackpad)
      └────────┬──────────┘                └──────┬──────┘
               │                                  │
        ┌──────┴──────────────────────────────────┘
        │
  Totem Left        Totem Right
  (xiao_ble)        (xiao_ble)
  Peripheral         Peripheral
        │                  │
        └──────┬────────────┘
               │
               ▼
     ┌──────────────────┐
     │  Universal Dongle │
     │   (xiao_ble)      │
     │   Central, BLE    │
     │   6 peripherals   │
     └────────┬──────────┘
              │
      ┌───────┴────────┐
      │                │
    USB             Bluetooth
  (Computer)       (5 profiles)
```

---

## Firmware per Device

| Device | Firmware file | Board | Role |
|---|---|---|---|
| Corne Left (standalone) | `corne_left-nice_nano-zmk.uf2` | nice_nano | Central |
| Corne Right | `corne_right-nice_nano-zmk.uf2` | nice_nano | Peripheral |
| Corne Left (dongle mode) | `corne_dongle_left-nice_nano-zmk.uf2` | nice_nano | Peripheral |
| Corne Right (dongle mode) | `corne_dongle_right-nice_nano-zmk.uf2` | nice_nano | Peripheral |
| Sweep Left (standalone) | `sweep_left-nice_nano-zmk.uf2` | nice_nano | Central, trackpad active |
| Sweep Right | `sweep_right-nice_nano-zmk.uf2` | nice_nano | Peripheral |
| Sweep Left (dongle mode) | `sweep_dongle_left-nice_nano-zmk.uf2` | nice_nano | Peripheral, e-ink status |
| Totem Left | `totem_left-xiao_ble-zmk.uf2` | xiao_ble | Peripheral |
| Totem Right | `totem_right-xiao_ble-zmk.uf2` | xiao_ble | Peripheral |
| Universal Dongle | `universal_dongle-xiao_ble-zmk.uf2` | xiao_ble | Central, up to 6 peripherals |

---

## Shared Keymap

All keyboards import `config/behaviors/keymap_layers.h`. The header defines:
- Layer indices (BASE=0 … FUNCTIONS=6)
- All row content macros (`KM_BASE_R0`, `KM_NUMS_R1`, …)
- Thumb cluster macros (`KM_THUMBS`, `KM_MID_T`)
- Conditional layers trigger (`KM_COND_LAYERS`)

Each keyboard wraps the shared macros with its own outer structure:

| Keyboard | Per-row wrapper | Thumb row |
|---|---|---|
| Corne / Totem (dongle keymap) | `&none KM_*_R0 &none` | `&kp ESC KM_THUMBS &kp BSLH` |
| Totem (standalone) | `KM_*_R0` rows 0-1, `&kp ESC KM_*_R2 &kp BSLH` row 2 | `KM_THUMBS` |
| Sweep | `KM_*_R0` (no outer columns) | `&kp C_MUTE KM_MID_T &studio_unlock` |

---

## Layer Map

### Layers 0-6

| # | Name | Activated by |
|---|---|---|
| 0 | Base | — |
| 1 | Numbers | Hold left-inner thumb |
| 2 | Symbols | Hold right-inner thumb |
| 3 | Media | NAV + SYMBOLS simultaneously (conditional) |
| 4 | Navigation | Hold right-outer thumb |
| 5 | System | NUMBERS + FUNCTIONS simultaneously (conditional) |
| 6 | Functions | Hold left-outer thumb |

### Thumb Cluster (Corne / Totem via dongle)

```
  ┌────────────┬────────────┬────────────┐   ┌────────────┬────────────┬────────────┐
  │  MED/BSPC  │  NUM/TAB   │  NAV/SPC   │   │  FUN/RET   │  SYM/ESC   │  SYS/DEL   │
  └────────────┴────────────┴────────────┘   └────────────┴────────────┴────────────┘
   (+ Totem: ESC outer-left)                   (+ Totem: BSLH outer-right)
```

### Thumb Cluster (Sweep)

```
  ┌──────────┬────────────┬────────────┐   ┌────────────┬────────────┬──────────┐
  │  C_MUTE  │  NUM/TAB   │  NAV/SPC   │   │  FUN/RET   │  SYM/ESC   │  Studio  │
  │ (encoder)│            │            │   │            │            │ (encoder)│
  └──────────┴────────────┴────────────┘   └────────────┴────────────┴──────────┘
   outer                  inner                          inner         outer
```

### BSPC / DEL without encoder clicks (Sweep)

| Action | How |
|---|---|
| Backspace | Hold **SYMBOLS** (`SYM/ESC`) → tap `NAV/SPC` (left inner 2) = `BSPC` |
| Delete | Hold **NUMBERS** (`NUM/TAB`) → tap `SYM/ESC` (right inner 2) = `DEL` |

---

## Base Layer

```
╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
│    Q     │    W     │    E     │    R     │    T     │   │    Y     │    U     │    I     │    O     │    P     │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│  GUI/A   │  ALT/S   │  CTL/D   │  SFT/F   │    G     │   │    H     │  SFT/J   │  CTL/K   │  ALT/L   │  GUI/;   │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│    Z     │    X     │    C     │    V     │    B     │   │    N     │    M     │    ,     │    .     │    /     │
╰──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────╯
                      │ MED/BSPC │ NUM/TAB  │ NAV/SPC  │   │ FUN/RET  │ SYM/ESC  │ SYS/DEL  │
                      ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
```

Corne adds `&none` outer columns. Totem adds `ESC` / `BSLH` outer keys in the bottom finger row.

---

## Numbers Layer (1)

```
╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
│    1     │    2     │    3     │    4     │    5     │   │    6     │    7     │    8     │    9     │    0     │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│  GUI/6   │  ALT/7   │  CTL/8   │  SFT/9   │    0     │   │    ;     │  SFT/←   │  CTL/↓   │  ALT/↑   │  GUI/→   │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│    -     │    -     │    -     │    -     │    -     │   │    -     │    -     │    ,     │    .     │    /     │
╰──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────╯
                      │   BSPC   │   (---) │   SPC    │   │   RET    │   DEL    │   (---)  │
                      ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
```

---

## Symbols Layer (2)

```
╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
│    !     │    @     │    #     │    $     │    %     │   │    ^     │    &     │    *     │    -     │    =     │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│  GUI/~   │  ALT/`   │  CTL/'   │  SFT/"   │    -     │   │    -     │  SFT/=   │  CTL/(   │  ALT/)   │  GUI/\   │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│    -     │    -     │    -     │    _     │    +     │   │    _     │    +     │    [     │    ]     │    /     │
╰──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────╯
                      │   (---)  │   BSPC   │   SPC    │   │   RET    │   (---)  │   DEL    │
                      ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
```

---

## Media Layer (3) — activated by NAV + SYMBOLS

```
╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
│    -     │  Vol-    │  Mute    │  Vol+    │    -     │   │    -     │  Prev    │  Play    │  Next    │ RGB Tog  │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│    -     │  Prev    │  Play    │  Next    │    -     │   │    -     │  Vol-    │  Mute    │  Vol+    │    -     │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│  ExtOff  │  ExtOn   │  BT Nxt  │    -     │    -     │   │ Soft Off │  Reset   │    -     │    -     │    -     │
╰──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────╯
                      │    -     │    -     │   (---)  │   │    -     │   (---)  │    -     │
                      ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
```

---

## Navigation Layer (4)

```
╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
│    ←     │    ↓     │    ↑     │    →     │    -     │   │    -     │  Home    │  PgDn    │  PgUp    │  End     │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│ GUI/Home │ALT/PgDn  │CTL/PgUp  │ SFT/End  │    -     │   │    -     │  SFT/←   │  CTL/↓   │  ALT/↑   │  GUI/→   │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│    -     │    -     │    -     │    -     │    -     │   │    -     │    -     │    -     │    -     │    -     │
╰──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────╯
                      │    -     │    -     │   (---)  │   │    -     │   (---)  │    -     │
                      ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
```

---

## System Layer (5) — activated by NUMBERS + FUNCTIONS

```
╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
│ OUT BLE  │  BT 0    │  BT 1    │  BT 2    │  BT 3    │   │  BT CLR  │  BT 4    │    -     │    -     │ OUT USB  │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│ RGB Spd+ │ RGB Sat+ │ RGB Bri+ │ RGB Hue+ │ RGB Eff+ │   │ RGB Togg │ Ext Pwr  │    -     │    -     │ Studio   │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│ RGB Spd- │ RGB Sat- │ RGB Bri- │ RGB Hue- │ RGB Eff- │   │ RGB EfR  │ Ext Off  │  Ext On  │  Reset   │ Soft Off │
╰──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────╯
                      │    -     │    -     │    -     │   │    -     │    -     │   (---)  │
                      ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
```

---

## Functions Layer (6)

```
╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
│   F6     │   F7     │   F8     │   F9     │  F10     │   │   F1     │   F2     │   F3     │   F4     │   F5     │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│   F1     │   F2     │   F3     │   F4     │   F5     │   │   F6     │   F7     │   F8     │   F9     │  F10     │
├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
│    -     │    -     │    -     │   DEL    │  PrtSc   │   │    -     │    -     │    -     │  Reset   │ Soft Off │
╰──────────┴──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┴──────────╯
                      │    -     │    -     │    -     │   │   (---)  │    -     │    -     │
                      ╰──────────┴──────────┴──────────╯   ╰──────────┴──────────┴──────────╯
```

---

## Getting Started

### Universal Dongle Setup (all keyboards at once)

1. Flash `settings_reset` to every device
2. Flash each keyboard peripheral firmware (see table above)
3. Flash `universal_dongle-xiao_ble-zmk.uf2` to the xiao_ble dongle
4. Power on dongle → keyboards → they auto-pair (30-60s)
5. Connect dongle to computer via USB or pair via Bluetooth ("Ade Universal")

### Standalone Mode (no dongle)

Each keyboard can operate independently:

- **Corne**: flash `corne_left` + `corne_right` — left half is central
- **Sweep**: flash `sweep_left` + `sweep_right` — left half is central, trackpad works
- **Totem**: flash `totem_left` + `totem_right` — connects to whichever is central

### Connectivity

```
BT Profile 0 ──► Work Laptop
BT Profile 1 ──► Personal Computer
BT Profile 2 ──► Phone
BT Profile 3 ──► Tablet
BT Profile 4 ──► Extra Device
USB Cable    ──► Desktop (direct, lowest latency)
```

| Action | Key Combination |
|---|---|
| Switch to USB | System → `OUT USB` |
| Switch to BLE | System → `OUT BLE` |
| Select BT profile 0-4 | System → `BT 0`…`BT 4` |
| Clear BT pairing | System → `BT CLR` |
| Soft off (deep sleep) | Hold power key 5 s |

---

## Layer Legend

| Symbol | Meaning |
|---|---|
| `GUI/A` | Hold = GUI modifier, tap = A |
| `MED/BSPC` | Hold = Media layer, tap = Backspace |
| `(---)` | Layer-activation thumb key |
| `RGB Tog` | Toggle RGB underglow on/off |
| `Studio` | ZMK Studio unlock |
