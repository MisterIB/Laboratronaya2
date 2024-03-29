#include <iostream>
#include <vector>
#include <set>
#include <map>

void zadanie3() {
	std::cout << "Введите3" << std::endl;
	int n = 0;
	std::cin >> n;
	std::vector<int> chisla;
	for (int i = 0; i < n; i++) {
		int n1 = 0;
		std::cin >> n1;
		chisla.push_back(n1);
	}
	int summa = 0;
	for (int chislo : chisla) {
		for (int cifra = 0; chislo > 0;chislo = chislo / 10) {
			cifra = chislo % 10;
			if (cifra % 3 == 0) summa = summa + cifra;
		}
	}
	std::cout << summa;
	/*for (int item : chisla) {
		std::cout << item;
	}*/
}

void zadanie2() {
	std::cout << "Введите2" << std::endl;
	std::string stroka;
	std::cin >> stroka;
	std::map<int, std::string> kesi;
	std::set<int> sterzh;
	for (int i = 1; stroka[i - 1] != '\0'; i = i + 2) {
		kesi[stroka[i] - '0'] = "";
		sterzh.insert(stroka[i] - '0');

	}
	for (int i = 1; stroka[i-1] != '\0'; i = i + 2) {
		kesi[stroka[i] - '0'] = kesi[stroka[i] - '0'] + stroka[i-1];
	}
	for (int i = 0; i < 3;i++) {
		std::cout << kesi[i] << " ";
	}
	int cout = 0;
	for (int sterzhen: sterzh){
		if (kesi[sterzhen].find('R') != std::string::npos and kesi[sterzhen].find('W') != std::string::npos and kesi[sterzhen].find('B') != std::string::npos) cout += 1;
	}
	std::cout << " " << cout;
	/*for (int i = 0;stroka[i] != '\0'; i =i +2) {
		char first;
		first = stroka[i];
		int second;
		second = stroka[i+1] - '0';
		sterz.push_back({first, second});
		
	}
	for (std::pair<char, int> test : sterz) {
		std::cout << test.first << " " << test.second;
	}
*/

}

void zadanie1() {
	std::vector<int> Birds;
	std::cout << "Введите1" << std::endl;
	for (int over_stns;1;over_stns = 0){
		std::cin >> over_stns;
		if (over_stns == 0) break;
		Birds.push_back(over_stns);
	}
	int stones = 10;
	std::vector<int> result;
	for (int i = 1;i <= stones;i++) {
		result.push_back(i);
	}
	std::set<int> res;
	int flag = 0;
	for (int stone: result) {
		flag = 0;
		for (int ptica : Birds) {
			if (stone % ptica == 0) flag = 1;
		}
		if (flag == 0) res.insert(stone);
	}
	for (int stone : res) {
		std::cout << stone << " ";
	}
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	std::cout << "Какое задание решить хочешь" << std::endl;
	int zdn = 0;
	std::cin >> zdn;
	switch (zdn) {
	case 1:
		zadanie1();
		break;
	case 2:
		zadanie2();
		break;
	case 3:
		zadanie3();
		break;
	default:
		break;
	}
 	return 0;
}