
#include "dungeon.hpp"

room::room(int init_Lx ,int init_Ly, std::vector<int>init_p, board &map):Lx{init_Lx},Ly{init_Ly},position{init_p}
{std::time_t seed;
srand(seed);
 int x;
 int y;
 int n =8;
 for (x = 0; x<Lx; x++)
  {for (y = 0; y < Ly; y++)
  {
    map(position[0] + x,position[1] + y) = 1;
  }
  }
for (x = 0; x<Lx; x++)
  {if(rand()%n==6 && map(position[0] + x-1,position[1]) == 0 && map(position[0] +x+1,position[1]) == 0){tile piece(std::vector<int> {position[0]+x,position[1]-1},map,3);}
   if(rand()%n==2 && map(position[0] + x-1,position[1] +Ly) == 0 && map(position[0] +x+1,position[1]+Ly) == 0){tile piece(std::vector<int> {position[0]+x,position[1]+Ly},map,1);}
  }
for (y = 0; y<Ly; y++)
  {if(rand()%n==3 && map(position[0],position[1]+y-1) == 0 && map(position[0],position[1]+y+1) == 0){tile piece(std::vector<int> {position[0]-1,position[1]+y},map,2);}
   if(rand()%n==1 && map(position[0]+Lx,position[1]+y-1) == 0 && map(position[0]+Lx,position[1]+y+1) == 0){tile piece(std::vector<int> {position[0]+Lx,position[1]+y},map,0);}
  }
}



tile::tile(std::vector<int>init_p, board &map,int init_direction):position{init_p},direction{init_direction}
{
    map(position[0],position[1]) = 2;
   int x;
   int y;
   bool triggered=false;
   bool placed =true;
   while(placed){
if(rand()%15<2){
  triggered= true;
   for (x = 0; x<10; x++)
  {for (y = 0; y <10 ; y++)
  { if (direction== 0){
    triggered = triggered && position[0] +1 + x < map.nx && position[1] + y-5 < map.ny && position[1] + y-5 > 0 && map(position[0] +1 + x,position[1] + y-5) == 0;
  }
  if (direction== 1){
    triggered = triggered && position[0] + x-5 < map.nx && position[0] + x-5 > 0 && position[1] + y + 1 < map.ny && map(position[0] + x-5,position[1] + y + 1) == 0;
  }
   if (direction== 2){
    triggered = triggered && position[0] - x-1 >0 && position[1] + y-5 > 0 && position[1] + y-5 < map.ny && map(position[0] -x-1,position[1] + y-5) == 0;
  }
   if (direction== 3){
    triggered = triggered && position[0] + x-5 > 0 && position[0] + x-5 < map.nx && position[1] -y-1 >0 && map(position[0] + x-5,position[1] - y-1) == 0;
  }
  }
  }}
  if (triggered){
    int Lx =(rand() % 10) +2;
    int Ly =(rand() % 10) +2;
    placed =false;
    if (direction==0){
        room piece(Lx,Ly, std::vector<int> {position[0]+1,position[1]-Ly/2},map);
    }
    if (direction==1){
        room piece(Lx,Ly, std::vector<int> {position[0]-Lx/2,position[1]+1},map);
    }
    if (direction==2){
        room piece(Lx,Ly, std::vector<int> {position[0]-Lx,position[1]-Ly/2},map);
    }
      if (direction==3){
        room piece(Lx,Ly, std::vector<int> {position[0]-Lx/2,position[1]-Ly},map);
    }
  }else{
    if (rand()%15<13){
    if (direction==0 && position[0]+1<map.nx && map(position[0] +1,position[1]) == 0 && map(position[0],position[1]+1) == 0 && map(position[0] ,position[1]-1) == 0){
        tile piece(std::vector<int> {position[0]+1,position[1]},map,0);placed =false;
    }
    if (direction==1 && position[1]+1<map.ny && map(position[0] ,position[1]+1) == 0 && map(position[0]+1,position[1]) == 0 && map(position[0]-1 ,position[1]) == 0){
        tile piece(std::vector<int> {position[0],position[1]+1},map,1);placed =false;
    }
    if (direction==2 && position[0]-1>=0 && map(position[0]-1 ,position[1]) == 0 && map(position[0],position[1]+1) == 0 && map(position[0] ,position[1]-1) == 0){
        tile piece(std::vector<int> {position[0]-1,position[1]},map,2);placed =false;
    }
      if (direction==3 && position[1]-1>=0 && map(position[0],position[1]-1) == 0 && map(position[0]+1,position[1]) == 0 && map(position[0]-1 ,position[1]) == 0){
        tile piece(std::vector<int> {position[0],position[1]-1},map,3);placed =false;
    }
placed =false;
    }

    else{
    int u = rand()%4;
    while (u==direction)
    {
      u = rand()%4;
    }
    
    if (u==0 && position[0]+1<map.nx && map(position[0] +1,position[1]) == 0 && map(position[0]+1,position[1]+1) == 0 && map(position[0] +1 ,position[1]-1) == 0){
        tile piece(std::vector<int> {position[0]+1,position[1]},map,0);placed =false;
    }
    if (u==1 && position[1]+1<map.ny && map(position[0],position[1]+1) == 0 && map(position[0]+1,position[1]+1) == 0 && map(position[0]-1 ,position[1]+1) == 0){
        tile piece(std::vector<int> {position[0],position[1]+1},map,1);placed =false;
    }
    if (u==2 && position[0]-1>=0 && map(position[0] -1,position[1]) == 0 && map(position[0]-1,position[1]+1) == 0 && map(position[0] -1 ,position[1]-1) == 0){
        tile piece(std::vector<int> {position[0]-1,position[1]},map,2);placed =false;
    }
      if (u==3 && position[1]-1>=0 && map(position[0],position[1]-1) == 0 && map(position[0]+1,position[1]-1) == 0 && map(position[0]-1 ,position[1]-1) == 0){
        tile piece(std::vector<int> {position[0],position[1]-1},map,3);placed =false;
    }
    }
    
    
 

  }
   }


}
