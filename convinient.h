#pragma once
#include "mbed.h"
#ifndef M_PI
#define M_PI 3.14159f
#endif

#ifndef G_DEFINED
#define G_DEFINED

constexpr float g = 9.80665f;

#endif

#ifndef EPSILON
#define EPSILON 1e-6f
#endif

//MLRCSより。
#ifndef STRUCT_POSE_DEFINED
#define STRUCT_POSE_DEFINED

struct Pose{
    float x;
    float y;
    float theta;
};
#endif

#ifndef STRUCT_POSISION_DEFINED
#define STRUCT_POSISION_DEFINED
struct Position{
    float pos_x = 0.0f; 
    float pos_y = 0.0f;
    float pos_z = 0.0f;
    float angle = 0.0f;
};
#endif

struct ObjectPos{
    Position corner={};
    float w=0.f;//x
    float d=0.f;//y
};

struct target{//的の座標。法線のやつを使いたいので若干上と構造が違う
    float x_lower=0.f;
    float x_center=0.f;
    float y=0.f;
    float z=0.f;
};

#ifndef VEC_SUM_DEFINED
#define VEC_SUM_DEFINED
inline void vec_sum(Position* pos,const Position add){
    pos->pos_x+=add.pos_x;
    pos->pos_y+=add.pos_y;
    pos->pos_z+=add.pos_z;
    pos->angle+=add.angle;
    return;
}
static Position vec_sum(const Position pos,const Position add){
    Position ans={pos.pos_x+add.pos_x,pos.pos_y+add.pos_y,pos.pos_z+add.pos_z,pos.angle+add.angle};
    return ans;
}
#endif


static float normalizeAngle(float angle) {
    while (angle > M_PI)  angle -= 2.0f * M_PI;
    while (angle < -M_PI) angle += 2.0f * M_PI;
    return angle;
}

template<typename T1,typename T2,typename T3>//doubleを一応対応させるため。贅沢？
static Position rotate(T1 &x,T2 &y,T3 &angle_rad){
    float cos_t = std::cos(angle_rad);
    float sin_t = std::sin(angle_rad);
    return Position{(float)(x * cos_t - y * sin_t),
                    (float)(x * sin_t + y * cos_t),
                    0.f,
                    (float)angle_rad};
}

static Position rotate(Position P){
    float cos_t = std::cos(P.angle);
    float sin_t = std::sin(P.angle);
    return Position{P.pos_x * cos_t - P.pos_y * sin_t,
                    P.pos_x * sin_t + P.pos_y * cos_t,
                    0.f,
                    P.angle};
}

static Position rotate(Pose P){
    float cos_t = std::cos(P.theta);
    float sin_t = std::sin(P.theta);
    return Position{P.x * cos_t - P.y * sin_t,
                    P.x * sin_t + P.x * cos_t,
                    0.f,
                    P.theta};
}

static Pose rotate(Position P,bool t){
    float cos_t = std::cos(P.angle);
    float sin_t = std::sin(P.angle);
    return Pose{P.pos_x * cos_t - P.pos_y * sin_t,
                P.pos_x * sin_t + P.pos_y * cos_t,
                P.angle};
}

static Pose Posi2Pos(const Position P){
    return Pose{P.pos_x,P.pos_y,P.angle};
}

enum{
    revCANmo,
    updCANod,
    updAUTOaim,
    ALL_VAL
};

enum ControlMode{
    Manual,
    SemiAutomatic,
    Automatic
};


inline float rpm2degps(float rpm){return rpm*6.f;};
#ifndef DEGRAD_DEFINED
#define DEGRAD_DEFINED
inline float deg2rad(float deg){return deg*2*M_PI/360.f;};
inline float rad2deg(float rad){return rad*360.f/2/M_PI;};

#endif