#pragma once

#ifndef cBControler_h
#define cBControler_h

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <vector>
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

	int getUserLocX() { return pUserLoc.getX(); }
	int getUserLocY() { return pUserLoc.getY(); }
	bool IsGameOver() { return bIsGameOver; }
	void UpdateUserLoc(int&, int&);


	void StartGame();
	
	//SubMethods

};

#endif

