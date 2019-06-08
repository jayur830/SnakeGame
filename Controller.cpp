#include "Controller.h"

// 생성자
Controller::Controller() : key(0) {}

// 생성자, 입력한 키 값을 초기화
Controller::Controller(int _key) : key(_key) {}

// 키 값 Getter 함수
int Controller::getKey() {
	return this->key;					// 키보드 키 값 반환
}

// 키 값 Setter 함수
void Controller::setKey() {
	// 키보드 버튼을 눌렀으며, 들어온 입력 값중 첫 입력 값의 ASCII 값이 224인 경우
	if (_kbhit() && _getch() == 224)
		this->key = _getch();
}