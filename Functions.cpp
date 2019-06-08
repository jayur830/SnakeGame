#include "Functions.h"
#include <cmath>

// string->int ��ȯ
int Functions::toInt(std::string s) {
	if (!isInt(s)) return INT_MIN;
	int n = 0;
	for (char c : s) {
		n *= 10;
		n += c - '0';
	}
	return n;
}

// string->float ��ȯ
double Functions::toFloat(std::string s) {
	if (!isFloat(s)) return DBL_MIN;
	int floatPoint = s.find('.');
	std::string integer = s.substr(0, floatPoint), minority = s.substr(floatPoint + 1);
	double number = toInt(integer);
	number += (double)toInt(minority) / (double)minority.size();
	return number;
}

// int->string ��ȯ
std::string Functions::toString(int n) {
	std::string s;
	if (n != 0) {
		s.append(toString(n / 10));
		s.push_back(n - ((n / 10) * 10) + '0');
	}
	return s;
}

// double->string ��ȯ
std::string Functions::toString(double n) {
	double temp = n;
	int count = 0, integer, minority;
	while (temp - (int)temp != 0) {
		++count;
		temp *= 10;
	}
	count = pow(10, count);
	integer = temp / count;
	minority = temp - (integer * count);
	return std::string(Functions::toString(integer)).append(".").append(Functions::toString(minority));
}

// �ش� ���ڿ��� ���� ������ ���ڸ� �����ϴ����� ���� �˻�
bool Functions::isInt(std::string s) {
	for (char c : s)
		if (c < '0' || c > '9') return false;
	return true;
}

// �ش� ���ڰ� �������������� ���� �˻�
bool Functions::isInt(char c) {
	if (c < '0' || c > '9') return false;
	return true;
}

// �ش� ���ڿ��� �Ǽ� ������ ���ڸ� �����ϴ����� ���� �˻�
bool Functions::isFloat(std::string s) {
	int index = s.find('.');
	if (index != -1) return isInt(s);
	else {
		if ((int)s.find('.', index) != -1) return false;
		else {
			s.erase(s.begin() + index);
			return isInt(s);
		}
	}
}

// �ش� ���� a�� b �������� �˻�
bool Functions::inRangeValue(int value, int a, int b) {
	return value >= a && value <= b;
}

// �ش� ���� a�� b �������� �˻�, �����ε�
bool Functions::inRangeValue(int value, std::string a, std::string b) {
	return value >= toInt(a) && value <= toInt(b);
}

// �ش� ���� a�� b �������� �˻�, �����ε�
bool Functions::inRangeValue(std::string value, int a, int b) {
	int n = toInt(value);
	return n >= a && n <= b;
}

// �ش� ���� a�� b �������� �˻�, �����ε�
bool Functions::inRangeValue(std::string value, std::string a, std::string b) {
	int n = toInt(value);
	return n >= toInt(a) && n <= toInt(b);
}

// �ش� ���ڿ��� ���� ���� ����
std::string Functions::trim(std::string s) {
	int a = 0, b = s.size() - 1;
	for (int& i = a; i < s.size() && s[i] == ' '; ++i);
	if (s.empty()) return "";
	for (int& i = b; i < s.size() && s[i] == ' '; --i);
	return s.substr(a, b - a + 1);
	return "";
}