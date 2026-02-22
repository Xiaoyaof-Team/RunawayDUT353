/*
 *@文件 ： AllAbnormity.cpp
 *@描述 ： 异常管理类实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-7
 */
#include "AllAbnormity.hpp"
#include "abnormity.hpp"
#include "scene.hpp"
#include <random>
#include "normal.hpp"
#include "Application.hpp"
#include "1.ClassroomWithManything/ClassroomWithManything.hpp"
#include "2.ClassroomWithWrongDesks/ClassroomWithWrongDesks.hpp"
#include "3.CorridorWithWrongBoard/CorridorWithWrongBoard.hpp"
#include "4.ToiletWithWrongGlass/ToiletWithWrongGlass.hpp"
#include "5.CorridorWithNoLight/CorridorWithNoLight.hpp"
#include "6.PlayerSpeedWrong/PlayerSpeedWrong.hpp"
#include "7.ToiletWithSomeone/ToiletWithSomeone.hpp"
#include "8.CorridorWithWrongClassroomDoor/CorridorWithWrongClassroomDoor.hpp"
#include "9.CorridorWithWrongToiletDoor/CorridorWithWrongToiletDoor.hpp"
#include "10.CorridorWithWrongClock/CorridorWithWrongClock.hpp"
#include "11.WrongBGM/WrongBGM.hpp"
#include "12.SomeoneWithToilet/SomeoneWithToilet.hpp"
#include "13.SomeoneWithCorridor/SomeoneWithCorridor.hpp"
#include "14.SomeoneWithClassroom/SomeoneWithClassroom.hpp"
#include "15.CorridorWithWrongCabinet/CorridorWithWrongCabinet.hpp"
#include "16.CorridorWithWrongFlower/CorridorWithWrongFlower.hpp"
#include "17.ToiletWithWrongWashbin/ToiletWithWrongWashbin.hpp"
#include "18.DoNotGoBack/DoNotGoBack.hpp"
#include "19.CorridorWithWrongBackground/CorridorWithWrongBackground.hpp"
#include "20.CorridorWithNoClassroomDoor/CorridorWithNoClassroomDoor.hpp"
#include "21.CorridorWithBanClassroomDoor/CorridorWithBanClassroomDoor.hpp"
#include "22.CorridorWithBanToiletDoor/CorridorWithBanToiletDoor.hpp"
#include "23.CorridorWithNoToiletBoyDoor/CorridorWithNoToiletBoyDoor.hpp"
#include "24.CorridorWithWrongEXIT/CorridorWithWrongEXIT.hpp"
#include "25.CorridorWithWrongWindow/CorridorWithWrongWindow.hpp"

AllAbnormity::AllAbnormity(Scene *scene) : p_s(scene), gen(rd())
{
    // 异常添加处
    abnormityFactory[0] = [this]()
    { return std::make_unique<Normal>(p_s); };
    abnormityFactory[1] = [this]()
    { return std::make_unique<ClassroomWithManything>(p_s); };
    abnormityFactory[2] = [this]()
    { return std::make_unique<ClassroomWithManything>(p_s); }; // { return std::make_unique<ClassroomWithWrongDesks>(p_s); };
    abnormityFactory[3] = [this]()
    { return std::make_unique<CorridorWithWrongBoard>(p_s); };
    abnormityFactory[4] = [this]()
    { return std::make_unique<ToiletWithWrongGlass>(p_s); };
    abnormityFactory[5] = [this]()
    { return std::make_unique<CorridorWithNoLight>(p_s); };
    abnormityFactory[6] = [this]()
    { return std::make_unique<PlayerSpeedWrong>(p_s); };
    abnormityFactory[7] = [this]()
    { return std::make_unique<ToiletWithSomeone>(p_s); };
    abnormityFactory[8] = [this]()
    { return std::make_unique<CorridorWithWrongClassroomDoor>(p_s); };
    abnormityFactory[9] = [this]()
    { return std::make_unique<CorridorWithWrongToiletDoor>(p_s); };
    abnormityFactory[10] = [this]()
    { return std::make_unique<CorridorWithWrongClock>(p_s); };
    abnormityFactory[11] = [this]()
    { return std::make_unique<WrongBGM>(p_s); };
    abnormityFactory[12] = [this]()
    { return std::make_unique<ClassroomWithManything>(p_s); }; // { return std::make_unique<SomeoneWithToilet>(p_s); };
    abnormityFactory[13] = [this]()
    { return std::make_unique<ClassroomWithManything>(p_s); }; // { return std::make_unique<SomeoneWithCorridor>(p_s); };
    abnormityFactory[14] = [this]()
    { return std::make_unique<ClassroomWithManything>(p_s); }; // { return std::make_unique<SomeoneWithClassroom>(p_s); };
    abnormityFactory[15] = [this]()
    { return std::make_unique<CorridorWithWrongCabinet>(p_s); };
    abnormityFactory[16] = [this]()
    { return std::make_unique<CorridorWithWrongFlower>(p_s); };
    abnormityFactory[17] = [this]()
    { return std::make_unique<ToiletWithWrongWashbin>(p_s); };
    abnormityFactory[18] = [this]()
    { return std::make_unique<DoNotGoBack>(p_s); };
    abnormityFactory[19] = [this]()
    { return std::make_unique<CorridorWithWrongBackground>(p_s); };
    abnormityFactory[20] = [this]()
    { return std::make_unique<CorridorWithNoClassroomDoor>(p_s); };
    abnormityFactory[21] = [this]()
    { return std::make_unique<CorridorWithBanClassroomDoor>(p_s); };
    abnormityFactory[22] = [this]()
    { return std::make_unique<CorridorWithBanToiletDoor>(p_s); };
    abnormityFactory[23] = [this]()
    { return std::make_unique<CorridorWithNoToiletBoyDoor>(p_s); };
    abnormityFactory[24] = [this]()
    { return std::make_unique<CorridorWithWrongEXIT>(p_s); };
    abnormityFactory[25] = [this]()
    { return std::make_unique<CorridorWithWrongWindow>(p_s); };

    // 初始化hasvisited向量，默认所有异常都未出现过
    // 默认初始异常为Normal
    hasvisited.resize(abnormityFactory.size(), false);
    currentAbnormity = abnormityFactory[0]();
}

// 生成新的随机数关卡、
int AllAbnormity::generateNewLevel()
{
    // return 25; // 测试用，直接返回对应关卡
    int n = 0;
    while (1)
    {
        if (getRandomLevel(1, 100) < 20)
        {
            printf("Generated new level: 0\n");
            return 0;
        }
        int newLevel = getRandomLevel(0, abnormityFactory.size() - 1);
        if (!gethasvisited(newLevel)&&newLevel != 12&&newLevel != 13&&newLevel != 14) 
        {
            sethasvisited(newLevel);
            printf("Generated new level: %d\n", newLevel);
            return newLevel;
        }
        n++;
        if (n >= 10)
            return 0;
        continue;
    }
}

// 获取当前异常索引
int AllAbnormity::getcurrentAbnormityIndex()
{
    return currentAbnormityIndex;
}

// 设置当前异常索引
void AllAbnormity::setcurrentAbnormityIndex(int index)
{
    currentAbnormityIndex = index;
}

// 获取当前剩余关卡数
int AllAbnormity::getstatistics_levels()
{
    return p_s->statistics_levels;
}

// 设置当前剩余关卡数
void AllAbnormity::setstatistics_levels(int levels)
{
    p_s->statistics_levels = levels;
}

// 获得关卡随机数
int AllAbnormity::getRandomLevel(int min, int max)
{
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// 获得当前异常是否出现过
bool AllAbnormity::gethasvisited(int index)
{
    return hasvisited[index];
}

// 设置当前异常为已出现
void AllAbnormity::sethasvisited(int index)
{
    hasvisited[index] = true;
}

// 判断是否正确，是则生成新关卡，否则重置当前关卡
void AllAbnormity::checkAnswer(Menu &c_menu)
{
    switch (p_s->answer)
    {
    case 0:
        break;
    case 1:
        // 正常应该走左边
        if (currentAbnormityIndex == 0)
        {
            generateLevel();
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Corridor);
            currentAbnormity->corridor_player_set_fromstairleft();
        }
        else
        {
            std::fill(hasvisited.begin(), hasvisited.end(), false);
            currentAbnormityIndex = 0;
            p_s->statistics_levels = 12;
            currentAbnormity = abnormityFactory[0]();
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Corridor);
            currentAbnormity->corridor_player_set_fromstairleft();
        }
        break;
    case 2:
        // 异常应该走右边
        if (currentAbnormityIndex != 0)
        {
            generateLevel();
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Corridor);
            currentAbnormity->corridor_player_set_fromstairright();
        }
        else
        {
            std::fill(hasvisited.begin(), hasvisited.end(), false);
            currentAbnormityIndex = 0;
            p_s->statistics_levels = 12;
            currentAbnormity = abnormityFactory[0]();
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Corridor);
            currentAbnormity->corridor_player_set_fromstairright();
        }
        break;

    case 3:
        if (p_s->statistics_levels == 1)
        {
            // 游戏胜利
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Classroom);
            c_menu.c_menuState.currentState = MenuState::Win;
        }
        else
        {
            std::fill(hasvisited.begin(), hasvisited.end(), false);
            currentAbnormityIndex = 0;
            p_s->statistics_levels = 12;
            currentAbnormity = abnormityFactory[0]();
            p_s->answer = 0;
            currentAbnormity->switchscene(SceneState::Corridor);
            currentAbnormity->corridor_player_set_fromstairright();
        }
        break;
    }
}

// 生成新的关卡
void AllAbnormity::generateLevel()
{
    hasvisited[currentAbnormityIndex] = true; // 将当前异常标记为已出现
    int newLevel = generateNewLevel();
    setcurrentAbnormityIndex(newLevel);
    currentAbnormity = abnormityFactory[newLevel]();
    setstatistics_levels(p_s->statistics_levels - 1);
    if (p_s->statistics_levels == 0)
    {
        resetLevel();
    }
}

// 重置关卡
void AllAbnormity::resetLevel()
{
    std::fill(hasvisited.begin(), hasvisited.end(), false);
    currentAbnormityIndex = 0;
    p_s->statistics_levels = 12;
    currentAbnormity = abnormityFactory[0]();
    p_s->answer = 0;
    currentAbnormity->corridor_player_set_fromstairleft();
    currentAbnormity->switch_CorridorToClassroom();
}
