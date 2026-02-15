/*
 *@ 文件 ： toilet.hpp
 *@ 描述 ： 厕所场景大类的实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-6
 */
#pragma once
#include <SFML/Graphics.hpp>

class Toilet
{
public:
    sf::Texture background;
    sf::Texture door;
    sf::Texture wash_basin;
    sf::Texture mirror;
    sf::Sprite background_sprite;
    sf::Sprite door_sprite;
    sf::Sprite wash_basin_sprite;
    sf::Sprite mirror_sprite;

private:
public:
    Toilet() : background("game_main/picture/scene/toilet/background.png"),
               door("game_main/picture/scene/toilet/door.png"),
               wash_basin("game_main/picture/scene/toilet/wash_basin.png"),
               mirror("game_main/picture/scene/toilet/mirror.png"),
               background_sprite(background),
               door_sprite(door),
               wash_basin_sprite(wash_basin),
               mirror_sprite(mirror)
    {
    }

private:
};