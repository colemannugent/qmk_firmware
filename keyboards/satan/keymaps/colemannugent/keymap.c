#include "satan.h" 

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

//TODO: Maybe replace this with something easier to see in the diagrams
#define _______ KC_TRNS

//See https://gist.github.com/ddeklerk/b5ffec98db2c90c46b95073db68f779f#file-keymap-c-L40
#define MACRO_BREATH_TOGGLE	21
#define M_BRTOG			M(MACRO_BREATH_TOGGLE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BL] = KEYMAP_ANSI(
KC_ESC, 	KC_1,    	KC_2,   	KC_3,  	KC_4,   	KC_5,   	KC_6,   	KC_7,    	KC_8,   	KC_9,  	KC_0,   	KC_MINS,	KC_EQL, 	KC_BSPC, \
KC_TAB, 	KC_Q,    	KC_W,   	KC_E,  	KC_R,   	KC_T,   	KC_Y,   	KC_U,    	KC_I,   	KC_O,  	KC_P,   	KC_LBRC,	KC_RBRC,	KC_BSLS, \
LT(_FL, KC_CAPS),		KC_A,   	KC_S,  	KC_D,   	KC_F,   	KC_G,   	KC_H,    	KC_J,   	KC_K,  	KC_L,   	KC_SCLN,	KC_QUOT,	KC_ENT, \
KC_LSPO,	KC_Z,    	KC_X,   	KC_C,  	KC_V,   	KC_B,   	KC_N,   	KC_M,    	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RSPC, \
KC_LCTL,	KC_LGUI, 	KC_LALT,				KC_SPC,					KC_RALT,	KC_RGUI,	MO(_FL),	KC_RCTL),

[_FL] = KEYMAP_ANSI(
KC_GRV, 	KC_F1,  	KC_F2,  	KC_F3,  	KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,   	KC_F8,  	KC_F9,   	KC_F10,   	KC_F11, 	KC_F12, 	KC_DEL, \
_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______, 	_______, 	M_BRTOG, 	KC_INSERT,	BL_DEC, 	BL_INC, 	BL_TOGG, \
_______,	KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,		_______,	KC_LEFT,	KC_DOWN, 	KC_UP,  	KC_RIGHT,	_______,  	_______,	_______, \
_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______, 	_______,	_______, 	_______,  	_______, \
_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch(id) {
		case MACRO_BREATH_TOGGLE:
			if (record->event.pressed)
			{
				breathing_toggle();
			}
			break;
	}
	return MACRO_NONE;
}
