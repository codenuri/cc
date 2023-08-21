
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
	/*
	virtual void foo(const T arg)
	{
		std::cout << "Base foo" << std::endl;
	}
	*/

	// foo를 위처럼 만들지 말고, 아래 처럼 했다면 어떨까요 ?
	// => Derived 에서 override 할때 T 자리만 "int*" 로 변경하면 됩니다
	virtual void foo( T const arg)
	{
		std::cout << "Base foo" << std::endl;
	}

};
class Derived : public Base<int*>
{
public:
	// foo override 해서, "Derived foo" 로 변경해 보세요
	// "override" 키워드 사용하지 말아 보세요
	// => 당연히, override 를 적으면 좋습니다. "에러를 즉시 알수있으므로"
	// 아래 인자의 의미는 : "arg 가 const 가 아니라 arg를 따라가면 const" 라는 의미
	/*
	virtual void foo(const int* arg)
	{
		std::cout << "Derived foo" << std::endl;
	}
	*/
	// 아래 코드가 "arg 가 const" 입니다.
	virtual void foo(int* const arg)
	{
		std::cout << "Derived foo" << std::endl;
	}

};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo"

	// 아래 2줄은 완전히 동일합니다.
	const int c1 = 10; // 일반적으로 널리 사용
	int const c2 = 10; // c1 코드가 위의 가상함수 override 같은 문제가 있으니
						// 이렇게 사용하자는 주장도 많습니다
}