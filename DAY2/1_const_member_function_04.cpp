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
						 // int* p = &(this->value) 인데.. this가 const Test*

		const int* p = &value; // ok
	}
	// 핵심 : 상수 멤버 함수 안에서 모든 멤버 는 "상수 취급" 됩니다.

};

int main()
{
	Test t(10);
	t.f1();
}


