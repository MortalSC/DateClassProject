#include "Date.h"

bool Date::IsLeapYear(int year)
{
	return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

void Date::Print()  const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

/* 日期对象等于判断 */
bool Date::operator == (const Date& d)  const {
	return _year == d._year && _month == d._month && _day == d._day;
}

/* 日期对象不等于判断 */
bool Date::operator != (const Date& d)  const {
	// return _year != d._year || _month != d._month || _day != d._day;
	return !(*this == d);			// 提高代码复用性【 等于的反面就是不等于！ 】
}

/* 日期对象大于判断 */
bool Date::operator > (const Date& d)  const {
#if 1		// 写法一
	if (_year > d._year) return true;
	else if (_year == d._year && _month > d._month) return true;
	else if (_year == d._year && _month == d._month && _day > d._day) return true;
	else return false;
#else		// 写法二
	if ( (_year > d._year)
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day) ) return true;
	else return false;
#endif
}

/* 日期对象小于等于判断 */
bool Date::operator <= (const Date& d)  const {
#if 0			// 写法一
	if (*this == d) return true;
	else if (_year < d._year) return true;
	else if (_year == d._year && _month < d._month) return true;
	else if (_year == d._year && _month == d._month && _day < d._day) return true;
	else return false;
	// 写法二
	//if ( (*this == d) || (_year < d._year)
	//	|| (_year == d._year && _month < d._month)
	//	|| (_year == d._year && _month == d._month && _day < d._day)) return true;
	//else return false;
#else
	return !(*this > d);		// 提高代码复用性【 小于等于的反面就是大于！ 】
#endif
}

/* 日期对象小于判断 */
bool Date::operator < (const Date& d)  const {
#if 0			// 写法一
	if (_year < d._year) return true;
	else if (_year == d._year && _month < d._month) return true;
	else if (_year == d._year && _month == d._month && _day < d._day) return true;
	else return false;
	// 写法二
	//if ((_year < d._year)
	//	|| (_year == d._year && _month < d._month)
	//	|| (_year == d._year && _month == d._month && _day < d._day)) return true;
	//else return false;
#else
	return !(*this >= d);					// 提高代码复用性【 小于的反面就是大于等于！ 】
#endif
}

/* 日期对象大于等于判断 */
bool Date::operator >= (const Date& d)  const {
#if 0			// 写法一
	if (*this == d) return true;
	else if (_year > d._year) return true;
	else if (_year == d._year && _month > d._month) return true;
	else if (_year == d._year && _month == d._month && _day > d._day) return true;
	else return false;
	// 写法二
	//if ( (*this == d) || (_year > d._year)
	//	|| (_year == d._year && _month > d._month)
	//	|| (_year == d._year && _month == d._month && _day > d._day)) return true;
	//else return false;
#else
	return (*this > d) || (*this == d);		// 提高代码复用性【 大于等于就是大于或等于！ 】
#endif
}




Date& Date::operator += (const int day) {
	_day += day;
	while (_day > GetMonthDay(_year, _month)) {		// 判断天数是否“合法”
		_day -= GetMonthDay(_year, _month);			// 减去对应天数
		_month += 1;								// 月份递增
		if (_month == 13) {							// 判断月数是否“合法”
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator + (const int day)  const {
	// Date ret(*this);		// 该过程是拷贝构造
	Date ret = *this;		// 该过程是拷贝构造
	ret += day;
	return ret;				// 该处不能使用引用返回，ret 是一个局部变量
}

Date& Date::operator -= (const int day) {
	_day -= day;
	while (_day <= 0) {
		if(_month == 1){
			_month = 13;
			_year--;
		}
		_day += GetMonthDay(_year, _month - 1);
		_month--;
	}
	return *this;
}

Date Date::operator - (const int day)  const {
	Date ret(*this);
	ret -= day;
	return ret;
}

Date& Date::operator ++ () {
	return *this += 1;		// 前置的处理方式就是先递增再返回
}
Date Date::operator ++ (int) {
	Date ret(*this);		// 后置的处理方式就是先返回再递增
	*this += 1;
	return ret;				// 该处不能使用引用返回，ret 是一个局部变量
}

Date& Date::operator -- () {
	return *this -= 1;
}
Date Date::operator -- (int) {
	Date ret(*this);
	*this -= 1;
	return ret;
}



/* 其他功能 */
/* 返回当前月日是当前的第几天 */
int Date::GetDaythOfYear() {
	int day = _day;							// 直接记录当前日是该月的第几天
	if (_month == 1) return day;			// 如果是 1 月直接返回
	for (int i = 1; i < _month; i++) {		// 反复递加前面月份天数
		day += GetMonthDay(_year, i);
	}
	return day;
}

/* 日期对象 - 日期对象 */
int Date::GetTimeInterval(const Date& d) {
	/*	两种实现方案：
		第一种：复用已有的代码实现计算
	*/
	int flag = 1;					// 假设正值运算
	Date _max = *this;				// 记录较大日期
	Date _min = d;					// 记录较小日期
	if (_max < _min) {				// 比较设定是否合理：不合理就转换
		_max = d;
		_min = *this;
		flag = -1;					// 假设错误：结果取 负值
	}

	int n = 0;
	while (_min != _max) {			// 采用逐日递增的计算方式获取结果
		++_min;
		++n;
	}
	return n*flag;
}