#pragma once
#include <string>

// 여러가지 기능을 가진 클래스
class Functions {
public:
	static int toInt(std::string);																	// string->int 변환
	static double toFloat(std::string);														// string->float 변환
	static std::string toString(int);															// int->string 변환
	static std::string toString(double);														// double->string 변환
	static bool isInt(std::string);																// 해당 문자열이 숫자 형태의 문자만 포함하는지의 여부 검사
	static bool isInt(char);																		// 해당 문자가 숫자형태인지의 여부 검사
	static bool isFloat(std::string);															// 해당 문자열이 실수 형태의 문자만 포함하는지의 여부 검사
	static bool inRangeValue(int, int, int);												// 해당 값이 a와 b 사이인지 검사
	static bool inRangeValue(int, std::string, std::string);							// 해당 값이 a와 b 사이인지 검사, 오버로딩
	static bool inRangeValue(std::string, int, int);										// 해당 값이 a와 b 사이인지 검사, 오버로딩
	static bool inRangeValue(std::string, std::string, std::string);				// 해당 값이 a와 b 사이인지 검사, 오버로딩
	static std::string trim(std::string);														// 해당 문자열의 양쪽 공백 제거
};