#include <iostream>

class Test
{
public:
	// �ٽ� : ���� �̸��� �Լ��� 
	//		 ���, ���� �������� ���ÿ� ���� �����մϴ�.
	void foo()       { std::cout << "foo" << std::endl; }
	void foo() const { std::cout << "foo const" << std::endl; }
};

int main()
{
	Test t;
	t.foo();

	const Test ct;
	ct.foo();

}