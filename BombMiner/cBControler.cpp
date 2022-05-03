#include "cBControler.h"

char cLR = '|'; //use Draw in left and right map
#pragma region DrawTitle
void DrawFullLineByChar(char c, int nSize)
{
	std::cout << std::setfill(c) << std::setw(nSize) << c << std::endl;
}

void DrawTitleLine(std::string title, int nMaxSize, char csplit)
{
	int titlesize = static_cast<int>(title.size());
	int nHalf = ((nMaxSize - titlesize) / 2) - 2;
	std::cout << csplit << csplit << std::setfill(' ') << std::setw(nHalf) << " " << title <<
		std::right << std::setfill(' ') << std::setw(nHalf) << " " << csplit << csplit << "\n";
}


void DrawTitle(std::string sTitle, int nmaxWidth)
{
	int titlesize = static_cast<int>(sTitle.size());
	if (nmaxWidth % 2 == 0)
		nmaxWidth++;
	DrawFullLineByChar('=', nmaxWidth);
	DrawTitleLine(" ", nmaxWidth, '|');
	DrawTitleLine("Bomb Game - FoxNQ", nmaxWidth, '|');
	DrawTitleLine(" ", nmaxWidth, '|');
	DrawFullLineByChar('=', nmaxWidth);

}

void DrawTip(std::string sTip, int nmaxWidth)
{
	int titlesize = static_cast<int>(sTip.size());

	DrawFullLineByChar('-', nmaxWidth);
	DrawTitleLine(sTip, nmaxWidth, '|');
	DrawFullLineByChar('-', nmaxWidth);
}
#pragma endregion

#pragma region SubMethods

void Debug()
{
	//std::cout << "in debug";
}



void DrawTip()
{

}

std::vector<Point> BControler::getAroundPoints(int& x, int& y)
{
	std::vector<Point> points;
	return points;
}


bool BControler::Contain(Point& p)
{
	return 0;
}

int BControler::getAroundBomb(int& x, int& y)
{
	return 0;
}

int BControler::getAroundBomb(Point& p)
{
	return 0;
}

BItem* BControler::getItem(int& x, int& y)
{
	if (Contain(x, y))
		return &(Map[x][y]);
	return nullptr;
}

bool BControler::Contain(int& x, int& y)
{
	if (x >= 0 && x < nHeight && y >= 0 && y < nWidth)
		return true;
	return false;
}

#pragma endregion


BControler::BControler(int& width, int& height, int& percentBomb, char& Serect)
{
	if (width <= 0 && height <= 0)
		throw new std::exception("With Height cant less than zero(0)");
	else
		nWidth = width; nHeight = height;

	if (percentBomb < 10)
		throw new std::exception("Are you kidding me?? Percent Bomb is smalless");
	else
		nBomb = (nWidth * nHeight) * percentBomb / 100;
	cSerect = Serect;
	bIsGameOver = true;

}



bool BControler::IsBomb(int& x, int& y)
{
	BItem* ptrItem = getItem(x, y);
	if (ptrItem && (*ptrItem).IsBomb())
		return true;
	return false;
}

void BControler::UpdateUserLoc(int& x, int& y)
{
	if (Contain(x, y) && x != pUserLoc.getX() && y != pUserLoc.getY())
		UpdateUserLoc(x, y);

}

void BControler::CreateMap(int nBomb)
{
	if (Map.size() > 0)
		Map.erase(Map.cbegin(), Map.cend());

	int seed = static_cast<int>(std::time(0));
	bool isrand = false;
	for (int h = 0; h < nHeight; h++)
	{
		Map.emplace_back(std::vector<BItem>());
		for (int w = 0; w < nWidth; w++)
		{
			if (nBomb > 0)
			{

				isrand = static_cast<int>(seed % 2);
				nBomb--;
			}
			else
			{
				isrand = false;
			}
			Map[h].emplace_back(BItem(isrand));
		}
	}
}

void BControler::DrawMap()
{
	if (Map.size() > 0)
	{
		std::string sData;
		int nMapHeight = static_cast<int>(Map.size()), nMapWidth = static_cast<int>(Map[0].size());
		int pX = pUserLoc.getX(), pY = pUserLoc.getY();
		int tmp;
		if (nMapHeight > 0 && nMapWidth > 0)
		{
			for (int h = 0; h < nMapHeight; h++)
			{
				std::cout << cLR;
				for (int w = 0; w < nMapWidth; w++)
				{
					if (Contain(h, w))
					{
						tmp = getItem(h, w)->getBombAround();
						if (tmp ==-1)
						{
							sData = cSerect;
						}
						else
						{
							sData = std::to_string(tmp);
						}
						if (h == pX && w == pY)
						{
							if(w==0)
								sData = " [" + sData + "] ";
							else if (w == nMapWidth - 1)
								sData = "  [" + sData + "] ";
							else
								sData = "  [" + sData + "]  ";
						}
						else
						{
							if (w == 0)
								sData = "  " + sData + "  ";
							else if (w == nMapWidth - 1)
								sData = "  " + sData + " ";
							else
							{
								sData = "  " + sData + "  ";
							}
						}
						std::cout << sData;
					}

				}
				std::cout << cLR << std::endl;
			}
		}
	}
}

void BControler::StartGame()
{
	int nMaxWidth = nWidth * 5 + 2;
	if (nMaxWidth < 50)
		nMaxWidth = 51;
	DrawTitle("Bomb Game by FoxNQ", nMaxWidth);
	CreateMap(nBomb);
	DrawMap();
	DrawTip("Use (W,A,S,D) = Move | Space = Select | E = Exit", nMaxWidth);
	//Debug();
}