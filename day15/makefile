q1 : q1.c 
	gcc -o $@ $^
ex02 : ex02.c ../engine/text_lable.c ../engine/button.c ../engine/util.c
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

ex03 : ex03.c ../engine/ui/text_lable.c 
	gcc -o $@ $^ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf