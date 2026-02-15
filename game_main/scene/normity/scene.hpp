/*
 *@ 文件 ： scene.hpp
 *@ 描述 ： 无异常场景大类的实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-6
 */
#pragma once
#include <SFML/Graphics.hpp>
#include "classroom.hpp"
#include "corridor.hpp"
#include "toilet.hpp"
#include "type.hpp"
#include "player.hpp"
#include <string>

class GameStateMachine;

enum class SceneState
{
    Classroom = 0,
    Classroom_desk = 1,
    Corridor = 2,
    Toilet = 3,
    Rule = 4,
    Mirror = 5
};

class Scene
{
public:
    // 获得全局状态机
    GameStateMachine &c_gamestate;
    // 场景大类的成员变量
    Classroom c_classroom;
    Corridor c_corridor;
    Toilet c_toilet;

    // 获得人物
    Player &c_player;

    // 场景状态
    SceneState currentSceneState = SceneState::Classroom;
    sf::Sprite *currentSceneBackground;
    sf::Text text_desk; // 作用于与讲台交互的文字

    sf::Text notion_board_text; // 作用于公告栏的文字
    sf::Text clock_text;        // 作用于时钟的文字
    sf::Text mirror_text;
    sf::Text mirror_intext;      // 作用于玩家说话的文字
    sf::Text player_word;        // 作用于玩家说话的文字
    sf::Clock player_word_clock; // 玩家说话文字的计时器

    int answer = 0;               // 记录走了哪边
    static int statistics_levels; // 统计当前游戏状态，默认时钟指向12

private:
public:
    Scene(GameStateMachine &c_gamestate, Player &c_player) : c_gamestate(c_gamestate),
                                                             c_player(c_player),
                                                             text_desk(typeface.Bold),
                                                             notion_board_text(typeface.Bold),
                                                             mirror_text(typeface.Bold),
                                                             clock_text(typeface.Bold),
                                                             mirror_intext(typeface.Bold),
                                                             player_word(typeface.Regular),
                                                             currentSceneBackground(&c_classroom.background_sprite)
    {
    }
    void classroom_set_first();

    void classroom_background_set();
    void classroom_player_set();
    void classroom_clock_set();
    void switch_ClassroomToCorridor();
    void switch_ClassroomToDesk();
    bool HandleEvent_Classroom_ondesk(const sf::Event::KeyPressed &key);
    bool HandleEvent_Classroom_ondoor(const sf::Event::KeyPressed &key);
    // 判断是否发生交互
    bool isplayerwithclassroom_desk();
    bool isplayerwithclassroom_door();

    void on_classroom_desk();

    void classroom_desk_background_set();
    void classroom_desk_player_reset();
    void switch_DeskToClassroom();
    bool HandleEvent_Classroom_desk_on(const sf::Event::KeyPressed &key);

    void corridor_background_set();
    void corridor_doorleft_set();
    void corridor_doorright_set();
    void corridor_flower_set();
    void corridor_flower_1_set();
    void corridor_flower2_set();
    void corridor_cabinet_set();
    void corridor_cabinet_1_set();
    void corridor_notion_board_set();
    void corridor_clock_set();
    void corridor_toiletman_set();
    void corridor_toiletwoman_set();
    void corridor_exitdoor_set();
    void corridor_player_set_fromstairleft();
    void corridor_player_set_fromstairright();
    void corridor_player_set_fromclassroomleft();
    void corridor_player_set_fromclassroomright();
    void corridor_player_set_fromtoiletman();
    void corridor_player_set_fromtoiletwoman();
    void switch_CorridorToRule();
    void switch_CorridorToClassroom();
    void switch_CorridorToToilet();
    bool HandleEvent_Corridor_ondoorleft(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_ondoorright(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_onnotionboard(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_ontoiletman(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_ontoiletwoman(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_onclock(const sf::Event::KeyPressed &key);
    // 判断是否相交
    bool isplayerwithcorridor_doorleft();
    bool isplayerwithcorridor_doorright();
    bool isplayerwithcorridor_notionboard();
    bool isplayerwithcorridor_toiletman();
    bool isplayerwithcorridor_toiletwoman();
    bool isplayerwithcorridor_stairleft();
    bool isplayerwithcorridor_stairright();
    bool isplayerwithcorridor_exitdoor();
    bool isplayerwithcorridor_flower();
    bool isplayerwithcorridor_flower_1();
    bool isplayerwithcorridor_flower2();
    bool isplayerwithcorridor_cabinet();
    bool isplayerwithcorridor_cabinet_1();
    bool isplayerwithcorridor_clock();

    void on_corridor_notion_board();
    void on_corridor_clock();
    void on_corridor_stair_left();
    void on_corridor_stair_right();
    void on_corridor_exit_door();

    bool HandleEvent_Corridor_stairleft(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_stairright(const sf::Event::KeyPressed &key);
    bool HandleEvent_Corridor_exitdoor(const sf::Event::KeyPressed &key);

    void rule_background_set();
    void rule_player_reset();
    void switch_RuleToCorridor();
    bool HandleEvent_Rule_on(const sf::Event::KeyPressed &key);

    void toilet_background_set();
    void toilet_door_set();
    void toilet_wash_basin_set();
    void toilet_mirror_set();
    void toilet_player_set();
    void switch_ToiletToCorridor();
    void switch_ToiletToMirror();
    bool HandleEvent_Toilet_ondoor(const sf::Event::KeyPressed &key);
    bool HandleEvent_Toilet_onmirror(const sf::Event::KeyPressed &key);

    void on_toilet_mirror();

    void mirror_background_set();
    void mirror_player_reset();
    void mirror_text_set();
    void switch_MirrorToToilet();
    bool HandleEvent_Mirror_on(const sf::Event::KeyPressed &key);

    bool isplayerwithtoiletdoor();
    bool isplayerwithtoiletmirror();
    bool isplayerwithtoiletwashbasin();
    bool isplayerwithtoiletlid();

    void switchscene(SceneState newScene);
    void edge_check_left();
    void edge_check_right();
    void player_text(std::wstring text);
    void player_text_update();

    template <class T>
    bool HandleEvent(const T &) { return false; }

private:
};