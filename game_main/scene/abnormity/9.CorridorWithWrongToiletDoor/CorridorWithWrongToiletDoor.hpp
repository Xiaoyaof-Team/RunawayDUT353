/*
 *@描述 ： 厕所门互换异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class CorridorWithWrongToiletDoor : public Abnormity
{
public:
    using Abnormity::HandleEvent;
    CorridorWithWrongToiletDoor(Scene *scene) : Abnormity(scene)
    {
        p_s->c_corridor.toiletman_sprite.setTexture(p_s->c_corridor.toiletwoman);
        p_s->c_corridor.toiletwoman_sprite.setTexture(p_s->c_corridor.toiletman);
    }
    void corridor_draw(sf::RenderWindow &window) override
    {
        Abnormity::corridor_draw(window);
    }
};