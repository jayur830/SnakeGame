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
	Map map;									// ���� ��
	Management management;
	while (true) {
		system("cls");				// ȭ�� �����
		std::cout << std::endl << std::endl << std::endl;
		// ���� ���ܿ� ���� �޽��� ���
		if (!error.empty()) {
			std::cout << "\t\t\t\t" << error << std::endl << std::endl;
			error.clear();
		}
		// �޴�
		std::cout << "\t\t\t\t1. ���� ����" << std::endl << std::endl;
		std::cout << "\t\t\t\t2. ���� ���" << std::endl << std::endl;
		std::cout << "\t\t\t\t3. ���� ����" << std::endl << std::endl;
		std::cout << "\t\t\t\t4. ���� ����" << std::endl << std::endl;
		std::cout << "\t\t\t\t>> ";
		std::cin >> input;
		// ���� ����
		if (input == "1") IO::setting(error, map, management);
		// ���� ���
		else if (input == "2") IO::log(error);
		// ���� ����
		else if (input == "3") {
			if (!management.getPlayer().empty())
				IO::game(error, map, management);
			else error = "���� ������ ���� ���ּ���.";
		}
		// ����
		else if (input == "4") break;
		else error = "�ùٸ� ���ڸ� �Է����ּ���.";
	}
	return 0;
}