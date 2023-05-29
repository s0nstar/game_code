#pragma once

class StateComponent
{
public:
    enum class StateType
    {
        IDLE = 0,
        ATTACK,
        HITTED,
        RUN,
        DEAD,
    };

    enum class StateLRUD
    {
        LEFT = 0,
        RIGHT,
        UP,
        DOWN,
    };

    enum class StateONOFF
    {
        ON = 0,
        OFF,
    };

    //StateType
public:
    void SetIdle() { currentState = StateType::IDLE; }
    void SetAttack() { currentState = StateType::ATTACK; }
    void SetHitted() { currentState = StateType::HITTED; }
    void SetRun() { currentState = StateType::RUN; }
    void SetDead() { currentState = StateType::DEAD; }

    bool IsIdle() { return currentState == StateType::IDLE; }
    bool IsAttack() { return currentState == StateType::ATTACK; }
    bool IsHitted() { return currentState == StateType::HITTED; }
    bool IsRun() { return currentState == StateType::RUN; }
    bool IsDead() { return currentState == StateType::DEAD; }

    //StateLR
public:
    void SetLeft() { currentLRUD = StateLRUD::LEFT; }
    void SetRight() { currentLRUD = StateLRUD::RIGHT; }
    void SetUp() { currentLRUD = StateLRUD::UP; }
    void SetDown() { currentLRUD = StateLRUD::DOWN; }

    bool IsLeft() { return currentLRUD == StateLRUD::LEFT; }
    bool IsRight() { return currentLRUD == StateLRUD::RIGHT; }
    bool IsUp() { return currentLRUD == StateLRUD::UP; }
    bool IsDown() { return currentLRUD == StateLRUD::DOWN; }

    //StateONOFF
public:
    void SetOn() { currentOnOff = StateONOFF::ON; }
    void SetOff() { currentOnOff = StateONOFF::OFF; }

    bool IsOn() { return currentOnOff == StateONOFF::ON; }
    bool IsOff() { return currentOnOff == StateONOFF::OFF; }

private:
    StateType currentState = StateType::IDLE;
    StateLRUD currentLRUD = StateLRUD::RIGHT;
    StateONOFF currentOnOff = StateONOFF::OFF;

};