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
static constexpr Position startzone_offset={0.5f, 1.8f};          // 開始時robot_posへの補正 [m]
static constexpr Position encoder_offset={0.0f, 0.343f, 0.0f, 0.0f}; // robot_posからエンコーダ中心の補正 [m]
static constexpr Position sdm_offset[]={//robot_pos(旋回中心)から見たsdmの補正[m]
                                            {},//sdm1
                                            { 300.f,-500.f,30.f,-M_PI/2.f},//sdm2
                                            {-300.f,-500.f,30.f,-M_PI/2.f},//sdm3
                                            {   0.f,-500.f,30.f,-M_PI/2.f}//Y軸測定用sdmの中心
                                        };

// 的の座標（敵陣・青ゾーン側のため y はマイナス） [m]
static constexpr target desk1_t={2.6f, 2.955f, -3.6f};             // 手前の方（机）
static constexpr target desk2_t={8.29f, 8.645f, -3.6f};            // 奥の方（机）
static constexpr target flag_t={5.8f, 6.1f, -2.95f};               // 旗
static constexpr target bucket1_t={5.93f, 6.1f, -0.57f};           // 敵陣真ん中（固定バケツ①）
static constexpr target bucket2_t={3.62f, 3.8f, -1.18f};           // 敵陣スタートゾーン側（固定バケツ②）
static constexpr target bucket3_t={8.32f, 8.5f, -0.48f};           // 敵陣奥側（固定バケツ③）

// オブジェクトの配置座標（自陣・赤ゾーン側。cornerは右上角、w=xサイズ、d=yサイズ） [m]
static constexpr ObjectPos desk1_m={{2.6f, 5.19f, 0.0f, 0.0f}, 0.71f, 0.51f};      // 手前（上側）の机
static constexpr ObjectPos desk2_m={{8.29f, 5.19f, 0.0f, 0.0f}, 0.71f, 0.51f};     // 奥（下側）の机
static constexpr ObjectPos flag_m={{5.8f, 1.56f, 0.0f, 0.0f}, 0.6f, 0.6f};         // 自陣の旗
static constexpr ObjectPos bucket1_m={{5.93f, 0.4f, 0.0f, 0.0f}, 0.34f, 0.34f};    // 自陣真ん中バケツ①
static constexpr ObjectPos bucket2_m={{3.62f, 1.0f, 0.0f, 0.0f}, 0.36f, 0.36f};    // 自陣スタート側バケツ②
static constexpr ObjectPos bucket3_m={{8.32f, 0.3f, 0.0f, 0.0f}, 0.36f, 0.36f};    // 自陣奥側バケツ③
static constexpr ObjectPos chair_m={{4.81f, 4.75f, 0.0f, 0.0f}, 0.42f, 0.46f};      // 赤ゾーン中央左の椅子
static constexpr ObjectPos replenish_m={{-1.0f, 1.475f, 0.0f, 0.0f}, 0.45f, 0.65f}; // 補充スポット
static constexpr ObjectPos controll_m={{-1.0f, 3.3f, 0.0f, 0.0f}, 1.0f, 2.4f};     // コントロールステーション

static const ObjectPos* obstacles[] = {
    &desk1_m, &desk2_m, &flag_m,
    &bucket1_m, &bucket2_m, &bucket3_m, 
    &chair_m, &replenish_m, &controll_m
};