#include "Management.h"
#include <fstream>
#include <algorithm>

// 정렬에 사용될 비교 기준
bool Management::compare(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
	return a.second > b.second;
}

// 생성자
Management::Management() : player(""), size(std::pair<int, int>(0, 0)), length(0), speed(0) {
	// 프로그래밍 조건 7. 게임 기록은 파일로 저장 / 출력할 것
	std::ifstream fin;
	fin.open("rank.txt", std::ios_base::in);
	if (fin.is_open()) {
		std::string temp, player, score;
		while (!fin.eof()) {
			fin >> temp >> temp >> player >> temp >> score;
			setRank(player, Functions::toInt(score.substr(0, score.find("점"))));
		}
	}
	fin.close();
}

// 초기화 생성자
Management::Management(std::string _player, std::pair<int, int> _size, int _length, double _speed) :
	player(_player), size(_size), length(_length), speed(_speed) {}

// 복사 생성자
Management::Management(const Management& object) :
	player(object.player), size(object.size), length(object.length), speed(object.speed) {}

// 플레이어 이름 Getter 함수
std::string Management::getPlayer() {
	return this->player;
}

// 스네이크 길이 Getter 함수
int Management::getLength() {
	return this->length;
}

// 게임 속도 Getter 함수
double Management::getSpeed() {
	return this->speed;
}

// 순위 Setter 함수, 플레이어 이름과 점수로 해당 플레이어 순위 초기화
void Management::setRank(std::string player, int score) {
	if (this->rank.size() < 5) {
		// C++ 람다표현식 - https://thrillfighter.tistory.com/276
		// 플레이어 존재 유무 검사, 존재하지 않으면 -1을 반환
		int index = [](									// C++ 람다 함수, 외부에서 쓰일 일이 없기 때문에 함수 내에서 람다로 정의하여 사용
			std::vector<std::pair<std::string, int>> rank,				// 프로그래밍 조건 6. 배열 대신 STL Vector만 사용할 것
			std::string player) -> int {
			for (int i = 0; i < rank.size(); ++i)
				if (rank[i].first == player) return i;
			return -1;
		}(this->rank, player);
		// 해당 플레이어가 전체 순위안에 아직 존재하지 않는 경우
		if (index == -1) {
			this->rank.push_back(std::pair<std::string, int>(player, score));							// 순위에 플레이어 추가
			std::sort(this->rank.begin(), this->rank.end(), Management::compare);				// 정렬
		}
		// 해당 플레이어가 전체 순위안에 존재하고, 기존 점수보다 새로 얻은 점수가 더 높을 경우
		else if (this->rank[index].second < score) {
			this->rank[index].second = score;																		// 점수 갱신
			std::sort(this->rank.begin(), this->rank.end(), Management::compare);				// 정렬
		}
	}
	// 전체 순위에 한 명의 플레이어라도 존재하는 경우
	if (!this->rank.empty()) {
		// 프로그래밍 조건 7. 게임 기록은 파일로 저장 / 출력할 것
		std::ofstream fout;
		fout.open("rank.txt", std::ios_base::out);								// 파일 열기
		for (int i = 0; i < this->rank.size(); ++i)
			fout << i + 1 << "등 : " << this->rank[i].first << " - " 
				<< this->rank[i].second << "점" << std::endl;
		fout.close();																			// 파일 닫기
	}
}

// 순위 Getter 함수, 플레이어 이름으로 검색
int Management::getRank(std::string player) {
	for (int i = 0; i < this->rank.size(); ++i)
		// i번째 플레이어의 이름과 매개변수 플레이어 이름이 같다면 i + 1(순위)을 반환
		if (this->rank[i].first == player) return i + 1;
}

// 전체 플레이어 순위 Getter 함수, 프로그래밍 조건 6. 배열 대신 STL Vector만 사용할 것
std::vector<std::pair<std::string, int>> Management::getRank() {
	return this->rank;
}

// 게임 점수 Getter 함수
int Management::getScore(std::string player) {
	for (std::pair<std::string, int> _player : this->rank)
		if (_player.first == player) return _player.second;					// 플레이어를 찾은 경우 해당 플레이어의 점수 반환
	return -1;						// 해당 플레이어를 못찾았을 경우
}

// 객체 대입 연산자, 복사 생성자와 기능 동일
Management& Management::operator=(const Management & object) {
	this->player = object.player;
	this->size = object.size;
	this->length = object.length;
	this->speed = object.speed;
	return *this;
}