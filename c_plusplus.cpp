#include <iostream>
#include <vector>
#include <set>
#include <map>

void SumNumDivThree(int Number, int& Sum) {
	for (; Number > 0; Number = Number / 10) {
		int Figure = Number % 10;
		if (Figure % 3 == 0) Sum = Sum + Figure;
	}
}

void NumberThree() {
	std::cout << "Введите количество чисел" << std::endl;
	int AmountOfNumbers = 0;
	std::cin >> AmountOfNumbers;
	std::cout << "Введите числа" << std::endl;
	int Sum = 0;
	for (int i = 0; i < AmountOfNumbers; i++) {
			int Number = 0;
			std::cin >> Number;
			SumNumDivThree(Number, Sum);
		}
	std::cout << Sum;

}

void NumberTwo() {
	std::cout << "Введите строку" << std::endl;
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
	int AmountOfStones = 0;
	std::cin >> AmountOfStones;
	std::vector<int> stones;
	for (int i = 1;i <= AmountOfStones;i++) {
		stones.push_back(i);
	}
	std::set<int> Result;
	int IsLndngOnAllStone = 0;
	for (int stone: stones) {
		int IsLndngOnStone = 0;
		for (int Bird : Birds) {
			if (Bird == 1) IsLndngOnAllStone = 1;
			if (stone % Bird == 0) IsLndngOnStone = 1;
		}
		if (IsLndngOnStone == 0) Result.insert(stone);
	}
	for (int stone : Result) {
		std::cout << stone << " ";
	}
	if (IsLndngOnAllStone == 1) std::cout << "Птицы сядут на каждый камень";
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