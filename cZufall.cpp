#include "cZufall.h"

int CZufall::wert(int a, int b) {
	return rand() % b + a;
}

void CZufall::initialisiere(int n) {
	srand(n);
}

std::vector<int> CZufall::test(int a, int b, int N) {
	std::vector<int> haeufigkeit_vec;
	haeufigkeit_vec.resize(N, 0);
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		tmp = wert(a, b);
		++haeufigkeit_vec[tmp];
	}

	return haeufigkeit_vec;
}

std::vector<int> CZufall::test_falsch(int a, int b, int N) {
	std::vector<int> haeufigkeit_vec;
	haeufigkeit_vec.resize(N, 0);
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		initialisiere(time(NULL));
		tmp = wert(a, b);
		++haeufigkeit_vec[tmp];
	}

	return haeufigkeit_vec;
}