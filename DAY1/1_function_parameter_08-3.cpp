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

// 그런데, T&& 를 사용하면 위 2개 버전을 자동생성할수 있습니다.
// => 그런데, 템플릿을 사용하려면 2개의 구현이 동일 해야 합니다.

/*
template<typename F>
void forward_argument(F f, int& arg)
{
//	f(arg);
	f(static_cast<int&>(arg) ); // 필요 없는 캐스팅 이지만
								// 있어도 문제되지 않습니다.
								// 성능에 영향을 주지 않고, 컴파일시에 제거됩니다.
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
	// 아래 캐스팅은 arg 를 항상 "rvalue"로 캐스팅하는 코드 이다 -> X

	// forward_argument 의 2번째 인자로
	// rvalue 를 (보내면 arg로 받으면서 lvalue 로 변경된것을 다시) rvalue 로 캐스팅
	// lvalue 를 (보내면 arg로 받으면서 lvalue 로 변경된것을 계속) lvalue 로 캐스팅
	// f(static_cast<T&&>(arg));

	// 위와 같은 캐스팅을 하는 C++ 표준 함수가 "std::forward" 입니다.
	f( std::forward<T>(arg) ); // 위와 동일
							   // 단, T&& 가 아닌 T 를 전달하면 됩니다.
}

int main()
{
	int n = 10;

	// 아래 2줄을 컴파일 할때 컴파일러가 생성하는 함수의 모양을 "정확히"
	// 예측할수 있어야 합니다.
	forward_argument(f1, 10); // 10 은 rvalue
							  // T=int, T&&=int&&
							  // => 함수 모양 : forward_argument(F f, int&& arg) 
							  // => 캐스팅모양: static_cast<int&&>(arg)

	forward_argument(f2, n);  // n 은 lvalue
							  // T=int&, T&&=int& && => int& 
							  // => 함수 모양 : forward_argument(F f, int& arg)
							  // => 캐스팅모양: static_cast<int&>(arg)

}


