#pragma once
#include <conio.h>

// ���α׷��� ���� 3. Ű �Է��� �ޱ� ���� Controller Ŭ���� �ۼ��� ��
class Controller {
	// ���α׷��� ���� 5. Ŭ������ ��� ��� ������ private���� �ۼ��� ��
	int key;
public:
	Controller();								// ������
	Controller(int);							// ������, �Է��� Ű ���� �ʱ�ȭ
	int getKey();								// Ű �� Getter �Լ�
	void setKey();							// Ű �� Setter �Լ�
};