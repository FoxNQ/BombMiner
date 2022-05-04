Frist Game in road to CPP Master of me, Thank you Playing
 -------------
 Sorry my English Bad :)
 -------------
Contact Me:
   ***********************************
  *  CaoNguyenKaitou99+git@gmail.com  *
   ***********************************
               *  Facbook/FoxNQCoder *
                *********************
_______________________________________

I Think this game no need Document , but if you want , it here :)

for me <vector> easy to control it, so i will use it in this project.
 
///Point <-- it wil be save location of player.

///Bitem <-- use Create and Draw A Matrix Map

 
  BControler 
 
 
///BControler <-- yah, of course it using Control this game
                  
      Thread:
                  set(Width Height) ------> StartGame Func ------> CreateMap ------> DrawMap ------> Key Check
                    (in Contructor)                                                       ^              | 
                                                                                          |              v
                                                                                          +<----------If Move
                  
   +CreateMap <-- i use two for loop Create matrix and use <random> to set random bomb.
     
   
   +DrawMap <-- still two for loop to Draw Matrix To Console
   
   +KeyCheck <-- use while loop and GetAsyncKeyStats to read key user press to move Point.
   
