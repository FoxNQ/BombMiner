#pragma once

#ifndef cBControler_h
#define cBControler_h

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
#include <random>
#include <ctime>
//Include user Define Class
#include "cPoint.h"
#include "cBItem.h"

class BControler
{
private:
	std::vector<std::vector<BItem> > Map;
	Point pUserLoc;
	bool bIsGameOver;
	int nWidth, nHeight;
	int nBomb;
	char cSerect;

public:
	BControler(int&, int&,int&,char&);


	//SubMethods
	std::vector<Point> getAroundPoints(int&, int&);
	bool Contain(int&, int&);
	bool Contain(Point&);
	int getAroundBomb(int&, int&);
	int getAroundBomb(Point&);
	int getUserLocX() { return pUserLoc.getX(); }
	int getUserLocY() { return pUserLoc.getY(); }

	void setGameOver(bool b) { bIsGameOver = b; };

	void SelectItem(int&, int&);
	BItem* getItem(int&, int&);
	bool IsBomb(int&, int&);
	bool IsGameOver() { return bIsGameOver; }
	bool UpdateUserLoc(int&, int&);

	void CreateMap(int);
	void DrawMap();
	void StartGame();
	void CheckKey();
	void GameOver();
	
	void CheckBonus(int, int);
};

#endif

