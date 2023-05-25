#include<iostream>
using namespace std;

#include"Date.h"

/* 闰年及获取月份天数测试 */
void test1() {
	Date d(2023, 5, 23);
	cout << d.GetMonthDay(2000,2) << endl;
}

/* 测试日期比较 */
void test2() {
	Date d1(2000, 1, 1);
	Date d2(2000, 1, 1);
	Date d3(2023, 1, 1);
	Date d4(2023, 5, 23);

	d1.Print();
	d2.Print();
	d3.Print();
	d4.Print();

	cout << "等于测试：" << endl;
	cout << "d1 == d2：" << (d1 == d2) << endl;

	cout << "不等于测试：" << endl;
	cout << "d1 != d2：" << (d1 != d2) << endl;
	cout << "d1 != d3：" << (d1 != d3) << endl;

	cout << "大于测试：" << endl;
	cout << "d1 > d2：" << (d1 > d2) << endl;
	cout << "d1 > d3：" << (d1 > d3) << endl;
	cout << "d4 > d3：" << (d4 > d3) << endl;

	cout << "小于等于测试：" << endl;
	cout << "d1 <= d2：" << (d1 <= d2) << endl;
	cout << "d1 <= d3：" << (d1 <= d3) << endl;
	cout << "d4 <= d3：" << (d4 <= d3) << endl;

	cout << "大于等于测试：" << endl;
	cout << "d1 >= d2：" << (d1 >= d2) << endl;
	cout << "d1 >= d3：" << (d1 >= d3) << endl;
	cout << "d4 >= d3：" << (d4 >= d3) << endl;

	cout << "小于测试：" << endl;
	cout << "d1 < d2：" << (d1 < d2) << endl;
	cout << "d1 < d3：" << (d1 < d3) << endl;
	cout << "d4 < d3：" << (d4 < d3) << endl;
}

void test3() {

	Date d1(2023, 5, 23);
	cout << "当前时间：";
	d1.Print();
	cout << "测试时间向后推算：" << endl;
	Date d2 = d1 + 5;
	cout << "向后推算：5 天：" << endl;
	d2.Print();

	cout << "当前时间：";
	d1.Print();
	d1 += 500;
	cout << "向后推算：500 天：" << endl;
	d1.Print();

	cout << "当前时间：";
	d2.Print();
	cout << "测试时间前后推算：" << endl;
	d2 = d2 - 5;
	cout << "向前推算：5 天：" << endl;
	d2.Print();

	cout << "当前时间：";
	d1.Print();
	d1 -= 500;
	cout << "向前推算：500 天：" << endl;
	d1.Print();
}


void test4() {
	Date d1(2020, 2, 28);
	cout << "当前时间：";
	d1.Print();
	cout << "前后置运算符的测试：" << endl;
	cout << "后置++：";
	(d1++).Print();
	cout << "执行后时间：";

	d1.Print();
	cout << "前置++：";
	(++d1).Print();
	cout << "执行后时间：";

	d1.Print();

	cout << "后置--：";
	(d1--).Print();
	cout << "执行后时间：";
	d1.Print();
	cout << "前置--：";
	(--d1).Print();
}


void test5() {
	Date d1(2028, 5, 23);
	Date d2(2023, 2, 1);
	Date d3(2023, 5, 23);

	cout << "当前时间：";
	d1.Print();
	cout << "当前时间是当前年份的第 " << d1.GetDaythOfYear() << " 天计算测试" << endl;
	
	cout << "当前时间：";
	d2.Print();
	cout << "当前时间是当前年份的第 " << d2.GetDaythOfYear() << " 天计算测试" << endl;

	d3.Print();
	cout << "当前时间是当前年份的第 " << d3.GetDaythOfYear() << " 天计算测试" << endl;

	cout << "日期差测试：" << endl;
	d1.Print();
	d2.Print();
	cout << "以上两个日期相差：" << d1.GetTimeInterval(d2)<< " 天" << endl;

	d1.Print();
	d3.Print();
	cout << "以上两个日期相差：" << d1.GetTimeInterval(d3) << " 天" << endl;
}


void test6() {
	cout << "时间非法检验测试：" << endl;
	cout << "测试示例：2023-2-29" << endl;
	Date d1(2023, 2, 29);

}

void test7() {
	cout << "测试输入输出重载：" << endl;
	Date d;
	cin >> d;
	cout << d;
}


int main() {
	cout << "=======================================================" << endl;
	cout << "闰年及获取月份天数测试：" << endl;
	test1();

	cout << "=======================================================" << endl;
	cout << "测试日期比较：" << endl;
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