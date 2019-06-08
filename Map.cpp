#include "Map.h"
#include <iostream>

// 생성자
Map::Map() : vertical(0), horizontal(0) {}

// 생성자, 세로, 가로의 크기 값으로 초기화
Map::Map(int ver, int hori) : vertical(ver), horizontal(hori) {
	std::vector<char> _map;				// 프로그래밍 조건 6. 배열 대신 STL Vector만 사용할 것
	_map.push_back(1);						// ASCII(1)
	for (int j = 0; j < this->horizontal; ++j) _map.push_back(6);							// ASCII(6)
	_map.push_back(2);						// ASCII(2)
	this->map.push_back(_map);		// 벡터 안에 벡터 삽입
	_map.clear();									// 내부 벡터 비워주기
	for (int i = 0; i < this->vertical; ++i) {
		_map.push_back(5);						// ASCII(5)
		for (int j = 0; j < this->horizontal; ++j) _map.push_back(' ');
		_map.push_back(5);						// ASCII(5)
		this->map.push_back(_map);	// 벡터 안에 벡터 삽입
		_map.clear();								// 내부 벡터 비워주기
	}
	_map.push_back(3);							// ASCII(3)
	for (int j = 0; j < this->horizontal; ++j) _map.push_back(6);   						// ASCII(6)
	_map.push_back(4);							// ASCII(4)
	this->map.push_back(_map);		// 벡터 안에 벡터 삽입
	_map.clear();									// 내부 벡터 비워주기
}

// 복사 생성자
Map::Map(const Map& object) : 
	vertical(object.vertical), horizontal(object.horizontal), map(object.map) {}

// 프로그래밍 조건 6. 배열 대신 STL Vector만 사용할 것
std::vector<std::vector<char>> Map::getMap() {
	return this->map;									// 2차원 배열 형태의 게임 맵 반환
}

// 객체 대입 연산자, 복사 생성자와 기능 동일
Map& Map::operator=(const Map& object) {
	this->vertical = object.vertical;
	this->horizontal = object.horizontal;
	this->map = object.map;
	return *this;
}