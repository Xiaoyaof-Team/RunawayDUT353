/*
 *@文件 ： DoNotGoBack.hpp
 *@描述 ： 别回头
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"
#include "AllAbnormity.hpp"

class DoNotGoBack : public Abnormity
{
private:
    bool has_warned = false; // 是否已经弹出过警告，不过似乎没啥用
    bool first_frame = true;
    float initial_x = 0.f;

public:
    using Abnormity::HandleEvent;

    DoNotGoBack(Scene *scene) : Abnormity(scene) {}

    void corridor_set() override
    {
        Abnormity::corridor_set();
        initial_x = p_s->c_player.getPosition().x;
        has_warned = false;
        first_frame = true;
    }

    void corridor_update() override
    {
        Abnormity::corridor_update();
        if (has_warned == false)
        {
            p_s->player_text(L"别回头...");
        }
        if (!first_frame)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            {
                trigger_jumpscare();
            }
        }
        first_frame = false;
    }

    void trigger_jumpscare()
    {

        p_s->answer = 1;
        this->corridor_player_set_fromclassroomleft();
        p_s->player_text(L"你回头了...");
        has_warned = true;
        // 这里以后可以加入音效触发
    }

    void corridor_draw(sf::RenderWindow &window) override
    {
        Abnormity::corridor_draw(window);
    }
};