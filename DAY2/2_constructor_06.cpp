// �����ڿ� �����Լ�
#include <iostream>

struct Base
{
	Base() { init(); } // ��� �Լ� ȣ������ ������ ������

//	void foo() { init(); }; // Derived::init() ȣ��

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
//	d.foo();   // ��� ������ ������
}
