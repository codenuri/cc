#include <iostream>

// C35. 기반 클래스 소멸자는 virtual 이거나 protected 이어야 한다.

// 멤버가 많은 클래스라면 "소멸자를 virtual"로 하세요
// 또는 기존에 다른 가상함수가 한개라도 있으면 "소멸자를 virual"

// 아주 간단하고, 다른 가상함수가 한개도 없는 클래스라면 "virtual" 사용은 오버헤드가 있습니다.(가상함수 테이블)


class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }

	// protected 소멸자의 의도
	// => Base* 변수로는 delete 할수 없게 하려면 의도!
protected:
	~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() 
	{
		std::cout << "~Derived()" << std::endl; 
//		~Base::Base(); // 컴파일러가 추가
	}
};

int main()
{
	Base* p = new Derived;	
//	delete p;	// error. protected 멤버를 외부에서 호출 안됨.	


	// 방법 1. p 를 Base* 가 아닌 Derived로 사용하던가!!
	//     2. 아니면 delete 할때 Derived로 캐스팅해야 한다
	delete static_cast<Derived*>(p);
}