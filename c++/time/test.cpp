#include <iostream>
#include <vector>
using namespace std;

class Date
{
public:
	Date(int year = 0, int month = 0, int day = 0)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void print()
	{
		cout << _year << "-";
		if (_month < 10)
			cout <<"0"<< _month<<"-";
		else
			cout << _month << "-";
		if (_day < 10)
			cout << "0" << _day << endl;
		else
			cout << _day << endl;

	}

	int GetMonthDay(int year, int month)
	{
		int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
		{
			return 29;
		}
		return monthday[month];
	}

	Date operator+(int day)
	{
		Date ret(*this);
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._month = 1;
				ret._year++;
			}
		}
		return ret;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int num;
	cin >> num;
	int year, mon, day,addday;
	for (int i = 0; i < num; i++)
	{
		cin >> year >> mon >> day >> addday;
		Date arr(year, mon, day);
		arr = arr + addday;
		arr.print();
	}
	return 0;
}