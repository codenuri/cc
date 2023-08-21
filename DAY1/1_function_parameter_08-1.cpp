#include <iostream>
#include <string>

// 인자를 다른 함수에 전달하는 경우

void f1(int  arg) {}
void f2(int& arg) { arg = 20; }

// 핵심 1. 완벽한 전달을 하려면 int&, int&& 버전을 각각 제공해야 합니다.
// 그런데, 이 코드는 단 한가지 경우에 문제가 됩니다.
// => f3의 경우 입니다.

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

	f3(10); // ok.. 10은 rvalue
	forward_argument(f3, 10); // error.
							  // 왜 에러인지를 이해 하는 것이 중요합니다.
								// 다음 소스에서 설명
}


