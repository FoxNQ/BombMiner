#include "cBControler.h"

char cLR = '|'; //use Draw in left and right map
#pragma region DrawTitle
void DrawFullLineByChar(char c, int nSize)
{
	std::cout << std::setfill(c) << std::setw(nSize) << c << std::endl;
}

void DrawLineBorder(std::string title, int nMaxSize, char csplit)
{
	
}


void DrawTitle(std::string sTitle, int nmaxWidth)
{
	int titlesize = static_cast<int>(sTitle.size());
	if (nmaxWidth % 2 == 0)
		nmaxWidth++;
	DrawFullLineByChar('=', nmaxWidth);
	DrawLineBorder(" ", nmaxWidth, '|');
	DrawLineBorder(sTitle, nmaxWidth, '|');
	DrawLineBorder(" ", nmaxWidth, '|');
	DrawFullLineByChar('=', nmaxWidth);

}

void DrawTip(std::string sTip, int nmaxWidth)
{
	int titlesize = static_cast<int>(sTip.size());

	DrawFullLineByChar('-', nmaxWidth);
	DrawLineBorder(sTip, nmaxWidth, '|');
	DrawFullLineByChar('-', nmaxWidth);
}
#pragma endregion
