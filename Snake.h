#pragma once
#include <deque>
#include <utility>

// 프로그래밍 조건 1. 스네이크 상태를 관리하는 Snake 클래스 작성할 것
class Snake {
	// 프로그래밍 조건 5. 클래스의 모든 멤버 변수는 private으로 작성할 것
	std::pair<int, int> head;									// 스네이크 머리 좌표, std::pair는 한 쌍(두 개)의 변수를 갖는 라이브러리 클래스 템플릿
	std::deque<std::pair<int, int>> body;				// 프로그래밍 조건 6. 배열 대신 STL Vector만 사용할 것(여기서는 양 쪽의 삽입, 삭제가 편리한 deque 사용)
public:
	Snake();															// 생성자
	Snake(int, int, int);												// 생성자, 스네이크 머리의 좌표와 스네이크 길이 초기화
	std::pair<int, int> getHead();								// 스네이크 머리 Getter 함수
	std::deque<std::pair<int, int>> getBody();		// 스네이크 몸통 Getter 함수
	void setLocation(int, int);									// 스네이크 머리 좌표 갱신
	void feed(std::pair<int, int>&, int&);					// 스네이크가 먹이를 먹었을 때 발생하는 이벤트
};