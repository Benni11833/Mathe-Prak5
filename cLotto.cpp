#include "cLotto.h"
#include <iostream>

CLotto::CLotto(int n) {
	if (n < 0)
		z1.initialisiere(time(NULL));
	else
		z1.initialisiere(n);
	tippzettel.resize(0);
}

void CLotto::setTippzettel(bool flag)	//wenn true -> tippzettel wird random gewaehlt
{
	tippzettel.resize(6, -1);
	if (flag) {
		tippzettel = ziehung6_aus_49();
	}
	else {
		int tmp = 0;
		std::cout << "Geben Sie 6 Tippzahlen ein(1-49): ";
		for (int i = 0; i < 6; i++) {
			do {
				std::cin >> tmp;
				if (tmp < 1 || tmp > 49)
					std::cout << tmp << " ist nicht zwischen 1 und 49" << std::endl;
				else if (std::find(tippzettel.begin(), tippzettel.end(), tmp) != tippzettel.end())
					std::cout << tmp << " ist bereits im Tippzettel" << std::endl;
			} while (std::find(tippzettel.begin(), tippzettel.end(), tmp) != tippzettel.end());
			tippzettel[i] = tmp;
		}
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
	z1.initialisiere(time(NULL));
	ziehung.resize(6, -1);
	for (int i = 0; i < 6; i++) {
		//z1.initialisiere(time(NULL));
		do {	//ziehe solange eine neue Zahl, bis sie einzigartig ist
			tmp = z1.wert(1, 49);
		} while (std::find(ziehung.begin(), ziehung.end(), tmp) != ziehung.end());	//solange wie es gefunden wurde im vector
		ziehung[i] = tmp;
	}

	return ziehung;
}

int CLotto::lotto_ziehung() {
	if (tippzettel.size() == 0)
		setTippzettel(true);
	std::vector<int> ziehungen = ziehung6_aus_49();
	std::vector<int> same;	same.resize(0);
	for (int i = 0; i < ziehungen.size(); i++) {
		if (std::find(tippzettel.begin(), tippzettel.end(), ziehungen[i]) != tippzettel.end())	//wenn ziehungen[i] im tippzettel vorkommt
			same.push_back(ziehungen[i]);
	}
	/*std::cout << "Es stimmen " << same.size() << " Zahlen mit den Ziehungen ueberein(";
	for (int i = 0; i < same.size(); i++)
		if (i < same.size() - 1)
			std::cout << same[i] << ",";
		else
			std::cout << same[i];
	std::cout << ")" << std::endl;*/
	return same.size();
}

int CLotto::lotto_ziehung2() {
	int count = lotto_ziehung();
	count += lotto_ziehung();
	return count;
}

long double CLotto::monte_carlo(bool flag, int N)//flag ==true->eine Lottoziehung, false->2lottoziehungen
{
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (flag) {
			if (lotto_ziehung() == 3)
				++count;
		}
		else {
			if (lotto_ziehung2() == 3)
				++count;
		}
	}
	return count / double(N);
}
