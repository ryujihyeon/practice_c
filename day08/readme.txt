Developer Command Prompt Vs2019 => 작업폴더로 이동( cd mywork) => code .
=> 터미널 창에서 cl.exe가 실행되는지 확인


2중 for문(루프) 으로 텍스트 그래픽 만들기 

****
****
****
****

*
**
***
****

   *
  ***
 *****
  ***
   *

2차원 데이터를 1차원으로 만들기
[1][1] => 5
[1][2] => 6

행번호 * 열갯수 + 열번호 = 1차원 인덱스

1차원 데이터를 2차원으로 만들기

1차원 인덱스 / 열갯수 = 행번호
1차원 인덱스 % 열갯수 = 열번호

32bit => 4byte

int d;
char a,b,c
00
a=b

1+1+1+4 = 7 => 8byte
4+4+4+4 = 16

char a,b;
int c;
char d;

a => 100번지
b => 101번지
c => 102
d => 106


어셈블리 출력 
gcc -S -o ex05.asm ex05.c

   movl	$1, 12(%esp)  값=>메모리
	movl	$2, 8(%esp)
	movl	12(%esp), %edx 메모리=>레지스터 
	movl	8(%esp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$0, %eax


& => 주소 연산자
* => 값 

