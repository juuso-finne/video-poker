#pragma once
#include <vector>
#include "../../Gui/gui.h"

class GameState{
    public:
        virtual void Init() = 0;

        virtual void Deal();
        virtual void Bet();
        virtual void Hold(int index);
        virtual void CashOut();
        virtual void Double();
        virtual void Small();
        virtual void Big();

        static bool state_changed_;

    protected:
        GameState();
        void ChangeState(GameState *new_state);
        void Reset();
};

class InitialState: public GameState{
    public:
        static InitialState* Instance();
        void Init() override;

        void Deal() override;
        void Bet() override;

    protected:
        InitialState();

    private:
        static InitialState initial_state_;

};

class DrawState: public GameState{
    public:
        static DrawState* Instance();
        void Init() override;

        void Deal() override;
        void Hold(int index) override;

    protected:
       DrawState();

    private:
        static DrawState draw_state_;
};

class WinState: public GameState{
    public:
        static WinState* Instance();
        void Init() override;

        void Double() override;
        void CashOut() override;

    protected:
       WinState();

    private:
        static WinState win_state_;
};

class DoubleState: public GameState{
    public:
        static DoubleState* Instance();
        void Init() override;

        void Small() override;
        void Big() override;

    protected:
        DoubleState();

    private:
        static DoubleState double_state_;
        void Resolve(bool success);
        void ResolveSeven();
        void Win();
        void Lose();
};

class EvaluationState: public GameState{
    public:
        static EvaluationState* Instance();
        void Init() override;

    protected:
       EvaluationState();

    private:
        static EvaluationState evaluation_state_;
};