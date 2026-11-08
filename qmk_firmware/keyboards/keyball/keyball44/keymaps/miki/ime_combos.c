#include "ime_combos.h"

// 日本語入力
const uint16_t PROGMEM kana_combo[] = {
    KC_S,
    KC_D,
    COMBO_END
};

// 英字入力
const uint16_t PROGMEM eisu_combo[] = {
    KC_K,
    KC_L,
    COMBO_END
};

// コンボの登録
combo_t key_combos[2] = {
    COMBO(kana_combo, KC_LNG1),
    COMBO(eisu_combo, KC_LNG2),
};