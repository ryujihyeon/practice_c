CXX?=c++
SDL2FLAGS=$(shell pkg-config sdl2  --cflags --libs)
SDL2IMAGEFLAGS=$(shell pkg-config sdl2_image  --cflags --libs)
CXXFLAGS?=-std=c++11 -Wall -pedantic -Werror -Wshadow -Wstrict-aliasing -Wstrict-overflow

.PHONY: all msg clean fullclean

all: msg main

msg:
	@echo '--- C++11 ---'

main: main.cpp
	${CXX} ${CXXFLAGS} -O2 -o $@ $< ${SDL2FLAGS} ${SDL2IMAGEFLAGS}

small: main.cpp
	${CXX} ${CXXFLAGS} -Os -o main $< ${SDL2FLAGS} ${SDL2IMAGEFLAGS}
	-strip main
	-sstrip main

debug: main.cpp
	${CXX} ${CXXFLAGS} -O0 -g -o main $< ${SDL2FLAGS} ${SDL2IMAGEFLAGS}

asm: main.asm

main.asm: main.cpp
	${CXX} ${CFLAGS} -S -o main.asm $< ${SDL2FLAGS} ${SDL2IMAGEFLAGS}


build_win : main.c
	gcc -o ../out/game.exe $^  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

build_mac : main.c
	gcc -o ../out/game $< ${SDL2FLAGS} ${SDL2IMAGEFLAGS}

run: msg main
	time ./main

clean:
	rm -f main *.o main.asm

fullclean: clean