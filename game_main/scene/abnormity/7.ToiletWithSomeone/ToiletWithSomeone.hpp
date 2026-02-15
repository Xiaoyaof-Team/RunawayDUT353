/*
 *@文件 ： ToiletWithSomeone.hpp
 *@描述 ： 女厕有人异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class ToiletWithSomeone : public Abnormity
{
public:
private:
    sf::Texture background_texture;

public:
    using Abnormity::HandleEvent;
    ToiletWithSomeone(Scene *scene) : Abnormity(scene)
    {
        background_texture.loadFromFile("game_main/picture/wrong/7.png");
    }

    void toilet_set() override
    {
        Abnormity::toilet_background_set();
        p_s->c_toilet.background_sprite.setTexture(background_texture);
        toilet_door_set();
        toilet_wash_basin_set();
        toilet_mirror_set();
    }
};