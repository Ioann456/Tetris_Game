#pragma once
#include "Engine.h"
#include "GameField.h"
#include "Figure.h"
class Tetris : public Engine
{
private:
	GameField m_GameField;
	Figure* m_Figure;
	Figure* m_NextFigure;
	bool m_End = false;
	size_t m_Score = 0;
	void drawScore(PaintDevice& paintDevice);
public:
	const size_t m_Width = 14;
	const size_t m_Height = 26;
	Tetris();

	bool end() const override { return m_End; } ;
	void on_button_press(const int button) override;
	void update(const int dt) override;
	void render(PaintDevice& paintDevice);

	Figure* Generate(Point);
};

