#include <iostream>
#include <string>


void f1(int  arg) {}
void f2(int& arg) { arg = 20; }
void f3(int&& arg) {}

// �ᱹ, int Ÿ�� ���� �Ѱ��� �Ϻ��� ������ �Ϸ���
// 
// 1. int&, int&& ������ �Լ��� ���� �����ؾ� �մϴ�.
// 2. int&& ������ �Լ������� ���ڸ� �ٸ� ���� ������
//    "static_cast<int&&>(arg)" �� ĳ���� ���� �����ؾ� �մϴ�.

template<typename F>
void forward_argument(F f, int& arg)
{
	f(arg);
}
template<typename F>
void forward_argument(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}

int main()
{
	int n = 10;

	f3(10);
	forward_argument(f3, 10);

}


