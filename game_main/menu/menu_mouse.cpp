/*
 *@ 文件 ： menu_mouse.cpp
 *@ 描述 ： 菜单界面的类对鼠标事件的实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#include "menu.hpp"
#include "type.hpp"
#include "Application.hpp"

bool Menu::HandleEvent(const sf::Event::MouseButtonPressed &mouse, sf::RenderWindow &c_window)
{
    auto mousePos = (sf::Vector2f)c_window.mapPixelToCoords(mouse.position);
    // 根据当前菜单状态处理鼠标点击事件
    switch (c_menuState.currentState)
    {
    case MenuState::None:
        // 不处理鼠标事件
        break;
    case MenuState::MainMenu:
        // 处理主菜单鼠标点击事件
        if (MainMenu_StartText.getGlobalBounds().contains(mousePos))
        {
            // 点击开始游戏
            c_menuState.lastState = c_menuState.currentState;
            c_menuState.currentState = MenuState::None;

            return true;
        }
        else if (MainMenu_SettingText.getGlobalBounds().contains(mousePos))
        {
            // 点击设置
            // 记录上一次菜单状态
            c_menuState.lastState = c_menuState.currentState;
            c_menuState.currentState = MenuState::Setting;
            return true;
        }
        else if (MainMenu_ExitText.getGlobalBounds().contains(mousePos))
        {
            // 点击退出游戏
            c_menuState.lastState = c_menuState.currentState;
            c_menuState.currentState = MenuState::Over;
            return true;
        }
        break;
    case MenuState::Setting:
        // 处理设置菜单鼠标点击事件
        // SED:还有其他的设置选项未实现，具体的实现待定
        handle_setting_change(mouse, c_window);
        if (Setting_BackText.getGlobalBounds().contains(mousePos))
        {
            // 点击返回
            c_menuState.currentState = c_menuState.lastState;
            return true;
        }
        break;
    case MenuState::Pause:
        // 处理暂停菜单鼠标点击事件
        if (Pause_ResumeText.getGlobalBounds().contains(mousePos))
        {
            // 点击继续游戏
            c_menuState.lastState = c_menuState.currentState;
            c_menuState.currentState = MenuState::None;
            return true;
        }
        else if (Pause_SettingText.getGlobalBounds().contains(mousePos))
        {
            // 点击设置
            // 记录上一次菜单状态
            c_menuState.lastState = c_menuState.currentState;
            c_menuState.currentState = MenuState::Setting;
            return true;
        }
        else if (Pause_ExitText.getGlobalBounds().contains(mousePos))
        {
            // 点击回到主菜单
            // SED：需要使游戏状态机回到初始状态
            c_allAbnormity.resetLevel();
            c_menuState.lastState = c_menuState.currentState;
            c_menuState.currentState = MenuState::MainMenu;
            return true;
        }
        break;
    case MenuState::Over:
        // 处理游戏结束菜单鼠标点击事件
        if (Over_RestartText.getGlobalBounds().contains(mousePos))
        {
            // 点击回到主菜单
            c_allAbnormity.resetLevel();
            c_menuState.lastState = c_menuState.currentState;
            c_menuState.currentState = MenuState::MainMenu;
            return true;
        }
        else if (Over_ExitText.getGlobalBounds().contains(mousePos))
        {
            // 点击退出游戏
            c_window.close();
            return true;
        }
        break;
    case MenuState::Win:
        if (Win_RestartText.getGlobalBounds().contains(mousePos))
        {
            // 点击开始游戏
            c_menuState.lastState = c_menuState.currentState;
            c_menuState.currentState = MenuState::None;
            return true;
        }
        else if (Win_ExitText.getGlobalBounds().contains(mousePos))
        {
            // 点击回到主菜单
            c_menuState.lastState = c_menuState.currentState;
            c_menuState.currentState = MenuState::MainMenu;
            return true;
        }
        break;

    default:
        break;
    }
    return false;
}

void Menu::handle_setting_change(const sf::Event::MouseButtonPressed &mouse, sf::RenderWindow &c_window)
{
    auto mousePos = (sf::Vector2f)c_window.mapPixelToCoords(mouse.position);
    // 处理设置菜单中的各项设置更改
    if (Setting_VolumeText.getGlobalBounds().contains(mousePos))
    {
        if (c_gameState.Volume < 100)
        {
            c_music.backgroundMusic.setVolume(c_gameState.Volume + 10);
            c_gameState.Volume += 10;
        }
        else
        {
            c_music.backgroundMusic.setVolume(0);
            c_gameState.Volume = 0;
        }
    }
    else if (Setting_isFullScreenText.getGlobalBounds().contains(mousePos))
    {
        if (c_gameState.is_FullScreen == L"窗口化")
        {
            auto mode = sf::VideoMode::getDesktopMode();
            c_window.create(mode, "RunawayDUT353", sf::State::Fullscreen);
            c_gameState.is_FullScreen = L"全屏";

            // 强制刷新相机比例
            float windowRatio = (float)mode.size.x / (float)mode.size.y;
            float viewRatio = 1920.f / 1080.f;
            float sizeX = 1.f;
            float sizeY = 1.f;
            float posX = 0.f;
            float posY = 0.f;

            if (windowRatio > viewRatio)
            {
                sizeX = viewRatio / windowRatio;
                posX = (1.f - sizeX) / 2.f;
            }
            else
            {
                sizeY = windowRatio / viewRatio;
                posY = (1.f - sizeY) / 2.f;
            }
            c_camera.setViewport(sf::FloatRect({posX, posY}, {sizeX, sizeY}));
            c_window.setView(c_camera);
        }
        else
        {
            c_window.create(sf::VideoMode(sf::Vector2u(1920, 1080)), "RunawayDUT353", sf::Style::Default);
            c_gameState.is_FullScreen = L"窗口化";

            // 窗口化回归默认16:9，重置视口为全铺满
            c_camera.setViewport(sf::FloatRect({0.f, 0.f}, {1.f, 1.f}));
            c_window.setView(c_camera);
        }
        // 默认设置帧数
        if (c_gameState.Frame_Rate == L"30")
        {
            c_window.setVerticalSyncEnabled(false);
            c_window.setFramerateLimit(30);
        }
        else if (c_gameState.Frame_Rate == L"60")
        {
            c_window.setVerticalSyncEnabled(false);
            c_window.setFramerateLimit(60);
        }
        else
        {
            c_window.setVerticalSyncEnabled(true);
        }
        // 禁用按键重复
        c_window.setKeyRepeatEnabled(false);
        // 重置相机视图
        c_camera.setSize({1920.f, 1080.f});
        c_camera.setCenter({960.f, 540.f});
        c_window.setView(c_camera);
    }
    else if (Setting_frameRateText.getGlobalBounds().contains(mousePos))
    {
        if (c_gameState.Frame_Rate == L"30")
        {
            c_window.setFramerateLimit(60);
            c_gameState.Frame_Rate = L"60";
        }
        else if (c_gameState.Frame_Rate == L"60")
        {
            c_window.setVerticalSyncEnabled(true);
            c_gameState.Frame_Rate = L"垂直同步";
        }
        else
        {
            c_window.setVerticalSyncEnabled(false);
            c_window.setFramerateLimit(30);
            c_gameState.Frame_Rate = L"30";
        }
    }
    else if (Setting_isSwayText.getGlobalBounds().contains(mousePos))
    {
        if (c_gameState.is_sway == L"是")
        {
            c_gameState.is_sway = L"否";
        }
        else
        {
            c_gameState.is_sway = L"是";
        }
    }
    else if (Setting_isMouseleaveText.getGlobalBounds().contains(mousePos))
    {
        if (c_gameState.is_MouseLeave_Pause == L"是")
        {
            c_window.setMouseCursorGrabbed(true);
            c_gameState.is_MouseLeave_Pause = L"否";
        }
        else
        {
            c_window.setMouseCursorGrabbed(false);
            c_gameState.is_MouseLeave_Pause = L"是";
        }
    }
    else if (Setting_isMousefollowText.getGlobalBounds().contains(mousePos))
    {
        // 切换鼠标跟随视角设置
        // SED: 我想加一个视角动画，让视角有一定跟手效果
    }
    else if (Setting_isSkipBeginText.getGlobalBounds().contains(mousePos))
    {
        if (c_gameState.is_SkipBegin == L"是")
        {
            c_gameState.is_SkipBegin = L"否";
        }
        else
        {
            c_gameState.is_SkipBegin = L"是";
        }
    }
}
