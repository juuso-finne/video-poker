#pragma once
#include "textSettings.h"

void PrintPayouts(const TextSettings &text_settings);
void PrintTotalBets(const TextSettings &text_settings);
void PrintTotalWins(const TextSettings &text_settings);
void PrintBet(const TextSettings &text_settings);
void DrawTextBox(Vector2 text_position, float text_width, int text_height, float padding);
void PrintTexts();