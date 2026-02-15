/*
 *@文件 ： ToiletWithWrongWashbin.hpp
 *@描述 ： 厕所水池异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class ToiletWithWrongWashbin : public Abnormity
{
private:
    sf::Texture Washbin_texture;
    sf::Sprite Washbin_sprite;

public:
    using Abnormity::HandleEvent;

    ToiletWithWrongWashbin(Scene *scene)
        : Abnormity(scene),
          Washbin_texture("game_main/picture/wrong/17.png"),
          Washbin_sprite(Washbin_texture)
    {
    }

    void toilet_wash_basin_set() override
    {
        p_s->toilet_wash_basin_set();

        Washbin_sprite.setPosition(p_s->c_toilet.wash_basin_sprite.getPosition());
        Washbin_sprite.setScale(p_s->c_toilet.wash_basin_sprite.getScale());
        Washbin_sprite.setOrigin(p_s->c_toilet.wash_basin_sprite.getOrigin());
    }

    void toilet_draw(sf::RenderWindow &window) override
    {

        window.draw(p_s->c_toilet.background_sprite);
        window.draw(p_s->c_toilet.door_sprite);
        window.draw(p_s->c_toilet.mirror_sprite);

        window.draw(Washbin_sprite);

        window.draw(p_s->mirror_text);
    }
};