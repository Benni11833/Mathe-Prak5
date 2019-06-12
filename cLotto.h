#include "cZufall.h"

class CLotto {
private:
	std::vector<int> tippzettel;
	CZufall z1;
public:
	CLotto(int n);
	void setTippzettel(bool flag);
	std::vector <int> ziehung6_aus_49();
	int lotto_ziehung();
	int lotto_ziehung2();
	long double monte_carlo(bool flag, int N);
};