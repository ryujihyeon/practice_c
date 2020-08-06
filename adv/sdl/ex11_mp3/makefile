CXX?=c++
SDL2FLAGS=$(shell pkg-config sdl2  --cflags --libs)
SDL2IMAGEFLAGS=$(shell pkg-config sdl2_image  --cflags --libs)
SDL2TTFFLAGS=$(shell pkg-config sdl2_ttf  --cflags --libs)
SDL2MIXERFLAGS=$(shell pkg-config sdl2_mixer  --cflags --libs)
CXXFLAGS?=-std=c++11 -Wall -pedantic -Werror -Wshadow -Wstrict-aliasing -Wstrict-overflow

mac : main.cpp
	${CXX} -o ../out/$@ $^  ${SDL2FLAGS} ${SDL2IMAGEFLAGS} $(SDL2TTFFLAGS) $(SDL2MIXERFLAGS)
win: main.c
	gcc -o ../out/$@ $^  -O2 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image