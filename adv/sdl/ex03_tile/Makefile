CXX?=c++
SDL2FLAGS=$(shell pkg-config sdl2  --cflags --libs)
SDL2IMAGEFLAGS=$(shell pkg-config sdl2_image  --cflags --libs)
CXXFLAGS?=-std=c++11 -Wall -pedantic -Werror -Wshadow -Wstrict-aliasing -Wstrict-overflow

mac: main.c
	gcc -o ../out/$@ $^  -O2 ${SDL2FLAGS} ${SDL2IMAGEFLAGS}

win: main.c
	gcc -o ../out/$@ $^  -O2 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
