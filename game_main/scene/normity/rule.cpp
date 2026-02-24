/*
 *@文件 ： rule.cpp
 *@描述 ： 无异常公告板的实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-6
 */
#include "scene.hpp"

void Scene::rule_background_set()
{
    c_corridor.rule_sprite.setOrigin(c_corridor.rule_sprite.getLocalBounds().size / 2.f);
    c_corridor.rule_sprite.setScale({2.f, 2.f});
    c_corridor.rule_sprite.setPosition(c_player.getPosition() + sf::Vector2f(0.f, -100.f));
}

bool Scene::HandleEvent_Rule_on(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::E)
    {
        // 处理点击事件，返回公告栏场景
        switch_RuleToCorridor();
        return true; // 事件已处理
    }
    return false; // 事件未处理
}

void Scene::rule_player_reset()
{
    // 将人物还原至初始位置
    c_player.setPosition(c_corridor.rule_sprite.getPosition() + sf::Vector2f(0.f, 100.f));
}

void Scene::switch_RuleToCorridor()
{
    switchscene(SceneState::Corridor);
}