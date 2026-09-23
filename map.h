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
    {-0.4f, -0.495f, 0.02f, -M_PI/2.f}, // sdm1
    { 0.4f, -0.495f, 0.02f, -M_PI/2.f}, // sdm2
    {}, // sdm3
    { 0.0f, -0.495f, 0.02f, -M_PI/2.f}  // Y軸測定用sdmの中心
};

// ==========================================
// 相対座標系オブジェクト定義 (スタート位置中心)
// corner は常に (Xの最小値, Yの最小値)
// w=x方向サイズ, d=y方向サイズ
// Y正 = フィールド外側
// ==========================================

namespace RedZone {
    // X原点 = スタートゾーン中心、 X正 = 中央方向(下)
    // Y原点 = スタートゾーン中心、 Y正 = 外側方向(左)
    
    constexpr ObjectPos desk1_m={{ 2.100f,  2.880f, 0.0f, 0.0f}, 0.71f, 0.51f};
    constexpr ObjectPos desk2_m={{ 7.790f,  2.880f, 0.0f, 0.0f}, 0.71f, 0.51f};
    constexpr ObjectPos flag_m={{  5.300f, -0.640f, 0.0f, 0.0f}, 0.60f, 0.60f};
    constexpr ObjectPos bucket1_m={{ 5.430f, -1.400f, 0.0f, 0.0f}, 0.34f, 0.34f};
    constexpr ObjectPos bucket2_m={{ 3.120f, -0.800f, 0.6f, 0.0f}, 0.36f, 0.36f};
    constexpr ObjectPos bucket3_m={{ 7.820f, -1.500f, 0.3f, 0.0f}, 0.36f, 0.36f};
    constexpr ObjectPos chair_m={{ 4.310f,  2.490f, 0.0f, 0.0f}, 0.42f, 0.46f};
    constexpr ObjectPos replenish_m={{-0.325f, -0.800f, 0.0f, 0.0f}, 0.65f, 0.45f};
    constexpr ObjectPos controll_m={{-0.500f,  1.500f, 0.0f, 0.0f}, 2.60f, 1.00f};
    constexpr ObjectPos kyodan_m={{ -0.500f, -2.100f, 0.2f, 0.0f}, 10.50f, 0.60f};

    // ノートブックの議論に基づき、教壇を「信頼できる壁」として有効リストに追加[cite: 24]
    static const ObjectPos* const valid_obstacles[] = { &bucket2_m, &bucket3_m, &kyodan_m };
    static const ObjectPos* const invalid_obstacles[] = { &desk1_m, &desk2_m, &flag_m, &bucket1_m, &chair_m, &replenish_m, &controll_m };
}

namespace BlueZone {
// X原点 = スタートゾーン中心、 X正 = 外壁方向(上)
    // Y原点 = スタートゾーン中心、 Y正 = 外側方向(右)
    
    constexpr ObjectPos desk1_m={{ -2.810f,  2.880f, 0.0f, 0.0f}, 0.71f, 0.51f};
    constexpr ObjectPos desk2_m={{ -8.500f,  2.880f, 0.0f, 0.0f}, 0.71f, 0.51f};
    constexpr ObjectPos flag_m={{ -5.900f, -0.040f, 0.0f, 0.0f}, 0.60f, 0.60f};
    constexpr ObjectPos bucket1_m={{ -5.770f, -1.400f, 0.0f, 0.0f}, 0.34f, 0.34f};
    constexpr ObjectPos bucket2_m={{ -3.480f, -0.800f, 0.6f, 0.0f}, 0.36f, 0.36f};
    constexpr ObjectPos bucket3_m={{ -8.180f, -1.500f, 0.3f, 0.0f}, 0.36f, 0.36f};
    constexpr ObjectPos chair_m={{ -4.730f,  2.490f, 0.0f, 0.0f}, 0.42f, 0.46f};
    constexpr ObjectPos replenish_m={{-0.325f, -0.800f, 0.0f, 0.0f}, 0.65f, 0.45f};
    constexpr ObjectPos controll_m={{ -2.100f,  1.500f, 0.0f, 0.0f}, 2.60f, 1.00f};
    constexpr ObjectPos kyodan_m={{-10.000f, -2.100f, 0.2f, 0.0f}, 10.50f, 0.60f};

    static const ObjectPos* const valid_obstacles[] = { &bucket2_m, &bucket3_m, &kyodan_m };
    static const ObjectPos* const invalid_obstacles[] = { &desk1_m, &desk2_m, &flag_m, &bucket1_m, &chair_m, &replenish_m, &controll_m };
}