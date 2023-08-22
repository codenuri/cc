#include <iostream>

// �����ڿ��� �����Լ� ó�� �����ϰ� �ʹٸ�
// "factory function" �� ����϶�!!
// 
// => ����鼭 ȣ������ ���� �����Ŀ� ȣ���ض�!

struct Base
{
	Base() { } 

	virtual void init() { std::cout << "Base::init" << std::endl; }     // 1

	// factory function : ��ü�� ����� �Լ�
	template<typename T>
	static T* create()
	{
		T* p = new T; // 1. ��ü�� �����
		p->init();    // 2. �����Լ� ȣ��
		return p;		
	}
};



struct Derived : public Base
{
	int x;
	Derived() : x(10) {}	

	virtual void init() override { std::cout << "Derived::init : " << x << std::endl; } // 2
};

int main()
{
	Derived* p = Base::create<Derived>();
					// �����, init ȣ��!!!
}
