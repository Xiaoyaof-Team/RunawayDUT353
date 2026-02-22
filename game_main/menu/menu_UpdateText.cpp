/*
 *@ 文件 ： menu_default.cpp
 *@ 描述 ： 菜单界面的类字体背景等预设配置
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#include "menu.hpp"

void Menu::Menu_UpdateText(GameStateMachine &c_gameState, sf::RenderWindow &c_window)
{
    auto mouseP = sf::Mouse::getPosition(c_window);
    auto mouse = (sf::Vector2f)(c_window.mapPixelToCoords(mouseP));
    // 设置主菜单选项文本与位置
    if (MainMenu_StartText.getGlobalBounds().contains(mouse))
    {
        MainMenu_StartText.setString(L"开始游戏");
        MainMenu_StartText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        MainMenu_StartText.setString(L"开始游戏");
        MainMenu_StartText.setFillColor(sf::Color(255, 255, 255, 150));
    }
    if (MainMenu_SettingText.getGlobalBounds().contains(mouse))
    {
        MainMenu_SettingText.setString(L"设置");
        MainMenu_SettingText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        MainMenu_SettingText.setString(L"设置");
        MainMenu_SettingText.setFillColor(sf::Color(255, 255, 255, 150));
    }
    if (MainMenu_ExitText.getGlobalBounds().contains(mouse))
    {
        MainMenu_ExitText.setString(L"退出游戏");
        MainMenu_ExitText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        MainMenu_ExitText.setString(L"退出游戏");
        MainMenu_ExitText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    // 设置设置菜单选项文本与位置
    if (Setting_VolumeText.getGlobalBounds().contains(mouse))
    {
        Setting_VolumeText.setString(L"音量 : " + std::to_wstring(c_gameState.Volume) + L" %");
        Setting_VolumeText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Setting_VolumeText.setString(L"音量 : " + std::to_wstring(c_gameState.Volume) + L" %");
        Setting_VolumeText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    if (Setting_isFullScreenText.getGlobalBounds().contains(mouse))
    {
        Setting_isFullScreenText.setString(L"显示设置 : " + c_gameState.is_FullScreen);
        Setting_isFullScreenText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Setting_isFullScreenText.setString(L"显示设置 : " + c_gameState.is_FullScreen);
        Setting_isFullScreenText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    if (Setting_frameRateText.getGlobalBounds().contains(mouse))
    {
        Setting_frameRateText.setString(L"帧率限制 : " + c_gameState.Frame_Rate + L" FPS");
        Setting_frameRateText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Setting_frameRateText.setString(L"帧率限制 : " + c_gameState.Frame_Rate + L" FPS");
        Setting_frameRateText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    if (Setting_isSwayText.getGlobalBounds().contains(mouse))
    {
        Setting_isSwayText.setString(L"允许视角晃动 : " + c_gameState.is_sway);
        Setting_isSwayText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Setting_isSwayText.setString(L"允许视角晃动 : " + c_gameState.is_sway);
        Setting_isSwayText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    if (Setting_isMouseleaveText.getGlobalBounds().contains(mouse))
    {
        Setting_isMouseleaveText.setString(L"允许鼠标离开 : " + c_gameState.is_MouseLeave_Pause);
        Setting_isMouseleaveText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Setting_isMouseleaveText.setString(L"允许鼠标离开 : " + c_gameState.is_MouseLeave_Pause);
        Setting_isMouseleaveText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    if (Setting_isMousefollowText.getGlobalBounds().contains(mouse))
    {
        Setting_isMousefollowText.setString(L"视角跟随 : " + c_gameState.is_Mouse_Follow_Camera);
        Setting_isMousefollowText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Setting_isMousefollowText.setString(L"视角跟随 : " + c_gameState.is_Mouse_Follow_Camera);
        Setting_isMousefollowText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    if (Setting_isSkipBeginText.getGlobalBounds().contains(mouse))
    {
        Setting_isSkipBeginText.setString(L"跳过片头：" + c_gameState.is_SkipBegin);
        Setting_isSkipBeginText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Setting_isSkipBeginText.setString(L"跳过片头：" + c_gameState.is_SkipBegin);
        Setting_isSkipBeginText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    if (Setting_BackText.getGlobalBounds().contains(mouse))
    {
        Setting_BackText.setString(L"返回");
        Setting_BackText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Setting_BackText.setString(L"返回");
        Setting_BackText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    // 设置暂停菜单选项文本与位置
    if (Pause_ResumeText.getGlobalBounds().contains(mouse))
    {
        Pause_ResumeText.setString(L"继续游戏");
        Pause_ResumeText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Pause_ResumeText.setString(L"继续游戏");
        Pause_ResumeText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    if (Pause_SettingText.getGlobalBounds().contains(mouse))
    {
        Pause_SettingText.setString(L"设置");
        Pause_SettingText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Pause_SettingText.setString(L"设置");
        Pause_SettingText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    if (Pause_ExitText.getGlobalBounds().contains(mouse))
    {
        Pause_ExitText.setString(L"退出到主菜单");
        Pause_ExitText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Pause_ExitText.setString(L"退出到主菜单");
        Pause_ExitText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    // 设置游戏结束菜单选项文本与位置
    if (Over_RestartText.getGlobalBounds().contains(mouse))
    {
        Over_RestartText.setString(L"再想想");
        Over_RestartText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Over_RestartText.setString(L"再想想");
        Over_RestartText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    if (Over_ExitText.getGlobalBounds().contains(mouse))
    {
        Over_ExitText.setString(L"说了！退出！！");
        Over_ExitText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Over_ExitText.setString(L"说了！退出！！");
        Over_ExitText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    // 设置游戏胜利菜单选项文本与位置
    if (Win_RestartText.getGlobalBounds().contains(mouse))
    {
        Win_RestartText.setString(L"再开一把");
        Win_RestartText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Win_RestartText.setString(L"再开一把");
        Win_RestartText.setFillColor(sf::Color(255, 255, 255, 150));
    }

    if (Win_ExitText.getGlobalBounds().contains(mouse))
    {
        Win_ExitText.setString(L"不玩了，退出");
        Win_ExitText.setFillColor(sf::Color(255, 255, 255, 255));
    }
    else
    {
        Win_ExitText.setString(L"不玩了，退出");
        Win_ExitText.setFillColor(sf::Color(255, 255, 255, 150));
    }
}