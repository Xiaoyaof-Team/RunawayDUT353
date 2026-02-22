/*
 *@文件 ： ToiletWithWrongGlass.hpp
 *@描述 ： 厕所镜子显示替换异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class ToiletWithWrongGlass : public Abnormity
{
public:
private:
    sf::Texture mirror_texture;

public:
    using Abnormity::HandleEvent;
    ToiletWithWrongGlass(Scene *scene) : Abnormity(scene)
    {
        mirror_texture.loadFromFile("game_main/picture/wrong/4.png");
    }

    ~ToiletWithWrongGlass()
    {
        p_s->c_toilet.mirror_sprite.setTexture(p_s->c_toilet.mirror);
    }

    void mirror_set() override
    {
        Abnormity::mirror_set();

        p_s->c_toilet.mirror_sprite.setTexture(mirror_texture);
    }

private:
};