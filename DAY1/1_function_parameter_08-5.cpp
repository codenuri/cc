#include <iostream>

void f1(int& a) { a = 10; } // 중요한 알고리즘 작성
void f2(double d) { }
void f3(double d, int a, int b) { }


int main()
{
	int n = 10;

	f1(n); // 수행시간을 알고 싶다!
}