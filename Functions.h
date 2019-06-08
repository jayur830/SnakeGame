#pragma once
#include <string>

// �������� ����� ���� Ŭ����
class Functions {
public:
	static int toInt(std::string);																	// string->int ��ȯ
	static double toFloat(std::string);														// string->float ��ȯ
	static std::string toString(int);															// int->string ��ȯ
	static std::string toString(double);														// double->string ��ȯ
	static bool isInt(std::string);																// �ش� ���ڿ��� ���� ������ ���ڸ� �����ϴ����� ���� �˻�
	static bool isInt(char);																		// �ش� ���ڰ� �������������� ���� �˻�
	static bool isFloat(std::string);															// �ش� ���ڿ��� �Ǽ� ������ ���ڸ� �����ϴ����� ���� �˻�
	static bool inRangeValue(int, int, int);												// �ش� ���� a�� b �������� �˻�
	static bool inRangeValue(int, std::string, std::string);							// �ش� ���� a�� b �������� �˻�, �����ε�
	static bool inRangeValue(std::string, int, int);										// �ش� ���� a�� b �������� �˻�, �����ε�
	static bool inRangeValue(std::string, std::string, std::string);				// �ش� ���� a�� b �������� �˻�, �����ε�
	static std::string trim(std::string);														// �ش� ���ڿ��� ���� ���� ����
};