/*
 *@文件 ： CorridorWithWrongBackground.hpp
 *@描述 ： 背景错误异常：helpme
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class CorridorWithWrongBackground : public Abnormity
{
private:
    sf::Texture background_texture;
    sf::Sprite background_sprite;

public:
    using Abnormity::HandleEvent;

    CorridorWithWrongBackground(Scene *scene)
        : Abnormity(scene),
          background_texture("game_main/picture/wrong/19.png"),
          background_sprite(background_texture)
    {
    }

    void corridor_set() override
    {
        Abnormity::corridor_set();
        p_s->currentSceneBackground = &background_sprite;
        background_sprite.setPosition({0.f, 0.f});
        background_sprite.setScale({0.8f, 0.8f});
    }

    void corridor_draw(sf::RenderWindow &window) override
    {
        window.draw(background_sprite);

        window.draw(p_s->c_corridor.cabinet_sprite);
        window.draw(p_s->c_corridor.cabinet_1_sprite);
        window.draw(p_s->c_corridor.flower_sprite);
        window.draw(p_s->c_corridor.flower_1_sprite);
        window.draw(p_s->c_corridor.flower2_sprite);
        window.draw(p_s->c_corridor.notion_board_sprite);
        window.draw(p_s->c_corridor.clock_sprite);
        window.draw(p_s->clock_text);
    }

    void corridor_doorleft_set() override
    {
    }
};