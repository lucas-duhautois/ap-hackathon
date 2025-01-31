
#include "dungeon.hpp"

room::room(int init_Lx ,int init_Ly, std::vector<int>init_p, board map):Lx{init_Lx},Ly{init_Ly},position{init_p}
{int x;
 int y;
 for (x = 0; x<Lx; x++)
  {for (y = 0; y < Ly; y++)
  {
    map(position[0] + x,position[1] + y) = 1;
  }
  }


}



tile::tile(std::vector<int>init_p, board map):position{init_p}
{
    map(position[0],position[1]) = 2;
   int x;
   int y;
if( rand() % 10==5){
   for (x = 0; x<10; x++)
  {for (y = 0; y <10 ; y++)
  {
    map(position[0] + x,position[1] + y) = 1;
  }
  }}

}
