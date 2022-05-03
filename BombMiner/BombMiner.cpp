#include "cBControler.h"

#include <iostream>

int main()
{
    int nWidth=20, nHeight=20, nPercent=40;
    char cSecrec = '*';
    BControler control(nHeight,nWidth,nPercent,cSecrec);
   control.StartGame();

}
