#include "Controller.h"

// ������
Controller::Controller() : key(0) {}

// ������, �Է��� Ű ���� �ʱ�ȭ
Controller::Controller(int _key) : key(_key) {}

// Ű �� Getter �Լ�
int Controller::getKey() {
	return this->key;					// Ű���� Ű �� ��ȯ
}

// Ű �� Setter �Լ�
void Controller::setKey() {
	// Ű���� ��ư�� ��������, ���� �Է� ���� ù �Է� ���� ASCII ���� 224�� ���
	if (_kbhit() && _getch() == 224)
		this->key = _getch();
}