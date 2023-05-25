#include "Date.h"

bool Date::IsLeapYear(int year)
{
	return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

void Date::Print()  const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

/* ���ڶ�������ж� */
bool Date::operator == (const Date& d)  const {
	return _year == d._year && _month == d._month && _day == d._day;
}

/* ���ڶ��󲻵����ж� */
bool Date::operator != (const Date& d)  const {
	// return _year != d._year || _month != d._month || _day != d._day;
	return !(*this == d);			// ��ߴ��븴���ԡ� ���ڵķ�����ǲ����ڣ� ��
}

/* ���ڶ�������ж� */
bool Date::operator > (const Date& d)  const {
#if 1		// д��һ
	if (_year > d._year) return true;
	else if (_year == d._year && _month > d._month) return true;
	else if (_year == d._year && _month == d._month && _day > d._day) return true;
	else return false;
#else		// д����
	if ( (_year > d._year)
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day) ) return true;
	else return false;
#endif
}

/* ���ڶ���С�ڵ����ж� */
bool Date::operator <= (const Date& d)  const {
#if 0			// д��һ
	if (*this == d) return true;
	else if (_year < d._year) return true;
	else if (_year == d._year && _month < d._month) return true;
	else if (_year == d._year && _month == d._month && _day < d._day) return true;
	else return false;
	// д����
	//if ( (*this == d) || (_year < d._year)
	//	|| (_year == d._year && _month < d._month)
	//	|| (_year == d._year && _month == d._month && _day < d._day)) return true;
	//else return false;
#else
	return !(*this > d);		// ��ߴ��븴���ԡ� С�ڵ��ڵķ�����Ǵ��ڣ� ��
#endif
}

/* ���ڶ���С���ж� */
bool Date::operator < (const Date& d)  const {
#if 0			// д��һ
	if (_year < d._year) return true;
	else if (_year == d._year && _month < d._month) return true;
	else if (_year == d._year && _month == d._month && _day < d._day) return true;
	else return false;
	// д����
	//if ((_year < d._year)
	//	|| (_year == d._year && _month < d._month)
	//	|| (_year == d._year && _month == d._month && _day < d._day)) return true;
	//else return false;
#else
	return !(*this >= d);					// ��ߴ��븴���ԡ� С�ڵķ�����Ǵ��ڵ��ڣ� ��
#endif
}

/* ���ڶ�����ڵ����ж� */
bool Date::operator >= (const Date& d)  const {
#if 0			// д��һ
	if (*this == d) return true;
	else if (_year > d._year) return true;
	else if (_year == d._year && _month > d._month) return true;
	else if (_year == d._year && _month == d._month && _day > d._day) return true;
	else return false;
	// д����
	//if ( (*this == d) || (_year > d._year)
	//	|| (_year == d._year && _month > d._month)
	//	|| (_year == d._year && _month == d._month && _day > d._day)) return true;
	//else return false;
#else
	return (*this > d) || (*this == d);		// ��ߴ��븴���ԡ� ���ڵ��ھ��Ǵ��ڻ���ڣ� ��
#endif
}




Date& Date::operator += (const int day) {
	_day += day;
	while (_day > GetMonthDay(_year, _month)) {		// �ж������Ƿ񡰺Ϸ���
		_day -= GetMonthDay(_year, _month);			// ��ȥ��Ӧ����
		_month += 1;								// �·ݵ���
		if (_month == 13) {							// �ж������Ƿ񡰺Ϸ���
			_month = 1;
			_year++;
		}
	}
	return *this;
}

Date Date::operator + (const int day)  const {
	// Date ret(*this);		// �ù����ǿ�������
	Date ret = *this;		// �ù����ǿ�������
	ret += day;
	return ret;				// �ô�����ʹ�����÷��أ�ret ��һ���ֲ�����
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
	return *this += 1;		// ǰ�õĴ���ʽ�����ȵ����ٷ���
}
Date Date::operator ++ (int) {
	Date ret(*this);		// ���õĴ���ʽ�����ȷ����ٵ���
	*this += 1;
	return ret;				// �ô�����ʹ�����÷��أ�ret ��һ���ֲ�����
}

Date& Date::operator -- () {
	return *this -= 1;
}
Date Date::operator -- (int) {
	Date ret(*this);
	*this -= 1;
	return ret;
}



/* �������� */
/* ���ص�ǰ�����ǵ�ǰ�ĵڼ��� */
int Date::GetDaythOfYear() {
	int day = _day;							// ֱ�Ӽ�¼��ǰ���Ǹ��µĵڼ���
	if (_month == 1) return day;			// ����� 1 ��ֱ�ӷ���
	for (int i = 1; i < _month; i++) {		// �����ݼ�ǰ���·�����
		day += GetMonthDay(_year, i);
	}
	return day;
}

/* ���ڶ��� - ���ڶ��� */
int Date::GetTimeInterval(const Date& d) {
	/*	����ʵ�ַ�����
		��һ�֣��������еĴ���ʵ�ּ���
	*/
	int flag = 1;					// ������ֵ����
	Date _max = *this;				// ��¼�ϴ�����
	Date _min = d;					// ��¼��С����
	if (_max < _min) {				// �Ƚ��趨�Ƿ�����������ת��
		_max = d;
		_min = *this;
		flag = -1;					// ������󣺽��ȡ ��ֵ
	}

	int n = 0;
	while (_min != _max) {			// �������յ����ļ��㷽ʽ��ȡ���
		++_min;
		++n;
	}
	return n*flag;
}