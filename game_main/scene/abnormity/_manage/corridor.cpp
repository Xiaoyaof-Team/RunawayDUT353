/*
 *@文件 ： corridor.cpp
 *@描述 ： 异常父类走廊的默认设置
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-10
 */
#include "abnormity.hpp"
#include "scene.hpp"

void Abnormity::corridor_set()
{
    corridor_background_set();
    corridor_doorleft_set();
    corridor_doorright_set();
    corridor_flower_set();
    corridor_flower_1_set();
    corridor_flower2_set();
    corridor_cabinet_set();
    corridor_cabinet_1_set();
    corridor_notion_board_set();
    corridor_clock_set();
    corridor_toiletman_set();
    corridor_toiletwoman_set();
    corridor_exitdoor_set();
}
void Abnormity::corridor_background_set() { p_s->corridor_background_set(); }
void Abnormity::corridor_doorleft_set() { p_s->corridor_doorleft_set(); }
void Abnormity::corridor_doorright_set() { p_s->corridor_doorright_set(); }
void Abnormity::corridor_flower_set() { p_s->corridor_flower_set(); }
void Abnormity::corridor_flower_1_set() { p_s->corridor_flower_1_set(); }
void Abnormity::corridor_flower2_set() { p_s->corridor_flower2_set(); }
void Abnormity::corridor_cabinet_set() { p_s->corridor_cabinet_set(); }
void Abnormity::corridor_cabinet_1_set() { p_s->corridor_cabinet_1_set(); }
void Abnormity::corridor_notion_board_set() { p_s->corridor_notion_board_set(); }
void Abnormity::corridor_clock_set() { p_s->corridor_clock_set(); }
void Abnormity::corridor_toiletman_set() { p_s->corridor_toiletman_set(); }
void Abnormity::corridor_toiletwoman_set() { p_s->corridor_toiletwoman_set(); }
void Abnormity::corridor_exitdoor_set() { p_s->corridor_exitdoor_set(); }
void Abnormity::corridor_player_set_fromstairleft() { p_s->corridor_player_set_fromstairleft(); }
void Abnormity::corridor_player_set_fromstairright() { p_s->corridor_player_set_fromstairright(); }
void Abnormity::corridor_player_set_fromclassroomleft() { p_s->corridor_player_set_fromclassroomleft(); }
void Abnormity::corridor_player_set_fromclassroomright() { p_s->corridor_player_set_fromclassroomright(); }
void Abnormity::corridor_player_set_fromtoiletman() { p_s->corridor_player_set_fromtoiletman(); }
void Abnormity::corridor_player_set_fromtoiletwoman() { p_s->corridor_player_set_fromtoiletwoman(); }

void Abnormity::switch_CorridorToRule()
{
    p_s->switch_CorridorToRule();
    this->scene_set();
}
void Abnormity::switch_CorridorToClassroom()
{
    p_s->switch_CorridorToClassroom();
    this->scene_set();
}
void Abnormity::switch_CorridorToToilet()
{
    p_s->switch_CorridorToToilet();
    this->scene_set();
}
bool Abnormity::HandleEvent_Corridor_ondoorleft(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Corridor_ondoorleft(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
bool Abnormity::HandleEvent_Corridor_ondoorright(const sf::Event::KeyPressed &key) { return p_s->HandleEvent_Corridor_ondoorright(key); }
bool Abnormity::HandleEvent_Corridor_onnotionboard(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Corridor_onnotionboard(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
bool Abnormity::HandleEvent_Corridor_ontoiletman(const sf::Event::KeyPressed &key) { return p_s->HandleEvent_Corridor_ontoiletman(key); }
bool Abnormity::HandleEvent_Corridor_ontoiletwoman(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Corridor_ontoiletwoman(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
void Abnormity::on_corridor_notion_board() { p_s->on_corridor_notion_board(); }
void Abnormity::on_corridor_stair_left() { p_s->on_corridor_stair_left(); }
void Abnormity::on_corridor_stair_right() { p_s->on_corridor_stair_right(); }
void Abnormity::on_corridor_exit_door() { p_s->on_corridor_exit_door(); }
void Abnormity::on_corridor_flower()
{
    // 空实现
}
void Abnormity::on_corridor_flower_1()
{
    // 空实现
}
void Abnormity::on_corridor_flower2()
{
    // 空实现
}
void Abnormity::on_corridor_cabinet()
{
    // 空实现
}
void Abnormity::on_corridor_cabinet_1()
{
    // 空实现
}
void Abnormity::on_corridor_toiletman()
{
    // 空实现
}
void Abnormity::on_corridor_toiletwoman()
{
    // 空实现
}
void Abnormity::on_corridor_door_left()
{
    // 空实现
}
void Abnormity::on_corridor_door_right()
{
    // 空实现
}
void Abnormity::on_corridor_clock()
{
    p_s->on_corridor_clock();
}
bool Abnormity::HandleEvent_Corridor_stairleft(const sf::Event::KeyPressed &key) { return p_s->HandleEvent_Corridor_stairleft(key); }
bool Abnormity::HandleEvent_Corridor_stairright(const sf::Event::KeyPressed &key) { return p_s->HandleEvent_Corridor_stairright(key); }
bool Abnormity::HandleEvent_Corridor_exitdoor(const sf::Event::KeyPressed &key) { return p_s->HandleEvent_Corridor_exitdoor(key); }
bool Abnormity::HandleEvent_Corridor_onflower(const sf::Event::KeyPressed &key)
{
    // 空实现
    return false;
}
bool Abnormity::HandleEvent_Corridor_onflower_1(const sf::Event::KeyPressed &key)
{
    // 空实现
    return false;
}
bool Abnormity::HandleEvent_Corridor_onflower2(const sf::Event::KeyPressed &key)
{
    // 空实现
    return false;
}
bool Abnormity::HandleEvent_Corridor_oncabinet(const sf::Event::KeyPressed &key)
{
    // 空实现
    return false;
}
bool Abnormity::HandleEvent_Corridor_oncabinet_1(const sf::Event::KeyPressed &key)
{
    // 空实现
    return false;
}
bool Abnormity::HandleEvent_Corridor_onclock(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Corridor_onclock(key))
    {
        return true;
    }
    return false;
}
void Abnormity::corridor_update()
{
    on_corridor_notion_board();
    on_corridor_stair_left();
    on_corridor_stair_right();
    on_corridor_flower();
    on_corridor_flower_1();
    on_corridor_flower2();
    on_corridor_cabinet();
    on_corridor_cabinet_1();
    on_corridor_toiletman();
    on_corridor_toiletwoman();
    on_corridor_door_left();
    on_corridor_door_right();
    on_corridor_clock();
    on_corridor_exit_door();
}
void Abnormity::corridor_draw(sf::RenderWindow &c_window)
{
    c_window.draw(p_s->c_corridor.background_sprite);
    c_window.draw(p_s->c_corridor.door_left_sprite);
    c_window.draw(p_s->c_corridor.door_right_sprite);
    c_window.draw(p_s->c_corridor.clock_sprite);
    c_window.draw(p_s->c_corridor.notion_board_sprite);
    c_window.draw(p_s->c_corridor.flower_sprite);
    c_window.draw(p_s->c_corridor.flower_1_sprite);
    c_window.draw(p_s->c_corridor.flower2_sprite);
    c_window.draw(p_s->c_corridor.cabinet_sprite);
    c_window.draw(p_s->c_corridor.cabinet_1_sprite);
    c_window.draw(p_s->c_corridor.toiletman_sprite);
    c_window.draw(p_s->c_corridor.toiletwoman_sprite);
    c_window.draw(p_s->c_corridor.exitdoor_sprite);
    c_window.draw(p_s->notion_board_text);
    c_window.draw(p_s->clock_text);
}
void Abnormity::corridor_draw_2(sf::RenderWindow &c_window)
{
    // 空实现
}

bool Abnormity::isplayerwithcorridor_doorleft() { return p_s->isplayerwithcorridor_doorleft(); }
bool Abnormity::isplayerwithcorridor_doorright() { return p_s->isplayerwithcorridor_doorright(); }
bool Abnormity::isplayerwithcorridor_stairleft() { return p_s->isplayerwithcorridor_stairleft(); }
bool Abnormity::isplayerwithcorridor_stairright() { return p_s->isplayerwithcorridor_stairright(); }
bool Abnormity::isplayerwithcorridor_exitdoor() { return p_s->isplayerwithcorridor_exitdoor(); }
bool Abnormity::isplayerwithcorridor_notionboard() { return p_s->isplayerwithcorridor_notionboard(); }
bool Abnormity::isplayerwithcorridor_toiletman() { return p_s->isplayerwithcorridor_toiletman(); }
bool Abnormity::isplayerwithcorridor_toiletwoman() { return p_s->isplayerwithcorridor_toiletwoman(); }
bool Abnormity::isplayerwithcorridor_clock() { return p_s->isplayerwithcorridor_clock(); }
bool Abnormity::isplayerwithcorridor_flower() { return p_s->isplayerwithcorridor_flower(); }
bool Abnormity::isplayerwithcorridor_flower_1() { return p_s->isplayerwithcorridor_flower_1(); }
bool Abnormity::isplayerwithcorridor_flower2() { return p_s->isplayerwithcorridor_flower2(); }
bool Abnormity::isplayerwithcorridor_cabinet() { return p_s->isplayerwithcorridor_cabinet(); }
bool Abnormity::isplayerwithcorridor_cabinet_1() { return p_s->isplayerwithcorridor_cabinet_1(); }
