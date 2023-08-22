#include <iostream>

class Test
{
public:
	// �ٽ� : ���� �̸��� �Լ��� 
	//		 ���, ���� �������� ���ÿ� ���� �����մϴ�.
	void foo()       { std::cout << "foo"       << std::endl; }
	void foo() const { std::cout << "foo const" << std::endl; }
};

int main()
{
	Test t;	// non-const object
	t.foo();// 1. foo() ���. 
			// 2. (1)�� ���ٸ� foo() const ���

	const Test ct; // const object
	ct.foo();	   // foo() const �� ��� ����. ���ٸ� ����

}