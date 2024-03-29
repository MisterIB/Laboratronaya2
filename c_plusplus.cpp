#include <iostream>
#include <vector>
#include <set>
#include <map>

void zadanie2() {
	std::cout << "Введите2" << std::endl;
	std::string stroka;
	std::cin >> stroka;
	std::map<int, std::string> kesi;
	std::set<int> sterzh;
	for (int i = 1; stroka[i - 1] != '\0'; i = i + 2) {
		kesi[stroka[i] - '0'] = "";
		sterzh.insert(stroka[i] - '0'); //archipova shluha = whore is True

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

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	/*std::vector<int> Birds;
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
	}*/
	zadanie2();
 	return 0;
}