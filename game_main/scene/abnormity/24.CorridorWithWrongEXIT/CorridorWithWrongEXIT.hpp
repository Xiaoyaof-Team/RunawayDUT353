/*
 *@文件 ： CorridorWithWrongEXIT.hpp
 *@描述 ： 额外EXIT异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class CorridorWithWrongEXIT : public Abnormity
{
public:
    using Abnormity::HandleEvent;

    CorridorWithWrongEXIT(Scene *scene) : Abnormity(scene) {}

    void corridor_set() override
    {
        // EXIT原先是自己写的，最快的一集
        p_s->c_corridor.exitdoor_sprite.setOrigin(p_s->c_corridor.exitdoor_sprite.getLocalBounds().size / 2.f);
        p_s->c_corridor.exitdoor_sprite.setPosition({5005.51, 449.794});
        p_s->c_corridor.exitdoor_sprite.setScale({0.8f, 0.8f});
    }
};