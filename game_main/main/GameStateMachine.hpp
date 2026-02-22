/*
 *@ 文件 ： GameStateMachine.hpp
 *@ 描述 ： 游戏主要设置状态机类声明
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#pragma once
#include <string>

// 设置游戏状态机
class GameStateMachine
{
public:
    int Volume = 50;                             // 音量大小，默认50%
    std::wstring is_FullScreen = L"窗口化";      // 是否全屏，默认否
    std::wstring Frame_Rate = L"60";             // 帧率限制，默认60
    std::wstring is_sway = L"是";              // 设置是否允许摇晃
    std::wstring is_MouseLeave_Pause = L"是";    // 是否鼠标离开屏幕，默认是
    std::wstring is_Mouse_Follow_Camera = L"是"; // 是否鼠标跟随相机，默认是
    std::wstring is_SkipBegin = L"否";           // 是否跳过片头，默认否
};