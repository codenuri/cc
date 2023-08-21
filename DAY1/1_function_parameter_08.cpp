#include <iostream>
#include <string>

// 인자를 다른 함수에 전달하는 경우

void f1(int  arg)  {}
void f2(int& arg) { arg = 20; }

// 완벽한 전달 ( perfect forwarding )
// => 인자로 전달 받은 것을 다른 함수에 전달할때 "완벽히 전달" 하는 기술
// => 조건 1. 복사본이 없어야 합니다.

template<typename F>
void forward_argument(F f, int arg)
{
	// 인자로 받은 것을 다른 함수에 전달하고 있습니다.
	// "forward parameter" 입니다.
	f(arg);
}

int main()
{
	int n = 10;

	forward_argument(f1, 10);
	forward_argument(f2, n);
}


