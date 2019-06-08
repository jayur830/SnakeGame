#pragma once
#include <deque>
#include <utility>

// ���α׷��� ���� 1. ������ũ ���¸� �����ϴ� Snake Ŭ���� �ۼ��� ��
class Snake {
	// ���α׷��� ���� 5. Ŭ������ ��� ��� ������ private���� �ۼ��� ��
	std::pair<int, int> head;									// ������ũ �Ӹ� ��ǥ, std::pair�� �� ��(�� ��)�� ������ ���� ���̺귯�� Ŭ���� ���ø�
	std::deque<std::pair<int, int>> body;				// ���α׷��� ���� 6. �迭 ��� STL Vector�� ����� ��(���⼭�� �� ���� ����, ������ ���� deque ���)
public:
	Snake();															// ������
	Snake(int, int, int);												// ������, ������ũ �Ӹ��� ��ǥ�� ������ũ ���� �ʱ�ȭ
	std::pair<int, int> getHead();								// ������ũ �Ӹ� Getter �Լ�
	std::deque<std::pair<int, int>> getBody();		// ������ũ ���� Getter �Լ�
	void setLocation(int, int);									// ������ũ �Ӹ� ��ǥ ����
	void feed(std::pair<int, int>&, int&);					// ������ũ�� ���̸� �Ծ��� �� �߻��ϴ� �̺�Ʈ
};