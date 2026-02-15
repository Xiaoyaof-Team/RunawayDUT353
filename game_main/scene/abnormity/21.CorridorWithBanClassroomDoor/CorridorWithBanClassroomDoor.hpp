/*
 *@文件 ： CorridorWithBanClassroomDoor.hpp
 *@描述 ： 走廊门进不去异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class CorridorWithBanClassroomDoor : public Abnormity
{
public:
    using Abnormity::HandleEvent;

    CorridorWithBanClassroomDoor(Scene *scene) : Abnormity(scene)
    {
    }

    void corridor_set() override
    {
        Abnormity::corridor_set();
    }

    bool HandleEvent_Corridor_ondoorleft(const sf::Event::KeyPressed &key) override
    {
        if (key.code == sf::Keyboard::Key::W)
        {
            player_text(L"这里好像上锁了");

            return true;
        }
        return false;
    }
};