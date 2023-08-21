#include <iostream>
#include <string>


void f1(int  arg) {}
void f2(int& arg) { arg = 20; }
void f3(int&& arg) {}

// 결국, int 타입 인자 한개를 완벽한 전달을 하려면
// 
// 1. int&, int&& 버전의 함수를 각각 제공해야 합니다.
// 2. int&& 버전의 함수에서는 인자를 다른 곳에 보낼때
//    "static_cast<int&&>(arg)" 로 캐스팅 한후 전달해야 합니다.

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


