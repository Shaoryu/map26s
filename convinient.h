#pragma once
#ifndef M_PI
#define M_PI 3.14159f
#endif

#ifndef G_DEFINED
#define G_DEFINED

constexpr float g = 9.80665f;

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

struct Position{
    float pos_x = 0.0f; 
    float pos_y = 0.0f;
    float pos_z = 0.0f;
    float angle = 0.0f;
};

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
static void vec_sum(Position* pos,const Position add){
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
