#include <iostream>

void f1(int& a) { a = 10; } // �߿��� �˰��� �ۼ�
void f2(double d) { }
void f3(double d, int a, int b) { }


int main()
{
	int n = 10;

	f1(n); // ����ð��� �˰� �ʹ�!
}