/*
 *@ 文件 ： scene.cpp
 *@ 描述 ： 无异常场景大类的实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-6
 */
#include "scene.hpp"
#include "GameStateMachine.hpp"

int Scene::statistics_levels = 12;

void Scene::switchscene(SceneState newScene)
{
    currentSceneState = newScene;
    switch (currentSceneState)
    {
    case SceneState::Classroom:
        currentSceneBackground = &c_classroom.background_sprite;
        break;
    case SceneState::Classroom_desk:
        currentSceneBackground = &c_classroom.desk_text_sprite;
        break;
    case SceneState::Corridor:
        currentSceneBackground = &c_corridor.background_sprite;
        break;
    case SceneState::Toilet:
        currentSceneBackground = &c_toilet.background_sprite;
        break;
    case SceneState::Rule:
        currentSceneBackground = &c_corridor.rule_sprite;
        break;
    case SceneState::Mirror:
        currentSceneBackground = &c_toilet.mirror_sprite;
        break;
    default:
        break;
    }
}

void Scene::edge_check_left()
{
    float leftLimit = currentSceneBackground->getGlobalBounds().position.x;
    if (c_player.getPosition().x - c_player.getSize().x / 2 < leftLimit)
    {
        c_player.setPosition(sf::Vector2f(leftLimit + c_player.getSize().x / 2, c_player.getPosition().y));
    }
}

void Scene::edge_check_right()
{
    float rightLimit = currentSceneBackground->getGlobalBounds().position.x + currentSceneBackground->getGlobalBounds().size.x;
    if (c_player.getPosition().x + c_player.getSize().x / 2 > rightLimit)
    {
        c_player.setPosition(sf::Vector2f(rightLimit - c_player.getSize().x / 2, c_player.getPosition().y));
    }
}

void Scene::player_text(std::wstring text)
{
    player_word.setString(text);
    player_word.setOrigin(player_word.getLocalBounds().size / 2.f); // 设置文字中心为原点
    player_word.setCharacterSize(40);
    player_word.setFillColor(sf::Color::White);
    player_word_clock.restart();
}

void Scene::player_text_update()
{
    if (player_word_clock.getElapsedTime().asSeconds() > 2) // 文字显示2秒后消失
    {
        player_word.setString(L"");
    }
    else
    {
        // 文字跟随玩家位置更新
        player_word.setPosition(c_player.getPosition() + sf::Vector2f(0, 40)); // 文字显示在玩家下方
    }
}