ex01:ex01.c
	gcc -o $@ $^ -Wall -std=c99 -pedantic -Werror -Wshadow -Wstrict-aliasing -Wstrict-overflow
ex02:ex02.c
	gcc -o $@ $^
ex03:ex03.c
	gcc -o $@ $^
ex04_debug:ex04.c
	gcc -o $@ $^ -D __DEBUG__
ex04_rel:ex04.c
	gcc -o $@ $^
ex05:ex05.c
	gcc -o $@ $^ 
ex06:ex06.c ../engine/util.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 
