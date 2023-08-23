#include <iostream>

// C35. 기반 클래스 소멸자는 virtual 이거나 protected 이어야 한다.

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	virtual ~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
//	Derived d; // Derived 생성자, 소멸자 호출 잘됨!!

//	Derived* p = new Derived;	// Derived 생성자 호출
//	delete p;					// Derived 소멸자 호출


	Base* p = new Derived;	// Derived 생성자 호출

	delete p;				// ??

	// delete p 할때, 컴파일러는
	// 1. p의 타입을 조사합니다. - Base*
	// 2. Base의 소멸자가 virtual 인지를 조사 합니다.
	//	  virtual 이 아니면 : 무조건 ~Base() 만 호출
	//    virtual 이면      : 실제 p가 어떤 객체를 가리키는지 조사후 호출
}