#pragma once
#include <conio.h>

// 프로그래밍 조건 3. 키 입력을 받기 위한 Controller 클래스 작성할 것
class Controller {
	// 프로그래밍 조건 5. 클래스의 모든 멤버 변수는 private으로 작성할 것
	int key;
public:
	Controller();								// 생성자
	Controller(int);							// 생성자, 입력한 키 값을 초기화
	int getKey();								// 키 값 Getter 함수
	void setKey();							// 키 값 Setter 함수
};