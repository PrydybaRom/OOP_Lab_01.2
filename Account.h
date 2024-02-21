#pragma once

#include <cmath>
#include <string>
#include <sstream> 
using namespace std;
class Account
{
private:
	string name;
	int no;
	double procent;
	double price;

public:
	string getName() const { return name; }
	int getNo() const { return no; }
	double getProcent() const { return procent; }
	double getPrice() const { return price; }

	void setName(string);
	bool setNo(int);
	bool setProcent(double);
	bool setPrice(double);

	double getDollar() const { return price / 38; }
	double getEuro() const { return price / 41; }
	void plusMoney(double);
	void minMoney(double);
	void plusProcent();

	string numberToWords();

	bool Init(string name, int no, double count, double price);
	void Read();
	void Display() const;
};


