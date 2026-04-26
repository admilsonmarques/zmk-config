# Ade's Sweep Pro Configuration

ZMK firmware for the Ferris Sweep Pro — nice_nano halves with e-ink display (left) and Cirque Pinnacle trackpad (right).

## Hardware

```
┌─────────────────┐    Bluetooth    ┌─────────────────┐
│   Sweep Left    │◄──────────────►│   Sweep Right   │
│   (Central)     │                │   (Peripheral)  │
│  ┌───────────┐  │                │  ┌───────────┐  │
│  │  E-Ink    │  │                │  │  Cirque   │  │
│  │  SSD1680  │  │                │  │ Pinnacle  │  │
│  └───────────┘  │                │  └───────────┘  │
└─────────────────┘                └─────────────────┘
```

Two operating modes:

| Mode | Central | Trackpad |
|---|---|---|
| Standalone | `sweep_left` (left half) | Active, relative mode |
| Dongle | `sweep_dongle_left` (peripheral) + `universal_dongle` | Forwarded via BLE split |

---

## Keyboard Layout

### Base Layer (0)

```
╭─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────╮
│    Q    │    W    │    E    │    R    │    T    │   │    Y    │    U    │    I    │    O    │    P    │
├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
│  GUI/A  │  ALT/S  │  CTL/D  │  SFT/F  │    G    │   │    H    │  SFT/J  │  CTL/K  │  ALT/L  │  GUI/;  │
├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
│    Z    │    X    │    C    │    V    │    B    │   │    N    │    M    │    ,    │    .    │    /    │
╰─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────╯
                    │ NUM/TAB │ NAV/SPC │  Enc L  │   │  Enc R  │ FUN/RET │ SYM/ESC │
                    ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

Encoder clicks: `Enc L` = `C_MUTE`, `Enc R` = ZMK Studio unlock.

### Numbers Layer (1)

```
╭─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────╮
│    1    │    2    │    3    │    4    │    5    │   │    6    │    7    │    8    │    9    │    0    │
├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
│  GUI/6  │  ALT/7  │  CTL/8  │  SFT/9  │    0    │   │    ;    │  SFT/←  │  CTL/↓  │  ALT/↑  │  GUI/→  │
├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │    -    │    -    │    -    │    -    │   │    -    │    -    │    ,    │    .    │    /    │
╰─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────╯
                    │  (---)  │   BSPC  │  Mute   │   │ PgUp/Dn │   RET   │   DEL   │
                    ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

### Symbols Layer (2)

```
╭─────────┬─────────┬─────────┬─────────┬─────────╮   ╭─────────┬─────────┬─────────┬─────────┬─────────╮
│    !    │    @    │    #    │    $    │    %    │   │    ^    │    &    │    *    │    -    │    =    │
├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
│  GUI/~  │  ALT/`  │  CTL/'  │  SFT/"  │    -    │   │    -    │  SFT/=  │  CTL/(  │  ALT/)  │  GUI/\  │
├─────────┼─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┼─────────┤
│    -    │    -    │    -    │    _    │    +    │   │    _    │    +    │    [    │    ]    │    /    │
╰─────────┴─────────┼─────────┼─────────┼─────────┤   ├─────────┼─────────┼─────────┼─────────┴─────────╯
                    │   BSPC  │   SPC   │  Mute   │   │ PgUp/Dn │   RET   │  (---)  │
                    ╰─────────┴─────────┴─────────╯   ╰─────────┴─────────┴─────────╯
```

---

## BSPC and DEL without encoder clicks

The outer thumb keys activate layers (not available as BSPC/DEL). Access them via the mirror-thumb trick:

| Want | How |
|---|---|
| **Backspace** | Hold **NUMBERS** (left inner) → left outer thumb sends `BSPC` |
| **Delete** | Hold **SYMBOLS** (right inner) → right inner thumb sends `DEL` |

---

## Conditional Layers

| Combination | Result |
|---|---|
| NAV + SYMBOLS held together | Media layer (3) |
| NUMBERS + FUNCTIONS held together | System layer (5) |

---

## Smart Encoders

| Layer | Left encoder | Right encoder |
|---|---|---|
| Base | Volume ↑↓ | Page Up/Down |
| Numbers | — | Next/Prev Word |
| Nav | Line Up/Down | Char Left/Right |
| Media | Volume ↑↓ | Next/Prev Track |
| Mouse | Scroll vertical | Scroll horizontal |

---

## Flashing Firmware

### Standalone mode

1. Flash `settings_reset-nice_nano-zmk.uf2` to both halves
2. Flash `sweep_left-nice_nano-zmk.uf2` to left half (becomes central)
3. Flash `sweep_right-nice_nano-zmk.uf2` to right half
4. Power on left → right auto-pairs

### Dongle mode

1. Flash `settings_reset` to both halves and the dongle
2. Flash `sweep_dongle_left-nice_nano-zmk.uf2` to left half (peripheral, e-ink shows status)
3. Flash `sweep_right-nice_nano-zmk.uf2` to right half (same firmware as standalone)
4. Flash `universal_dongle-xiao_ble-zmk.uf2` to dongle
5. Power on dongle → halves auto-pair

> Note: in dongle mode the Cirque trackpad on the right half is forwarded to the dongle via BLE split (`zmk,input-split`).

---

## Layer Legend

| Symbol | Meaning |
|---|---|
| `GUI/A` | Hold = GUI, tap = A |
| `NUM/TAB` | Hold = Numbers layer, tap = Tab |
| `(---)` | Layer-activation thumb key |
| `Studio` | ZMK Studio unlock |
