#include <iostream>

// C150. �����Լ������� ���� ����Ʈ ���ڸ� �������� ����(������� ������ �� ����.)

class Base
{
public:
	virtual void foo(int a = 10) { std::cout << "Base : " << a << std::endl; }
};

class Derived : public Base
{
public:
	virtual void foo(int a = 20) override { std::cout << "Derived : " << a << std::endl; }
};

int main()
{
	Base* p = new Derived;

	p->foo(); // ������ ������ ������
			  // Derived : 10

	// �����Լ�   : ����ð��� ��ü�� Ÿ���� �����ؼ� �Լ��� ����
	// ����Ʈ���� : ������ �Ҷ� �����Ϸ��� ����Ʈ ���� ä�� �ִ°�

	// ����ð��� �����ϴ� ������ ������ �ð��� �����ϴ� ������ �� �����ϼ���
}