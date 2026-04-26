# GPIO Configuration Reference

Pin assignments for each keyboard shield.

---

## Corne Dongle Peripherals (nice_nano)

Both halves share the same row GPIOs. Columns are physically mirrored on the right side.

### Row GPIOs (identical on both halves)

| Row | GPIO | nRF Pin |
|---|---|---|
| 0 | `gpio0 22` | P0.22 |
| 1 | `gpio0 24` | P0.24 |
| 2 | `gpio1 0`  | P1.00 |
| 3 | `gpio0 11` | P0.11 |

Pull: `GPIO_ACTIVE_HIGH | GPIO_PULL_DOWN`, diode direction: `col2row`.

### Column GPIOs — Left Half (col-offset = 0, global cols 0-5)

| Local col | GPIO | nRF Pin | Key column |
|---|---|---|---|
| 0 | `gpio0 31` | P0.31 | Q / A / Z |
| 1 | `gpio0 29` | P0.29 | W / S / X |
| 2 | `gpio0 2`  | P0.02 | E / D / C |
| 3 | `gpio1 15` | P1.15 | R / F / V |
| 4 | `gpio1 13` | P1.13 | T / G / B |
| 5 | `gpio1 11` | P1.11 | (outer column) |

### Column GPIOs — Right Half (col-offset = 6, global cols 6-11)

| Local col | GPIO | nRF Pin | Key column |
|---|---|---|---|
| 0 | `gpio1 11` | P1.11 | (outer column) |
| 1 | `gpio1 13` | P1.13 | Y / H / N |
| 2 | `gpio1 15` | P1.15 | U / J / M |
| 3 | `gpio0 2`  | P0.02 | I / K / , |
| 4 | `gpio0 29` | P0.29 | O / L / . |
| 5 | `gpio0 31` | P0.31 | P / ; / / |

### Matrix layout (global 12-column space)

```
Global cols:  0   1   2   3   4   5     6   7   8   9  10  11
Row 0:       [-]  Q   W   E   R   T  │  Y   U   I   O   P  [-]
Row 1:       [-] A/G S/A D/C F/S  G  │  H  J/S K/C L/A ;/G [-]
Row 2:       [-]  Z   X   C   V   B  │  N   M   ,   .   /  [-]
Row 3:                   BSP TAB SPC │ RET ESC DEL
```

`[-]` = outer column, bound to `&none` in the universal dongle keymap.
Thumbs: global RC(3,3)–RC(3,5) left, RC(3,6)–RC(3,8) right.

---

## Sweep Pro Peripherals (nice_nano)

### Row GPIOs (identical on both halves)

| Row | GPIO | nRF Pin |
|---|---|---|
| 0 | `gpio0 9`  | P0.09 |
| 1 | `gpio0 10` | P0.10 |
| 2 | `gpio1 11` | P1.11 |
| 3 | `gpio1 6`  | P1.06 |

Pull: `GPIO_ACTIVE_HIGH | GPIO_PULL_DOWN`, diode direction: `col2row`.

### Column GPIOs — Left Half (col-offset = 1, global cols 1-5)

| Local col | GPIO | nRF Pin |
|---|---|---|
| 0 | `gpio1 13` | P1.13 |
| 1 | `gpio1 15` | P1.15 |
| 2 | `gpio0 2`  | P0.02 |
| 3 | `gpio0 29` | P0.29 |
| 4 | `gpio0 31` | P0.31 |

### Column GPIOs — Right Half (col-offset = 6, global cols 6-10)

| Local col | GPIO | nRF Pin |
|---|---|---|
| 0 | `gpio1 13` | P1.13 |
| 1 | `gpio1 15` | P1.15 |
| 2 | `gpio0 2`  | P0.02 |
| 3 | `gpio0 29` | P0.29 |
| 4 | `gpio0 31` | P0.31 |

### Matrix layout (global 12-column space)

```
Global cols:  1   2   3   4   5     6   7   8   9  10
Row 0:        Q   W   E   R   T  │  Y   U   I   O   P
Row 1:       A/G S/A D/C F/S  G  │  H  J/S K/C L/A ;/G
Row 2:        Z   X   C   V   B  │  N   M   ,   .   /
Row 3:                TAB SPC   │    RET ESC
```

Cols 0 and 11 are unused. Thumbs: RC(3,3)–RC(3,5) left, RC(3,6)–RC(3,8) right.

### Encoders (left half)

| Signal | GPIO | nRF Pin |
|---|---|---|
| A | `gpio0 11` | P0.11 |
| B | `gpio1 0`  | P1.00 |

### E-ink Display SPI (left half, SSD1680)

| Signal | GPIO | nRF Pin |
|---|---|---|
| SCK (SPIM) | `gpio0 24` | P0.24 |
| MOSI (SPIM) | `gpio0 22` | P0.22 |
| CS | `gpio0 17` | P0.17 |
| DC | `gpio0 20` | P0.20 |
| RST | `gpio1 4`  | P1.04 |
| BUSY | `gpio0 6`  | P0.06 |

### Cirque Trackpad I2C (right half, addr 0x2A)

| Signal | GPIO | nRF Pin |
|---|---|---|
| SDA | `gpio0 20` | P0.20 |
| SCL | `gpio0 17` | P0.17 |
| Data ready | `gpio0 22` | P0.22 |

---

## Totem Peripherals (xiao_ble)

### Row GPIOs (identical on both halves, xiao_d alias)

| Row | xiao_d pin |
|---|---|
| 0 | `xiao_d 0` |
| 1 | `xiao_d 1` |
| 2 | `xiao_d 2` |
| 3 | `xiao_d 3` |

### Column GPIOs — Left Half (col-offset = 1, global cols 1-5)

`xiao_d 4, 5, 10, 9, 8`

### Column GPIOs — Right Half (col-offset = 6, global cols 6-10)

`xiao_d 8, 9, 10, 5, 4`

### Matrix layout (global 12-column space)

```
Global cols:  1   2   3   4   5     6   7   8   9  10
Row 0:        Q   W   E   R   T  │  Y   U   I   O   P
Row 1:       A/G S/A D/C F/S  G  │  H  J/S K/C L/A ;/G
Row 3(outer) ESC  Z   X   C   V   B  │  N   M   ,   .   /  BSLH
Row 3:                TAB SPC RET│ RET ESC DEL
```

Outer keys: RC(3,1) = ESC (left), RC(3,10) = BSLH (right). Thumbs: RC(3,3)–RC(3,5) / RC(3,6)–RC(3,8).

---

## Universal Dongle (xiao_ble)

No physical GPIO scanning — uses `zmk,kscan-mock`. Receives key events from all peripherals over BLE.

Transform covers the full global 12-column space:

```
Rows 0-2: RC(*,0)–RC(*,11)         (42 finger keys)
Row 3:    RC(3,1) RC(3,3-5) RC(3,6-8) RC(3,10)  (8 thumb/outer keys)
```

Total: 50 key positions (44 used by Corne keymap). Corne outer cols RC(*,0)/RC(*,11) and Sweep cols 0/11 are never pressed; they're bound to `&none` in the keymap.

---

## RGB Underglow — Corne Dongle Peripherals

The LED strip is configured in `boards/nice_nano_nrf52840_zmk.overlay` (auto-applied for nice_nano builds):

| Signal | GPIO | nRF Pin | Protocol |
|---|---|---|---|
| Data (MOSI) | SPI3 | P0.06 | WS2812-SPI |

Chain length: 27 LEDs per half. Color order: GRB.
