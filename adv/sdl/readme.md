
### 준비사항 

#### window

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

