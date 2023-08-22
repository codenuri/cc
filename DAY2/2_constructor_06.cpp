// 생성자와 가상함수
#include <iostream>
// 핵심 : 생성자에서는 가상함수가 동작하지 않습니다.
//        Base() 생성자 에서는 항상 Base::init 호출합니다.
//        => 이유는 아래 코드에서 Base::init 이 아닌 Derived::init 이 호출되면
//			 초기화 되지 않은 x를 사용하게 됩니다.
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
