#include <iostream>
#include <string>

// ���ڸ� �ٸ� �Լ��� �����ϴ� ���

void f1(int  arg)  {}
void f2(int& arg) { arg = 20; }

// �Ϻ��� ���� ( perfect forwarding )
// => ���ڷ� ���� ���� ���� �ٸ� �Լ��� �����Ҷ� "�Ϻ��� ����" �ϴ� ���
// => ���� 1. ���纻�� ����� �մϴ�.

template<typename F>
void forward_argument(F f, int arg)
{
	// ���ڷ� ���� ���� �ٸ� �Լ��� �����ϰ� �ֽ��ϴ�.
	// "forward parameter" �Դϴ�.
	f(arg);
}

int main()
{
	int n = 10;

	forward_argument(f1, 10);
	forward_argument(f2, n);
}


