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
	DrawTitleLine(sTitle, nmaxWidth, '|');
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

void ClearScreen()
{
	system("CLS");
	std::cin.clear();
	fflush(stdin);
}

void ExitApp()
{
	int nwidth = 40, key = 0;
	ClearScreen();
	DrawTitle("Do You Really Want Exit?", nwidth);
	DrawTip(" Y:Yes | N: No", nwidth);
}

void Debug()
{
	//std::cout << "in debug";
}



std::vector<Point> BControler::getAroundPoints(int& x, int& y)
{
	int pX = 0, pY = 0;
	std::vector<Point> Points;
	std::vector<Point> templates{ Point(x - 1, y), Point(x - 1 , y + 1), Point(x , y + 1), Point(x + 1, y + 1), Point(x + 1, y), Point(x + 1, y - 1), Point(x, y - 1), Point(x - 1, y - 1) };
	for (Point p : templates)
	{
		if (Contain(p))
			Points.emplace_back(p);
	}
	return Points;
}

bool BControler::Contain(int& x, int& y)
{
	if (x >= 0 && x < nHeight && y >= 0 && y < nWidth)
		return true;
	return false;
}

bool BControler::Contain(Point& p)
{
	if (p.getX() >= 0 && p.getX() < nHeight && p.getY() >= 0 && p.getY() < nWidth)
		return true;
	return false;
}

int BControler::getAroundBomb(int& x, int& y)
{
	int nBombAround = 0;
	BItem* item;
	std::vector<Point> AroundPoints = getAroundPoints(x, y);
	for (Point ptmp : AroundPoints)
	{
		item = getItem(x, y);
		if (item&&item->IsBomb())
			nBombAround++;
	}
	return nBombAround;
}

void BControler::CheckBonus(int x, int y)
{
	if (Contain(x, y))
	{
		int pX, pY = 0;
		BItem* itemptr;
		std::vector<Point> AroundPoints = getAroundPoints(x, y);
		for (Point p : AroundPoints)
		{
			pX = p.getX(); pY = p.getY();
			if (Contain(pX, pY))
			{
				itemptr = getItem(pX, pY);
				if (!(itemptr->IsSelected()) && itemptr && !(itemptr->IsBomb()))
				{
					SelectItem(pX, pY);
				}
			}
		}
	}
}


int BControler::getAroundBomb(Point& p)
{
	int nBombAround = 0;
	int pX = p.getX(), pY = p.getY();
	BItem* itemPtr;
	std::vector<Point> AroundPoints = getAroundPoints(pX, pY);
	for (Point ptmp : AroundPoints)
	{
		pX = ptmp.getX(); pY = ptmp.getY();
		itemPtr = getItem(pX, pY);
		if (itemPtr&&itemPtr->IsBomb())
				nBombAround++;
	}
	return nBombAround;
}

void BControler::SelectItem(int& x, int& y)
{
	BItem* item = getItem(x, y);
	if (item && !item->IsSelected())
	{
		if (item->Select())
		{
			GameOver();
		}
		else
		{
			int BombAround = getAroundBomb(x, y);
			item->setBombAround(BombAround);
			if (BombAround == 0)
			{
				CheckBonus(x, y);
			}
			else
			{
				DrawMap();
			}
		}

	}
}

BItem* BControler::getItem(int& x, int& y)
{
	if (Contain(x, y))
		return &(Map[x][y]);
	return nullptr;
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

bool BControler::UpdateUserLoc(int& x, int& y)
{
	if (Contain(x, y) && (x != pUserLoc.getX() || y != pUserLoc.getY()))
	{
		pUserLoc.Update(x, y);
		return true;
	}
	return false;
}

void BControler::CreateMap(int nBomb)
{

	bool isrand = false;
	if (Map.size() > 0)
		Map.erase(Map.begin(), Map.end());

	Map.assign(nHeight, std::vector<BItem>());
	for (int w = 0; w < nWidth; w++)
	{
		Map[w].assign(nHeight, BItem(isrand));
	}

	for (int i = 0; i < nBomb; i++)
	{
		Map.emplace_back();
		
	}
}

void BControler::DrawMap()
{
	ClearScreen();
	int nMaxWidth = nWidth * 5 + 2;
	if (nMaxWidth < 50)
		nMaxWidth = 51;
	DrawTitle("Bomb Game by FoxNQ", nMaxWidth);
	if (Map.size() > 0 && !IsGameOver())
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
						if (tmp == -1)
						{
							sData = cSerect;
						}
						else
						{
							sData = std::to_string(tmp);
						}
						if (h == pX && w == pY)
						{
							if (w == 0)
								sData = " [" + sData + "] ";
							else if (w == nMapWidth - 1)
								sData = " [" + sData + "] ";
							else
								sData = " [" + sData + "] ";
						}
						else
						{
							if (w == 0)
								sData = "  " + sData + "  ";
							else if (w == nMapWidth - 1)
								sData = "  " + sData + "  ";
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
	DrawTip("Use (W,A,S,D) = Move | Space = Select | E = Exit", nMaxWidth);
}

void BControler::StartGame()
{
	setGameOver(false);
	CreateMap(nBomb);
	DrawMap();
	CheckKey();
	//Debug();
}

void BControler::CheckKey()
{
	bool bexiting = false;
	int pX = 0, pY = 0, ntemp = 0;
	while (true)
	{
		if (GetAsyncKeyState('Y')&&bexiting)
		{
			exit(0);
			break;
		}
		else if(GetAsyncKeyState('N') && bexiting)
		{
			bexiting = false;
			DrawMap();
		}
		if (GetAsyncKeyState('R') && IsGameOver())
		{
			StartGame();
		}
		else if (GetAsyncKeyState('E'))
		{
			bexiting = true;
			ExitApp();

		}
		if (!IsGameOver())
		{
			if (GetAsyncKeyState('W') && pX - 1 >= 0)
				pX--;
			else if (GetAsyncKeyState('A') && pY - 1 >= 0)
				pY--;
			else if (GetAsyncKeyState('S') && pX + 1 < nHeight)
				pX++;
			else if (GetAsyncKeyState('D') && pY + 1 < nWidth)
				pY++;
			else if (GetAsyncKeyState(VK_SPACE))
			{
				SelectItem(pX, pY);
			}
			if (UpdateUserLoc(pX, pY))
				DrawMap();
		}

	}
}

void BControler::GameOver()
{
	ClearScreen();
	setGameOver(true);
	int nmaxWidth = 40;
	DrawTitle("Game Over", nmaxWidth);
	DrawTip("Press R to ReStart game | E to Exit ", nmaxWidth);
}

