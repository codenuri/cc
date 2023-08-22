#include <iostream>

// 생성자에서 가상함수 처럼 동작하고 싶다면
// "factory function" 을 사용하라!!
// 
// => 만들면서 호출하지 말고 만든후에 호출해라!

struct Base
{
	Base() { } 

	virtual void init() { std::cout << "Base::init" << std::endl; }     // 1

	// factory function : 객체를 만드는 함수
	template<typename T>
	static T* create()
	{
		T* p = new T; // 1. 객체를 만들고
		p->init();    // 2. 가상함수 호출
		return p;		
	}
};



struct Derived : public Base
{
	int x;
	Derived() : x(10) {}	

	virtual void init() override { std::cout << "Derived::init : " << x << std::endl; } // 2
};

int main()
{
	Derived* p = Base::create<Derived>();
					// 만들고, init 호출!!!
}
