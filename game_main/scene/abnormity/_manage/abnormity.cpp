/*
 *@文件 ： abnormity.cpp
 *@描述 ： 异常父类主要控制逻辑的默认设置
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-10
 */
#include "abnormity.hpp"
#include "scene.hpp"

void Abnormity::scene_set()
{
    switch (p_s->currentSceneState)
    {
    case SceneState::Classroom:
        classroom_set();
        break;
    case SceneState::Classroom_desk:
        classroom_desk_set();
        break;
    case SceneState::Corridor:
        corridor_set();
        break;
    case SceneState::Toilet:
        toilet_set();
        break;
    case SceneState::Rule:
        rule_set();
        break;
    case SceneState::Mirror:
        mirror_set();
        break;
    default:
        break;
    }
}

void Abnormity::scene_update()
{
    switch (p_s->currentSceneState)
    {
    case SceneState::Classroom:
        classroom_update();
        break;
    case SceneState::Classroom_desk:
        classroom_desk_update();
        break;
    case SceneState::Corridor:
        corridor_update();
        break;
    case SceneState::Toilet:
        toilet_update();
        break;
    case SceneState::Rule:
        rule_update();
        break;
    case SceneState::Mirror:
        mirror_update();
        break;
    default:
        break;
    }
    edge_check_left();
    edge_check_right();
    player_text_update();
}

void Abnormity::scene_update(float deltatime)
{
    switch (p_s->currentSceneState)
    {
    case SceneState::Classroom:
        classroom_update(deltatime);
        break;
    case SceneState::Classroom_desk:
        classroom_desk_update(deltatime);
        break;
    case SceneState::Corridor:
        corridor_update(deltatime);
        break;
    case SceneState::Toilet:
        toilet_update(deltatime);
        break;
    case SceneState::Rule:
        rule_update(deltatime);
        break;
    case SceneState::Mirror:
        mirror_update(deltatime);
        break;
    default:
        break;
    }
}

void Abnormity::scene_draw(sf::RenderWindow &c_window)
{
    switch (p_s->currentSceneState)
    {
    case SceneState::Classroom:
        classroom_draw(c_window);
        break;
    case SceneState::Classroom_desk:
        classroom_desk_draw(c_window);
        break;
    case SceneState::Corridor:
        corridor_draw(c_window);
        break;
    case SceneState::Toilet:
        toilet_draw(c_window);
        break;
    case SceneState::Rule:
        rule_draw(c_window);
        break;
    case SceneState::Mirror:
        mirror_draw(c_window);
        break;
    default:
        break;
    }
}

void Abnormity::scene_draw_2(sf::RenderWindow &c_window)
{
    switch (p_s->currentSceneState)
    {
    case SceneState::Classroom:
        classroom_draw_2(c_window);
        break;
    case SceneState::Classroom_desk:
        classroom_desk_draw_2(c_window);
        break;
    case SceneState::Corridor:
        corridor_draw_2(c_window);
        break;
    case SceneState::Toilet:
        toilet_draw_2(c_window);
        break;
    case SceneState::Rule:
        rule_draw_2(c_window);
        break;
    case SceneState::Mirror:
        mirror_draw_2(c_window);
        break;
    default:
        break;
    }
    c_window.draw(p_s->player_word);
}

bool Abnormity::HandleEvent(const sf::Event::KeyPressed &key)
{
    switch (p_s->currentSceneState)
    {
    case SceneState::Classroom:
        if (isplayerwithclassroom_desk() && HandleEvent_Classroom_ondesk(key))
            return true;
        if (isplayerwithclassroom_door() && HandleEvent_Classroom_ondoor(key))
            return true;
        break;
    case SceneState::Classroom_desk:
        if (HandleEvent_Classroom_desk_on(key))
            return true;
        break;
    case SceneState::Corridor:
        if (isplayerwithcorridor_doorleft() && HandleEvent_Corridor_ondoorleft(key))
            return true;
        if (isplayerwithcorridor_doorright() && HandleEvent_Corridor_ondoorright(key))
            return true;
        if (isplayerwithcorridor_notionboard() && HandleEvent_Corridor_onnotionboard(key))
            return true;
        if (isplayerwithcorridor_toiletman() && HandleEvent_Corridor_ontoiletman(key))
            return true;
        if (isplayerwithcorridor_toiletwoman() && HandleEvent_Corridor_ontoiletwoman(key))
            return true;
        if (isplayerwithcorridor_stairleft() && HandleEvent_Corridor_stairleft(key))
            return true;
        if (isplayerwithcorridor_stairright() && HandleEvent_Corridor_stairright(key))
            return true;
        if (isplayerwithcorridor_exitdoor() && HandleEvent_Corridor_exitdoor(key))
            return true;
        if (isplayerwithcorridor_flower() && HandleEvent_Corridor_onflower(key))
            return true;
        if (isplayerwithcorridor_flower_1() && HandleEvent_Corridor_onflower_1(key))
            return true;
        if (isplayerwithcorridor_flower2() && HandleEvent_Corridor_onflower2(key))
            return true;
        if (isplayerwithcorridor_cabinet() && HandleEvent_Corridor_oncabinet(key))
            return true;
        if (isplayerwithcorridor_cabinet_1() && HandleEvent_Corridor_oncabinet_1(key))
            return true;
        if (isplayerwithcorridor_clock() && HandleEvent_Corridor_onclock(key))
            return true;
        break;
    case SceneState::Toilet:
        if (isplayerwithtoilet_door() && HandleEvent_Toilet_ondoor(key))
            return true;
        if (isplayerwithtoilet_mirror() && HandleEvent_Toilet_onmirror(key))
            return true;
        if (isplayerwithtoilet_washbasin() && HandleEvent_Toilet_onwashbasin(key))
            return true;
        if (isplayerwithtoilet_lid() && HandleEvent_Toilet_onlid(key))
            return true;
        break;
    case SceneState::Rule:
        if (HandleEvent_Rule_on(key))
            return true;
        break;
    case SceneState::Mirror:
        if (HandleEvent_Mirror_on(key))
            return true;
        break;
    default:
        break;
    }
    return false;
}

void Abnormity::switchscene(SceneState newScene)
{
    p_s->switchscene(newScene);
    this->scene_set();
}
void Abnormity::edge_check_left() { p_s->edge_check_left(); }
void Abnormity::edge_check_right() { p_s->edge_check_right(); }
void Abnormity::player_text(std::wstring text) { p_s->player_text(text); }
void Abnormity::player_text_update() { p_s->player_text_update(); }
