#pragma once
#include<iostream>
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Date
{
public:
	/* 实现构造函数：由于构造函数会高频率调用，故可选择在类中实现 */
	/* 基础写法 */
	//Date(int year = 1, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	/* 使用参数列表式写法的构造函数 */
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day) {
		if (!checked()) {
			Print();
			cout << "以上时间构造非法！" << endl;
		}
	}

	// 时间检查
	bool checked() {
		if (_year > 0
			&& _month >= 1 && _month <= 12
			&& _day >= 0 &&_day <= GetMonthDay(_year, _month)) {
			return true;
		}
		return false;
	}

	// 获取月份天数函数：调用频率高，使用内联实现！
	int GetMonthDay(int year, int month)
	{
		// int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		/*
			优化：由于函数调用频率高，每次调用若使用上行代码，
			每次调用都会申请空间初始化数组，耗费资源，故优化为静态量
		*/
		static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		// 闰年判断
		if ( month == 2 && IsLeapYear(year)) return arr[month] + 1;
		return arr[month];
	}

	// 闰年判断
	bool IsLeapYear(int year);

	// 打印日期
	void Print() const;


	/* 赋值运算符重载 */
	Date& operator = (const Date& d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	/* 实现两个日期对象的大小比较 */
	bool operator == (const Date& d)  const;
	bool operator != (const Date& d) const;
	bool operator > (const Date& d) const;
	bool operator < (const Date& d) const;
	bool operator >= (const Date& d) const;
	bool operator <= (const Date& d) const;

	/* 日期运算的重载：实现指定日期 +/+=/-/-= 多少天，问题的结果输出 */
	Date operator + (const int day) const;
	Date& operator += (const int day);
	Date operator - (const int day) const;
	Date& operator -= (const int day);


	// 前后置++	--：区分方式：后置型在函数参数列表传递一个整形标识，构成函数重载
	// 注：在实际调用中不需要传递参数，C++ 编译器会自动处理
	Date& operator ++ ();
	Date operator ++ (int);

	Date& operator -- ();
	Date operator -- (int);

	/* 其他功能 */
	/* 返回当前月日是当前的第几天 */
	int GetDaythOfYear();
	
	/* 日期对象 - 日期对象 */
	int GetTimeInterval(const Date& d);

	friend ostream& operator << (ostream& _cout, const Date& d);
	friend istream& operator >> (istream& _cin, Date& d);

private:
	int _year;
	int _month;
	int _day;
};

/* 流输入输出的重载 */
inline ostream& operator << (ostream& _cout, const Date& d) {
	_cout << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return _cout;
}
inline istream& operator >> (istream& _cin, Date& d) {
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}

