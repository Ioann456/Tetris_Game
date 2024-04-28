#include "Figure.h"

Figure::Figure(Point position)
{
	m_Position = position;
}

void Figure::update(double dt)
{
	m_TimeFromLastUpdatec += dt;
	if (m_TimeFromLastUpdatec <= m_TimeForUpdate) return;
	m_TimeFromLastUpdatec = 0;

	++m_Position.y;
}

void Figure::render(PaintDevice& paintDevice)
{
	for (const Point& point : m_Body[m_CurrentRotate])
	{
		Vector2 v(point.x + m_Position.x,
			point.y + m_Position.y);
		paintDevice.set_char(v, 0x25D8);
	}
}

void Figure::boost()
{
	m_TimeForUpdate = 50;
}

void Figure::unboost()
{
	m_TimeForUpdate = 500;
}

void Figure::rotate()
{
	m_CurrentRotate++;
	if (m_CurrentRotate >= m_Body.size()) m_CurrentRotate = 0;
}



IBlock::IBlock(Point position) :Figure(position)
{
	m_Body = { { Point(0,0), Point(0,1), Point(0,2), Point(0,3) },
{ Point(0,2), Point(1,2), Point(2,2), Point(3,2) },
{ Point(2,0), Point(2,1), Point(2,2), Point(2,3) },
{ Point(0,1), Point(1,1), Point(2,1), Point(3,1) } };
}


OBlock::OBlock(Point position) : Figure(position)
{
	m_Body = { { Point(0, 0), Point(1, 0), Point(0, 1), Point(1, 1) } };
}


//std::vector<std::vector<Point>> Figure::Generate()
//{
//	switch (rand() % 3) {
//	case 0: return { { Point(1,0), Point(1,1), Point(1,2), Point(1,3) },
//{ Point(0,2), Point(1,2), Point(2,2), Point(3,2) },
//{ Point(2,0), Point(2,1), Point(2,2), Point(2,3) },
//{ Point(0,1), Point(1,1), Point(2,1), Point(3,1) } };
//	{
//	case 1: return { {Point(0, 0), Point(1, 0), Point(1, 1), Point(1, 1)} };
//	}
//	}
//}

JBlock::JBlock(Point position) : Figure(position)
{
	m_Body = { {Point(1, 0), Point(1, 1), Point(1, 2), Point(0, 2)},
		{ Point(0, 0), Point(0, 1), Point(1,1), Point(2,1) },
		{Point(0, 0), Point(1, 0), Point(0, 1), Point(0, 2)},
		{ Point(0, 0), Point(1, 0), Point(2, 0), Point(2, 1) }};
}

LBlock::LBlock(Point position) : Figure(position)
{
	m_Body = { {Point(0, 0), Point(0, 1), Point(0, 2), Point(1, 2)},
		{ Point(0, 0), Point(1, 0), Point(2,0), Point(0,1) },
		{Point(0, 0), Point(1, 0), Point(1, 1), Point(1, 2)},
		{ Point(2, 0), Point(0, 1), Point(1, 1), Point(2, 1) } };
}

ZBlock::ZBlock(Point position) : Figure(position)
{
	m_Body = { {Point(1, 0), Point(1, 1), Point(0, 1), Point(0, 2)},
		{ Point(0, 0), Point(1, 0), Point(2,1), Point(1,1) } };
}

TBlock::TBlock(Point position) : Figure(position)
{
	m_Body = { { Point(0, 1), Point(1, 1), Point(2, 1), Point(1, 0) },
		{Point(0, 0), Point(0, 1), Point(0, 2), Point(1, 1)},
		{Point(0, 0), Point(1, 0), Point(2, 0), Point(1, 1)},
	{ Point(1, 0), Point(1, 1), Point(1, 2), Point(0, 1) } };
}

SBlock::SBlock(Point position) : Figure(position)
{
	m_Body = { {Point(1, 0), Point(2, 0), Point(0, 1), Point(1, 1)},
		{ Point(0, 0), Point(0, 1), Point(1,1), Point(1,2) } };
}
