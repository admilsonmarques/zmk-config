# Universal Dongle Troubleshooting Guide

## Overview

The universal dongle (xiao_ble) is the central for all keyboards simultaneously:

| Device | Firmware | Board |
|---|---|---|
| Universal Dongle | `universal_dongle-xiao_ble-zmk.uf2` | xiao_ble |
| Corne Left | `corne_dongle_left-nice_nano-zmk.uf2` | nice_nano |
| Corne Right | `corne_dongle_right-nice_nano-zmk.uf2` | nice_nano |
| Sweep Left (dongle mode) | `sweep_dongle_left-nice_nano-zmk.uf2` | nice_nano |
| Sweep Right | `sweep_right-nice_nano-zmk.uf2` | nice_nano |
| Totem Left | `totem_left-xiao_ble-zmk.uf2` | xiao_ble |
| Totem Right | `totem_right-xiao_ble-zmk.uf2` | xiao_ble |

Settings-reset files:
- `settings_reset-xiao_ble-zmk.uf2` — for dongle, Totem halves
- `settings_reset-nice_nano-zmk.uf2` — for Corne and Sweep halves

---

## Step 1: Build New Firmware

Push your changes to trigger a GitHub Actions build, then download the firmware ZIP.

---

## Step 2: Complete Reset

Flash `settings_reset` to **every** device. Order matters:

1. **Dongle**: double-tap reset → flash `settings_reset-xiao_ble-zmk.uf2` → disconnect
2. **Corne Left**: double-tap reset → flash `settings_reset-nice_nano-zmk.uf2` → disconnect
3. **Corne Right**: same
4. **Sweep Left**: same
5. **Sweep Right**: same
6. **Totem Left**: double-tap reset → flash `settings_reset-xiao_ble-zmk.uf2` → disconnect
7. **Totem Right**: same

---

## Step 3: Flash Keyboard Firmware

Wait 15 seconds between each device.

1. Corne Left → `corne_dongle_left-nice_nano-zmk.uf2`
2. Corne Right → `corne_dongle_right-nice_nano-zmk.uf2`
3. Sweep Left → `sweep_dongle_left-nice_nano-zmk.uf2`
4. Sweep Right → `sweep_right-nice_nano-zmk.uf2`
5. Totem Left → `totem_left-xiao_ble-zmk.uf2`
6. Totem Right → `totem_right-xiao_ble-zmk.uf2`
7. Dongle → `universal_dongle-xiao_ble-zmk.uf2`

---

## Step 4: Pairing

1. Power on the dongle (connect via USB)
2. Power on each keyboard half
3. Wait 30-60 seconds — halves auto-pair with the dongle
4. Test keys on each keyboard
5. The dongle appears to the host as **"Ade Universal"**

---

## Step 5: Manual Pairing (if auto-pairing fails)

Reset all devices simultaneously (press reset on each within 1-2 seconds), then wait again.

---

## Step 6: Troubleshooting

### Dongle connects but a keyboard doesn't respond
- That keyboard half didn't pair — reset just that half and the dongle

### Only one half of a keyboard works
- The other half is paired to a different dongle slot or hasn't paired yet
- Do a full reset for that keyboard pair

### Nothing works
- The reset procedure wasn't followed in order — start over from Step 2

### Keyboard connects but output goes nowhere
- The dongle might be on BLE output — switch to USB via `System → OUT USB`
- Or pair the dongle to your host via `System → BT 0` + `System → OUT BLE`

---

## Tips

- **Peripheral sleep**: halves can sleep (`CONFIG_ZMK_SLEEP`); pressing any key wakes them
- **Dongle always on**: the universal_dongle has sleep disabled so it stays ready for the host
- **Standalone mode**: each keyboard also works without the dongle — see main README
- **BT profiles**: the dongle supports 5 profiles (BT 0-4) + USB simultaneously

---

**Need help?** Note which step you're stuck on, what LEDs show, and your OS.
