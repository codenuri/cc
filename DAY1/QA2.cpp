
// const Rect& vs. Rect const&
// 어떤 표현이 권장 되나요 ? 
// => Core guide lines 에는 없는데, 
// => Core guide lines 예제 : const Rect& 
// => 일부 개발자들이 "Rect const&" 가 좋다고 주장..

#include <iostream>


template<typename T>
class Base
{
public:
	// 아래 인자의 의미는 : "arg 가 const" 라는 의미 입니다.
	virtual void foo(const T arg)
	{
		std::cout << "Base foo" << std::endl;
	}
};
class Derived : public Base<int*>
{
public:
	// foo override 해서, "Derived foo" 로 변경해 보세요
	// "override" 키워드 사용하지 말아 보세요
	virtual void foo(const int* arg)
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo"
}