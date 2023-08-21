#include <iostream>
#include <string>

// 인자를 다른 함수에 전달하는 경우

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
	// int&& arg = 10 으로 인자를 받게 되는데..
	// "10"은 rvalue 지만 "arg" 는 lvalue 입니다.
//	f(arg); // 그래서 이코드가 f3(int&) 를 찾게 됩니다.

	f(static_cast<int&&>(arg)); // lvalue 인 arg 를 rvalue 로 캐스팅 하는 코드
						// int&& 인 arg를 다시 int&& 타입으로 캐스팅 하는 것이 아닙니다.
						// C++ 문법에 static_cast<&&> 는 타입 캐스팅이 아닌 value 캐스팅 입니다.
						// 그래서, lvalue => rvalue 캐스팅 입니다.
}

int main()
{
	int n = 10;

	f3(10); 
	forward_argument(f3, 10); 

	// 참고
	int&& arg = 10; // 10은 rvalue 입니다.
					// 하지만 "arg" 자체는 이름이 있고
					// 계속 사용 가능합니다. "lvalue" 입니다.
}


