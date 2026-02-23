/*
 *@文件 ： mirror.cpp
 *@描述 ： 无异常场景大类镜子的实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-6
 */
#include "scene.hpp"

void Scene::mirror_background_set()
{
    c_toilet.mirror_sprite.setOrigin(c_toilet.mirror_sprite.getLocalBounds().size / 2.f);
    c_toilet.mirror_sprite.setPosition(c_player.getPosition() + sf::Vector2f(0.f, -100.f));
    c_toilet.mirror_sprite.setScale({8.f, 6.f});
}

void Scene::mirror_text_set()
{
    mirror_intext.setPosition(c_toilet.mirror_sprite.getPosition() + sf::Vector2f(-200.f, 100.f));
    mirror_intext.setCharacterSize(40);
    mirror_intext.setString(L"一片模糊，什么都看不清");
}

void Scene::mirror_player_reset()
{
    c_player.setPosition(c_toilet.mirror_sprite.getPosition() + sf::Vector2f(0.f, 100.f));
}

void Scene::switch_MirrorToToilet()
{
    mirror_player_reset();
    switchscene(SceneState::Toilet);
}

bool Scene::HandleEvent_Mirror_on(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::E)
    {
        switch_MirrorToToilet();
        return true;
    }
    return false;
}