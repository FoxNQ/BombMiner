#pragma once

#ifndef cPoint_h
#define cPoint_h

class Point
{
private:
	int x, y;

public:
	Point() { x = y = 0; }
	Point(int X, int Y) { x = X; y = Y; }

	void Update(int& X, int& Y) { x = X; y = Y; }

	int getX() { return x; }

	int getY() { return y; }
};
#endif