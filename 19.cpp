#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Define class dateType
class dateType
{
private:
	int dMonth; // variable to store the month
	int dDay;	// variable to store the day
	int dYear;	// variable to store the year

public:
	void setDate(int month, int day, int year);	// Set day
	int getDate() const;	// Get date
	int getMonth() const;	// Get month
	int getYear() const;	// Get year
	void printDate();		// Print date

	bool isLeapYear();		// Check if Leap year
	int getCenturyValue();	// Get Cenetury Year Value
	int getYearValue();		// Get Year Value
	int getMonthValue();	// Get Mont Value
	int theDayOfTheWeek();	// Get the Day of the Weak
};

void dateType::printDate()
{
	cout << "Date: " << getDate() << "\t| " << "Month: " << getMonth() << "\t| " << "Year: " << getYear() << "\n";
}

int dateType::getDate() const
{
	return dDay;
}

int dateType::getMonth() const
{
	return dMonth;
}

int dateType::getYear() const
{
	return dYear;
}

bool dateType::isLeapYear()
{
	if (dYear % 400 == 0 || (dYear % 100 == 0 && dYear % 100 != 0)) return true; // Return true if the year is Leap Year
	return false;	// Return false if the year is not Leap Year
}

int dateType::getCenturyValue()
{
	int century = dYear / 100;
	int remainder = century % 4;
	return (3 - remainder)*2;
}

int dateType::getYearValue()
{
	int decade = dYear % 100;
	return decade / 4 + decade;
}

int dateType::getMonthValue()
{
	switch (dMonth)
	{
	case 1:
	  if (isLeapYear()) return 8;
		return 0;
	case 2:
		if (isLeapYear()) return 2;
		return 3;
	case 3:
	case 11:
		return 3;
	case 4:
	case 7:
		return 6;
	case 5:
		return 1;
	case 6:
		return 4;
	case 8:
		return 2;
	case 9:
	case 12:
		return 5;
	case 10:
		return 0;

	default:
		break;
	}
}

int dateType::theDayOfTheWeek()
{
	int sum = dDay + getCenturyValue() + getYearValue() + getMonthValue();
	return sum%7;
}

void dateType::setDate(int month, int day, int year)
{
	if (month<1 || month>12) return;	// Check month between 1 and 12
	if (day<1 || day>31) return;		// Check day between 1 and 31
	if (year < 0) return;				// Check year is > 0

	// Check the day of each month of the years
	if (month == 2)
	{
		if (isLeapYear())
		{
			if (day > 29) return; // The day of Leap Year on February is <= 29
		}
		else
		{
			if (day > 28) return; // The day of Normal Year on February is <= 28
		}
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30) return;	// The day on April, June, September, November of each Year is <= 30
	}

	// Store dateType
	dMonth = month;
	dYear = year;
	dDay = day;
}

dateType date;
string  dayOfweek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"};
int main()
{
	int month, day, year;
	// Test class
	do{
		cout << "Type month (number):\t";
		cin >> month;
	} while (!(month <= 12 && month > 0));
	do{
		cout << "Type day (number):\t";
		cin >> day;
	}
	while (!(day > 0 && day <= 31));
	do{
		cout << "Type year (number):\t";
		cin >> year;
	} while (!(year>0&&year<=9999));

	date.setDate(month, day, year);	// Set dateType to store
	if (date.getYear() > 0)
	{
		date.printDate();			// Print dateType, if it's not store, it will print 0;
		cout << "Year " << date.getYear() << " is a " << (date.isLeapYear() ? "Leap Year" : "Normal Year") << "\n";
		cout << "The day of the week is:\t"<< dayOfweek[date.theDayOfTheWeek()] << endl;
	}
	else cout << "Store error\n";
	return 0;
}
