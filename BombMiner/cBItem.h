#pragma once

#ifndef cBItem_h
#define cBItem_h

class BItem
{
private:
	bool bIsBomb;
	bool bIsSelected;
	int nBombAround;

public:
	BItem(bool& b) 
	{
		bIsBomb = b; 
		bIsSelected = false;
		nBombAround = 0;
	};

	
	bool IsSelected() { return bIsSelected; };
	bool IsBomb() { return bIsBomb; };

	int getBombAround()
	{
		if (!bIsSelected)
			return -1;
		else
			return nBombAround;
	};
	bool Select() 
	{
		bIsSelected = true;
		if (bIsBomb)
			return true;
		return false;
	}
	void setBomb(bool b) { bIsBomb = b; }
	
	void setBombAround(int& nBomb) 
	{
		if (bIsSelected)
		{
			nBombAround = nBomb;
		}
	};
	
};
#endif
