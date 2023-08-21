#include <iostream>

void f1(int& a) { a = 10; } // 중요한 알고리즘 작성
void f2(double d) { }
void f3(double d, int a, int b) { }

// 함수의 수행시간을 측정하는 함수
template<typename F, typename T>
void chronometry(F f, T arg)
{
	// =============> 시간 기록
	f(arg);
	// =============> 수행 시간 출력
}

int main()
{
	int n = 10;

//	f1(n); // 수행시간을 알고 싶다!
	chronometry(f1, n);
}
