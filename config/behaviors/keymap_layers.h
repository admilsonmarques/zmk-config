/*
 * Shared keymap layer content — imported by Corne, Sweep, and Totem.
 *
 * Each keyboard wraps these 10-key row macros with its own outer structure:
 *   Corne dongle:  &none  KM_*_R0  &none    (outer &none columns)
 *   Totem:         &kp ESC  KM_*_R2  &kp BSLH (outer keys on bottom row only)
 *   Sweep:         KM_*_R0             (no outer columns)
 */

#pragma once

// ─── Layer indices ──────────────────────────────────────────────────────────
#define BASE      0
#define NUMBERS   1
#define SYMBOLS   2
#define MEDIA     3
#define NAV       4
#define SYSTEM    5
#define FUNCTIONS 6

// ─── Conditional layers (NAV+SYMBOLS→MEDIA, NUMBERS+FUNCTIONS→SYSTEM) ──────
// Paste inside / { } after behaviors {}
#define KM_COND_LAYERS \
    conditional_layers { \
        compatible = "zmk,conditional-layers"; \
        tri_media { \
            if-layers = <NAV SYMBOLS>; \
            then-layer = <MEDIA>; \
        }; \
        tri_system { \
            if-layers = <NUMBERS FUNCTIONS>; \
            then-layer = <SYSTEM>; \
        }; \
    };

// ─── Thumb clusters ─────────────────────────────────────────────────────────
// 4 middle thumbs — shared by all keyboards
#define KM_MID_T \
    &lt NUMBERS TAB  &lt NAV SPACE \
    &lt FUNCTIONS RET  &lt SYMBOLS ESC

// 6-thumb cluster (Corne / Totem base layer)
#define KM_THUMBS \
    &lt MEDIA BSPC  KM_MID_T  &lt SYSTEM DEL

// ─── BASE ────────────────────────────────────────────────────────────────────
#define KM_BASE_R0 \
    &kp Q       &kp W       &kp E        &kp R        &kp T \
    &kp Y       &kp U       &kp I        &kp O        &kp P

#define KM_BASE_R1 \
    &hm LGUI A  &hm LALT S  &hm LCTRL D  &hm LSHFT F  &kp G \
    &kp H       &hm RSHFT J &hm RCTRL K  &hm RALT L   &hm RGUI SEMICOLON

#define KM_BASE_R2 \
    &kp Z       &kp X       &kp C        &kp V        &kp B \
    &kp N       &kp M       &kp COMMA    &kp PERIOD   &kp SLASH

// ─── NUMBERS ─────────────────────────────────────────────────────────────────
#define KM_NUMS_R0 \
    &kp N1       &kp N2       &kp N3       &kp N4       &kp N5 \
    &kp N6       &kp N7       &kp N8       &kp N9       &kp N0

#define KM_NUMS_R1 \
    &hm LGUI N6  &hm LALT N7  &hm LCTRL N8 &hm LSHFT N9 &kp N0 \
    &kp SEMICOLON &hm RSHFT LEFT &hm RCTRL DOWN &hm RALT UP &hm RGUI RIGHT

#define KM_NUMS_R2 \
    &none        &none        &none        &none        &none \
    &none        &none        &kp COMMA    &kp PERIOD   &kp SLASH

// Thumbs: BSPC direct (pos1) | mirror DEL (pos5 = SYMBOLS thumb position)
#define KM_NUMS_T \
    &kp BSPC  &none  &kp SPACE  &kp RET  &kp DEL  &none

// ─── SYMBOLS ─────────────────────────────────────────────────────────────────
#define KM_SYMS_R0 \
    &kp EXCL     &kp AT       &kp HASH     &kp DLLR     &kp PRCNT \
    &kp CARET    &kp AMPS     &kp ASTRK    &kp MINUS    &kp EQUAL

#define KM_SYMS_R1 \
    &hm LGUI TILDE &hm LALT GRAVE &hm LCTRL SQT &hm LSHFT DQT &trans \
    &kp MINUS   &hm RSHFT EQUAL &hm RCTRL LPAR &hm RALT RPAR &hm RGUI BSLH

#define KM_SYMS_R2 \
    &none        &none        &none        &kp UNDER    &kp PLUS \
    &kp UNDER    &kp PLUS     &kp LBKT     &kp RBKT     &kp SLASH

// Thumbs: mirror BSPC (pos2 = NUMBERS thumb position) | DEL direct (pos6)
#define KM_SYMS_T \
    &none  &kp BSPC  &kp SPACE  &kp RET  &none  &kp DEL

// ─── MEDIA ───────────────────────────────────────────────────────────────────
#define KM_MEDI_R0 \
    &trans       &kp C_VOL_DN &kp C_MUTE   &kp C_VOL_UP &trans \
    &trans       &kp C_PREV   &kp C_PP     &kp C_NEXT   &rgb_ug RGB_TOG

#define KM_MEDI_R1 \
    &trans       &kp C_PREV   &kp C_PP     &kp C_NEXT   &trans \
    &trans       &kp C_VOL_DN &kp C_MUTE   &kp C_VOL_UP &trans

#define KM_MEDI_R2 \
    &ext_power EP_OFF &ext_power EP_ON &bt BT_NXT &trans &trans \
    &soft_off    &sys_reset   &trans       &trans       &trans

#define KM_MEDI_T \
    &trans  &trans  &trans  &trans  &trans  &trans

// ─── NAV ─────────────────────────────────────────────────────────────────────
#define KM_NAV_R0 \
    &kp LEFT     &kp DOWN     &kp UP       &kp RIGHT    &trans \
    &trans       &kp HOME     &kp PG_DN    &kp PG_UP    &kp END

#define KM_NAV_R1 \
    &hm LGUI HOME &hm LALT PG_DN &hm LCTRL PG_UP &hm LSHFT END &trans \
    &trans       &hm RSHFT LEFT &hm RCTRL DOWN &hm RALT UP &hm RGUI RIGHT

#define KM_NAV_R2 \
    &trans       &trans       &trans       &trans       &trans \
    &trans       &trans       &trans       &trans       &trans

#define KM_NAV_T \
    &trans  &trans  &trans  &trans  &trans  &trans

// ─── SYSTEM ──────────────────────────────────────────────────────────────────
#define KM_SYS_R0 \
    &out OUT_BLE &bt BT_SEL 0 &bt BT_SEL 1 &bt BT_SEL 2 &bt BT_SEL 3 \
    &bt BT_CLR   &bt BT_SEL 4 &trans       &trans        &out OUT_USB

#define KM_SYS_R1 \
    &trans       &rgb_ug RGB_SPI &rgb_ug RGB_SAI &rgb_ug RGB_BRI &rgb_ug RGB_HUI \
    &rgb_ug RGB_EFF &rgb_ug RGB_TOG &ext_power EP_TOG &trans &studio_unlock

#define KM_SYS_R2 \
    &trans       &rgb_ug RGB_SPD &rgb_ug RGB_SAD &rgb_ug RGB_BRD &rgb_ug RGB_HUD \
    &rgb_ug RGB_EFR &ext_power EP_OFF &ext_power EP_ON &sys_reset &soft_off

#define KM_SYS_T \
    &trans  &trans  &trans  &trans  &trans  &trans

// ─── FUNCTIONS ───────────────────────────────────────────────────────────────
#define KM_FUNC_R0 \
    &kp F6       &kp F7       &kp F8       &kp F9       &kp F10 \
    &kp F1       &kp F2       &kp F3       &kp F4       &kp F5

#define KM_FUNC_R1 \
    &kp F1       &kp F2       &kp F3       &kp F4       &kp F5 \
    &kp F6       &kp F7       &kp F8       &kp F9       &kp F10

#define KM_FUNC_R2 \
    &trans       &trans       &trans       &kp DEL      &kp PSCRN \
    &trans       &trans       &trans       &sys_reset   &soft_off

#define KM_FUNC_T \
    &trans  &trans  &trans  &trans  &trans  &trans
