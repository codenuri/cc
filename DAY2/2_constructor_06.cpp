// �����ڿ� �����Լ�
#include <iostream>
// �ٽ� : �����ڿ����� �����Լ��� �������� �ʽ��ϴ�.
//        Base() ������ ������ �׻� Base::init ȣ���մϴ�.
//        => ������ �Ʒ� �ڵ忡�� Base::init �� �ƴ� Derived::init �� ȣ��Ǹ�
//			 �ʱ�ȭ ���� ���� x�� ����ϰ� �˴ϴ�.
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
