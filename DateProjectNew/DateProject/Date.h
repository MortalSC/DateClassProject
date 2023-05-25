#pragma once
#include<iostream>
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Date
{
public:
	/* ʵ�ֹ��캯�������ڹ��캯�����Ƶ�ʵ��ã��ʿ�ѡ��������ʵ�� */
	/* ����д�� */
	//Date(int year = 1, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	/* ʹ�ò����б�ʽд���Ĺ��캯�� */
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day) {
		if (!checked()) {
			Print();
			cout << "����ʱ�乹��Ƿ���" << endl;
		}
	}

	// ʱ����
	bool checked() {
		if (_year > 0
			&& _month >= 1 && _month <= 12
			&& _day >= 0 &&_day <= GetMonthDay(_year, _month)) {
			return true;
		}
		return false;
	}

	// ��ȡ�·���������������Ƶ�ʸߣ�ʹ������ʵ�֣�
	int GetMonthDay(int year, int month)
	{
		// int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		/*
			�Ż������ں�������Ƶ�ʸߣ�ÿ�ε�����ʹ�����д��룬
			ÿ�ε��ö�������ռ��ʼ�����飬�ķ���Դ�����Ż�Ϊ��̬��
		*/
		static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		// �����ж�
		if ( month == 2 && IsLeapYear(year)) return arr[month] + 1;
		return arr[month];
	}

	// �����ж�
	bool IsLeapYear(int year);

	// ��ӡ����
	void Print() const;


	/* ��ֵ��������� */
	Date& operator = (const Date& d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	/* ʵ���������ڶ���Ĵ�С�Ƚ� */
	bool operator == (const Date& d)  const;
	bool operator != (const Date& d) const;
	bool operator > (const Date& d) const;
	bool operator < (const Date& d) const;
	bool operator >= (const Date& d) const;
	bool operator <= (const Date& d) const;

	/* ������������أ�ʵ��ָ������ +/+=/-/-= �����죬����Ľ����� */
	Date operator + (const int day) const;
	Date& operator += (const int day);
	Date operator - (const int day) const;
	Date& operator -= (const int day);


	// ǰ����++	--�����ַ�ʽ���������ں��������б���һ�����α�ʶ�����ɺ�������
	// ע����ʵ�ʵ����в���Ҫ���ݲ�����C++ ���������Զ�����
	Date& operator ++ ();
	Date operator ++ (int);

	Date& operator -- ();
	Date operator -- (int);

	/* �������� */
	/* ���ص�ǰ�����ǵ�ǰ�ĵڼ��� */
	int GetDaythOfYear();
	
	/* ���ڶ��� - ���ڶ��� */
	int GetTimeInterval(const Date& d);

	friend ostream& operator << (ostream& _cout, const Date& d);
	friend istream& operator >> (istream& _cin, Date& d);

private:
	int _year;
	int _month;
	int _day;
};

/* ��������������� */
inline ostream& operator << (ostream& _cout, const Date& d) {
	_cout << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return _cout;
}
inline istream& operator >> (istream& _cin, Date& d) {
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}

