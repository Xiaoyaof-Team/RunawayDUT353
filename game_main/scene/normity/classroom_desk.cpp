/*
 *@文件 ： classroom_desk.cpp
 *@描述 ： 无异常场景大类教室的实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-6
 */
#include "scene.hpp"

void Scene::classroom_desk_background_set()
{
    // 设置讲台内容
    c_classroom.desk_text_sprite.setOrigin(c_classroom.desk_text_sprite.getLocalBounds().size / 2.f);
    c_classroom.desk_text_sprite.setPosition(c_player.getPosition() + sf::Vector2f(0.f, -100.f));
    c_classroom.desk_text_sprite.setScale({1.0f, 1.0f});
}

bool Scene::HandleEvent_Classroom_desk_on(const sf::Event::KeyPressed &key)
{
    // 处理与讲台交互的按键事件
    if (key.code == sf::Keyboard::Key::E)
    {
        // 处理点击事件，返回教室场景
        classroom_desk_player_reset();
        switch_DeskToClassroom();
        return true; // 事件已处理
    }
    return false; // 事件未处理
}

void Scene::classroom_desk_player_reset()
{
    // 将人物还原至初始位置
    c_player.setPosition(c_classroom.desk_text_sprite.getPosition() + sf::Vector2f(0.f, 100.f));
}

void Scene::switch_DeskToClassroom()
{
    // 切换回教室场景
    text_desk.setString(L"");
    switchscene(SceneState::Classroom);
}