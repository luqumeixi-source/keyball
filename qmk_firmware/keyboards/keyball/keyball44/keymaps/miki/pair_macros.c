
#include "quantum.h"
#include "pair_macros.h"

enum custom_keycodes {
    PAIR_PAREN = QK_KB_16,
    PAIR_BRACKET,
    PAIR_BRACE,
    WRAP_MODE,
};

static bool wrap_mode = false;

// 選択文字を括弧で囲む
static void wrap_selection(const char *pair) {
    tap_code16(C(KC_C));
    wait_ms(100);

    send_char(pair[0]);

    tap_code16(C(KC_V));
    wait_ms(100);

    send_char(pair[1]);
}

// 括弧マクロの処理
bool process_pair_macro(uint16_t keycode, bool pressed) {

    if (keycode == WRAP_MODE) {
        if (pressed) {
            wrap_mode = !wrap_mode;
        }
        return false;
    }

    const char *pair;

    switch (keycode) {
        case PAIR_PAREN:
            pair = "()";
            break;

        case PAIR_BRACKET:
            pair = "[]";
            break;

        case PAIR_BRACE:
            pair = "{}";
            break;

        default:
            return true;
    }

    if (pressed) {
        if (wrap_mode) {
            wrap_selection(pair);
        } else {
            send_string(pair);
            tap_code(KC_LEFT);
        }
    }

    return false;
}