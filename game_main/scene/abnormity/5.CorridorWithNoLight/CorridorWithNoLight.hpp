/*
 *@文件 ： CorridorBlackout.hpp
 *@描述 ： 走廊全黑异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class CorridorWithNoLight : public Abnormity
{
public:
private:
    sf::Texture blackout_texture;

public:
    using Abnormity::HandleEvent;
    CorridorWithNoLight(Scene *scene) : Abnormity(scene)
    {
        blackout_texture.loadFromFile("game_main/picture/wrong/5.png");
    }

    void corridor_set() override
    {
        Abnormity::corridor_set();
        p_s->c_corridor.background_sprite.setTexture(blackout_texture);
    }

private:
};