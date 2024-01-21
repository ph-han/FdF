# FdF
> 이 과제는 그래픽 프로그래밍의 기초를 배우는 과제이다. <br>
> map파일에 3차원 좌표 정보들을 이용하여 2차원 공간인 화면에 등축투영법을 이용해 표현한다. <br>
> 등축투영법외에도 다양한 투영법을 통해 화면에 표현할 수 있다. <br>
> 또한, 키보드/마우스 이벤트 들을 처리해본다. <br>
> 각 점들을 DDA 직선 알고리즘을 사용하여 그려준다. <br>

### 0. 사용 언어/라이브러리
* lanuage : C
* Graphic lib : MLX (miniLibX) made by 42 
  
### 1. 실행방법
  > ⚠️ Apple Mac에서만 사용 가능

1. ```console git clone https://github.com/ph-han/FdF.git ```
2. ```console cd FdF && make ```
3. ```./fdf [fdf map file path && you can only input ".fdf" file extension] ```
   1. example : ```./fdf ./example/42.fdf ```

### 2. 예제
* 작성예정

### 3. 업데이트 내역
* ver.1 (2월 예정)
  - 전체적인 코드 리펙토링
  - "구" / "도넛" 형태로 투영
* ver.0 (now)
  - 입력된 맵 등축 투영, 축 회전, 좌표 이동 가능
