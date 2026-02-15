/*
 *@文件 ： ClassroomwithManything.hpp
 *@描述 ： 教室物品变多异常
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-6
 */
#pragma once
#include "abnormity.hpp"

class ClassroomWithManything : public Abnormity
{
public:
private:
    sf::Texture background_texture;
    sf::Sprite background_sprite;

public:
    using Abnormity::HandleEvent;
    ClassroomWithManything(Scene *scene) : Abnormity(scene),
                                           background_texture("game_main/picture/wrong/1.png"),
                                           background_sprite(background_texture)
    {
    }

    // 重写教室背景刷新函数
    void classroom_set() override
    {
        p_s->currentSceneBackground = &background_sprite;
        background_sprite.setTexture(background_texture);
        background_sprite.setPosition({0.f, 0.f});
        background_sprite.setScale({1.27f, 1.27f});
        p_s->c_classroom.desk_sprite.setPosition({430.f, 960.f});
        p_s->c_classroom.desk_sprite.setScale({1.3f, 1.3f});
    }
    void classroom_draw(sf::RenderWindow &window) override
    {
        window.draw(background_sprite);
    }

private:
};