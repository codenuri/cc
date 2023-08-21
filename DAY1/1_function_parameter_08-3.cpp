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
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 10;

	// 아래 2줄을 컴파일 할때 컴파일러가 생성하는 함수의 모양을 "정확히"
	// 예측할수 있어야 합니다.
	forward_argument(f1, 10);
	forward_argument(f2, n);

}


