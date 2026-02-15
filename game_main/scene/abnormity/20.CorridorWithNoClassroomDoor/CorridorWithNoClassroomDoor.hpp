/*
 *@文件 ： CorridorWithNoClassroomDoor.hpp
 *@描述 ： 走廊无教室门异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class CorridorWithNoClassroomDoor : public Abnormity
{
public:
private:
    sf::Texture background_texture;
    sf::Sprite background_sprite;

public:
    using Abnormity::HandleEvent;

    CorridorWithNoClassroomDoor(Scene *scene) : Abnormity(scene),
                                                background_texture("game_main/picture/wrong/20.png"),
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

    void corridor_draw(sf::RenderWindow &c_window) override
    {
        c_window.draw(background_sprite);

        c_window.draw(p_s->c_corridor.door_right_sprite);
        c_window.draw(p_s->c_corridor.flower_sprite);
        c_window.draw(p_s->c_corridor.flower_1_sprite);
        c_window.draw(p_s->c_corridor.flower2_sprite);
        c_window.draw(p_s->c_corridor.cabinet_sprite);
        c_window.draw(p_s->c_corridor.cabinet_1_sprite);
        c_window.draw(p_s->c_corridor.notion_board_sprite);
        c_window.draw(p_s->c_corridor.clock_sprite);
        c_window.draw(p_s->c_corridor.toiletman_sprite);
        c_window.draw(p_s->c_corridor.toiletwoman_sprite);
        c_window.draw(p_s->c_corridor.exitdoor_sprite);

        c_window.draw(p_s->notion_board_text);
        c_window.draw(p_s->clock_text);
    }

    bool HandleEvent_Corridor_ondoorleft(const sf::Event::KeyPressed &key) override
    {
        if (key.code == sf::Keyboard::Key::W)
        {
            player_text(L"我记得这里应该有个门…");
            return true;
        }
        return false;
    }
};