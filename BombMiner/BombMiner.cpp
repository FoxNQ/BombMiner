#include "cBControler.h"

#include <iostream>

void sLowerCase(std::string& s)
{
    std::string temp = "";
    for (char c :s)
    {
        if (c >= 65 && c <= 91)
            c += 32;
        temp += c;
    }
    s = temp;
}

int main()
{
    std::string difficulty = "";
	char cSecrec = '*';
    int nWidth=0, nHeight=0, nPercent=40;
    std::cout << "Input Size Map ( Height ):";
    std::cin >> nHeight;
	std::cout << "Input Size Map ( Width ):";
	std::cin >> nWidth;

    std::cout << "Input Difficulty (Easy|Medium|Hard|FKHard):";
    std::cin >> difficulty;
    
    sLowerCase(difficulty);

    if (difficulty == "fkhard")
        nPercent = 90;
	else if (difficulty == "hard")
		nPercent = 80;
	if (difficulty == "medium")
		nPercent = 70;
    else
		nPercent = 50;


    BControler control(nHeight,nWidth,nPercent,cSecrec);
   control.StartGame();

}
