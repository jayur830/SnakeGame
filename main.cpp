#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <conio.h>
#include "Functions.h"
#include "Snake.h"
#include "Map.h"
#include "Controller.h"
#include "Management.h"
#include "IO.h"

int main() {
	std::string input, error;
	Map map;									// 게임 맵
	Management management;
	while (true) {
		system("cls");				// 화면 지우기
		std::cout << std::endl << std::endl << std::endl;
		// 여러 예외에 대한 메시지 출력
		if (!error.empty()) {
			std::cout << "\t\t\t\t" << error << std::endl << std::endl;
			error.clear();
		}
		// 메뉴
		std::cout << "\t\t\t\t1. 게임 설정" << std::endl << std::endl;
		std::cout << "\t\t\t\t2. 게임 기록" << std::endl << std::endl;
		std::cout << "\t\t\t\t3. 게임 시작" << std::endl << std::endl;
		std::cout << "\t\t\t\t4. 게임 종료" << std::endl << std::endl;
		std::cout << "\t\t\t\t>> ";
		std::cin >> input;
		// 게임 설정
		if (input == "1") IO::setting(error, map, management);
		// 게임 기록
		else if (input == "2") IO::log(error);
		// 게임 시작
		else if (input == "3") {
			if (!management.getPlayer().empty())
				IO::game(error, map, management);
			else error = "게임 설정을 먼저 해주세요.";
		}
		// 종료
		else if (input == "4") break;
		else error = "올바른 숫자를 입력해주세요.";
	}
	return 0;
}