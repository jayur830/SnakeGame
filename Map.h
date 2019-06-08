#pragma once
#include <vector>

// ���α׷��� ���� 2. ������ �����ϱ� ���� Map Ŭ���� �ۼ��� ��
class Map {
	// ���α׷��� ���� 5. Ŭ������ ��� ��� ������ private���� �ۼ��� ��
	friend class Map;												// Map �ν��Ͻ� ���� ��� �����͸� ���ϰ� �ְ�ޱ� ����
	int vertical = 0, horizontal = 0;							// ���� ���� ���̿� ���� ����	
	std::vector<std::vector<char>> map;				// ���α׷��� ���� 6. �迭 ��� STL Vector�� ����� ��
public:
	Map();																// ������
	Map(int, int);														// ������, ����, ������ ũ�� ������ �ʱ�ȭ
	Map(const Map&);											// ���� ������
	std::vector<std::vector<char>> getMap();		// ���α׷��� ���� 6. �迭 ��� STL Vector�� ����� ��
	Map& operator=(const Map&);						// ��ü ���� ������, ���� �����ڿ� ��� ����
};