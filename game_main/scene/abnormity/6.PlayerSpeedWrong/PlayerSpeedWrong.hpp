/*
 *@文件 ： PlayerSpeedWrong.hpp
 *@描述 ： 角色速度异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class PlayerSpeedWrong : public Abnormity
{
public:
    using Abnormity::HandleEvent;

    PlayerSpeedWrong(Scene *scene) : Abnormity(scene)
    {
        p_s->c_player.speed = 2500.0f;
    }

    // 离开关卡时还原速度
    virtual ~PlayerSpeedWrong()
    {
        p_s->c_player.speed = 800.0f;
    }
};