#include "Tetris.h"
#include <string>

Tetris::Tetris()
{
	m_Figure = Generate(Point(5, 1));
	m_NextFigure = Generate(Point(16, 1));
	paint_device().resize(Size(m_Width + 7, m_Height));
	m_GameField.resize(m_Width, m_Height);
	track_key(VK_LEFT);
	track_key(VK_RIGHT);
	track_key(VK_DOWN);
	track_key(VK_UP);
	track_key(VK_SPACE);
}

void Tetris::on_button_press(const int button)
{
	m_Figure->backup();
	switch (button)
	{
	case VK_LEFT:
		m_Figure->move_left();
		break;
	case VK_RIGHT:
		m_Figure->move_right();
		break;
	case VK_DOWN:
		m_Figure->boost();
		break;
	case VK_UP:
		m_Figure->unboost();
		break;
	case VK_SPACE:
		m_Figure->rotate();
		break;
	}
	if (m_GameField.has_collision(*m_Figure))
		m_Figure->restore();
}

void Tetris::update(const int dt)
{
	m_Figure->backup();
	m_Figure->update(dt);
	if (m_GameField.has_collision(*m_Figure))
	{
		m_Figure->restore();
		m_Score += m_GameField.merge(*m_Figure);
		if (m_Score > 999999) m_Score = 0;
		m_Figure = m_NextFigure;
		m_Figure->set_position(Point(5, 1));
		m_NextFigure = Generate(Point(16, 1));
		if (m_GameField.has_collision(*m_Figure))
			m_End = true;
	}
	drawScore(paint_device());
}

void Tetris::render(PaintDevice& paintDevice)
{
	m_GameField.render(paintDevice);
	m_Figure->render(paintDevice);
	m_NextFigure->render(paintDevice);
	drawScore(paintDevice);
}

void Tetris::drawScore(PaintDevice& paintDevice)
{
	std::string score = std::to_string(m_Score);
	Vector2 v1(14, 7);
	paintDevice.set_char(v1, 'S');
	Vector2 v2(15, 7);
	paintDevice.set_char(v2, 'C');
	Vector2 v3(16, 7);
	paintDevice.set_char(v3, 'O');
	Vector2 v4(17, 7);
	paintDevice.set_char(v4, 'R');
	Vector2 v5(18, 7);
	paintDevice.set_char(v5, 'E');
	Vector2 v6(19, 7);
	paintDevice.set_char(v6, ':');
	for (int i = 0; i < score.size(); i++) {
		Vector2 v7(14 + i, 8);
		paintDevice.set_char(v7, score[i]);
	}
}


Figure* Tetris::Generate(Point position)
{
	switch (rand() % 7) {
	case 0: return new IBlock(Point(position));
	case 1: return new OBlock(Point(position));
	case 2: return new JBlock(Point(position));
	case 3: return new LBlock(Point(position));
	case 4: return new ZBlock(Point(position));
	case 5: return new SBlock(Point(position));
	case 6: return new TBlock(Point(position));
	}
}