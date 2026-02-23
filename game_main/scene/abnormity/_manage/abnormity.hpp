/*
 *@文件 ： abnormity.hpp
 *@描述 ： 异常父类实现
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-7
 */
#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Scene;
enum class SceneState;

class Abnormity
{
public:
    Scene *p_s;

public:
    Abnormity(Scene *scene) : p_s(scene) {}
    // 纯虚析构函数
    virtual ~Abnormity() = default;

public:
    // 总设置场景，用于在场景最开始配置场景基本位置（如设置贴图位置）
    virtual void scene_set();
    // 总更新场景，用于在场景每一帧更新时调用
    virtual void scene_update();
    virtual void scene_update(float deltatime);
    // 总绘制场景，用于在场景每一帧绘制时调用，该函数用于绘制角色背后的画面
    virtual void scene_draw(sf::RenderWindow &c_window);
    // 总绘制场景2：绘制可以覆盖角色的画面
    virtual void scene_draw_2(sf::RenderWindow &c_window);
    // 初始教室背景基础设置，包含背景贴图的位置，讲台元素的位置，时钟配置的调用，只在游戏最开始（从桌子醒来）时调用
    virtual void classroom_set_first();
    // 教室背景设置，包含背景贴图的位置，讲台元素的位置，时钟配置的调用（注意额外元素中只有讲台贴图在这里被设置，下面的set函数均会将除背景外的其他set函数单独实现，只在场景set中像这里的时钟一样被调用）
    virtual void classroom_set();
    virtual void classroom_background_set();
    // 进入教室后人物的位置设置，默认位置查询具体实现，面向左边
    virtual void classroom_player_set();
    // 时钟的设置，包含位置
    virtual void classroom_clock_set();
    // 教室背景的更新，更新函数是on开头的，这里只处理讲台文字的更新
    virtual void classroom_update();
    virtual void classroom_update(float deltatime);
    // 教室背景的绘制，背景和时钟在这里被绘制
    virtual void classroom_draw(sf::RenderWindow &c_window);
    // 教室背景的绘制2，讲台和文字在这里被绘制
    virtual void classroom_draw_2(sf::RenderWindow &c_window);
    // 切换场景函数，教室切换到走廊
    virtual void switch_ClassroomToCorridor();
    // 切换场景函数，教室切换到讲台
    virtual void switch_ClassroomToDesk();
    // 处理与讲台交互的事件，默认按下E键交互，交互成功进入讲台场景
    virtual bool HandleEvent_Classroom_ondesk(const sf::Event::KeyPressed &key);
    // 处理与教室门交互的事件，默认按下W键交互，交互成功进入走廊场景
    virtual bool HandleEvent_Classroom_ondoor(const sf::Event::KeyPressed &key);
    virtual bool isplayerwithclassroom_desk();
    virtual bool isplayerwithclassroom_door();
    // 与讲台交互的事件，用于生成交互提示文字
    virtual void on_classroom_desk();
    // 空实现
    virtual void on_classroom_door();
    // 讲台场景的设置，包含背景贴图的位置
    virtual void classroom_desk_set();
    virtual void classroom_desk_background_set();
    // 从讲台场景返回教室场景时人物位置的重置，默认位置是进入讲台场景时的位置
    virtual void classroom_desk_player_reset();
    // 讲台场景的更新，约等于空实现
    virtual void classroom_desk_update();
    virtual void classroom_desk_update(float deltatime);
    // 约等于空实现
    virtual void classroom_desk_draw(sf::RenderWindow &c_window);
    // 绘制背景
    virtual void classroom_desk_draw_2(sf::RenderWindow &c_window);
    // 切换场景函数，讲台切换到教室
    virtual void switch_DeskToClassroom();
    // 处理讲台场景中与讲台交互的事件，默认按下E键交互，交互成功返回教室场景
    virtual bool HandleEvent_Classroom_desk_on(const sf::Event::KeyPressed &key);
    // 空实现
    virtual void on_classroom_desk_text();
    // 下面的set都是元素设置，逻辑同上教室中的命名规则
    virtual void corridor_set();
    virtual void corridor_background_set();
    virtual void corridor_doorleft_set();
    virtual void corridor_doorright_set();
    virtual void corridor_flower_set();
    virtual void corridor_flower_1_set();
    virtual void corridor_flower2_set();
    virtual void corridor_cabinet_set();
    virtual void corridor_cabinet_1_set();
    virtual void corridor_notion_board_set();
    virtual void corridor_clock_set();
    virtual void corridor_toiletman_set();
    virtual void corridor_toiletwoman_set();
    virtual void corridor_exitdoor_set();
    // 下面均在设置人物从不同位置进入走廊时的位置
    virtual void corridor_player_set_fromstairleft();
    virtual void corridor_player_set_fromstairright();
    virtual void corridor_player_set_fromclassroomleft();
    virtual void corridor_player_set_fromclassroomright();
    virtual void corridor_player_set_fromtoiletman();
    virtual void corridor_player_set_fromtoiletwoman();
    // 场景切换
    virtual void switch_CorridorToRule();
    virtual void switch_CorridorToClassroom();
    virtual void switch_CorridorToToilet();
    // 交互处理
    virtual bool HandleEvent_Corridor_ondoorleft(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_ondoorright(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_onnotionboard(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_ontoiletman(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_ontoiletwoman(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_onflower(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_onflower_1(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_onflower2(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_oncabinet(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_oncabinet_1(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_onclock(const sf::Event::KeyPressed &key);
    virtual bool isplayerwithcorridor_doorleft();
    virtual bool isplayerwithcorridor_doorright();
    virtual bool isplayerwithcorridor_notionboard();
    virtual bool isplayerwithcorridor_toiletman();
    virtual bool isplayerwithcorridor_toiletwoman();
    virtual bool isplayerwithcorridor_stairleft();
    virtual bool isplayerwithcorridor_stairright();
    virtual bool isplayerwithcorridor_exitdoor();
    virtual bool isplayerwithcorridor_flower();
    virtual bool isplayerwithcorridor_flower_1();
    virtual bool isplayerwithcorridor_flower2();
    virtual bool isplayerwithcorridor_cabinet();
    virtual bool isplayerwithcorridor_cabinet_1();
    virtual bool isplayerwithcorridor_clock();
    // 与走廊交互的事件，用于生成交互提示文字
    virtual void on_corridor_notion_board();
    // 与走廊交互的事件，用于生成交互提示文字
    virtual void on_corridor_stair_left();
    // 与走廊交互的事件，用于生成交互提示文字
    virtual void on_corridor_stair_right();
    // 与走廊交互的事件，用于生成交互提示文字
    virtual void on_corridor_exit_door();
    // 增加大量空实现
    virtual void on_corridor_flower();
    virtual void on_corridor_flower_1();
    virtual void on_corridor_flower2();
    virtual void on_corridor_cabinet();
    virtual void on_corridor_cabinet_1();
    virtual void on_corridor_toiletman();
    virtual void on_corridor_toiletwoman();
    virtual void on_corridor_door_left();
    virtual void on_corridor_door_right();
    // 获得当前剩余关卡时钟显示
    virtual void on_corridor_clock();
    // 与走廊交互的事件，默认按下W键交互，交互成功更改answer值用于实现楼梯左右选择是否正确
    virtual bool HandleEvent_Corridor_stairleft(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_stairright(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Corridor_exitdoor(const sf::Event::KeyPressed &key);
    // 走廊场景的更新，调用所有on_开头的函数
    virtual void corridor_update();
    virtual void corridor_update(float deltatime);
    virtual void corridor_draw(sf::RenderWindow &c_window);
    virtual void corridor_draw_2(sf::RenderWindow &c_window);
    // 布告牌游戏规则页面的设置
    virtual void rule_set();
    virtual void rule_background_set();
    // 依旧是设置角色回到初始位置
    virtual void rule_player_reset();
    virtual void rule_update();
    virtual void rule_update(float deltatime);
    virtual void rule_draw(sf::RenderWindow &c_window);
    virtual void rule_draw_2(sf::RenderWindow &c_window);
    virtual void switch_RuleToCorridor();
    // 退出布告牌游戏规则页面的事件处理，默认按下E键交互，交互成功返回走廊场景
    virtual bool HandleEvent_Rule_on(const sf::Event::KeyPressed &key);
    virtual void on_rule();
    // 下面是卫生间的设置，命名规则同上
    virtual void toilet_set();
    virtual void toilet_background_set();
    virtual void toilet_door_set();
    virtual void toilet_wash_basin_set();
    virtual void toilet_mirror_set();
    virtual void toilet_player_set();
    virtual void switch_ToiletToCorridor();
    virtual void switch_ToiletToMirror();
    virtual void toilet_update();
    virtual void toilet_update(float deltatime);
    virtual void toilet_draw(sf::RenderWindow &window);
    virtual void toilet_draw_2(sf::RenderWindow &window);
    virtual bool HandleEvent_Toilet_ondoor(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Toilet_onmirror(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Toilet_onwashbasin(const sf::Event::KeyPressed &key);
    virtual bool HandleEvent_Toilet_onlid(const sf::Event::KeyPressed &key);
    virtual void on_toilet_mirror();
    virtual void on_toilet_wash_basin();
    virtual void on_toilet_door();
    virtual void on_toilet_lid();
    // 镜子场景的设置
    virtual void mirror_set();
    virtual void mirror_background_set();
    virtual void mirror_player_reset();
    virtual void mirror_text_set();
    virtual void mirror_update();
    virtual void mirror_update(float deltatime);
    virtual void mirror_draw(sf::RenderWindow &window);
    virtual void mirror_draw_2(sf::RenderWindow &window);
    virtual void switch_MirrorToToilet();
    virtual bool HandleEvent_Mirror_on(const sf::Event::KeyPressed &key);

    bool isplayerwithtoilet_door();
    bool isplayerwithtoilet_mirror();
    bool isplayerwithtoilet_washbasin();
    bool isplayerwithtoilet_lid();
    // 场景切换函数
    virtual void switchscene(SceneState newScene);
    // 左右边缘碰撞检测函数，防止出界
    virtual void edge_check_left();
    virtual void edge_check_right();
    // 用于生成随人物移动的文字信息，如角色说话字幕的实现
    virtual void player_text(std::wstring text);
    virtual void player_text_update();
    // 上述碰撞检测和文字更新函数均在总更新函数中被调用
    // 总的事件处理
    virtual bool HandleEvent(const sf::Event::KeyPressed &key);
    // 垃圾事件处理
    template <class T>
    bool HandleEvent(const T &) { return false; }
};
