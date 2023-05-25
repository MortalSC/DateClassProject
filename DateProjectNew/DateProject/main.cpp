#include<iostream>
using namespace std;

#include"Date.h"

/* ���꼰��ȡ�·��������� */
void test1() {
	Date d(2023, 5, 23);
	cout << d.GetMonthDay(2000,2) << endl;
}

/* �������ڱȽ� */
void test2() {
	Date d1(2000, 1, 1);
	Date d2(2000, 1, 1);
	Date d3(2023, 1, 1);
	Date d4(2023, 5, 23);

	d1.Print();
	d2.Print();
	d3.Print();
	d4.Print();

	cout << "���ڲ��ԣ�" << endl;
	cout << "d1 == d2��" << (d1 == d2) << endl;

	cout << "�����ڲ��ԣ�" << endl;
	cout << "d1 != d2��" << (d1 != d2) << endl;
	cout << "d1 != d3��" << (d1 != d3) << endl;

	cout << "���ڲ��ԣ�" << endl;
	cout << "d1 > d2��" << (d1 > d2) << endl;
	cout << "d1 > d3��" << (d1 > d3) << endl;
	cout << "d4 > d3��" << (d4 > d3) << endl;

	cout << "С�ڵ��ڲ��ԣ�" << endl;
	cout << "d1 <= d2��" << (d1 <= d2) << endl;
	cout << "d1 <= d3��" << (d1 <= d3) << endl;
	cout << "d4 <= d3��" << (d4 <= d3) << endl;

	cout << "���ڵ��ڲ��ԣ�" << endl;
	cout << "d1 >= d2��" << (d1 >= d2) << endl;
	cout << "d1 >= d3��" << (d1 >= d3) << endl;
	cout << "d4 >= d3��" << (d4 >= d3) << endl;

	cout << "С�ڲ��ԣ�" << endl;
	cout << "d1 < d2��" << (d1 < d2) << endl;
	cout << "d1 < d3��" << (d1 < d3) << endl;
	cout << "d4 < d3��" << (d4 < d3) << endl;
}

void test3() {

	Date d1(2023, 5, 23);
	cout << "��ǰʱ�䣺";
	d1.Print();
	cout << "����ʱ��������㣺" << endl;
	Date d2 = d1 + 5;
	cout << "������㣺5 �죺" << endl;
	d2.Print();

	cout << "��ǰʱ�䣺";
	d1.Print();
	d1 += 500;
	cout << "������㣺500 �죺" << endl;
	d1.Print();

	cout << "��ǰʱ�䣺";
	d2.Print();
	cout << "����ʱ��ǰ�����㣺" << endl;
	d2 = d2 - 5;
	cout << "��ǰ���㣺5 �죺" << endl;
	d2.Print();

	cout << "��ǰʱ�䣺";
	d1.Print();
	d1 -= 500;
	cout << "��ǰ���㣺500 �죺" << endl;
	d1.Print();
}


void test4() {
	Date d1(2020, 2, 28);
	cout << "��ǰʱ�䣺";
	d1.Print();
	cout << "ǰ����������Ĳ��ԣ�" << endl;
	cout << "����++��";
	(d1++).Print();
	cout << "ִ�к�ʱ�䣺";

	d1.Print();
	cout << "ǰ��++��";
	(++d1).Print();
	cout << "ִ�к�ʱ�䣺";

	d1.Print();

	cout << "����--��";
	(d1--).Print();
	cout << "ִ�к�ʱ�䣺";
	d1.Print();
	cout << "ǰ��--��";
	(--d1).Print();
}


void test5() {
	Date d1(2028, 5, 23);
	Date d2(2023, 2, 1);
	Date d3(2023, 5, 23);

	cout << "��ǰʱ�䣺";
	d1.Print();
	cout << "��ǰʱ���ǵ�ǰ��ݵĵ� " << d1.GetDaythOfYear() << " ��������" << endl;
	
	cout << "��ǰʱ�䣺";
	d2.Print();
	cout << "��ǰʱ���ǵ�ǰ��ݵĵ� " << d2.GetDaythOfYear() << " ��������" << endl;

	d3.Print();
	cout << "��ǰʱ���ǵ�ǰ��ݵĵ� " << d3.GetDaythOfYear() << " ��������" << endl;

	cout << "���ڲ���ԣ�" << endl;
	d1.Print();
	d2.Print();
	cout << "��������������" << d1.GetTimeInterval(d2)<< " ��" << endl;

	d1.Print();
	d3.Print();
	cout << "��������������" << d1.GetTimeInterval(d3) << " ��" << endl;
}


void test6() {
	cout << "ʱ��Ƿ�������ԣ�" << endl;
	cout << "����ʾ����2023-2-29" << endl;
	Date d1(2023, 2, 29);

}

void test7() {
	cout << "��������������أ�" << endl;
	Date d;
	cin >> d;
	cout << d;
}


int main() {
	cout << "=======================================================" << endl;
	cout << "���꼰��ȡ�·��������ԣ�" << endl;
	test1();

	cout << "=======================================================" << endl;
	cout << "�������ڱȽϣ�" << endl;
	test2();

	cout << "=======================================================" << endl;
	test3();

	cout << "=======================================================" << endl;
	test4();

	cout << "=======================================================" << endl;
	test5();

	cout << "=======================================================" << endl;
	test6();

	cout << "=======================================================" << endl;
	test7();
	return 0;
}