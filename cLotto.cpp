#include "cLotto.h"
#include <iostream>

CLotto::CLotto(int n) {
	if (n < 0)
		z1.initialisiere(time(NULL));
	else
		z1.initialisiere(n);
}

void CLotto::setTippzettel()
{
	std::cout << "Geben Sie 6 Tippzahlen ein: ";
	for (int i = 0; i < 6; i++) {
		std::cin >> tippzettel[i];
	}
	std::cout << "Tippzettel: ";
	for (int i = 0; i < tippzettel.size(); i++)
		if (i < tippzettel.size() - 1)
			std::cout << tippzettel[i] << ",";
		else
			std::cout << tippzettel[i];
	std::cout << std::endl;
}

std::vector<int> CLotto::ziehung6_aus_49()
{
	std::vector<int> ziehung;
	int tmp = -1;
	bool flag = false;
	CZufall z1;
	ziehung.resize(6, -1);
	for (int i = 0; i < 6; i++) {
		//z1.initialisiere(time(NULL));
		do {
			tmp = z1.wert(1, 49);
			flag = true;
			for (int i = 0; i < ziehung.size(); i++)
				if (tmp == ziehung[i])
					flag == false;
		} while (!flag);
		ziehung[i] = tmp;
	}

	return ziehung;
}

int CLotto::lotto_ziehung() {
	std::vector<int> ziehungen = ziehung6_aus_49();
	std::vector<int> same;	same.resize(0);
	for (int i = 0; i < ziehungen.size(); i++) {
		if (ziehungen[i] == tippzettel[i])
			same.push_back(ziehungen[i]);
	}
	std::cout << "Es stimmen " << same.size() << " Zahlen mit den Ziehungen ueberein(";
	for (int i = 0; i < same.size(); i++)
		if (i < same.size() - 1)
			std::cout << same[i] << ",";
		else
			std::cout << same[i];
	std::cout << std::endl;
	return same.size();
}

int CLotto::lotto_ziehung2() {
	int count = lotto_ziehung();
	count += lotto_ziehung();
}