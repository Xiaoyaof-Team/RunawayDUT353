/*
 *@文件 ： toilet.cpp
 *@描述 ： 无异常场景大类厕所的实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-6
 */
#include "scene.hpp"

void Scene::toilet_background_set()
{
    c_toilet.background_sprite.setPosition({0.f, 0.f});
    c_toilet.background_sprite.setScale({0.8f, 0.8f});
}

void Scene::toilet_door_set()
{
    c_toilet.door_sprite.setOrigin(c_toilet.door_sprite.getLocalBounds().size / 2.f);
    c_toilet.door_sprite.setPosition({310.541, 300.698});
    c_toilet.door_sprite.setScale({0.61f, 0.61f});
}

void Scene::toilet_wash_basin_set()
{
    c_toilet.wash_basin_sprite.setOrigin(c_toilet.wash_basin_sprite.getLocalBounds().size / 2.f);
    c_toilet.wash_basin_sprite.setPosition({931.284f, 430.419f});
    c_toilet.wash_basin_sprite.setScale({1.1f, 1.1f});
}

void Scene::toilet_mirror_set()
{
    c_toilet.mirror_sprite.setOrigin(c_toilet.mirror_sprite.getLocalBounds().size / 2.f);
    c_toilet.mirror_sprite.setPosition({931.284f, 200.f});
    c_toilet.mirror_sprite.setScale({1.3f, 1.f});
}

void Scene::toilet_player_set()
{
    c_player.setPosition({302.058, 376.012});
    c_player.setDirection_right();
}

void Scene::switch_ToiletToCorridor()
{
    switchscene(SceneState::Corridor);
    corridor_player_set_fromtoiletwoman();
}

void Scene::switch_ToiletToMirror()
{
    switchscene(SceneState::Mirror);
}

void Scene::on_toilet_mirror()
{
    if (c_player.getGlobalBounds().contains(c_toilet.mirror_sprite.getGlobalBounds().getCenter()))
    {
        mirror_text.setString(L"E键照镜子");
        mirror_text.setPosition(c_toilet.mirror_sprite.getPosition() + sf::Vector2f(-100.f, -150.f));
        mirror_text.setCharacterSize(40);
        mirror_text.setFillColor(sf::Color::White);
    }
    else
    {
        mirror_text.setString(L"");
    }
}

bool Scene::HandleEvent_Toilet_ondoor(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        switch_ToiletToCorridor();
        return true;
    }
    return false;
}

bool Scene::HandleEvent_Toilet_onmirror(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::E)
    {
        switch_ToiletToMirror();
        return true;
    }
    return false;
}

bool Scene::isplayerwithtoiletmirror()
{
    return c_player.getGlobalBounds().contains(c_toilet.mirror_sprite.getGlobalBounds().getCenter());
}

bool Scene::isplayerwithtoiletdoor()
{
    return c_toilet.door_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithtoiletwashbasin()
{
    return c_toilet.wash_basin_sprite.getGlobalBounds().contains(c_player.getPosition());
}

bool Scene::isplayerwithtoiletlid()
{
    return c_player.getPosition().x >= 1217.82;
}
