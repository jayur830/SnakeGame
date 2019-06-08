#pragma once
#include "Map.h"
#include "Management.h"

// 입출력 관리 클래스
class IO {
	static void gotoxy(int, int);					// 오픈 소스, 콘솔의 커서 위치 변경
public:
	static void setting(std::string&, Map&, Management&);			// 게임 설정
	static void log(std::string&);														// 게임 기록
	static void game(std::string&, Map&, Management&);				// 게임 시작
};