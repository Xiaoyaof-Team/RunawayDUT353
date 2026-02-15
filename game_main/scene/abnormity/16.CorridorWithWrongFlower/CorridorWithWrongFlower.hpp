/*
 *@文件 ： CorridorWithWrongFlower.hpp
 *@描述 ： 植物变矮异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class CorridorWithWrongFlower : public Abnormity
{
private:
    sf::Texture flora_texture;
    sf::Sprite flora_sprite;
    sf::Sprite flora_1_sprite;

public:
    using Abnormity::HandleEvent;

    CorridorWithWrongFlower(Scene *scene)
        : Abnormity(scene),
          flora_texture("game_main/picture/wrong/16.png"),
          flora_sprite(flora_texture),
          flora_1_sprite(flora_texture)
    {
    }

    void corridor_set() override
    {
        Abnormity::corridor_set();

        flora_sprite.setPosition(p_s->c_corridor.flower_sprite.getPosition());
        flora_sprite.setScale(p_s->c_corridor.flower_sprite.getScale());
        flora_sprite.setOrigin(p_s->c_corridor.flower_sprite.getOrigin());

        flora_1_sprite.setPosition(p_s->c_corridor.flower_1_sprite.getPosition());
        flora_1_sprite.setScale(p_s->c_corridor.flower_1_sprite.getScale());
        flora_1_sprite.setOrigin(p_s->c_corridor.flower_1_sprite.getOrigin());
    }

    void corridor_draw(sf::RenderWindow &window) override
    {

        window.draw(p_s->c_corridor.background_sprite);
        window.draw(p_s->c_corridor.door_left_sprite);
        window.draw(p_s->c_corridor.door_right_sprite);
        window.draw(p_s->c_corridor.cabinet_sprite);
        window.draw(p_s->c_corridor.cabinet_1_sprite);

        window.draw(flora_sprite);
        window.draw(flora_1_sprite);

        window.draw(p_s->c_corridor.flower2_sprite);
        window.draw(p_s->c_corridor.notion_board_sprite);
        window.draw(p_s->c_corridor.clock_sprite);
        window.draw(p_s->clock_text);
    }
};