build:
	g++ -o rogue rogue.cpp Hero.cpp item.cpp dungeon.cpp enemies.cpp -lsfml-graphics -lsfml-window -lsfml-system