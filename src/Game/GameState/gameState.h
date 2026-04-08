#pragma once

class GameState{
    public:
        GameState();
        virtual void DealButtonClick();
        virtual bool DealButtonEnabled();

        virtual bool BetButtonEnabled();
        virtual void BetButtonClick();

        virtual bool HoldButtonEnabled();
        virtual void HoldButtonClick(int index);

        virtual bool CashOutButtonEnabled();
        virtual void CashOutButtonClick();

        virtual bool DoubleButtonEnabled();
        virtual void DoubleButtonClick();

        virtual bool SmallButtonEnabled();
        virtual void SmallButtonClick();

        virtual bool BigButtonEnabled();
        virtual void BigButtonClick();
};

class InitialState: public GameState{
    public:
        bool DealButtonEnabled() override;
        void DealButtonClick() override;

        bool BetButtonEnabled() override;
        void BetButtonClick() override;
};