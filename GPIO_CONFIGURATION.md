# 🔌 GPIO Configuration Guide

A detailed visual explanation of how GPIO pins are configured for the Corne Dongle setup.

---

## 🏗️ Overview: Matrix Scanning

### **How Keyboard Matrix Works**
```
         COLUMNS (COL)
    │ C0 │ C1 │ C2 │ C3 │ C4 │ C5 │
────┼────┼────┼────┼────┼────┼────┤
R0  │ Q  │ W  │ E  │ R  │ T  │ Y  │ ← ROW 0
────┼────┼────┼────┼────┼────┼────┤
R1  │ A  │ S  │ D  │ F  │ G  │ H  │ ← ROW 1
────┼────┼────┼────┼────┼────┼────┤
R2  │ Z  │ X  │ C  │ V  │ B  │ N  │ ← ROW 2
────┼────┼────┼────┼────┼────┼────┤
R3  │    │    │    │BSP │TAB │SPC │ ← ROW 3
    ↑    ↑    ↑    ↑    ↑    ↑
   ROWS (ROW)
```

**Scanning Process:**
1. **Activate Row**: Set one row HIGH
2. **Read Columns**: Check which columns detect the signal
3. **Key Detection**: If Row X + Column Y = Key pressed at (X,Y)
4. **Repeat**: Scan all rows continuously

---

## 📟 nice!nano v2 Pinout

### **Physical Pin Layout**
```
     nice!nano v2 (Top View)
    ┌─────────────────────────┐
    │  ●                   ● │ ← VCC / GND
    │  ● P0.02          P1.15 ● │
    │  ● P0.29          P1.13 ● │
    │  ● P0.31          P1.11 ● │
    │  ● P1.13          P0.10 ● │
    │  ● P1.15          P0.09 ● │
    │  ● P0.02          P0.06 ● │
    │  ● P0.29          P0.08 ● │
    │  ● P0.31          P1.09 ● │
    │  ● VCC           P0.06  ● │
    │  ● RST           P0.04  ● │
    │  ● GND           P1.04  ● │
    │  ● P1.06         P1.06  ● │
    │  ● P1.04         P1.02  ● │
    │  ● P1.02         P1.00  ● │
    │  ● P1.00         P0.22  ● │
    │  ● P0.22         P0.24  ● │
    │  ● P0.24         P1.00  ● │
    │  ● P1.00         P0.11  ● │
    │  ● P0.11         P1.08  ● │
    │  ● P1.08         P1.01  ● │
    │  ● P1.01         P1.03  ● │
    │  ● P1.03           GND ● │
    │  ●               VCC   ● │
    └─────────────────────────┘
```

### **GPIO Reference Translation**
```
ZMK Reference  →  Physical Pin  →  Function
─────────────────────────────────────────────
&gpio0 22      →  P0.22        →  Row 0
&gpio1 0       →  P1.00        →  Row 1  
&gpio1 3       →  P1.03        →  Row 2
&gpio1 1       →  P1.01        →  Row 3

&gpio0 31      →  P0.31        →  Col 0
&gpio0 29      →  P0.29        →  Col 1
&gpio0 2       →  P0.02        →  Col 2
&gpio1 15      →  P1.15        →  Col 3
&gpio1 13      →  P1.13        →  Col 4
&gpio1 11      →  P1.11        →  Col 5
```

---

## 🎹 Left Half Configuration

### **GPIO Assignment (nice_nano_v2)**
```
Row Configuration:
  ROW 0: P0.22 (gpio0 22) ─┐
  ROW 1: P1.00 (gpio1 0)  ─┤
  ROW 2: P1.03 (gpio1 3)  ─┤ ROWS
  ROW 3: P1.01 (gpio1 1)  ─┘

Column Configuration:
  COL 0: P0.31 (gpio0 31) ─┐
  COL 1: P0.29 (gpio0 29) ─┤
  COL 2: P0.02 (gpio0 2)  ─┤ COLUMNS
  COL 3: P1.15 (gpio1 15) ─┤
  COL 4: P1.13 (gpio1 13) ─┤
  COL 5: P1.11 (gpio1 11) ─┘
```

### **Left Half Matrix Map**
```
         C0    C1    C2    C3    C4    C5
       ┌─────┬─────┬─────┬─────┬─────┬─────┐
    R0 │  Q  │  W  │  E  │  R  │  T  │  -  │
       ├─────┼─────┼─────┼─────┼─────┼─────┤
    R1 │  A  │  S  │  D  │  F  │  G  │  -  │
       ├─────┼─────┼─────┼─────┼─────┼─────┤
    R2 │  Z  │  X  │  C  │  V  │  B  │  -  │
       ├─────┼─────┼─────┼─────┼─────┼─────┤
    R3 │  -  │  -  │  -  │ BSP │ TAB │ SPC │
       └─────┴─────┴─────┴─────┴─────┴─────┘

Physical Pins Used:
Rows: P0.22, P1.00, P1.03, P1.01
Cols: P0.31, P0.29, P0.02, P1.15, P1.13, P1.11
```

---

## 🎹 Right Half Configuration

### **GPIO Assignment (nice_nano_v2)**
```
Row Configuration: (SAME as left!)
  ROW 0: P0.22 (gpio0 22) ─┐
  ROW 1: P1.00 (gpio1 0)  ─┤
  ROW 2: P1.03 (gpio1 3)  ─┤ ROWS
  ROW 3: P1.01 (gpio1 1)  ─┘

Column Configuration: (REVERSED!)
  COL 0: P1.11 (gpio1 11) ─┐
  COL 1: P1.13 (gpio1 13) ─┤
  COL 2: P1.15 (gpio1 15) ─┤ COLUMNS
  COL 3: P0.02 (gpio0 2)  ─┤ (Mirrored)
  COL 4: P0.29 (gpio0 29) ─┤
  COL 5: P0.31 (gpio0 31) ─┘
```

### **Right Half Matrix Map**
```
         C0    C1    C2    C3    C4    C5
       ┌─────┬─────┬─────┬─────┬─────┬─────┐
    R0 │  -  │  Y  │  U  │  I  │  O  │  P  │
       ├─────┼─────┼─────┼─────┼─────┼─────┤
    R1 │  -  │  H  │  J  │  K  │  L  │  ;  │
       ├─────┼─────┼─────┼─────┼─────┼─────┤
    R2 │  -  │  N  │  M  │  ,  │  .  │  /  │
       ├─────┼─────┼─────┼─────┼─────┼─────┤
    R3 │ RET │ ESC │ DEL │  -  │  -  │  -  │
       └─────┴─────┴─────┴─────┴─────┴─────┘

Physical Pins Used:
Rows: P0.22, P1.00, P1.03, P1.01 (Same as left)
Cols: P1.11, P1.13, P1.15, P0.02, P0.29, P0.31 (Reversed)
```

---

## 📡 Dongle Configuration

### **seeeduino_xiao_ble Layout**
```
      XIAO BLE nRF52840 (Top View)
    ┌─────────────────────────┐
    │  ● P0.02  P0.03 ●      │ ← A0/D0, A1/D1
    │  ● P0.28  P0.29 ●      │ ← A2/D2, A3/D3  
    │  ● P0.04  P0.05 ●      │ ← A4/D4, A5/D5
    │  ● P0.06  P1.11 ●      │ ← A6/D6, A7/D7
    │  ● P0.30  P1.12 ●      │ ← A8/D8, A9/D9
    │  ● P0.31  P1.13 ●      │ ← A10/D10, A11/RX
    │  ● GND    VCC  ●       │
    │  ● P1.15  P1.14 ●      │ ← SDA, SCL
    │  ● P1.10   RST ●       │ ← TX, RST
    │  ● 3V3     GND ●       │
    └─────────────────────────┘
```

### **Mock Scan Configuration**
```
📡 DONGLE (No Physical Keys!)
┌─────────────────────────────┐
│        Mock KScan           │
│                             │
│   • No GPIO pins needed     │
│   • No physical switches    │
│   • Just wireless receiver  │
│   • Forwards key events     │
│                             │
│  Left Half ──┐  ┌── Right   │
│      BLE     │  │    Half   │
│              ▼  ▼           │
│         [ Dongle ]          │
│              │              │
│              ▼              │
│         Computer            │
│      (USB or BLE)           │
└─────────────────────────────┘
```

---

## 🔌 Pin Mapping Summary

### **Left Half (nice_nano_v2)**
| Function | GPIO Ref | Physical Pin | Description |
|----------|----------|--------------|-------------|
| Row 0    | gpio0 22 | P0.22        | Top row scan |
| Row 1    | gpio1 0  | P1.00        | Home row scan |
| Row 2    | gpio1 3  | P1.03        | Bottom row scan |
| Row 3    | gpio1 1  | P1.01        | Thumb row scan |
| Col 0    | gpio0 31 | P0.31        | Q, A, Z column |
| Col 1    | gpio0 29 | P0.29        | W, S, X column |
| Col 2    | gpio0 2  | P0.02        | E, D, C column |
| Col 3    | gpio1 15 | P1.15        | R, F, V column |
| Col 4    | gpio1 13 | P1.13        | T, G, B column |
| Col 5    | gpio1 11 | P1.11        | -, -, - column |

### **Right Half (nice_nano_v2)**
| Function | GPIO Ref | Physical Pin | Description |
|----------|----------|--------------|-------------|
| Row 0-3  | Same as left | Same as left | Identical row config |
| Col 0    | gpio1 11 | P1.11        | -, H, N column |
| Col 1    | gpio1 13 | P1.13        | Y, J, M column |
| Col 2    | gpio1 15 | P1.15        | U, K, , column |
| Col 3    | gpio0 2  | P0.02        | I, L, . column |
| Col 4    | gpio0 29 | P0.29        | O, ;, / column |
| Col 5    | gpio0 31 | P0.31        | P, -, - column |

### **Dongle (seeeduino_xiao_ble)**
| Function | Configuration | Description |
|----------|---------------|-------------|
| Scanning | Mock KScan    | No physical pins used |
| Purpose  | BLE Central   | Receives from peripherals |
| Keys     | None          | Pure wireless coordinator |

---

## ⚡ Key Technical Points

### **Diode Direction: col2row**
```
ROW ──►──[Diode]──►── COLUMN
    (High)         (Detected)

When row goes HIGH:
• Current flows through pressed key's diode
• Column pin detects the signal
• Key position = (active_row, detected_column)
```

### **Pull-down Resistors on Rows**
```
Row Pin Configuration:
(GPIO_ACTIVE_HIGH | GPIO_PULL_DOWN)

• PULL_DOWN: Keeps row at LOW when not driven
• ACTIVE_HIGH: Row goes HIGH when scanning
• Prevents floating pins and false triggers
```

### **Why Columns are Reversed on Right Half?**
```
Left Half Columns:  [C0 C1 C2 C3 C4 C5]
Right Half Columns: [C5 C4 C3 C2 C1 C0]

Physical Layout:
Left:  Q W E R T    Right:  Y U I O P
       ↑ ↑ ↑ ↑ ↑            ↑ ↑ ↑ ↑ ↑
     C0C1C2C3C4           C1C2C3C4C5

The right side is physically mirrored, so
column assignments are reversed to match!
```

---

## 🧠 Matrix Scanning Flow

```
1. Initialize GPIO
   ├── Set all rows as OUTPUT (LOW)
   ├── Set all columns as INPUT
   └── Enable pull-down on rows

2. Scanning Loop
   ├── Set Row 0 HIGH ──┐
   ├── Read all columns ┤ → Check for key presses
   ├── Set Row 0 LOW ───┘
   ├── Set Row 1 HIGH ──┐
   ├── Read all columns ┤ → Check for key presses  
   ├── Set Row 1 LOW ───┘
   └── Repeat for all rows...

3. Key Detection
   ├── Row N + Column M = Key at position (N,M)
   ├── Send key event to ZMK
   └── ZMK processes keymap
```

This configuration ensures reliable key detection while maximizing battery life and connection stability! 🎯 