
### 준비사항 


#### window

[sdl 개발킷다운로드](https://www.libsdl.org/download-2.0.php)  
[sdl image](https://www.libsdl.org/projects/SDL_image/)  
[sdl ttf](https://www.libsdl.org/projects/SDL_ttf/)  
[sdl mixer](https://www.libsdl.org/projects/SDL_mixer/)  

SDL2-devel-2.0.12-mingw.tar.gz 파일을 다운로드 받아 압축을 해제한다.  
압축을 풀어 i686-w64-mingw32 (64bit 버전) 폴더를 찾는다.  

image,ttf,mixer는 선택사항이다. 
png,jpg 이미지를 불러오기 위해서 sdl_image가 필요하다.
다국어 문자처리(한글)을 위해서 sdl_ttf가 필요하다.
sound효과를 위해서 sdl_mixer가 필요하다. 

bin/ => dll파일을 windows system폴더에 카피한다. 또는 실행파일 폴더에 카피한다.  
(SDL 응용 프로그램을 실행시키려면 dll이 필요하다.)  

include/ => 폴더안의 내용물을 mingw/include/ 폴더에 카피한다.  
lib/ => 폴더안의 내용물을 mingw/lib/ 폴더에 카피한다.

컴파일 옵션  

기본옵션
```sh
 gcc -o test.exe main.cpp -lmingw32 -lSDL2main -lSDL2 
```
이미지 라이브러리추가

```sh
gcc -o test.exe main.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
```


bash 쉘에서는 실행이 불가하고 탐색기에서 더블클릭으로 실행한다.  

참고자료  
https://w3.cs.jmu.edu/bernstdh/Web/common/help/cpp_mingw-sdl-setup.php  



#### linux

#### mac 

``` sh
brew install sdl2 sdl2_image sdl2_ttf  
```

gcc 로 컴파일 할경우 경로 이름을 알아내기 위해서 pkg-config 유틸리티를 사용한다.
```sh
pkg-config sdl2  --cflags --libs
pkg-config sdl2_image  --cflags --libs
```

위에서 얻는 것으로 만든 간단하게 만든 makefile 예
```make
game:
	gcc main.c -o out/play -I /usr/local/include/SDL2 -L /usr/local/lib -l SDL2 -D_THREAD_SAFE -I/usr/local/include/SDL2 -L/usr/local/lib -lSDL2_image -lSDL2
```


### 참고자료

https://medium.com/@edkins.sarah/set-up-sdl2-on-your-mac-without-xcode-6b0c33b723f7

https://github.com/xyproto/sdl2-examples

https://github.com/Twinklebear/TwinklebearDev-Lessons

https://lazyfoo.net/tutorials/SDL/index.php


