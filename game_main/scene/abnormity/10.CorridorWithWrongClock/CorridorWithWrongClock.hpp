/*
 *@文件 ： CorridorWithWrongClock.hpp
 *@描述 ： 走廊时钟消失异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class CorridorWithWrongClock : public Abnormity
{
public:
    using Abnormity::HandleEvent;
    CorridorWithWrongClock(Scene *scene) : Abnormity(scene) {}

    void corridor_set() override
    {
        Abnormity::corridor_set();
        p_s->c_corridor.clock_sprite.setColor(sf::Color::Transparent);
    }

    virtual ~CorridorWithWrongClock()
    {
        p_s->c_corridor.clock_sprite.setColor(sf::Color::White);
    }
};