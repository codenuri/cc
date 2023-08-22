// 생성자와 가상함수
#include <iostream>

struct Base
{
	Base() { init(); } // 어느 함수 호출할지 예측해 보세요

//	void foo() { init(); }; // Derived::init() 호출

	virtual void init() { std::cout << "Base::init" << std::endl; }     // 1
};
struct Derived : public Base
{
	int x;	
	Derived() : x(10) {}	// Derived() : Base(), x(10) {}

	virtual void init() override { std::cout << "Derived::init : " << x << std::endl; } // 2
};

int main()
{
	Derived d;
//	d.foo();   // 결과 예측해 보세요
}
