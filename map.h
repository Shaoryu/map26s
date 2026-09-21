#pragma once
#include "convinient.h"

enum target_num{
    desk1,
    desk2,
    flag,
    bucket1,
    bucket2,
    bucket3,
    chair,
    replenish,
    controll
};

enum sdm_num{
    sdm1,
    sdm2,
    sdm3,
    sdm_Y
};

// オフセット・初期値
static constexpr Position startzone_offset={0.f, 0.f};          // 開始時robot_posへの補正 [m]
static constexpr Position encoder_offset={0.0f, 0.343f, 0.0f, 0.0f}; // robot_posからエンコーダ中心の補正 [m]
static constexpr Position sdm_offset[]={//robot_pos(旋回中心)から見たsdmの補正[m]
                                            {},//sdm1
                                            { 300.f,-500.f,30.f,-M_PI/2.f},//sdm2
                                            {-300.f,-500.f,30.f,-M_PI/2.f},//sdm3
                                            {   0.f,-500.f,30.f,-M_PI/2.f}//Y軸測定用sdmの中心
                                        };

// 的の座標（敵陣・青ゾーン側） [m]
constexpr target desk1_t={2.1f, 2.455f, -5.4f};             // 手前の方（机）
constexpr target desk2_t={7.79f, 8.145f, -5.4f};            // 奥の方（机）
constexpr target flag_t={5.3f, 5.6f, -4.75f};               // 旗
constexpr target bucket1_t={5.43f, 5.6f, -2.37f};           // 敵陣真ん中（固定バケツ①）
constexpr target bucket2_t={3.12f, 3.3f, -2.98f};           // 敵陣スタートゾーン側（固定バケツ②）
constexpr target bucket3_t={7.82f, 8.0f, -2.28f};           // 敵陣奥側（固定バケツ③）

// オブジェクトの配置座標（自陣・赤ゾーン側。cornerは右上角、w=x方向サイズ, d=y方向サイズ） [m]
constexpr ObjectPos desk1_m={{2.1f, 3.39f, 0.0f, 0.0f}, 0.71f, 0.51f};       // 手前（上側）の机
constexpr ObjectPos desk2_m={{7.79f, 3.39f, 0.0f, 0.0f}, 0.71f, 0.51f};      // 奥（下側）の机
constexpr ObjectPos flag_m={{5.3f, -0.04f, 0.0f, 0.0f}, 0.6f, 0.6f};         // 自陣の旗
constexpr ObjectPos bucket1_m={{5.43f, -1.4f, 0.0f, 0.0f}, 0.34f, 0.34f};    // 自陣真ん中バケツ①
constexpr ObjectPos bucket2_m={{3.12f, -0.8f, 0.6f, 0.0f}, 0.36f, 0.36f};    // 自陣スタート側バケツ②（木台H600）
constexpr ObjectPos bucket3_m={{7.82f, -1.5f, 0.3f, 0.0f}, 0.36f, 0.36f};    // 自陣奥側バケツ③（木台H300）
constexpr ObjectPos chair_m={{4.31f, 2.95f, 0.0f, 0.0f}, 0.42f, 0.46f};      // 赤ゾーン中央左の椅子
constexpr ObjectPos replenish_m={{-0.325f, -0.8f, 0.0f, 0.0f}, 0.65f, 0.45f};// 補充スポット
constexpr ObjectPos controll_m={{-0.5f, 1.5f, 0.0f, 0.0f}, 2.6f, 1.0f};      // コントロールステーション
constexpr ObjectPos kyodan_m={{-0.5f, -2.1f, 0.2f, 0.0f}, 10.5f, 0.6f};      // 教壇（共有ゾーン・高さH200）

static const ObjectPos* obstacles[] = {
    &desk1_m, &desk2_m, &flag_m,
    &bucket1_m, &bucket2_m, &bucket3_m, 
    &chair_m, &replenish_m, &controll_m
};