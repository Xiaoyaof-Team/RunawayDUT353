/*
 *@文件 ： WrongBGM.hpp
 *@描述 ： 背景音乐异常
 *@作者 ： 逍遥风鉴事
 *@时间 ： 2026-2-15
 */
#pragma once
#include "abnormity.hpp"
#include "scene.hpp"
#include "music.hpp"

class WrongBGM : public Abnormity
{
public:
    using Abnormity::HandleEvent;

    WrongBGM(Scene *scene) : Abnormity(scene)
    {
        c_music.backgroundMusic.stop();

        if (c_music.backgroundMusic.openFromFile("game_main/picture/wrong/11.mp3"))
        {
            c_music.backgroundMusic.setLooping(true);
            c_music.backgroundMusic.play();
        }
    }

    // 析构函数
    virtual ~WrongBGM()
    {
        c_music.backgroundMusic.stop();

        // 换回初始
        if (c_music.backgroundMusic.openFromFile("game_main/music/background/rain.mp3"))
        {
            c_music.backgroundMusic.setLooping(true);
            c_music.backgroundMusic.play();
        }
    }
};