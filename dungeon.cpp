
#include "dungeon.hpp"

room::room(int init_Lx ,int init_Ly, std::vector<int>init_p, board map):Lx{init_Lx},Ly{init_Ly},position{init_p}
{


}



tile::tile(std::vector<int>init_p, board map):position{init_p}
{


}
