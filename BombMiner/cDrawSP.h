#pragma once

#ifndef cDrawSP_h
#define cDrawSP_h

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <list>

static std::list<std::string> str_split(std::string s, char cSplit)
{
	s += cSplit;
	std::string tmp;
	std::list<std::string> array;
	for (char c : s)
	{
		if (c != cSplit)
		{
			tmp += c;
			continue;
		}
		if (tmp.size() > 0)
		{
			array.push_back(tmp);
			tmp = "";
		}
	}

	return array;
}

static void LineFullChar(char c, int nWidth,bool bCenterText=false)
{
	char space = 32;
	if (bCenterText)
	{
		std::cout << space << std::setfill(space) << std::setw(nWidth) << space;
	}
	std::cout << c << std::setfill(c) << std::setw(nWidth) << c << '\n';
}

static void LineWithBorder(std::string sResult, int nWidth, char cBorder = '=',bool bCenterText=false)
{
	int nResultsize = static_cast<int>(sResult.size());
	int nHalf = ((nWidth - nResultsize) / 2);

	//Draw Top Border
	
	//Draw sResult
	for (std::string s : str_split(sResult, '\n'))
	{
		std::cout << cBorder << std::setfill(' ') << std::setw(nHalf) << " " << sResult <<
			std::right << std::setfill(' ') << std::setw(nHalf) << " " << cBorder << "\n";
	}

	//Draw Bottom Border
	std::cout << cBorder << std::setfill(cBorder) << std::setw(nWidth) << cBorder << '\n\n';

}

#endif