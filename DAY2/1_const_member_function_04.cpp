#include <iostream>

class Test
{
	int value;
public:
	Test(int value) : value(value) {}

	void f1()			// void f1(Test* this)
	{
		int* p = &value; // ok
						 // int* p = &(this->value)
	}

	void f2() const		// void f2(const Test* this)
	{
//		int* p = &value; // error.
						 // int* p = &(this->value) �ε�.. this�� const Test*

		const int* p = &value; // ok
	}
	// �ٽ� : ��� ��� �Լ� �ȿ��� ��� ��� �� "��� ���" �˴ϴ�.

};

int main()
{
	Test t(10);
	t.f1();
}


