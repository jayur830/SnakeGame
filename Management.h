#pragma once
#include "Functions.h"
#include <utility>
#include <vector>

// 프로그래밍 조건 4. 게임 관리를 위한 Management 클래스 작성할 것
class	Management {
	// 프로그래밍 조건 5. 클래스의 모든 멤버 변수는 private으로 작성할 것
	friend class Management;									// Management 인스턴스 간의 모든 데이터를 편리하게 주고받기 위함
	std::string player;												// 플레이어 이름
	std::pair<int, int> size;										// 맵 크기
	int length;															// 스네이크 길이
	double speed;													// 스네이크 속도
	std::vector<std::pair<std::string, int>> rank;							// 프로그래밍 조건 6. 배열 대신 STL Vector만 사용할 것
	static bool compare(const std::pair<std::string, int>&, const std::pair<std::string, int>&);				// 정렬에 사용될 비교 기준
public:
	Management();																		// 생성자
	Management(std::string, std::pair<int, int>, int, double);		// 초기화 생성자
	Management(const Management&);									// 복사 생성자
	std::string getPlayer();															// 플레이어 이름 Getter 함수
	int getLength();																		// 스네이크 길이 Getter 함수
	double getSpeed();																// 게임 속도 Getter 함수
	void setRank(std::string, int);													// 순위 Setter 함수, 플레이어 이름과 점수로 해당 플레이어 순위 초기화
	int getRank(std::string);															// 순위 Getter 함수, 플레이어 이름으로 검색
	int getScore(std::string);														// 게임 점수 Getter 함수
	std::vector<std::pair<std::string, int>> getRank();					// 전체 플레이어 순위 Getter 함수, 프로그래밍 조건 6. 배열 대신 STL Vector만 사용할 것
	Management& operator=(const Management&);					// 객체 대입 연산자, 복사 생성자와 기능 동일
};