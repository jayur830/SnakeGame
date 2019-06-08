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

// ���� �ҽ�, �ܼ��� Ŀ�� ��ġ ����
void IO::gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// ���� ����
void IO::setting(std::string& error, Map& map, Management& management) {
	bool back = false;
	std::string player, size_hori, size_ver, _length, _speed;
	std::pair<int, int> size;
	int length;
	double speed;
	system("cls");
	std::cout << std::endl << std::endl;
	// �÷��̾� �̸� �Է�
	getchar();
	while (true) {
		std::cout << std::endl << "\t\t\t\t�÷��̾� �̸� : ";
		getline(std::cin, player);														// �� �� ������ �Է�
		if (player.empty() || Functions::trim(player).empty())			// �׳� ���͸� �ưų� ���鸸 �Է����� ���
			std::cout << std::endl << "\t\t\t\t�÷��̾� �̸��� �Է����ּ���." << std::endl;
		else {
			if (Functions::trim(player) == "0") back = true;				// ���� ȭ�� ���ư���
			break;
		}
	}
	// ���� ȭ�� ���ư���
	if (back) {
		error = "���� ȭ������ ���ƿԽ��ϴ�.";
		return;
	}
	// �� ũ�� �Է�
	while (true) {
		std::cout << std::endl << "\t\t\t\t�� ũ�� : ";
		std::cin >> size_hori >> size_ver;
		// ���� ȭ�� ���ư���
		if (size_hori == "0" || size_ver == "0") {
			back = true;
			break;
		}
		// �Է��� ���ڰ� �ƴ� ���
		if (!Functions::isInt(size_hori) || !Functions::isInt(size_ver))
			std::cout << std::endl << "\t\t\t\t1���� 100������ ���ڷ� �Է����ּ���." << std::endl;
		else {
			// 1���� 100 �������� üũ
			if (!Functions::inRangeValue(size_hori, 1, 100) || !Functions::inRangeValue(size_ver, 1, 100))
				std::cout << std::endl << "\t\t\t\t1���� 100������ ���ڷ� �Է����ּ���." << std::endl;
			else {
				size.first = Functions::toInt(size_hori);
				size.second = Functions::toInt(size_ver);
				break;
			}
		}
	}
	// ���� ȭ�� ���ư���
	if (back) {
		error = "���� ȭ������ ���ƿԽ��ϴ�.";
		return;
	}
	// ������ũ ���� �Է�
	while (true) {
		std::cout << std::endl << "\t\t\t\t������ũ ����(1~10) : ";
		std::cin >> _length;
		// ���� ȭ�� ���ư���
		if (_length == "0") {
			back = true;
			break;
		}
		// �Է��� ���ڰ� �ƴ� ���
		if (!Functions::isInt(_length))
			std::cout << std::endl << "\t\t\t\t1���� 10������ ���ڷ� �Է����ּ���." << std::endl;
		else {
			// 1���� 10������ ������ �ƴ� ���
			if (!Functions::inRangeValue(_length, 1, 10))
				std::cout << std::endl << "\t\t\t\t1���� 10������ ���ڷ� �Է����ּ���." << std::endl;
			else {
				length = Functions::toInt(_length);
				break;
			}
		}
	}
	// ���� ȭ�� ���ư���
	if (back) {
		error = "���� ȭ������ ���ƿԽ��ϴ�.";
		return;
	}
	// ���� �ӵ� �Է�
	while (true) {
		std::cout << std::endl << "\t\t\t\t���� �ӵ�(1 = 0.1msec) : ";
		std::cin >> _speed;
		// ���� ȭ�� ���ư���
		if (_speed == "0") {
			back = true;
			break;
		}
		// �Է��� ���ڰ� �ƴ� ���
		if (!Functions::isInt(_speed))
			std::cout << std::endl << "\t\t\t\t1���� 10������ ���ڷ� �Է����ּ���." << std::endl;
		else {
			speed = (double)Functions::toInt(_speed);
			break;
		}
	}
	// ���� ȭ�� ���ư���
	if (back) {
		error = "���� ȭ������ ���ƿԽ��ϴ�.";
		return;
	}
	map = Map(size.second, size.first);											// ���� �� �ʱ�ȭ
	management = Management(player, size, length, speed);		// ���� ���� �ʱ�ȭ
	error = "���� ������ �Ϸ�Ǿ����ϴ�.";
}

// ���� ���
void IO::log(std::string& error) {
	// ���α׷��� ���� 7. ���� ����� ���Ϸ� ���� / ����� ��
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
	else error = "���� ���� ����� �����ϴ�.";
	fin.close();
}

// ���� ����
void IO::game(std::string& error, Map& _map, Management& management) {
	// ���� ���� �� ȭ�� ���
	while (true) {
		system("cls");
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "========================================================================================================================" << std::endl;
		std::cout << "\t\t\t\t\t\t������ ��������? (y/n)" << std::endl;
		std::cout << "========================================================================================================================" << std::endl;
		std::cout << "\t\t\t\t\t\t>> ";
		char c = _getch();						// Ű���� �Է� ���۸� ��ġ�� �ʰ� Ű���带 ������ ���� �̺�Ʈ �߻�
		if (c == 'y') break;
		else if (c == 'n') {
			error = "���� ȭ������ ���ƿԽ��ϴ�.";
			return;
		}
	}
	// ���������� ���� ����
	while (true) {
		system("cls");
		std::vector<std::vector<char>> map = _map.getMap();					// ���α׷��� ���� 6. �迭 ��� STL Vector�� ����� ��
		int verticalSize = map.size(), horizontalSize = map[0].size();				// ���� �� ���� ���̿� ���� ����
		for (int i = 0; i < verticalSize; ++i) {									// ���� �� ���
			for (int j = 0; j < horizontalSize; ++j)
				std::cout << map[i][j];
			std::cout << std::endl;
		}
		int key = UP, input = 224, score = 0,				// Ű �Է°� �� ���� ���� ����, ���� ���� ����, ����
			preScore = management.getScore(management.getPlayer()), rank;
		Snake snake(verticalSize / 2, horizontalSize / 2, management.getLength());				// ������ũ ��ü ����
		Controller controller;																								// Ű �Է��� ���� ��ü ����
		std::pair<int, int> head, pre(std::pair<int, int>(-1, -1)), food(std::pair<int, int>(-1, -1));
		std::deque<std::pair<int, int>> body;												// ���α׷��� ���� 6. �迭 ��� STL Vector�� ����� ��(���⼭�� �� ���� ����, ������ ���� deque ���)
		double speed = management.getSpeed() * 100;								// ���� �ӵ�
		while (true) {
			Sleep(speed);																				// �����ߴ� ���� �ӵ���ŭ �ð� ����
			head = snake.getHead();																// �Ӹ�
			body = snake.getBody();																// ����
			// ���̰� �������� �ʾ��� �� ����, -1�� �ʱⰪ
			if (food.first == -1 && food.second == -1) {
				do {
					srand(clock());													// ���� ����
					int y = rand() % (verticalSize - 2) + 1;				// ���� ����
					srand(clock());													// ���� ����
					int x = rand() % (horizontalSize - 2) + 1;			// ���� ����
					food = std::pair<int, int>(y, x);							// ���� ��ǥ ����
					// ������ ������ ���� ��ǥ�� ������ũ�� �Ӹ� �Ǵ� ������ ��� �Ϻκа��� ��ġ�� ������ break
				} while (head == food || std::find(body.begin(), body.end(), food) != body.end());
				// �ش� ���� ��ǥ�� �ܼ� Ŀ�� �̵� �� ����('*') ���
				gotoxy(food.second, food.first);
				std::cout << "*";
			}
			// �Ӹ��� ���� �ε����� ���
			if (head.first == 0 || head.first == verticalSize - 1 ||
				head.second == 0 || head.second == horizontalSize - 1) break;
			// �Ӹ��� ���뿡 �ε����� ���
			else if (!body.empty() && std::find(body.begin(), body.end(), head) != body.end()) break;
			snake.feed(food, score);									// �ȳ�, ����
			// ������ũ�� �� �󿡼� �����ƴٴ� �� �� ĭ �̵��� ��ŭ �� ĭ �����ִ� �ڵ�
			if (pre.first != -1 && pre.first != -1) {
				gotoxy(pre.second, pre.first);
				std::cout << " \b";
			}
			// ������ �����ϴ� ���
			if (!body.empty())
				// ������ ��� �κ� ���
				for (std::pair<int, int> loc : body) {
					gotoxy(loc.second, loc.first);
					std::cout << "#\b";
				}
			// �Ӹ� ���
			gotoxy(head.second, head.first);
			std::cout << "@\b";
			// ���� ��ǥ(pre)���� ������ ���� ��ǥ�� �ʱ�ȭ, ������ ���� ��쿡�� �Ӹ� ��ǥ�� �ʱ�ȭ
			if (!body.empty()) pre = body.back();
			else pre = head;
			controller.setKey();							// ����Ű �Է�
			key = controller.getKey();					// Ű �� ���
			if (input == 224) {
				if (key == LEFT) snake.setLocation(head.first, head.second - 1);						// ���� �̵�
				else if (key == RIGHT) snake.setLocation(head.first, head.second + 1);			// ������ �̵�
				else if (key == UP) snake.setLocation(head.first - 1, head.second);				// ���� �̵�
				else if (key == DOWN) snake.setLocation(head.first + 1, head.second);		// �Ʒ��� �̵�
			}
		}
		char select;
		std::string player = management.getPlayer();			// ���� �÷��̾� �̸� ���
		management.setRank(player, score);						// ���� ����
		rank = management.getRank(player);						// �÷��̾��� ���� ���
		// ������ ���� �� ��� ���
		while (true) {
			system("cls");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "========================================================================================================================" << std::endl;
			std::cout << "\t\t\t\t\t";
			// ������ ��� �������� ���� ���� ������ �� ���� ��쿡�� ����
			if (preScore < score) {
				if (rank == 1) std::cout << "�����մϴ�! 1���Դϴ�. ";
				else if (rank == 2) std::cout << "�Ʊ��׿�. 2���Դϴ�. ";
				else if (rank == 3) std::cout << "������ �ƽ����ϴ�. 3���Դϴ�. ";
				else if (rank == 4 || rank == 5) std::cout << "���� �� �й��ϼ���. " << rank << "���Դϴ�. ";
			}
			std::cout << "�ٽ� �����Ͻðڽ��ϱ�? (y/n)" << std::endl;
			std::cout << "========================================================================================================================" << std::endl;
			std::cout << "\t\t\t\t\t>> ";
			if ((select = _getch()) == 'n' || select == 'y') break;				// Yes �Ǵ� No �� ���� break
		}
		// No�̸� break �� �ش� �Լ� ����, Yes�� �ٽ� �� �� ���� �б�
		if (select == 'n') break;
	}
}