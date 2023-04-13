build:
	g++ -c src/*.cpp -std=c++17 -g -Wall -m64 -I include -I SDL2/include && g++ *.o -o bin/debug/main -L SDL2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer && start bin/debug/main
official:
	g++ -c src/*.cpp -std=c++17 -O3 -Wall -m64 -I include -I SDL2/include && g++ *.o -o bin/release/main -L SDL2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer && start bin/release/main