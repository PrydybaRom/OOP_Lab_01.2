
#include "Account.h"
#include <iostream>

using namespace std;
void Account::setName(string value)
{
	name = value;
}
bool Account::setNo(int value)
{
	if (value > 0)
	{
		no = value;
		return true;
	}
	else
	{
		no = 0;
		return false;
	}
}
bool Account::setProcent(double value)
{
	if (value > 0)
	{
		procent = value;
		return true;
	}
	else
	{
		procent = -value;
		return false;
	}
}
bool Account::setPrice(double value)
{
	if (value > 0)
	{
		price = value;
		return true;
	}
	else
	{
		price = -value;
		return false;
	}
}

void Account::plusMoney(double money) {
	price = price + money;
}
void Account::minMoney(double money) {
	price = price - money;
}

void Account::plusProcent()
{
	price = price + (price/100)*procent;
}


bool Account::Init(string name, int no, double procent, double price)
{
	setName(name);
	return setNo(no) && setProcent(procent) && setPrice(price);
}

void Account::Read()
{
	string name;
	int no;
	double procent;
	double price;
	cout << " name = ? "; cin >> name;
	do
	{
		cout << " no = ? "; cin >> no;
		cout << " procent = ? "; cin >> procent;
		cout << " price = ? "; cin >> price;
	} while (!Init(name, no, procent, price));
}
void Account::Display() const
{
	cout << " name = " << name << endl;
	cout << " no = " << no << endl;
	cout << " procent = " << procent << endl;
	cout << " price = " << price << endl;
}



string Account::numberToWords() {
    // Розділення на гривні та копійки
    int grivnas = static_cast<int>(price);
    int kopecks = static_cast<int>((price - grivnas) * 100);

    // Масиви з літерами, що використовуються для перетворення числа в слова
    const std::string units[] = { "", "odin", "dva", "tri", "chotiri", "piat", "shist", "sim", "visim", "deviat" };
    const std::string teens[] = { "desiat", "odinatsiat", "dvanatsiat", "trinadsiat", "chitirnatsiat", "piatnadsia", "sichnadsiat", "simnadsiat", "visimnadsiat", "devaitnadsiat" };
    const std::string tens[] = { "", "", "dvadsiat", "tridsat", "sorok", "piatdesat", "shistdesat", "simdesat", "visimdesat", "devainosto" };
    const std::string hundreds[] = { "", "sto", "dvista", "trista", "chotirista", "piatsot", "shisot", "simsot", "visimsot", "deviatsot" };
    const std::string thousands[] = { "", "tisacha", "tisachi", "tisach" };
    const std::string millions[] = { "", "milion", "miliona", "milioniv" };

    // Число в словах
    std::string result;

    // Гривні
    int unit = grivnas % 10;
    int ten = (grivnas % 100) / 10;
    int hundred = (grivnas % 1000) / 100;
    int thousand = (grivnas % 10000) / 1000;
    int million = grivnas / 1000000;

    if (million > 0) {
        result += hundreds[million] + " ";
        result += millions[million] + " ";
    }
    if (thousand > 0) {
        result += hundreds[thousand] + " ";
        result += thousands[thousand] + " ";
    }
    if (hundred > 0) {
        result += hundreds[hundred] + " ";
    }
    if (ten > 1) {
        result += tens[ten] + " ";
        result += units[unit] + " ";
    }
    else if (ten == 1) {
        result += teens[unit] + " ";
    }
    else {
        result += units[unit] + " ";
    }

    // Додавання копійок до результату
    if (kopecks > 0) {
        result += "griven' ";
        if (kopecks < 10) {
            result += units[kopecks];
        }
        else if (kopecks < 20) {
            result += teens[kopecks - 10];
        }
        else {
            int kopecks_tens = kopecks / 10;
            int kopecks_units = kopecks % 10;
            result += tens[kopecks_tens] + " ";
            result += units[kopecks_units];
        }
        result += " kopeeks";
    }
    else {
        result += "griven'";
    }

    return result;
}