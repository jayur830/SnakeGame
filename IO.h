#pragma once
#include "Map.h"
#include "Management.h"

// ����� ���� Ŭ����
class IO {
	static void gotoxy(int, int);					// ���� �ҽ�, �ܼ��� Ŀ�� ��ġ ����
public:
	static void setting(std::string&, Map&, Management&);			// ���� ����
	static void log(std::string&);														// ���� ���
	static void game(std::string&, Map&, Management&);				// ���� ����
};