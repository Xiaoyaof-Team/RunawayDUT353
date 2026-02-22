/*
 *@ 文件 ： menu_default.cpp
 *@ 描述 ： 菜单界面的类字体背景等预设配置
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#include "menu.hpp"
#include "type.hpp"
#include <string>

// SED: AI补全，后续需要调整
void Menu::Menu_loadResources(GameStateMachine &c_gameState)
{
    // 加载背景纹理
    // backgroundTexture.loadFromFile();
    // backgroundSprite.setTexture(backgroundTexture);

    // 设置标题文本
    titleText.setString(L"逃离踪遗");
    titleText.setCharacterSize(120);
    titleText.setFillColor(sf::Color(255, 255, 255, 255));
    titleText.setPosition({150.f, 100.f}); // 设置标题位置

    // 设置主菜单选项文本与位置
    MainMenu_StartText.setString(L"开始游戏");
    MainMenu_StartText.setCharacterSize(50);
    MainMenu_StartText.setFillColor(sf::Color(255, 255, 255, 150));
    MainMenu_StartText.setPosition({150.f, 450.f});

    MainMenu_SettingText.setString(L"设置");
    MainMenu_SettingText.setCharacterSize(50);
    MainMenu_SettingText.setFillColor(sf::Color(255, 255, 255, 150));
    MainMenu_SettingText.setPosition({150.f, 550.f});

    MainMenu_ExitText.setString(L"退出游戏");
    MainMenu_ExitText.setCharacterSize(50);
    MainMenu_ExitText.setFillColor(sf::Color(255, 255, 255, 150));
    MainMenu_ExitText.setPosition({150.f, 650.f});

    // 设置设置菜单选项文本与位置
    Setting_VolumeText.setString(L"音量 : " + std::to_wstring(c_gameState.Volume) + L" %");
    Setting_VolumeText.setCharacterSize(40);
    Setting_VolumeText.setFillColor(sf::Color(255, 255, 255, 150));
    Setting_VolumeText.setPosition({150.f, 300.f});

    Setting_isFullScreenText.setString(L"显示设置 : " + c_gameState.is_FullScreen);
    Setting_isFullScreenText.setCharacterSize(40);
    Setting_isFullScreenText.setFillColor(sf::Color(255, 255, 255, 150));
    Setting_isFullScreenText.setPosition({150.f, 380.f});

    Setting_frameRateText.setString(L"帧率限制 : " + c_gameState.Frame_Rate + L" FPS");
    Setting_frameRateText.setCharacterSize(40);
    Setting_frameRateText.setFillColor(sf::Color(255, 255, 255, 150));
    Setting_frameRateText.setPosition({150.f, 460.f});

    Setting_isSwayText.setString(L"允许视角晃动 : " + c_gameState.is_sway);
    Setting_isSwayText.setCharacterSize(40);
    Setting_isSwayText.setFillColor(sf::Color(255, 255, 255, 150));
    Setting_isSwayText.setPosition({150.f, 540.f});

    Setting_isMouseleaveText.setString(L"允许鼠标离开 : " + c_gameState.is_MouseLeave_Pause);
    Setting_isMouseleaveText.setCharacterSize(40);
    Setting_isMouseleaveText.setFillColor(sf::Color(255, 255, 255, 150));
    Setting_isMouseleaveText.setPosition({150.f, 620.f});

    Setting_isMousefollowText.setString(L"视角跟随 : " + c_gameState.is_Mouse_Follow_Camera);
    Setting_isMousefollowText.setCharacterSize(40);
    Setting_isMousefollowText.setFillColor(sf::Color(255, 255, 255, 150));
    Setting_isMousefollowText.setPosition({150.f, 700.f});

    Setting_isSkipBeginText.setString(L"跳过片头：" + c_gameState.is_SkipBegin);
    Setting_isSkipBeginText.setCharacterSize(40);
    Setting_isSkipBeginText.setFillColor(sf::Color(255, 255, 255, 150));
    Setting_isSkipBeginText.setPosition({150.f, 780.f});

    Setting_BackText.setString(L"返回");
    Setting_BackText.setCharacterSize(40);
    Setting_BackText.setFillColor(sf::Color(255, 255, 255, 150));
    Setting_BackText.setPosition({150.f, 860.f});

    // 设置暂停菜单选项文本与位置
    Pause_ResumeText.setString(L"继续游戏");
    Pause_ResumeText.setCharacterSize(50);
    Pause_ResumeText.setFillColor(sf::Color(255, 255, 255, 150));
    Pause_ResumeText.setPosition({150.f, 450.f});

    Pause_SettingText.setString(L"设置");
    Pause_SettingText.setCharacterSize(50);
    Pause_SettingText.setFillColor(sf::Color(255, 255, 255, 150));
    Pause_SettingText.setPosition({150.f, 550.f});

    Pause_ExitText.setString(L"退出到主菜单");
    Pause_ExitText.setCharacterSize(50);
    Pause_ExitText.setFillColor(sf::Color(255, 255, 255, 150));
    Pause_ExitText.setPosition({150.f, 650.f});

    // 设置游戏结束菜单选项文本与位置
    Over_RestartText.setString(L"再想想");
    Over_RestartText.setCharacterSize(50);
    Over_RestartText.setFillColor(sf::Color(255, 255, 255, 150));
    Over_RestartText.setPosition({150.f, 450.f});

    Over_ExitText.setString(L"说了！退出！！");
    Over_ExitText.setCharacterSize(50);
    Over_ExitText.setFillColor(sf::Color(255, 255, 255, 150));
    Over_ExitText.setPosition({150.f, 550.f});

    // 设置游戏胜利菜单选项文本与位置
    Win_RestartText.setString(L"再开一把");
    Win_RestartText.setCharacterSize(50);
    Win_RestartText.setFillColor(sf::Color(255, 255, 255, 150));
    Win_RestartText.setPosition({150.f, 450.f});

    Win_ExitText.setString(L"不玩了，退出");
    Win_ExitText.setCharacterSize(50);
    Win_ExitText.setFillColor(sf::Color(255, 255, 255, 150));
    Win_ExitText.setPosition({150.f, 550.f});
}