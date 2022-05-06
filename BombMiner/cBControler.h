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


};

#endif

