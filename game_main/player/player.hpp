/*
 *@ 文件 ： player.hpp
 *@ 描述 ： 角色移动
 *@ 作者 ： 逍遥风鉴事
 *@ 时间 ： 2026-2-4
 */
#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "menu.hpp"
#include "type.hpp"
class Player
{
public:
    Player();

    // 初始化
    void init();

    // 角色计算
    void update(float deltaTime);

    // 角色更新
    void draw(sf::RenderWindow &window);

    // 绘制
    void display();

    // 开始游戏动画
    void startgame(sf::RenderWindow &window);

    // 获取位置
    sf::Vector2f getPosition() const;

    // SED:新增需要的函数
    // 设置位置
    void setPosition(const sf::Vector2f &newPosition);

    // 获得碰撞箱
    sf::FloatRect getGlobalBounds();

    // 获得尺寸
    sf::Vector2f getSize() const;

    // 设置人物朝向
    void setDirection_left();
    void setDirection_right();

    // 检测状态
    void checkState(MenuState currentState, MenuState lastState, sf::RenderWindow &window, std::wstring skipBegin);

public:
    float speed;

private:
    sf::Vector2f position;
    sf::FloatRect hitbox;
    std::array<sf::Texture, 6> textures; // 哈哈好不容易扣完图才知道有雪碧图这个东西
    sf::Texture test;
    sf::Sprite sprite;
    int currentFrame; // 当前画序
    float changeTime; // 动画切换时间
    float timing;
    float scale;
    int moving;
    int playerState; // 游戏状态，0菜单界面，1游戏中，2暂停，3死亡，4胜利，5初始人物动画，6异常
    sf::Text text;

private:
    // 加载角色贴图
    std::array<sf::Texture, 6> loadPlayerTextures();
};

#endif