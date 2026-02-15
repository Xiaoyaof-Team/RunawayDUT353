/*
 *@文件 ： corridor.cpp
 *@描述 ： 无异常场景大类走廊的实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-6
 */
#include "scene.hpp"
#include <iostream>
void Scene::corridor_background_set()
{
    // 设置走廊场景初始状态
    c_corridor.background_sprite.setPosition({0.f, 0.f});
    c_corridor.background_sprite.setScale({0.8f, 0.8f});
}

void Scene::corridor_doorleft_set()
{
    c_corridor.door_left_sprite.setOrigin(c_corridor.door_left_sprite.getLocalBounds().size / 2.f);
    c_corridor.door_left_sprite.setPosition({1035.87, 495.794});
    c_corridor.door_left_sprite.setScale({0.85f, 0.85f});
}

void Scene::corridor_doorright_set()
{
    c_corridor.door_right_sprite.setOrigin(c_corridor.door_right_sprite.getLocalBounds().size / 2.f);
    c_corridor.door_right_sprite.setPosition({5860.62, 495.794});
    c_corridor.door_right_sprite.setScale({1.f, 1.f});
}

void Scene::corridor_flower_set()
{
    c_corridor.flower_sprite.setOrigin(c_corridor.flower_sprite.getLocalBounds().size / 2.f);
    c_corridor.flower_sprite.setPosition({1830.0, 590.794});
    c_corridor.flower_sprite.setScale({0.4f, 0.4f});
}

void Scene::corridor_flower_1_set()
{
    c_corridor.flower_1_sprite.setOrigin(c_corridor.flower_1_sprite.getLocalBounds().size / 2.f);
    c_corridor.flower_1_sprite.setPosition({3850.0, 590.794});
    c_corridor.flower_1_sprite.setScale({0.4f, 0.4f});
}

void Scene::corridor_flower2_set()
{
    c_corridor.flower2_sprite.setOrigin(c_corridor.flower2_sprite.getLocalBounds().size / 2.f);
    c_corridor.flower2_sprite.setPosition({2400, 510.794});
    c_corridor.flower2_sprite.setScale({0.5f, 0.5f});
}

void Scene::corridor_cabinet_set()
{
    c_corridor.cabinet_sprite.setOrigin(c_corridor.cabinet_sprite.getLocalBounds().size / 2.f);
    c_corridor.cabinet_sprite.setPosition({2107.26, 490.794});
    c_corridor.cabinet_sprite.setScale({0.7f, 0.7f});
}

void Scene::corridor_cabinet_1_set()
{
    c_corridor.cabinet_1_sprite.setOrigin(c_corridor.cabinet_1_sprite.getLocalBounds().size / 2.f);
    c_corridor.cabinet_1_sprite.setPosition({4108.2, 490.794});
    c_corridor.cabinet_1_sprite.setScale({0.7f, 0.7f});
}

void Scene::corridor_notion_board_set()
{
    c_corridor.notion_board_sprite.setOrigin(c_corridor.notion_board_sprite.getLocalBounds().size / 2.f);
    c_corridor.notion_board_sprite.setPosition({660.649, 420.0});
    c_corridor.notion_board_sprite.setScale({0.58f, 0.58f});
}

void Scene::corridor_toiletman_set()
{
    c_corridor.toiletman_sprite.setOrigin(c_corridor.toiletman_sprite.getLocalBounds().size / 2.f);
    c_corridor.toiletman_sprite.setPosition({6265.56, 499.794});
    c_corridor.toiletman_sprite.setScale({0.55f, 0.55f});
}

void Scene::corridor_toiletwoman_set()
{
    c_corridor.toiletwoman_sprite.setOrigin(c_corridor.toiletwoman_sprite.getLocalBounds().size / 2.f);
    c_corridor.toiletwoman_sprite.setPosition({6505.51, 499.794});
    c_corridor.toiletwoman_sprite.setScale({0.55f, 0.55f});
}

void Scene::corridor_exitdoor_set()
{
    if (statistics_levels == 1)
    {
        c_corridor.exitdoor_sprite.setOrigin(c_corridor.exitdoor_sprite.getLocalBounds().size / 2.f);
        c_corridor.exitdoor_sprite.setPosition({5005.51, 449.794});
        c_corridor.exitdoor_sprite.setScale({0.8f, 0.8f});
    }
    else
    {
        // 感觉这是最高效的办法
        c_corridor.exitdoor_sprite.setScale({0.0f, 0.0f});
    }
}

void Scene::corridor_player_set_fromstairleft()
{
    c_player.setPosition({351.355, 644.794});
    c_player.setDirection_right();
}

void Scene::corridor_player_set_fromstairright()
{
    c_player.setPosition({351.355, 644.794});
    c_player.setDirection_right();
}

void Scene::corridor_player_set_fromclassroomleft()
{
    c_player.setPosition({1035.87, 644.794});
    c_player.setDirection_right();
}

void Scene::corridor_player_set_fromclassroomright()
{
    c_player.setPosition({5894.62, 644.794});
    c_player.setDirection_left();
}

void Scene::corridor_player_set_fromtoiletman()
{
    c_player.setPosition({6276.56, 644.794});
    c_player.setDirection_right();
}

void Scene::corridor_player_set_fromtoiletwoman()
{
    c_player.setPosition({6513.51, 644.794});
    c_player.setDirection_right();
}

void Scene::on_corridor_notion_board()
{
    if (c_player.getGlobalBounds().findIntersection(c_corridor.notion_board_sprite.getGlobalBounds()).has_value())
    {
        notion_board_text.setString(L"E键查看公告栏");
        notion_board_text.setPosition(c_corridor.notion_board_sprite.getPosition() + sf::Vector2f(-130.f, -150.f));
        notion_board_text.setCharacterSize(40);
        notion_board_text.setFillColor(sf::Color::White);
    }
    else
    {
        notion_board_text.setString(L"");
    }
}

void Scene::on_corridor_stair_left()
{
    if (c_player.getPosition().x <= 351.355f)
    {
        player_text(L"...走这里吗?");
    }
}

void Scene::on_corridor_stair_right()
{
    if (c_player.getPosition().x >= 6805.22f)
    {
        player_text(L"...走这里吗?");
    }
}

void Scene::on_corridor_exit_door()
{
    if (c_player.getGlobalBounds().findIntersection(c_corridor.exitdoor_sprite.getGlobalBounds()).has_value())
    {
        player_text(L"逃出去！");
    }
}

void Scene::on_corridor_clock()
{
    if (c_corridor.clock_sprite.getGlobalBounds().contains(c_player.getPosition() + sf::Vector2f(0.f, -324.f)))
    {
        clock_text.setString(L"E键查看时钟");
        clock_text.setPosition(c_corridor.clock_sprite.getPosition() + sf::Vector2f(-100.f, -150.f));
        clock_text.setCharacterSize(40);
        clock_text.setFillColor(sf::Color::White);
    }
    else
    {
        clock_text.setString(L"");
    }
}

void Scene::switch_CorridorToRule()
{
    switchscene(SceneState::Rule);
}

void Scene::switch_CorridorToClassroom()
{
    switchscene(SceneState::Classroom);
    classroom_player_set();
}

void Scene::switch_CorridorToToilet()
{
    switchscene(SceneState::Toilet);
    toilet_player_set();
}

bool Scene::HandleEvent_Corridor_ondoorleft(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        switch_CorridorToClassroom();
        return true;
    }
    return false;
}

bool Scene::HandleEvent_Corridor_ondoorright(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        player_text(L"这里好像上锁了");
        return true;
    }
    return false;
}

bool Scene::HandleEvent_Corridor_onnotionboard(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::E)
    {
        switch_CorridorToRule();
        return true;
    }
    return false;
}

bool Scene::HandleEvent_Corridor_ontoiletman(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        player_text(L"我似乎不应该进去...");
        return true;
    }
    return false;
}

bool Scene::HandleEvent_Corridor_ontoiletwoman(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        switch_CorridorToToilet();
        return true;
    }
    return false;
}

bool Scene::HandleEvent_Corridor_stairleft(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        answer = 1;
        return true;
    }
    return false;
}

bool Scene::HandleEvent_Corridor_stairright(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        answer = 2;
        return true;
    }
    return false;
}

bool Scene::HandleEvent_Corridor_exitdoor(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        answer = 3;
        return true;
    }
    return false;
}

bool Scene::HandleEvent_Corridor_onclock(sf::Event::KeyPressed const &key)
{
    if (key.code == sf::Keyboard::Key::E)
    {
        player_text(L"时钟静止不动...\n时针停在了" + std::to_wstring(statistics_levels) + L"点的位置...");
        return true;
    }
    return false;
}

bool Scene::isplayerwithcorridor_doorleft()
{
    return c_corridor.door_left_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithcorridor_doorright()
{
    return c_corridor.door_right_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithcorridor_notionboard()
{
    return c_corridor.notion_board_sprite.getGlobalBounds().findIntersection(c_player.getGlobalBounds()).has_value();
}

bool Scene::isplayerwithcorridor_toiletman()
{
    return c_corridor.toiletman_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithcorridor_toiletwoman()
{
    return c_corridor.toiletwoman_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithcorridor_stairleft()
{
    return c_player.getPosition().x <= 351.355f;
}

bool Scene::isplayerwithcorridor_stairright()
{
    return c_player.getPosition().x >= 6805.22f;
}

bool Scene::isplayerwithcorridor_exitdoor()
{
    return c_corridor.exitdoor_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithcorridor_flower()
{
    return c_corridor.flower_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithcorridor_flower_1()
{
    return c_corridor.flower_1_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithcorridor_flower2()
{
    return c_corridor.flower2_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithcorridor_cabinet()
{
    return c_corridor.cabinet_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithcorridor_cabinet_1()
{
    return c_corridor.cabinet_1_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithcorridor_clock()
{
    return c_corridor.clock_sprite.getGlobalBounds().contains(c_player.getPosition() + sf::Vector2f(0.f, -324.f));
}
