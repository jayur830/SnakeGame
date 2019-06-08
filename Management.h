#pragma once
#include "Functions.h"
#include <utility>
#include <vector>

// ���α׷��� ���� 4. ���� ������ ���� Management Ŭ���� �ۼ��� ��
class	Management {
	// ���α׷��� ���� 5. Ŭ������ ��� ��� ������ private���� �ۼ��� ��
	friend class Management;									// Management �ν��Ͻ� ���� ��� �����͸� ���ϰ� �ְ�ޱ� ����
	std::string player;												// �÷��̾� �̸�
	std::pair<int, int> size;										// �� ũ��
	int length;															// ������ũ ����
	double speed;													// ������ũ �ӵ�
	std::vector<std::pair<std::string, int>> rank;							// ���α׷��� ���� 6. �迭 ��� STL Vector�� ����� ��
	static bool compare(const std::pair<std::string, int>&, const std::pair<std::string, int>&);				// ���Ŀ� ���� �� ����
public:
	Management();																		// ������
	Management(std::string, std::pair<int, int>, int, double);		// �ʱ�ȭ ������
	Management(const Management&);									// ���� ������
	std::string getPlayer();															// �÷��̾� �̸� Getter �Լ�
	int getLength();																		// ������ũ ���� Getter �Լ�
	double getSpeed();																// ���� �ӵ� Getter �Լ�
	void setRank(std::string, int);													// ���� Setter �Լ�, �÷��̾� �̸��� ������ �ش� �÷��̾� ���� �ʱ�ȭ
	int getRank(std::string);															// ���� Getter �Լ�, �÷��̾� �̸����� �˻�
	int getScore(std::string);														// ���� ���� Getter �Լ�
	std::vector<std::pair<std::string, int>> getRank();					// ��ü �÷��̾� ���� Getter �Լ�, ���α׷��� ���� 6. �迭 ��� STL Vector�� ����� ��
	Management& operator=(const Management&);					// ��ü ���� ������, ���� �����ڿ� ��� ����
};