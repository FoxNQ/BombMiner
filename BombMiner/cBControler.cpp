#include "cBControler.h"

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
