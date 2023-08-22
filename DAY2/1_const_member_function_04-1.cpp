#include <iostream>

class Test
{
public:
	// 핵심 : 동일 이름의 함수를 
	//		 상수, 비상수 버전으로 동시에 제공 가능합니다.
	void foo()       { std::cout << "foo" << std::endl; }
	void foo() const { std::cout << "foo const" << std::endl; }
};

int main()
{
	Test t;
	t.foo();

	const Test ct;
	ct.foo();

}