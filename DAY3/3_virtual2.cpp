#include <iostream>

// C35. ��� Ŭ���� �Ҹ��ڴ� virtual �̰ų� protected �̾�� �Ѵ�.

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	virtual ~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
//	Derived d; // Derived ������, �Ҹ��� ȣ�� �ߵ�!!

//	Derived* p = new Derived;	// Derived ������ ȣ��
//	delete p;					// Derived �Ҹ��� ȣ��


	Base* p = new Derived;	// Derived ������ ȣ��

	delete p;				// ??

	// delete p �Ҷ�, �����Ϸ���
	// 1. p�� Ÿ���� �����մϴ�. - Base*
	// 2. Base�� �Ҹ��ڰ� virtual ������ ���� �մϴ�.
	//	  virtual �� �ƴϸ� : ������ ~Base() �� ȣ��
	//    virtual �̸�      : ���� p�� � ��ü�� ����Ű���� ������ ȣ��
}