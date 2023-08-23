#include <iostream>

// C35. ��� Ŭ���� �Ҹ��ڴ� virtual �̰ų� protected �̾�� �Ѵ�.

// ����� ���� Ŭ������� "�Ҹ��ڸ� virtual"�� �ϼ���
// �Ǵ� ������ �ٸ� �����Լ��� �Ѱ��� ������ "�Ҹ��ڸ� virual"

// ���� �����ϰ�, �ٸ� �����Լ��� �Ѱ��� ���� Ŭ������� "virtual" ����� ������尡 �ֽ��ϴ�.(�����Լ� ���̺�)


class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }

	// protected �Ҹ����� �ǵ�
	// => Base* �����δ� delete �Ҽ� ���� �Ϸ��� �ǵ�!
protected:
	~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() 
	{
		std::cout << "~Derived()" << std::endl; 
//		~Base::Base(); // �����Ϸ��� �߰�
	}
};

int main()
{
	Base* p = new Derived;	
//	delete p;	// error. protected ����� �ܺο��� ȣ�� �ȵ�.	


	// ��� 1. p �� Base* �� �ƴ� Derived�� ����ϴ���!!
	//     2. �ƴϸ� delete �Ҷ� Derived�� ĳ�����ؾ� �Ѵ�
	delete static_cast<Derived*>(p);
}