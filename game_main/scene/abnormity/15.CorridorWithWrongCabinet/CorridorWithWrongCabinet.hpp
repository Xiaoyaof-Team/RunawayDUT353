/*
 *@文件 ： CorridorWithWrongCabinet.hpp
 *@描述 ： 走廊柜子可交互异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class CorridorWithWrongCabinet : public Abnormity
{
public:
    using Abnormity::HandleEvent;

    CorridorWithWrongCabinet(Scene *scene) : Abnormity(scene)
    {
    }

    void corridor_update() override
    {
        Abnormity::corridor_update();
        if (p_s->isplayerwithcorridor_cabinet() || p_s->isplayerwithcorridor_cabinet_1())
        {
            p_s->clock_text.setString(L"按 E 检查柜子");
            p_s->clock_text.setCharacterSize(35);
            p_s->clock_text.setPosition(p_s->c_player.getPosition() + sf::Vector2f(-80.f, -300.f));
        }
    }

    bool HandleEvent_Corridor_oncabinet(const sf::Event::KeyPressed &key) override
    {
        if (key.code == sf::Keyboard::Key::E)
        {
            this->player_text(L"柜子里有一件发霉的校服，但传出指甲抓挠木板的声音。");
            return true;
        }
        return false;
    }

    bool HandleEvent_Corridor_oncabinet_1(const sf::Event::KeyPressed &key) override
    {
        return HandleEvent_Corridor_oncabinet(key);
    }

    void corridor_cabinet_set() override
    {
        p_s->corridor_cabinet_set();
    }
};