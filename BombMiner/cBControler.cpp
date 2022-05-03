#include "cBControler.h"


#pragma region DrawTitle
void DrawFullLineByChar(char c,int nSize)
{
	std::cout << std::setfill(c) << std::setw(nSize) << c << std::endl;
}

void DrawTitleLine(std::string title,int nMaxSize, char csplit)
{
	int titlesize = static_cast<int>(title.size());
	int nHalf = ((nMaxSize - titlesize) / 2)-2;
	std::cout << csplit << csplit << std::setfill(' ') << std::setw(nHalf) << " " << title <<
		std::right << std::setfill(' ') << std::setw(nHalf) << " " << csplit << csplit << "\n";
}


void DrawTitle(std::string sTitle,int nmaxWidth)
{
	int titlesize = static_cast<int>(sTitle.size());
	if (nmaxWidth % 2==0)
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

BItem* BControler::getItem(int& x,int& y)
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
	if (ptrItem&&(*ptrItem).IsBomb())
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

	std::string seed =std::to_string(std::time(0));

	std::random_device rd(seed);
	std::mt19937 mt(rd);

	for (int h = 0;h<nHeight;h++)
	{
		std::vector<BItem>* vec;
		Map.emplace_back(vec);
		for (int w = 0; w < nWidth; w++)
		{
			bool isrand = (mt() % 2);
			Map[h].emplace_back(BItem(isrand));
		}
	}
}

void BControler::DrawMap()
{

}

void BControler::StartGame()
{
	int nMaxWidth = nWidth * 5+2;
	if (nMaxWidth < 50)
		nMaxWidth = 51;
	DrawTitle("Bomb Game by FoxNQ", nMaxWidth);

	DrawTip("Use (W,A,S,D) = Move | Space = Select | E = Exit", nMaxWidth);
	Debug();
}