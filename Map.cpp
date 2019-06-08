#include "Map.h"
#include <iostream>

// ������
Map::Map() : vertical(0), horizontal(0) {}

// ������, ����, ������ ũ�� ������ �ʱ�ȭ
Map::Map(int ver, int hori) : vertical(ver), horizontal(hori) {
	std::vector<char> _map;				// ���α׷��� ���� 6. �迭 ��� STL Vector�� ����� ��
	_map.push_back(1);						// ASCII(1)
	for (int j = 0; j < this->horizontal; ++j) _map.push_back(6);							// ASCII(6)
	_map.push_back(2);						// ASCII(2)
	this->map.push_back(_map);		// ���� �ȿ� ���� ����
	_map.clear();									// ���� ���� ����ֱ�
	for (int i = 0; i < this->vertical; ++i) {
		_map.push_back(5);						// ASCII(5)
		for (int j = 0; j < this->horizontal; ++j) _map.push_back(' ');
		_map.push_back(5);						// ASCII(5)
		this->map.push_back(_map);	// ���� �ȿ� ���� ����
		_map.clear();								// ���� ���� ����ֱ�
	}
	_map.push_back(3);							// ASCII(3)
	for (int j = 0; j < this->horizontal; ++j) _map.push_back(6);   						// ASCII(6)
	_map.push_back(4);							// ASCII(4)
	this->map.push_back(_map);		// ���� �ȿ� ���� ����
	_map.clear();									// ���� ���� ����ֱ�
}

// ���� ������
Map::Map(const Map& object) : 
	vertical(object.vertical), horizontal(object.horizontal), map(object.map) {}

// ���α׷��� ���� 6. �迭 ��� STL Vector�� ����� ��
std::vector<std::vector<char>> Map::getMap() {
	return this->map;									// 2���� �迭 ������ ���� �� ��ȯ
}

// ��ü ���� ������, ���� �����ڿ� ��� ����
Map& Map::operator=(const Map& object) {
	this->vertical = object.vertical;
	this->horizontal = object.horizontal;
	this->map = object.map;
	return *this;
}