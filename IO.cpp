#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include <Windows.h>
#include <conio.h>
#include <random>
#include <time.h>
#include "Functions.h"
#include "Snake.h"
#include "Controller.h"
#include "IO.h"
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

// 오픈 소스, 콘솔의 커서 위치 변경
void IO::gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 게임 설정
void IO::setting(std::string& error, Map& map, Management& management) {
	bool back = false;
	std::string player, size_hori, size_ver, _length, _speed;
	std::pair<int, int> size;
	int length;
	double speed;
	system("cls");
	std::cout << std::endl << std::endl;
	// 플레이어 이름 입력
	getchar();
	while (true) {
		std::cout << std::endl << "\t\t\t\t플레이어 이름 : ";
		getline(std::cin, player);														// 한 줄 단위로 입력
		if (player.empty() || Functions::trim(player).empty())			// 그냥 엔터를 쳤거나 공백만 입력했을 경우
			std::cout << std::endl << "\t\t\t\t플레이어 이름을 입력해주세요." << std::endl;
		else {
			if (Functions::trim(player) == "0") back = true;				// 이전 화면 돌아가기
			break;
		}
	}
	// 이전 화면 돌아가기
	if (back) {
		error = "이전 화면으로 돌아왔습니다.";
		return;
	}
	// 맵 크기 입력
	while (true) {
		std::cout << std::endl << "\t\t\t\t맵 크기 : ";
		std::cin >> size_hori >> size_ver;
		// 이전 화면 돌아가기
		if (size_hori == "0" || size_ver == "0") {
			back = true;
			break;
		}
		// 입력이 숫자가 아닌 경우
		if (!Functions::isInt(size_hori) || !Functions::isInt(size_ver))
			std::cout << std::endl << "\t\t\t\t1에서 100사이의 숫자로 입력해주세요." << std::endl;
		else {
			// 1에서 100 사이인지 체크
			if (!Functions::inRangeValue(size_hori, 1, 100) || !Functions::inRangeValue(size_ver, 1, 100))
				std::cout << std::endl << "\t\t\t\t1에서 100사이의 숫자로 입력해주세요." << std::endl;
			else {
				size.first = Functions::toInt(size_hori);
				size.second = Functions::toInt(size_ver);
				break;
			}
		}
	}
	// 이전 화면 돌아가기
	if (back) {
		error = "이전 화면으로 돌아왔습니다.";
		return;
	}
	// 스네이크 길이 입력
	while (true) {
		std::cout << std::endl << "\t\t\t\t스네이크 길이(1~10) : ";
		std::cin >> _length;
		// 이전 화면 돌아가기
		if (_length == "0") {
			back = true;
			break;
		}
		// 입력이 숫자가 아닌 경우
		if (!Functions::isInt(_length))
			std::cout << std::endl << "\t\t\t\t1에서 10사이의 숫자로 입력해주세요." << std::endl;
		else {
			// 1에서 10사이의 범위가 아닌 경우
			if (!Functions::inRangeValue(_length, 1, 10))
				std::cout << std::endl << "\t\t\t\t1에서 10사이의 숫자로 입력해주세요." << std::endl;
			else {
				length = Functions::toInt(_length);
				break;
			}
		}
	}
	// 이전 화면 돌아가기
	if (back) {
		error = "이전 화면으로 돌아왔습니다.";
		return;
	}
	// 게임 속도 입력
	while (true) {
		std::cout << std::endl << "\t\t\t\t게임 속도(1 = 0.1msec) : ";
		std::cin >> _speed;
		// 이전 화면 돌아가기
		if (_speed == "0") {
			back = true;
			break;
		}
		// 입력이 숫자가 아닌 경우
		if (!Functions::isInt(_speed))
			std::cout << std::endl << "\t\t\t\t1에서 10사이의 숫자로 입력해주세요." << std::endl;
		else {
			speed = (double)Functions::toInt(_speed);
			break;
		}
	}
	// 이전 화면 돌아가기
	if (back) {
		error = "이전 화면으로 돌아왔습니다.";
		return;
	}
	map = Map(size.second, size.first);											// 게임 맵 초기화
	management = Management(player, size, length, speed);		// 게임 설정 초기화
	error = "게임 설정이 완료되었습니다.";
}

// 게임 기록
void IO::log(std::string& error) {
	// 프로그래밍 조건 7. 게임 기록은 파일로 저장 / 출력할 것
	std::ifstream fin;
	fin.open("rank.txt", std::ios_base::in);
	if (fin.is_open()) {
		system("cls");
		std::cout << std::endl << std::endl << std::endl;
		std::string line;
		getchar();
		while (!fin.eof()) {
			getline(fin, line);
			std::cout << "\t\t\t\t" << line << std::endl << std::endl;
		}
		std::cout << "\t\t\t\t";
		system("pause");
	}
	else error = "현재 게임 기록이 없습니다.";
	fin.close();
}

// 게임 시작
void IO::game(std::string& error, Map& _map, Management& management) {
	// 게임 시작 전 화면 출력
	while (true) {
		system("cls");
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "========================================================================================================================" << std::endl;
		std::cout << "\t\t\t\t\t\t게임을 시작하지? (y/n)" << std::endl;
		std::cout << "========================================================================================================================" << std::endl;
		std::cout << "\t\t\t\t\t\t>> ";
		char c = _getch();						// 키보드 입력 버퍼를 거치지 않고 키보드를 누르자 마자 이벤트 발생
		if (c == 'y') break;
		else if (c == 'n') {
			error = "이전 화면으로 돌아왔습니다.";
			return;
		}
	}
	// 본격적으로 게임 시작
	while (true) {
		system("cls");
		std::vector<std::vector<char>> map = _map.getMap();					// 프로그래밍 조건 6. 배열 대신 STL Vector만 사용할 것
		int verticalSize = map.size(), horizontalSize = map[0].size();				// 게임 맵 세로 길이와 가로 길이
		for (int i = 0; i < verticalSize; ++i) {									// 게임 맵 출력
			for (int j = 0; j < horizontalSize; ++j)
				std::cout << map[i][j];
			std::cout << std::endl;
		}
		int key = UP, input = 224, score = 0,				// 키 입력값 두 개와 게임 점수, 이전 게임 점수, 순위
			preScore = management.getScore(management.getPlayer()), rank;
		Snake snake(verticalSize / 2, horizontalSize / 2, management.getLength());				// 스네이크 객체 생성
		Controller controller;																								// 키 입력을 위한 객체 생성
		std::pair<int, int> head, pre(std::pair<int, int>(-1, -1)), food(std::pair<int, int>(-1, -1));
		std::deque<std::pair<int, int>> body;												// 프로그래밍 조건 6. 배열 대신 STL Vector만 사용할 것(여기서는 양 쪽의 삽입, 삭제가 편리한 deque 사용)
		double speed = management.getSpeed() * 100;								// 게임 속도
		while (true) {
			Sleep(speed);																				// 설정했던 게임 속도만큼 시간 지연
			head = snake.getHead();																// 머리
			body = snake.getBody();																// 몸통
			// 먹이가 생성되지 않았을 때 수행, -1은 초기값
			if (food.first == -1 && food.second == -1) {
				do {
					srand(clock());													// 난수 설정
					int y = rand() % (verticalSize - 2) + 1;				// 난수 생성
					srand(clock());													// 난수 설정
					int x = rand() % (horizontalSize - 2) + 1;			// 난수 생성
					food = std::pair<int, int>(y, x);							// 먹이 좌표 설정
					// 난수로 생성된 먹이 좌표가 스네이크의 머리 또는 몸통의 어느 일부분과도 겹치지 않으면 break
				} while (head == food || std::find(body.begin(), body.end(), food) != body.end());
				// 해당 먹이 좌표로 콘솔 커서 이동 후 먹이('*') 출력
				gotoxy(food.second, food.first);
				std::cout << "*";
			}
			// 머리가 벽에 부딪혔을 경우
			if (head.first == 0 || head.first == verticalSize - 1 ||
				head.second == 0 || head.second == horizontalSize - 1) break;
			// 머리가 몸통에 부딪혔을 경우
			else if (!body.empty() && std::find(body.begin(), body.end(), head) != body.end()) break;
			snake.feed(food, score);									// 냠냠, 버억
			// 스네이크가 맵 상에서 떠돌아다닐 때 한 칸 이동한 만큼 한 칸 지워주는 코드
			if (pre.first != -1 && pre.first != -1) {
				gotoxy(pre.second, pre.first);
				std::cout << " \b";
			}
			// 몸통이 존재하는 경우
			if (!body.empty())
				// 몸통의 모든 부분 출력
				for (std::pair<int, int> loc : body) {
					gotoxy(loc.second, loc.first);
					std::cout << "#\b";
				}
			// 머리 출력
			gotoxy(head.second, head.first);
			std::cout << "@\b";
			// 이전 좌표(pre)에는 몸통의 꼬리 좌표로 초기화, 몸통이 없을 경우에는 머리 좌표로 초기화
			if (!body.empty()) pre = body.back();
			else pre = head;
			controller.setKey();							// 방향키 입력
			key = controller.getKey();					// 키 값 얻기
			if (input == 224) {
				if (key == LEFT) snake.setLocation(head.first, head.second - 1);						// 왼쪽 이동
				else if (key == RIGHT) snake.setLocation(head.first, head.second + 1);			// 오른쪽 이동
				else if (key == UP) snake.setLocation(head.first - 1, head.second);				// 위쪽 이동
				else if (key == DOWN) snake.setLocation(head.first + 1, head.second);		// 아래쪽 이동
			}
		}
		char select;
		std::string player = management.getPlayer();			// 현재 플레이어 이름 얻기
		management.setRank(player, score);						// 순위 갱신
		rank = management.getRank(player);						// 플레이어의 순위 얻기
		// 게임이 끝난 후 결과 출력
		while (true) {
			system("cls");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "========================================================================================================================" << std::endl;
			std::cout << "\t\t\t\t\t";
			// 기존의 기록 점수보다 새로 얻은 점수가 더 높은 경우에만 수행
			if (preScore < score) {
				if (rank == 1) std::cout << "축하합니다! 1등입니다. ";
				else if (rank == 2) std::cout << "아깝네요. 2등입니다. ";
				else if (rank == 3) std::cout << "참으로 아쉽습니다. 3등입니다. ";
				else if (rank == 4 || rank == 5) std::cout << "조금 더 분발하세요. " << rank << "등입니다. ";
			}
			std::cout << "다시 도전하시겠습니까? (y/n)" << std::endl;
			std::cout << "========================================================================================================================" << std::endl;
			std::cout << "\t\t\t\t\t>> ";
			if ((select = _getch()) == 'n' || select == 'y') break;				// Yes 또는 No 일 때만 break
		}
		// No이면 break 후 해당 함수 종료, Yes면 다시 한 번 루프 분기
		if (select == 'n') break;
	}
}