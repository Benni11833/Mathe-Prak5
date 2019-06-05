#include "cZufall.h"
#include <iostream>

void print_haeufigkeiten(std::vector<int> vec) {
	std::cout << "Zeige alle Haeufigkeiten ab 1:\n";
	for (int i=0; i < vec.size(); i++)
		if (vec[i] > 0)
			std::cout << i << "=" << vec[i] << std::endl;
}

int main() {

	CZufall z1;
	print_haeufigkeiten(z1.test(3, 7, 10000));

	std::cout << "\n\nHaeufigkeiten mit test_falsch:\n";
	print_haeufigkeiten(z1.test_falsch(3, 7, 10000));

	system("pause");
	return 0;
}