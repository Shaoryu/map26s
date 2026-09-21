#pragma once
#include "convinient.h"

enum target_num{
    desk1, // 手前（上側）の机
    desk2, // 奥（下側）の机
    flag, // 自陣の旗
    bucket1, // 自陣真ん中バケツ①
    bucket2, // 自陣スタート側バケツ②（木台H600）
    bucket3, // 自陣奥側バケツ③（木台H300）
    chair,  // 赤ゾーン中央左の椅子
    replenish, // 補充スポット
    controll // コントロールステーション
};

enum sdm_num{
    sdm1,
    sdm2,
    sdm3,
    sdm_Y
};

enum STATE_ZONE{
    RED_ZONE,
    BLUE_ZONE
};

// オフセット・初期値
static constexpr Position startzone_offset={0.f, 0.f};          // 開始時robot_posへの補正 [m]
static constexpr Position encoder_offset={0.0f, 0.343f, 0.0f, 0.0f}; // robot_posからエンコーダ中心の補正 [m]
//robot_pos(旋回中心)から見たsdmの補正[m]
// SDMのオフセット [m] (mm表記から修正)
static constexpr Position sdm_offset[]={
    {}, // sdm1
    { 0.3f, -0.5f, 0.03f, -M_PI/2.f}, // sdm2
    {-0.3f, -0.5f, 0.03f, -M_PI/2.f}, // sdm3
    { 0.0f, -0.5f, 0.03f, -M_PI/2.f}  // Y軸測定用sdmの中心
};

// ==========================================
// 相対座標系オブジェクト定義 (スタート位置中心)
// corner は常に (Xの最小値, Yの最小値)
// ==========================================

namespace RedZone { // Y正 = フィールド外側(下)
    constexpr ObjectPos desk1_m={{ -1.80f,  2.10f, 0.0f, 0.0f}, 0.71f, 0.51f};
    constexpr ObjectPos desk2_m={{ -1.80f,  7.99f, 0.0f, 0.0f}, 0.71f, 0.51f};
    constexpr ObjectPos flag_m={{   0.00f,  5.00f, 0.0f, 0.0f}, 0.60f, 0.60f};
    constexpr ObjectPos bucket1_m={{1.10f,  5.13f, 0.0f, 0.0f}, 0.34f, 0.34f};
    constexpr ObjectPos bucket2_m={{0.50f,  3.12f, 0.6f, 0.0f}, 0.36f, 0.36f};
    constexpr ObjectPos bucket3_m={{1.20f,  7.82f, 0.3f, 0.0f}, 0.36f, 0.36f};
    constexpr ObjectPos chair_m={{ -3.71f,  6.07f, 0.0f, 0.0f}, 0.46f, 0.42f};
    constexpr ObjectPos replenish_m={{-1.15f, -0.50f, 0.0f, 0.0f}, 0.65f, 0.45f};
    constexpr ObjectPos controll_m={{ -0.50f, -0.50f, 0.0f, 0.0f}, 2.10f, 1.00f};

    static const ObjectPos* const valid_obstacles[] = { &bucket2_m, &bucket3_m };
    static const ObjectPos* const invalid_obstacles[] = { &desk1_m, &desk2_m, &flag_m, &bucket1_m, &chair_m, &replenish_m, &controll_m };
}

namespace BlueZone { // Y正 = フィールド内側(上) ※Y座標の範囲が赤ゾーンと反転
    constexpr ObjectPos desk1_m={{ -1.80f, -2.61f, 0.0f, 0.0f}, 0.71f, 0.51f};
    constexpr ObjectPos desk2_m={{ -1.80f, -8.50f, 0.0f, 0.0f}, 0.71f, 0.51f};
    constexpr ObjectPos flag_m={{   0.00f, -5.60f, 0.0f, 0.0f}, 0.60f, 0.60f};
    constexpr ObjectPos bucket1_m={{1.10f, -5.47f, 0.0f, 0.0f}, 0.34f, 0.34f};
    constexpr ObjectPos bucket2_m={{0.50f, -3.48f, 0.6f, 0.0f}, 0.36f, 0.36f};
    constexpr ObjectPos bucket3_m={{1.20f, -8.18f, 0.3f, 0.0f}, 0.36f, 0.36f};
    constexpr ObjectPos chair_m={{ -3.71f, -6.49f, 0.0f, 0.0f}, 0.46f, 0.42f};
    constexpr ObjectPos replenish_m={{-1.15f,  0.05f, 0.0f, 0.0f}, 0.65f, 0.45f};
    constexpr ObjectPos controll_m={{ -0.50f, -0.50f, 0.0f, 0.0f}, 2.10f, 1.00f};

    static const ObjectPos* const valid_obstacles[] = { &bucket2_m, &bucket3_m };
    static const ObjectPos* const invalid_obstacles[] = { &desk1_m, &desk2_m, &flag_m, &bucket1_m, &chair_m, &replenish_m, &controll_m };
}