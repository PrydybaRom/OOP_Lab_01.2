#include <iostream>
#include "Account.h"

int main()
{
	Account g;
	g.Init("Roman",1, 8, 395.56);
	g.Display();
	cout << "Amount in words: " << g.numberToWords() << endl;
	cout << " " << g.getDollar() << " DOLLAR" << endl;
	cout << " " << g.getEuro() << " EURO" << endl;
	g.Display();
	g.plusMoney(100);
	g.Display();
	g.minMoney(200);
	g.Display();
	g.plusProcent();
	g.Display();
	

	return 0;
}
