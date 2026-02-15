/*
 *@文件 ： CorridorWithWrongBoard.hpp
 *@描述 ： 走廊告示牌显示图片错误异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-14
 */
#pragma once
#include "abnormity.hpp"

class CorridorWithWrongBoard : public Abnormity
{
public:
private:
    sf::Texture rule_texture;
    sf::Sprite rule_sprite;

public:
    using Abnormity::HandleEvent;
    CorridorWithWrongBoard(Scene *scene) : Abnormity(scene),
                                           rule_texture("game_main/picture/wrong/3.png"),
                                           rule_sprite(rule_texture)
    {
    }

    void rule_draw_2(sf::RenderWindow &c_window) override
    {
        c_window.draw(rule_sprite);
    }

private:
};