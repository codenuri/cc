#include <iostream>
#include <string>

// ���ڸ� �ٸ� �Լ��� �����ϴ� ���

void f1(int  arg) {}
void f2(int& arg) { arg = 20; }


void f3(int&& arg) {}

template<typename F>
void forward_argument(F f, int& arg)
{
	f(arg);
}

// main				forward_argument(int&& arg)					f3(int&&)
// f3(10) ==========================================================> ok
// forward_arg(10) ============> int&& arg = 10;
//								 f3(arg) ===========================> error. 
//								 f3(static_cast<int&&>(arg)) =======> ok.

template<typename F>
void forward_argument(F f, int&& arg)
{
	// int&& arg = 10 ���� ���ڸ� �ް� �Ǵµ�..
	// "10"�� rvalue ���� "arg" �� lvalue �Դϴ�.
//	f(arg); // �׷��� ���ڵ尡 f3(int&) �� ã�� �˴ϴ�.

	f(static_cast<int&&>(arg)); // lvalue �� arg �� rvalue �� ĳ���� �ϴ� �ڵ�
						// int&& �� arg�� �ٽ� int&& Ÿ������ ĳ���� �ϴ� ���� �ƴմϴ�.
						// C++ ������ static_cast<&&> �� Ÿ�� ĳ������ �ƴ� value ĳ���� �Դϴ�.
						// �׷���, lvalue => rvalue ĳ���� �Դϴ�.
}

int main()
{
	int n = 10;

	f3(10); 
	forward_argument(f3, 10); 

	// ����
	int&& arg = 10; // 10�� rvalue �Դϴ�.
					// ������ "arg" ��ü�� �̸��� �ְ�
					// ��� ��� �����մϴ�. "lvalue" �Դϴ�.
}


