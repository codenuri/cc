#include <iostream>
#include <string>


void f1(int  arg) {}
void f2(int& arg) { arg = 20; }
void f3(int&& arg) {}

// ���� ���
// "forward parameter(���� ���ڸ� �ٸ����� ����)"�Ҷ���

// 1. ���ڸ� T&& �� ��������
// 2. �ٸ� ���� ������ "std::forward<T>(arg)" �� ��� ��������

template<typename F, typename T>
void forward_argument(F f, T&& arg)
{
	f(std::forward<T>(arg));
}

int main()
{
	int n = 10;

	forward_argument(f1, 10);
	forward_argument(f2, n); 


}


