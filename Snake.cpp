#include "Snake.h"

// ������
Snake::Snake() {}

// ������, ������ũ �Ӹ��� ��ǥ�� ������ũ ���� �ʱ�ȭ
Snake::Snake(int y, int x, int length) : head(std::pair<int, int>(y, x)) {
	// ������ũ �Ӹ��� (y, x)��, ������ y���� ��ȭ���� ������ũ�� ���̸�ŭ �Ҵ�
	for (int i = 1; i < length; ++i)
		this->body.push_back(std::pair<int, int>(y + i, x));
}

// ������ũ �Ӹ� Getter �Լ�
std::pair<int, int> Snake::getHead() {
	return this->head;						// ������ũ �Ӹ��� ��ǥ ��ȯ
}

// ������ũ ���� Getter �Լ�
std::deque<std::pair<int, int>> Snake::getBody() {
	return this->body;						// ������ũ ���� �迭 ��ȯ
}

// ������ũ �Ӹ� ��ǥ ����
void Snake::setLocation(int y, int x) {
	// �Ӹ��� �ִ� ��찡 �ƴ� ���
	if (!body.empty()) {
		if (body.size() != 1 || body[0].first != y || body[0].second != x)
			this->body.pop_back();
		this->body.push_front(this->head);
	}
	// �Ӹ� ��ǥ ����
	this->head.first = y;
	this->head.second = x;
}

// ������ũ�� ���̸� �Ծ��� �� �߻��ϴ� �̺�Ʈ
void Snake::feed(std::pair<int, int>& food, int& score) {
	if (this->head == food) {
		score += 100;												// 100���� ����
		// ������ ����ִٸ�
		if (this->body.empty()) {
			this->body.push_back(food);					// ���̸� ���� ��ǥ�� ���뿡 �߰�
			food.first = -1;
			food.second = -1;										// �ʱ�ȭ
			return;														// �Լ� ����
		}
		// ������ũ�� ���̸� �Ծ��� ��� ������ �ϳ� �߰��Ǿ�� �ϴµ�
		// �����κ��� ���� �ִ� ���� ��ҿ� ���Ͽ� ���⼺�� �����ؼ� ������ �߰��ؾ� ��
		auto iter = this->body.end();
		std::pair<int, int> pre;									// ���� ������ ����κ��� ��ǥ
		--iter;															// size - 1 �ε��� �κ��� ���� �����κ� �ݺ��� �ʱ�ȭ
		if (this->body.size() == 1) pre = head;			// ������ �� �κ��� ���ؾ� �ϴµ� ������ �ϳ��ۿ� ���ٸ� �Ӹ��� ��ǥ�� �ʱ�ȭ
		else pre = *(iter - 1);										// ������ ���� ��ǥ�� �ʱ�ȭ
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