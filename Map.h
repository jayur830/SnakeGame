#pragma once
#include <vector>

// 프로그래밍 조건 2. 지도를 관리하기 위한 Map 클래스 작성할 것
class Map {
	// 프로그래밍 조건 5. 클래스의 모든 멤버 변수는 private으로 작성할 것
	friend class Map;												// Map 인스턴스 간의 모든 데이터를 편리하게 주고받기 위함
	int vertical = 0, horizontal = 0;							// 맵의 세로 길이와 가로 길이	
	std::vector<std::vector<char>> map;				// 프로그래밍 조건 6. 배열 대신 STL Vector만 사용할 것
public:
	Map();																// 생성자
	Map(int, int);														// 생성자, 세로, 가로의 크기 값으로 초기화
	Map(const Map&);											// 복사 생성자
	std::vector<std::vector<char>> getMap();		// 프로그래밍 조건 6. 배열 대신 STL Vector만 사용할 것
	Map& operator=(const Map&);						// 객체 대입 연산자, 복사 생성자와 기능 동일
};