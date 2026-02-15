/*
 *@ 文件 ： corridor.hpp
 *@ 描述 ： 走廊场景大类的实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-6
 */
#pragma once
#include <SFML/Graphics.hpp>

class Corridor
{
public:
    sf::Texture background;
    sf::Texture door;
    sf::Texture door2;
    std::array<sf::Texture, 13> clock;
    sf::Texture notion_board;
    sf::Texture flower;
    sf::Texture flower2;
    sf::Texture cabinet;
    sf::Texture toiletman;
    sf::Texture toiletwoman;
    sf::Texture rule;
    sf::Texture exitdoor;
    sf::Sprite background_sprite;
    sf::Sprite door_left_sprite;
    sf::Sprite door_right_sprite;
    sf::Sprite clock_sprite;
    sf::Sprite notion_board_sprite;
    sf::Sprite flower_sprite;
    sf::Sprite flower_1_sprite;
    sf::Sprite flower2_sprite;
    sf::Sprite cabinet_sprite;
    sf::Sprite cabinet_1_sprite;
    sf::Sprite toiletman_sprite;
    sf::Sprite toiletwoman_sprite;
    sf::Sprite rule_sprite;
    sf::Sprite exitdoor_sprite;

public:
    std::array<sf::Texture, 13> loadClockTextures();

private:
public:
    Corridor() : background("game_main/picture/scene/corridor/background.png"),
                 door("game_main/picture/scene/corridor/door.png"),
                 door2("game_main/picture/scene/corridor/door2.png"),
                 clock(loadClockTextures()),
                 notion_board("game_main/picture/scene/corridor/notionboard.png"),
                 flower("game_main/picture/scene/corridor/flower.png"),
                 flower2("game_main/picture/scene/corridor/flower2.png"),
                 cabinet("game_main/picture/scene/corridor/cabinet.png"),
                 toiletman("game_main/picture/scene/corridor/toiletman.png"),
                 toiletwoman("game_main/picture/scene/corridor/toiletwoman.png"),
                 exitdoor("game_main/picture/scene/corridor/exitdoor.png"),
                 // SED:规则图片后续需要替换
                 rule("game_main/picture/scene/corridor/rule.png"),
                 background_sprite(background),
                 door_left_sprite(door),
                 door_right_sprite(door2),
                 clock_sprite(clock[1]),
                 notion_board_sprite(notion_board),
                 flower_sprite(flower),
                 flower_1_sprite(flower),
                 flower2_sprite(flower2),
                 cabinet_sprite(cabinet),
                 cabinet_1_sprite(cabinet),
                 toiletman_sprite(toiletman),
                 toiletwoman_sprite(toiletwoman),
                 rule_sprite(rule),
                 exitdoor_sprite(exitdoor)
    {
    }

private:
};
