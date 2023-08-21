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

// �׷���, T&& �� ����ϸ� �� 2�� ������ �ڵ������Ҽ� �ֽ��ϴ�.
// => �׷���, ���ø��� ����Ϸ��� 2���� ������ ���� �ؾ� �մϴ�.

/*
template<typename F>
void forward_argument(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg) ); // �ʿ� ���� ĳ���� ������
								// �־ �������� �ʽ��ϴ�.
								// ���ɿ� ������ ���� �ʰ�, �����Ͻÿ� ���ŵ˴ϴ�.
}

template<typename F>
void forward_argument(F f, int&& arg)
{
	f(static_cast<int&&>(arg)); 
}
*/

template<typename F, typename T>
void forward_argument(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 10;

	// �Ʒ� 2���� ������ �Ҷ� �����Ϸ��� �����ϴ� �Լ��� ����� "��Ȯ��"
	// �����Ҽ� �־�� �մϴ�.
	forward_argument(f1, 10);
	forward_argument(f2, n);

}


