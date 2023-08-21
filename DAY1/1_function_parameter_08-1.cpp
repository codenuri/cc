#include <iostream>
#include <string>

// ���ڸ� �ٸ� �Լ��� �����ϴ� ���

void f1(int  arg) {}
void f2(int& arg) { arg = 20; }

// �ٽ� 1. �Ϻ��� ������ �Ϸ��� int&, int&& ������ ���� �����ؾ� �մϴ�.
// �׷���, �� �ڵ�� �� �Ѱ��� ��쿡 ������ �˴ϴ�.
// => f3�� ��� �Դϴ�.

void f3(int&& arg) {}

template<typename F>
void forward_argument(F f, int& arg)
{
	f(arg);
}

template<typename F>
void forward_argument(F f, int&& arg)
{
	f(arg);
}

int main()
{
	int n = 10;

	forward_argument(f1, 10);
	forward_argument(f2, n);

	f3(10); // ok.. 10�� rvalue
	forward_argument(f3, 10); // error.
							  // �� ���������� ���� �ϴ� ���� �߿��մϴ�.
								// ���� �ҽ����� ����
}


