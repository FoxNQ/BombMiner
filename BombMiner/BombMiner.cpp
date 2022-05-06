#include "cBControler.h"
#include "cDrawSP.h"

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

    //May be to soon complete it, see ya!! :)
#pragma region MyRegion
	//std::cout << "game being update , pls come later, thank you!!";
 //   std::string difficulty = "";
	//char cSecrec = '*';
 //   int nWidth=0, nHeight=0, nPercent=40;
 //   std::cout << "Input Size Map ( Height ):";
 //   std::cin >> nHeight;
	//std::cout << "Input Size Map ( Width ):";
	//std::cin >> nWidth;

 //   std::cout << "Input Difficulty (Easy|Medium|Hard|FKHard):";
 //   std::cin >> difficulty;
 //   
 //   sLowerCase(difficulty);

 //   if (difficulty == "fkhard")
 //       nPercent = 80;
	//else if (difficulty == "hard")
	//	nPercent = 60;
	//if (difficulty == "medium")
	//	nPercent = 50;
 //   else
	//	nPercent = 40;


 //   BControler control(nHeight,nWidth,nPercent,cSecrec);
 //  control.StartGame();
#pragma endregion


    /*CONSOLE_SCREEN_BUFFER_INFO temp;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &temp);*/

    //LineFullChar('=', 40, true);
    //LineWithBorder("Test Result", 40);

}
