#include <iostream>
#include <string>


void f1(int  arg) {}
void f2(int& arg) { arg = 20; }
void f3(int&& arg) {}

// 최종 결론
// "forward parameter(받은 인자를 다른곳에 전달)"할때는

// 1. 인자를 T&& 로 받으세요
// 2. 다른 곳에 보낼때 "std::forward<T>(arg)" 로 묶어서 보내세요

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


