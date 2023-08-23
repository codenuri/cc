#include <iostream>

// C150. 가상함수에서는 절대 디폴트 인자를 변경하지 말라(사용하지 않으면 더 좋다.)

class Base
{
public:
	virtual void foo(int a = 10) { std::cout << "Base : " << a << std::endl; }
};

class Derived : public Base
{
public:
	virtual void foo(int a = 20) override { std::cout << "Derived : " << a << std::endl; }
};

int main()
{
	Base* p = new Derived;

	p->foo(); // 실행결과 예측해 보세요
			  // Derived : 10

	// 가상함수   : 실행시간에 객체의 타입을 조사해서 함수를 결정
	// 디폴트인자 : 컴파일 할때 컴파일러가 디폴트 값을 채워 주는것

	// 실행시간에 동작하는 문법과 컴파일 시간에 동작하는 문법을 잘 구별하세요
}