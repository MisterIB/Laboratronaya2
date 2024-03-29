#include <iostream>
#include <vector>
#include <set>
#include <map>

void NumberThree() {
	std::cout << "Введите количество чисел" << std::endl;
	int n = 0;
	std::cin >> n;
	std::cout << "Введите числа" << std::endl;
	std::vector<int> Numbers;
	for (int i = 0; i < n; i++) {
		int n1 = 0;
		std::cin >> n1;
		Numbers.push_back(n1);
	}
	int Summ = 0;
	for (int Number : Numbers) {
		for (int Figure = 0;Number > 0;Number = Number / 10) {
			Figure = Number % 10;
			if (Figure % 3 == 0) Summ = Summ + Figure;
		}
	}
	std::cout << Summ;
}

void NumberTwo() {
	std::cout << "Введите2" << std::endl;
	std::string TextLine;
	std::cin >> TextLine;
	std::map<int, std::string> ColorsRings;
	std::set<int> Kernels;
	for (int i = 1; TextLine[i - 1] != '\0'; i = i + 2) {
		ColorsRings[TextLine[i] - '0'] = "";
		Kernels.insert(TextLine[i] - '0');

	}
	for (int i = 1; TextLine[i-1] != '\0'; i = i + 2) {
		ColorsRings[TextLine[i] - '0'] = ColorsRings[TextLine[i] - '0'] + TextLine[i-1];
	}
	for (int i = 0; i < 3;i++) {
		std::cout << ColorsRings[i] << " ";
	}
	int count = 0;
	for (int Kernel: Kernels){
		if (ColorsRings[Kernel].find('R') != std::string::npos and ColorsRings[Kernel].find('W') != std::string::npos and ColorsRings[Kernel].find('B') != std::string::npos) count += 1;
	}
	std::cout << " " << count;
}

void NumberOne() {
	std::vector<int> Birds;
	std::cout << "Введите дальность полета каждой птицы, чтобы перейти к следющему шагу введите 0" << std::endl;
	for (int FlightRange;1; FlightRange = 0){
		std::cin >> FlightRange;
		if (FlightRange == 0) break;
		Birds.push_back(FlightRange);
	}
	std::cout << "Введите количество валунов" << std::endl;
	int stones = 0;
	std::cin >> stones;
	std::vector<int> result;
	for (int i = 1;i <= stones;i++) {
		result.push_back(i);
	}
	std::set<int> res;
	int flag = 0;
	for (int stone: result) {
		flag = 0;
		for (int Bird : Birds) {
			if (stone % Bird == 0) flag = 1;
		}
		if (flag == 0) res.insert(stone);
	}
	for (int stone : res) {
		std::cout << stone << " ";
	}
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	std::cout << "Выберите номер задания" << std::endl;
	int TaskNumber = 0;
	std::cin >> TaskNumber;
	switch (TaskNumber) {
	case 1:
		NumberOne();
		break;
	case 2:
		NumberTwo();
		break;
	case 3:
		NumberThree();
		break;
	default:
		break;
	}
 	return 0;
}