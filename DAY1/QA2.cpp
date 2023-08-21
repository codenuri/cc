
// const Rect& vs. Rect const&
// � ǥ���� ���� �ǳ��� ? 
// => Core guide lines ���� ���µ�, 
// => Core guide lines ���� : const Rect& 
// => �Ϻ� �����ڵ��� "Rect const&" �� ���ٰ� ����..

#include <iostream>


template<typename T>
class Base
{
public:
	void foo(const T arg)
	{
		std::cout << "Base foo" << std::endl;
	}
};
class Derived : public Base<int*>
{
public:
	// foo override �ؼ�, "Derived foo" �� ������ ������
	// "override" Ű���� ������� ���� ������
};

int main()
{
	Base<int>* p = new Derived;
	p->foo(0); // "Derived foo"
}