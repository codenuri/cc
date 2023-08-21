#include <iostream>
#include <string>

// 용어 정리

// 1. in parameter : 함수 안에서 값을 읽기만 하는 경우
void f1(int n) { int s = n * n; }

// 2. out parameter : 함수안에서 값을 담아주는 파라미터
void f2(int& n) { n = 100; }

// 3. in-out parameter 
void f3(int& n) { n = n + 1; }

// 4. forward parameter : 전달 받은 인자를 다른 곳에 전달하는 파라미터
template<typename T>
void f4(T&& n) { f2(n); }

// 5. retain(will-from-move) : 전달 받은 인자를 "보관" 하게 되는 파라 미터.
class People
{
	std::string name;
public:
	void set_name(const std::string& s)
	{
		name = s;
	}
};
