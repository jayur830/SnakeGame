#include "Snake.h"

// 생성자
Snake::Snake() {}

// 생성자, 스네이크 머리의 좌표와 스네이크 길이 초기화
Snake::Snake(int y, int x, int length) : head(std::pair<int, int>(y, x)) {
	// 스네이크 머리는 (y, x)로, 몸통은 y값만 변화시켜 스네이크의 길이만큼 할당
	for (int i = 1; i < length; ++i)
		this->body.push_back(std::pair<int, int>(y + i, x));
}

// 스네이크 머리 Getter 함수
std::pair<int, int> Snake::getHead() {
	return this->head;						// 스네이크 머리의 좌표 반환
}

// 스네이크 몸통 Getter 함수
std::deque<std::pair<int, int>> Snake::getBody() {
	return this->body;						// 스네이크 몸통 배열 반환
}

// 스네이크 머리 좌표 갱신
void Snake::setLocation(int y, int x) {
	// 머리만 있는 경우가 아닌 경우
	if (!body.empty()) {
		if (body.size() != 1 || body[0].first != y || body[0].second != x)
			this->body.pop_back();
		this->body.push_front(this->head);
	}
	// 머리 좌표 갱신
	this->head.first = y;
	this->head.second = x;
}

// 스네이크가 먹이를 먹었을 때 발생하는 이벤트
void Snake::feed(std::pair<int, int>& food, int& score) {
	if (this->head == food) {
		score += 100;												// 100점씩 증가
		// 몸통이 비어있다면
		if (this->body.empty()) {
			this->body.push_back(food);					// 먹이를 먹은 좌표를 몸통에 추가
			food.first = -1;
			food.second = -1;										// 초기화
			return;														// 함수 종료
		}
		// 스네이크가 먹이를 먹었을 경우 몸통이 하나 추가되어야 하는데
		// 꼬리부분의 전에 있는 몸통 요소와 비교하여 방향성을 결정해서 몸통을 추가해야 함
		auto iter = this->body.end();
		std::pair<int, int> pre;									// 꼬리 이전의 몸통부분의 좌표
		--iter;															// size - 1 인덱스 부분의 몸통 꼬리부분 반복자 초기화
		if (this->body.size() == 1) pre = head;			// 몸통의 두 부분을 비교해야 하는데 몸통이 하나밖에 없다면 머리의 좌표로 초기화
		else pre = *(iter - 1);										// 현재의 꼬리 좌표를 초기화
		int y, x;
		if (pre.first != iter->first) {
			x = iter->second;
			if (pre.first < iter->first) y = iter->first + 1;
			else y = iter->first - 1;
		}
		else if (pre.second != iter->second) {
			y = iter->first;
			if (pre.second < iter->second) x = iter->second + 1;
			else x = iter->second - 1;
		}
		this->body.push_back(std::pair<int, int>(y, x));
		food.first = -1;
		food.second = -1;
	}
}