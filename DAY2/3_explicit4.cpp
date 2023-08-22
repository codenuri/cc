#include <iostream>

class String
{
public:
	explicit String(const char* s) {}
};

void foo(String s) {}

int main()
{
	String s1 = "Hello"; // 복사 초기화
	String s2("Hello");  // 직접 초기화

	foo("Hello");		// String s = "Hello";  즉, 복사 초기화


	const String& r1 = "Hello";
						// 1. "Hello" 를 변환 생성자를 사용해서 String 임시객체생성
						// 2. 임시객체를 r1 이 가리키게 되는 모양

	const String& r2 = String("Hello");
						// 1. 사용자가 명시적으로 임시객체를 생성한것(직접초기화방식)
						// 2. 임시객체를 r2 가 가리키게 되는 모양
}

void f(const String& s) {}

f("hello");         // explicit 라면 에러
f(String("hello")); // explicit 라도 ok..