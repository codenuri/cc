#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg) // std::nullptr_t&& arg = nullptr;
{							   // 핵심 : T가 std::nullptr_t 로 추론
	f(std::forward<T>(arg));   // foo(arg) 인데... arg는  std::nullptr_t 이므로
}							   // 모든 타입의 포인터로 형변환 가능

void foo(int* p) {}

int main()
{	
//	chronometry(foo, 0); // T 가 int로 추론되므로 error
	chronometry(foo, nullptr); 
}