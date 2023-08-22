#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)  // int&& arg = 0  핵심 arg는 int 타입
{								// 
	f( std::forward<T>(arg) );  // foo(arg) 의 의미 인데 arg는 int 이므로 
}								//			error. 

void foo(int* p) {}

int main()
{
	int n = 0;
	foo(0); // ok. 리터럴 0 은 "int" 타입이지만, 포인터로 암시적 변환 가능
//	foo(n); // error. 0 을 가진 정수형 변수는 포인터로 암시적 변환 안됩니다.

	// 위 코드를 참고해서, 아래 코드를 생각해 봅시다.(어제 배운 완벽한전달)
	chronometry(foo, 0); // foo(0) 실행해달라는 것
	
}