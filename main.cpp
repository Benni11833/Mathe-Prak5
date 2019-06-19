#include "cLotto.h"
#include <iostream>

void print_haeufigkeiten(std::vector<int> vec) {
	std::cout << "Zeige alle Haeufigkeiten ab 1:\n";
	for (int i=0; i < vec.size(); i++)
		if (vec[i] > 0)
			std::cout << i << "=" << vec[i] << std::endl;
}

int main() {

	/*CZufall z1;
	print_haeufigkeiten(z1.test(3, 7, 10000));
	std::cout << "\n\nHaeufigkeiten mit test_falsch:\n";
	print_haeufigkeiten(z1.test_falsch(3, 7, 10000));*/

	CLotto l1{ 0 };

	//Monte-Carlo:
	//a)
	l1.setTippzettel(true);
	//std::cout << l1.lotto_ziehung() << std::endl;
	std::cout << "Wahrscheinlichkeit bei 100k Ziehungen: " << l1.monte_carlo(true, 100000) << std::endl;
	std::cout << "Wahrscheinlichkeit bei 1kk Ziehungen: " << l1.monte_carlo(true, 1000000) << std::endl;
	//b)
	std::cout << "Wahrscheinlichkeit bei 100k Ziehungen: " << l1.monte_carlo(false, 100000) << std::endl;
	std::cout << "Wahrscheinlichkeit bei 1kk Ziehungen: " << l1.monte_carlo(false, 1000000) << std::endl;
	system("pause");
	return 0;
}