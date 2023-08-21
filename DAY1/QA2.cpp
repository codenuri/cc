
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
	// �Ʒ� ������ �ǹ̴� : "arg �� const" ��� �ǹ� �Դϴ�.
	/*
	virtual void foo(const T arg)
	{
		std::cout << "Base foo" << std::endl;
	}
	*/

	// foo�� ��ó�� ������ ����, �Ʒ� ó�� �ߴٸ� ���� ?
	// => Derived ���� override �Ҷ� T �ڸ��� "int*" �� �����ϸ� �˴ϴ�
	virtual void foo( T const arg)
	{
		std::cout << "Base foo" << std::endl;
	}

};
class Derived : public Base<int*>
{
public:
	// foo override �ؼ�, "Derived foo" �� ������ ������
	// "override" Ű���� ������� ���� ������
	// => �翬��, override �� ������ �����ϴ�. "������ ��� �˼������Ƿ�"
	// �Ʒ� ������ �ǹ̴� : "arg �� const �� �ƴ϶� arg�� ���󰡸� const" ��� �ǹ�
	/*
	virtual void foo(const int* arg)
	{
		std::cout << "Derived foo" << std::endl;
	}
	*/
	// �Ʒ� �ڵ尡 "arg �� const" �Դϴ�.
	virtual void foo(int* const arg)
	{
		std::cout << "Derived foo" << std::endl;
	}

};

int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo"

	// �Ʒ� 2���� ������ �����մϴ�.
	const int c1 = 10; // �Ϲ������� �θ� ���
	int const c2 = 10; // c1 �ڵ尡 ���� �����Լ� override ���� ������ ������
						// �̷��� ������ڴ� ���嵵 �����ϴ�
}