build:
	g++ -c src/*.cpp -std=c++17 -g -Wall -m64 -I include -I C:/projects/SDL2/include && g++ *.o -o bin/debug/main -L C:/projects/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image && start bin/debug/main
official:
	g++ -c src/*.cpp -std=c++17 -O3 -Wall -m64 -I include -I C:/projects/SDL2/include && g++ *.o -o bin/release/main -L C:/projects/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image && start bin/release/main