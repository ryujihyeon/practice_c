ex01 : ex01.c
	gcc -o ex01.exe ex01.c
ex02 : ex02.c
	gcc -o ex02.exe ex02.c
ex03 : ex03.c
	gcc -o $@ $^
ex04 : ex04.c
	gcc -o $@ $^
ex05 : ex05.c
	gcc -o $@ $^
ex06 : ex06.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2
ex08 : ex08.c
	gcc -o $@ $^
ex09 : ex09.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2
ex10 : ex10.c ../engine/parser.c ../engine/tile.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image