/*
 *@文件 ： CorridorWithBanToiletDoor.hpp
 *@描述 ： 厕所门进不去异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class CorridorWithBanToiletDoor : public Abnormity
{
public:
    using Abnormity::HandleEvent;

    CorridorWithBanToiletDoor(Scene *scene) : Abnormity(scene)
    {
    }

    bool HandleEvent_Corridor_ontoiletwoman(const sf::Event::KeyPressed &key) override
    {
        if (key.code == sf::Keyboard::Key::W)
        {
            player_text(L"锁上了。");
            return true;
        }
        return false;
    }

    void corridor_set() override
    {
        Abnormity::corridor_set();
    }
};