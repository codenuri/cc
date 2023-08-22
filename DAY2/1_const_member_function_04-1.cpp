#include <iostream>

class Test
{
public:
	// 핵심 : 동일 이름의 함수를 
	//		 상수, 비상수 버전으로 동시에 제공 가능합니다.
	void foo()       { std::cout << "foo"       << std::endl; }
	void foo() const { std::cout << "foo const" << std::endl; }
};

int main()
{
	Test t;	// non-const object
	t.foo();// 1. foo() 사용. 
			// 2. (1)이 없다면 foo() const 사용

	const Test ct; // const object
	ct.foo();	   // foo() const 만 사용 가능. 없다면 에러

}