/*
 *@ 文件 ： Application.hpp
 *@ 描述 ： 游戏主体框架的类声明
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "music.hpp"
#include "menu.hpp"
#include "GameStateMachine.hpp"
#include "player.hpp"
#include "scene.hpp"
#include "AllAbnormity.hpp"
#include "abnormity.hpp"

class Application
{
public:
    // 声明游戏状态机 (Game State Machine)
    GameStateMachine c_gameState;
    // 声明异常管理类
    AllAbnormity c_allAbnormity;

private:
    // 创建窗口
    sf::RenderWindow c_window;
    // 创建时间刻度
    sf::Clock deltaTime;

    // 创建相机
    sf::View c_camera;
    sf::View c_uiView;
    float Last_distance_to_player = 0.f;
    sf::Time timeinView;

    // 创建菜单
    Menu c_menu;

    // 创建人物
    Player c_player;

    // SED::创建场景
    Scene c_scene;

public:
    Application();
    bool IsRunning() const;
    void ProcessEvent();
    void Update();
    void Render();
    void Close();

private:
    bool HandleEvent(const sf::Event::Resized &resized);
    bool HandleEvent(const sf::Event::Closed &);
    bool HandleEvent(const sf::Event::MouseButtonPressed &mouse);
    // 处理其余事件
    template <class T>
    bool HandleEvent(const T &) { return false; }

    void UpdateCameraViewPort(uint32_t width, uint32_t height);
    void CreateDefaultWindow();
    void CreateDefaultCamera();

    void UpdateCamera(float deltaTime);
};
