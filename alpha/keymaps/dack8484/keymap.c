#include QMK_KEYBOARD_H
// alpha windows
#define BASE 0
#define CLOSE 1
#define FAR 2
#define FUNKY 3
#define CLS_SPC LT(CLOSE, KC_SPC)
#define FAR_F LT(FAR, KC_F)
#define FNK_D LT(FUNKY, KC_D)
#define SFT_Z LSFT_T(KC_Z)
#define SFT_M RSFT_T(KC_M)
#define CTL_X LCTL_T(KC_X)
#define CTL_N RCTL_T(KC_N)
#define WIN_C LWIN_T(KC_C)
#define WIN_B RWIN_T(KC_B)
#define ALT_V LALT_T(KC_V)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)
#define UNDO LCTL(KC_Z)
#define RUS_TGL LALT(KC_LSFT)
#define LOCK LWIN(KC_L)
#define vvv KC_TRNS

enum custom_keycodes {
	TYPEDON = SAFE_RANGE,
    BRACKETBRACKET,
    CURLYCURLY,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {
			case TYPEDON:
				SEND_STRING("<typed on an alpha>");
				return false;
            case BRACKETBRACKET:
                if (record->event.pressed) {
                    // when keycode QMKBEST is pressed
                    SEND_STRING("[]" SS_TAP(X_LEFT));
                } else {
                    // when keycode QMKBEST is released
                }
                break;
            case CURLYCURLY:
                if (record->event.pressed) {
                    // when keycode QMKBEST is pressed
                    SEND_STRING("{}" SS_TAP(X_LEFT));
                } else {
                    // when keycode QMKBEST is released
                }
		}
	}
	return true;
};

enum combos { JBACK_ENT, CORNERS_PWR, BN_COMM, NM_DOT, LBACK_QUOT };

const uint16_t PROGMEM jback_combo[] = {KC_J, KC_BSPC, COMBO_END};
const uint16_t PROGMEM corners_combo[] = {KC_Q, KC_P, SFT_Z, SFT_M, COMBO_END};
const uint16_t PROGMEM bn_combo[]   = {WIN_B, CTL_N, COMBO_END};
const uint16_t PROGMEM nm_combo[]   = {CTL_N, SFT_M, COMBO_END};
const uint16_t PROGMEM lback_combo[]= {KC_L, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {[JBACK_ENT] = COMBO(jback_combo, KC_ENT), [CORNERS_PWR] = COMBO(corners_combo, KC_PWR), [BN_COMM] = COMBO(bn_combo, KC_COMM), [NM_DOT] = COMBO(nm_combo, KC_DOT), [LBACK_QUOT] = COMBO(lback_combo, KC_QUOT)};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_A, KC_S, FNK_D, FAR_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_BSPC,
		    SFT_Z, CTL_X, WIN_C, ALT_V, CLS_SPC, WIN_B, CTL_N, SFT_M
    ),
	[CLOSE] = LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
		     KC_MINS, KC_UNDS, KC_EQL, KC_PLUS, vvv, KC_SCOLON, KC_COLON, KC_SLSH
    ),
	[FAR] = LAYOUT(
		KC_ESC, TYPEDON, KC_BSLS, RUS_TGL, _______, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_INS,
		KC_CAPS, KC_TAB, KC_PIPE, vvv,      LOCK, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,
		      UNDO, CUT, COPY, PASTE, KC_SPC, KC_QUOT, KC_DQT, KC_QUES
    ),
	[FUNKY] = LAYOUT(
		KC_VOLU, KC_LBRC,KC_RBRC,KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, _______,
		KC_VOLD, _______, vvv,   KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______,
		     RESET, _______, KC_MPLY, RGB_MOD, RGB_TOG, KC_GRAVE, KC_TILDE, _______
    )
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FAR_F:
            return TAPPING_TERM - 50;
        case CLS_SPC:
            return TAPPING_TERM - 50;
        case SFT_Z:
            return TAPPING_TERM - 80;
        case SFT_M:
            return TAPPING_TERM - 75;
        case FNK_D:
            return TAPPING_TERM - 40;
        default:
            return TAPPING_TERM;
    }
};

