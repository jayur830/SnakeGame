#include "Management.h"
#include <fstream>
#include <algorithm>

// ���Ŀ� ���� �� ����
bool Management::compare(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
	return a.second > b.second;
}

// ������
Management::Management() : player(""), size(std::pair<int, int>(0, 0)), length(0), speed(0) {
	// ���α׷��� ���� 7. ���� ����� ���Ϸ� ���� / ����� ��
	std::ifstream fin;
	fin.open("rank.txt", std::ios_base::in);
	if (fin.is_open()) {
		std::string temp, player, score;
		while (!fin.eof()) {
			fin >> temp >> temp >> player >> temp >> score;
			setRank(player, Functions::toInt(score.substr(0, score.find("��"))));
		}
	}
	fin.close();
}

// �ʱ�ȭ ������
Management::Management(std::string _player, std::pair<int, int> _size, int _length, double _speed) :
	player(_player), size(_size), length(_length), speed(_speed) {}

// ���� ������
Management::Management(const Management& object) :
	player(object.player), size(object.size), length(object.length), speed(object.speed) {}

// �÷��̾� �̸� Getter �Լ�
std::string Management::getPlayer() {
	return this->player;
}

// ������ũ ���� Getter �Լ�
int Management::getLength() {
	return this->length;
}

// ���� �ӵ� Getter �Լ�
double Management::getSpeed() {
	return this->speed;
}

// ���� Setter �Լ�, �÷��̾� �̸��� ������ �ش� �÷��̾� ���� �ʱ�ȭ
void Management::setRank(std::string player, int score) {
	if (this->rank.size() < 5) {
		// C++ ����ǥ���� - https://thrillfighter.tistory.com/276
		// �÷��̾� ���� ���� �˻�, �������� ������ -1�� ��ȯ
		int index = [](									// C++ ���� �Լ�, �ܺο��� ���� ���� ���� ������ �Լ� ������ ���ٷ� �����Ͽ� ���
			std::vector<std::pair<std::string, int>> rank,				// ���α׷��� ���� 6. �迭 ��� STL Vector�� ����� ��
			std::string player) -> int {
			for (int i = 0; i < rank.size(); ++i)
				if (rank[i].first == player) return i;
			return -1;
		}(this->rank, player);
		// �ش� �÷��̾ ��ü �����ȿ� ���� �������� �ʴ� ���
		if (index == -1) {
			this->rank.push_back(std::pair<std::string, int>(player, score));							// ������ �÷��̾� �߰�
			std::sort(this->rank.begin(), this->rank.end(), Management::compare);				// ����
		}
		// �ش� �÷��̾ ��ü �����ȿ� �����ϰ�, ���� �������� ���� ���� ������ �� ���� ���
		else if (this->rank[index].second < score) {
			this->rank[index].second = score;																		// ���� ����
			std::sort(this->rank.begin(), this->rank.end(), Management::compare);				// ����
		}
	}
	// ��ü ������ �� ���� �÷��̾�� �����ϴ� ���
	if (!this->rank.empty()) {
		// ���α׷��� ���� 7. ���� ����� ���Ϸ� ���� / ����� ��
		std::ofstream fout;
		fout.open("rank.txt", std::ios_base::out);								// ���� ����
		for (int i = 0; i < this->rank.size(); ++i)
			fout << i + 1 << "�� : " << this->rank[i].first << " - " 
				<< this->rank[i].second << "��" << std::endl;
		fout.close();																			// ���� �ݱ�
	}
}

// ���� Getter �Լ�, �÷��̾� �̸����� �˻�
int Management::getRank(std::string player) {
	for (int i = 0; i < this->rank.size(); ++i)
		// i��° �÷��̾��� �̸��� �Ű����� �÷��̾� �̸��� ���ٸ� i + 1(����)�� ��ȯ
		if (this->rank[i].first == player) return i + 1;
}

// ��ü �÷��̾� ���� Getter �Լ�, ���α׷��� ���� 6. �迭 ��� STL Vector�� ����� ��
std::vector<std::pair<std::string, int>> Management::getRank() {
	return this->rank;
}

// ���� ���� Getter �Լ�
int Management::getScore(std::string player) {
	for (std::pair<std::string, int> _player : this->rank)
		if (_player.first == player) return _player.second;					// �÷��̾ ã�� ��� �ش� �÷��̾��� ���� ��ȯ
	return -1;						// �ش� �÷��̾ ��ã���� ���
}

// ��ü ���� ������, ���� �����ڿ� ��� ����
Management& Management::operator=(const Management & object) {
	this->player = object.player;
	this->size = object.size;
	this->length = object.length;
	this->speed = object.speed;
	return *this;
}