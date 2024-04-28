#pragma once
#include <vector>
#include "Engine.h"

struct Point
{
	int x;
	int y;
	inline Point(int _x = 0, int _y = 0) : x(_x), y(_y) {};
};

class Figure
{
private:
	Point m_Position;
	double m_TimeFromLastUpdatec = 0;
	double m_TimeForUpdate = 500; //полсекунды
public:
	std::vector<std::vector<Point>> m_Body;
	Point m_PositionBackup;
	size_t m_CurrentRotate = 0;
	size_t m_CurrentRotateBackup = 0;

	Figure(Point position);
	Figure() {};
	void update(double dt);
	void render(PaintDevice& paintDevice);

	inline void move_right() { m_Position.x++; };
	inline void move_left() { m_Position.x--; };

	inline const std::vector<Point>& get_body() const { return m_Body[m_CurrentRotate]; };

	inline Point get_position() const { return m_Position; };
	inline void set_position(Point position) { m_Position = position; };

	inline void backup() { m_PositionBackup = m_Position; m_CurrentRotateBackup = m_CurrentRotate; };
	inline void restore() { m_Position = m_PositionBackup; m_CurrentRotate = m_CurrentRotateBackup; };

	void boost();
	void unboost();

	void rotate();

	//std::vector<std::vector<Point>> Generate();
};

class IBlock : public Figure 
{
public:
	IBlock(Point);
};

class OBlock : public Figure
{
public:
	OBlock(Point);
};

class JBlock : public Figure
{
public:
	JBlock(Point);
};

class LBlock : public Figure
{
public:
	LBlock(Point);
};

class ZBlock : public Figure
{
public:
	ZBlock(Point);
};

class TBlock : public Figure
{
public:
	TBlock(Point);
};

class SBlock : public Figure
{
public:
	SBlock(Point);
};
