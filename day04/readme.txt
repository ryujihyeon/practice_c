함수 => 작업단위 => 구조화 => {} => foo() {...}
객체 => 프로그램단위

구조화의 예>
물마시기

컵을 구한다 => 물 체운다 =>  물을 마신다.
종이컵             콜라              
                      커피

main 함수

반환형 함수이름( 매개변수1,.....,매개변수2 ) { 함수 내용 }

return

함수 원형(prototype)

컴파일(compiler) -> o , obj -> -c
링킹(linker) -> .exe

컴파일만 => -c
예>
gcc ex04_lib.c -c -o ex04_lib.o

라이브러리 가져와 합치기
예>
gcc ex04.c ex04_lib.o   -o ex04.exe

gcc ex04.c ex04_lib.o ex04_lib2.o  -o ex04.exe
gcc ex04.c ex04_lib.c ex04_lib2.c  -o ex04.exe

두개의 오브잭트 파일 합치기 
ar r libex04.a ./ex04_lib2.o ./ex04_lib2.o 

gcc ex04.c -o ex04.exe -L ./ -lex04

라이브러리 파일확장자 .a
접두사는 반드시 lib => 예> libxxxx.a => 실제이름은 xxxx => -lxxxx

45841byte => sum,mul
46236byte => sum

전처리기
#include
#define

00 0 0
01 1 1 
10 2  -2
11 3  -1

3+4+5+6
+ 3 4 + 5

3+4-5
+ 3 4 - 5 









