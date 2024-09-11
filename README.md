# FdF
이 프로젝트는 형식에 맞게 미리 작성된 map파일의 3차원 좌표 정보들을 이용하여 2차원 공간인 화면에 등축투영법을 이용해 표현한다. <br> 
등축투영법외에도 다양한 투영법을 통해 화면에 표현하였다. <br>
또한, 키보드/마우스 이벤트 들을 처리해본다. <br>
각 점들을 DDA 직선 알고리즘을 사용하여 점들을 이은 직선을 그린다. <br>

### 0. 사용 언어/라이브러리
* lanuage : C
* library : <a href="https://harm-smits.github.io/42docs/libs/minilibx">MLX (miniLibX)</a>based on OpenGL Library
  
### 1. 실행방법
  > ⚠️ Apple Mac에서만 사용 가능
```bash
  # 1. git clone 받기
  git clone https://github.com/ph-han/FdF.git
```
```bash
  # 2. 폴더 이동후 빌드
  cd FdF && make
```
```bash
  # 3. 실행
  # - arg1 : [fdf map file path && you can only input ".fdf" file extension]
  # example : ./fdf ./example/42.fdf
  ./fdf arg1
```

### 2. 실행 에시
<img width="500" alt="fdf" src="https://github.com/ph-han/FdF/assets/58614643/b05613c7-ad31-4f87-a014-49c98bd30c77">

### 3. 키 입력

### 4. FdF map 양식
+ 직사각형 형태만 가능
+ 

### A. 추가 할 것들
- 구, 도넛 모양 만들기
- 곡선 연결해보기
