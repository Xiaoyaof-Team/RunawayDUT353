/*
 *@文件 ： CorridorWithWrongClassroomDoor.hpp
 *@描述 ： 走廊教室门异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"

class CorridorWithWrongClassroomDoor : public Abnormity
{
public:
    using Abnormity::HandleEvent;

    CorridorWithWrongClassroomDoor(Scene *scene) : Abnormity(scene)
    {
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

    bool HandleEvent_Corridor_ondoorright(const sf::Event::KeyPressed &key) override
    {
        if (key.code == sf::Keyboard::Key::W)
        {
            switch_CorridorToClassroom();
            return true;
        }
        return false;
    }

    void corridor_set() override
    {
        Abnormity::corridor_set();
    }
};