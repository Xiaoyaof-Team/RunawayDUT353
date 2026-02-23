/*
    小恐龙大魔王彩蛋异常！
*/
#pragma once
#include "abnormity.hpp"
#include <string>
#include <vector>
#include <memory>
#include "SFML/Audio.hpp"
#include "Scene.hpp"

class sEvil_Dragon : public Abnormity
{
public:
    // 异常状态机，用于检测事件是否发生
    bool isPlayerWithsEvil_Dragon_mirror_1 = false;
    bool isPlayerWithsEvil_Dragon_mirror_2 = false;
    bool isPlayerWithsEvil_Dragon_mirror_3 = false;
    bool isPlayerWithsEvil_Dragon_mirror_4 = false;
    bool isPlayerWithsMonster_1 = false; // 怪物是否出现
    bool isPlayerWithsMonster_2 = false; // 怪物是否结束
    bool isDoorLocked = false;           // 是否触发过门上锁事件
    bool isPlayercanEscape = false;      // 玩家是否满足离开条件

public:
    sf::Texture sEvil_dragon_texture;
    sf::Sprite sEvil_dragon_sprite;
    sf::Text sEvil_dragon_text;
    float sEvil_dragon_text_timer = 0.f;                  // 文字显示计时器
    int sEvil_dragon_text_index = 0;                      // 当前显示的文字索引
    bool sEvil_dragon_text_finished = false;              // 文字是否全部显示完毕
    bool is_sEvil_dragon_text_animating = false;          // 是否正在进行文字动画
    std::vector<std::wstring> sEvil_dragon_dialogues_1 = {// 第一次事件的对话
                                                          // 添加对话
                                                          L"你终于来了！！！",
                                                          L"我等了你很久了！！！",
                                                          L"虽然等了很久是以为我特意把这个异常藏的很深",
                                                          L"概率很小才能出现",
                                                          L"嗯，是的",
                                                          L"我就是小恐龙大魔王！！！",
                                                          L"什么？你问我为什么只有一个头像？",
                                                          L"我也想要立绘哇！！！",
                                                          L"但是AI真的很不给力哇！",
                                                          L"你看看这个破厕所，",
                                                          L"我说这厕所本身就像个异常",
                                                          L"不过没关系！",
                                                          L"你想想，如果我有立绘",
                                                          L"那不就变成旮旯干木了嘛~多不好~",
                                                          L"什么？你说没有追击不够刺激？",
                                                          L"哼！",
                                                          L"这就给你安排！！！！",
                                                          // 最后添加一个特殊的对话，用于防止指针越界
                                                          L"小恐龙大魔王是最棒的！"};
    std::vector<std::wstring> sEvil_dragon_dialogues_2 = {// 被抓住的时候的对话
                                                          // 添加对话
                                                          L"啧啧啧啧啧~",
                                                          L"菜！",
                                                          L"还好我好心没直接让你Game Over！",
                                                          L"什么？你说是我懒得加逻辑了？",
                                                          L"虽然是这样~吧，",
                                                          L"两边楼梯都可以通向下一层~去吧！",
                                                          // 最后添加一个特殊的对话，用于防止指针越界
                                                          L"小恐龙大魔王是最棒的！"};
    std::vector<std::wstring> sEvil_dragon_dialogues_3 = {// 逃离怪物追击后的对话
                                                          // 添加对话
                                                          L"？？？？？",
                                                          L"你为什么知道厕所是安全的？？",
                                                          L"你说我的怪物连贴图都没有，一定蠢的不得了？？",
                                                          L"你以为异形隔离呢？？",
                                                          L"我哪有时间写那么智能的AI，，，",
                                                          L"什么？？你说这没意思？？",
                                                          L"好吧！",
                                                          L"你等着！！！",
                                                          // 最后添加一个特殊的对话，用于防止指针越界
                                                          L"小恐龙大魔王是最棒的！"};
    std::vector<std::wstring> sEvil_dragon_dialogues_4 = {// 逃离怪物追击后的对话
                                                          // 添加对话
                                                          L"你以为这样就完了？？",
                                                          L"你以为我会放过你吗？？",
                                                          L"你以为我没有后续事件了吗？？",
                                                          L"你以为我会让你轻易离开吗？？",
                                                          L"哼！",
                                                          L"其实还真是",
                                                          L"因为实在不想再写后面解码的代码了",
                                                          L"所以就直接放了个彩蛋事件在这里了！",
                                                          L"你走吧~",
                                                          L"两边都可以下楼梯哦~",
                                                          // 最后添加一个特殊的对话，用于防止指针越界
                                                          L"小恐龙大魔王是最棒的！"};
    std::unique_ptr<std::wstring> dialogues_ptr = nullptr;   // 指向目前的对话
    std::unique_ptr<std::wstring> dialogues_ptr_2 = nullptr; // 指向第二个事件的对话
    std::unique_ptr<std::wstring> dialogues_ptr_3 = nullptr; // 指向第三个事件的对话
    std::unique_ptr<std::wstring> dialogues_ptr_4 = nullptr; // 指向第四个事件的对话
    int current_dialogue_index = 0;                          // 当前对话索引
    // 字体出现音效
    sf::SoundBuffer fontfBuffer;
    sf::Sound fontfSound;
    float sprite_animation_timer = 0.f;      // 头像动画计时器
    float sprite_animation_timer_fade = 0.f; // 头像渐渐出现动画

    sf::Texture monster_texture;
    sf::Sprite monster_sprite;
    float monster_appear_timer = 0.f; // 怪物出现计时器,用于实时刷新怪物位置

private:
public:
    using Abnormity::HandleEvent;
    sEvil_Dragon(Scene *scene) : Abnormity(scene),
                                 sEvil_dragon_texture("game_main/scene/abnormity/2.sEvil_Dragon!!!/picture/sEvil_Dragon.png"),
                                 sEvil_dragon_sprite(sEvil_dragon_texture),
                                 sEvil_dragon_text(typeface.Bold),
                                 fontfBuffer("game_main/scene/abnormity/2.sEvil_Dragon!!!/music/font_f.mp3"),
                                 fontfSound(fontfBuffer),
                                 monster_texture("game_main/scene/abnormity/2.sEvil_Dragon!!!/picture/monster.png"),
                                 monster_sprite(monster_texture)
    {
        current_dialogue_index = 0;
        dialogues_ptr = std::make_unique<std::wstring>(sEvil_dragon_dialogues_1[0]);
        dialogues_ptr_2 = std::make_unique<std::wstring>(sEvil_dragon_dialogues_2[0]);
        dialogues_ptr_3 = std::make_unique<std::wstring>(sEvil_dragon_dialogues_3[0]);
        dialogues_ptr_4 = std::make_unique<std::wstring>(sEvil_dragon_dialogues_4[0]);
        sEvil_dragon_text.setString(L"");

        // 设置怪物大小
        monster_sprite.setScale({0.5f, 0.5f});
        // 设置中心
        monster_sprite.setOrigin(monster_sprite.getLocalBounds().size / 2.f);
    }

private:
public:
    // 添加文字动效
    void sEvil_Dragon_AnimateText(const std::wstring &newString, float deltatime, sf::Vector2f position, float displayDuration = 0.08f, int size = 40, sf::Color color = sf::Color::White);
    // 清空动画
    void sEvil_Dragon_ResetTextAnimation();
    bool HandleEvent_Mirror_on(const sf::Event::KeyPressed &key) override;
    bool HandleEvent_Mirror_1(const sf::Event::KeyPressed &key);
    // 为第一个事件重写更新和刷新函数
    void mirror_update(float deltatime) override;
    void mirror_draw_2(sf::RenderWindow &window) override;
    // 添加头像动效和定位
    void sEvil_Dragon_AnimateSprite(float deltatime);
    // 重写走廊更新函数，以方便怪物出现
    void corridor_update(float deltatime) override;
    // 重写与左边门交互的事件函数，已开始怪物追击
    bool HandleEvent_Corridor_ondoorleft(const sf::Event::KeyPressed &key) override;
    // 重写走廊刷新二号函数，刷新怪物位置
    void corridor_draw_2(sf::RenderWindow &window) override;
    // 重写进厕所事件函数，结束怪物追击
    bool HandleEvent_Corridor_ontoiletwoman(const sf::Event::KeyPressed &key) override;
    bool HandleEvent_Mirror_2(const sf::Event::KeyPressed &key);
    bool HandleEvent_Mirror_3(const sf::Event::KeyPressed &key);
    // 处理走廊事件，让两边走廊都可以下去但是需要特定条件
    bool HandleEvent_Corridor_stairleft(const sf::Event::KeyPressed &key) override;
    bool HandleEvent_Corridor_stairright(const sf::Event::KeyPressed &key) override;
    // 重写逃离怪物后，门上锁事件
    bool HandleEvent_Toilet_ondoor(const sf::Event::KeyPressed &key) override;
    bool HandleEvent_Mirror_4(const sf::Event::KeyPressed &key);
    void on_corridor_stair_left() override;
    void on_corridor_stair_right() override;
};