# Corne Dongle Troubleshooting Guide

## Overview
Your Corne dongle setup uses mixed boards:
- **Dongle (Central)**: Seeeduino Xiao BLE
- **Left/Right Halves (Peripherals)**: Nice Nano v2

This mixed configuration requires specific pairing procedures to work correctly.

## **Step 1: Build New Firmware**

After updating your `build.yaml`, rebuild your firmware to get the new `settings_reset` files:

1. Commit and push your changes to trigger a GitHub Actions build
2. Download the new firmware ZIP file
3. You should now have these files:
   - `settings_reset-seeeduino_xiao_ble-zmk.uf2` (for dongle)
   - `settings_reset-nice_nano_v2-zmk.uf2` (for left/right halves)
   - `corne_dongle_left-nice_nano_v2-zmk.uf2`
   - `corne_dongle_right-nice_nano_v2-zmk.uf2`
   - `corne_dongle_dongle-seeeduino_xiao_ble-zmk.uf2`

## **Step 2: Complete Reset Procedure**

### Important Notes:
- **ALL THREE DEVICES** need to be reset with `settings_reset` firmware
- The order matters - follow exactly as written
- Wait for each step to complete before proceeding

### Reset Sequence:

#### A. Reset the Dongle
1. Disconnect dongle from USB
2. Put dongle in bootloader mode (double-tap reset)
3. Flash `settings_reset-seeeduino_xiao_ble-zmk.uf2`
4. Wait for it to complete, then disconnect

#### B. Reset Left Half
1. Put left half in bootloader mode (double-tap reset)
2. Flash `settings_reset-nice_nano_v2-zmk.uf2`
3. Wait for it to complete, then disconnect

#### C. Reset Right Half
1. Put right half in bootloader mode (double-tap reset)
2. Flash `settings_reset-nice_nano_v2-zmk.uf2`
3. Wait for it to complete, then disconnect

## **Step 3: Flash New Firmware**

### Important: Wait 15 seconds between each flashing step

#### A. Flash Left Half
1. Put left half in bootloader mode
2. Flash `corne_dongle_left-nice_nano_v2-zmk.uf2`
3. **Wait 15 seconds** after flashing completes
4. Disconnect and set aside

#### B. Flash Right Half
1. Put right half in bootloader mode
2. Flash `corne_dongle_right-nice_nano_v2-zmk.uf2`
3. **Wait 15 seconds** after flashing completes
4. Disconnect and set aside

#### C. Flash Dongle
1. Put dongle in bootloader mode
2. Flash `corne_dongle_dongle-seeeduino_xiao_ble-zmk.uf2`
3. **Wait 15 seconds** after flashing completes

## **Step 4: Pairing Procedure**

### Critical: Follow this exact sequence

1. **Power on all devices simultaneously**:
   - Connect dongle to USB
   - Power on left half (via battery or USB)
   - Power on right half (via battery or USB)

2. **Wait for auto-pairing** (30-60 seconds):
   - The halves should automatically pair with the dongle
   - You might see LED activity during this process

3. **Test the connection**:
   - Try typing keys on both halves
   - If keys don't register, proceed to Step 5

## **Step 5: Manual Pairing (if auto-pairing fails)**

If the automatic pairing doesn't work:

1. **Reset all devices simultaneously**:
   - Press reset button on dongle
   - Press reset button on left half
   - Press reset button on right half
   - Try to do this within 1-2 seconds of each other

2. **Wait again** (30-60 seconds) for pairing

3. **Test again**

## **Step 6: Troubleshooting**

### If still not working:

#### A. Check for Interference
- Move away from other Bluetooth devices
- Turn off other keyboards/mice
- Try in a different room

#### B. Verify Firmware Files
- Ensure you're using the correct firmware files for each device
- Check that the build completed successfully

#### C. Check Power
- Ensure all devices have sufficient power
- Try fresh batteries if using battery power

#### D. USB vs Bluetooth Output
- The dongle might be defaulting to USB output
- Try pressing the output selection keys in your keymap:
  - Look for `&out OUT_BLE` or `&out OUT_TOG` in your keymap
  - This switches between USB and Bluetooth output

### Common Issues:

1. **Dongle connects to computer but halves don't work**:
   - The halves haven't paired with the dongle yet
   - Repeat the pairing procedure

2. **Only one half works**:
   - One half paired, the other didn't
   - Reset and re-pair both halves

3. **Nothing works**:
   - Complete reset procedure wasn't followed
   - Start over from Step 2

## **Step 7: Verifying Success**

Your setup is working correctly when:
- Both halves respond to key presses
- The dongle successfully sends input to your computer
- You can switch between USB and Bluetooth output modes

## **Additional Tips**

1. **Battery Life**: The dongle setup improves battery life on the halves since they're now peripherals
2. **Connection Management**: The dongle manages the Bluetooth connection - the halves only connect to the dongle
3. **Profile Switching**: Use the Bluetooth profile keys on the dongle to switch between connected devices

## **If All Else Fails**

1. Try the procedure with a different USB cable
2. Test with a phone/tablet first (better Bluetooth compatibility)
3. Check if your computer supports Bluetooth 4.2 or newer
4. Consider using a different Bluetooth adapter if on a desktop

---

**Need Help?** If you're still having issues, please note:
- Which step you're stuck on
- What happens when you try (LEDs, behavior, etc.)
- Your operating system
- Whether you're using USB or battery power 