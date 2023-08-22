#include <iostream>

// ������ ȣ�����

struct BM	// Base Member ��� �ǹ̷� "BM" �̶�� �߽��ϴ�
{
	BM() { std::cout << "BM()" << std::endl; }
	~BM() { std::cout << "~BM()" << std::endl; }
};

struct DM	// Derived Member
{
	DM() { std::cout << "DM()" << std::endl; }
	~DM() { std::cout << "~DM()" << std::endl; }
};

struct Base
{
	BM bm;
	
	// ����� �ڵ�		// �����Ϸ��� ������ �ڵ�
	Base()				// Base() : bm()
	{						
		std::cout << "Base()" << std::endl;
	}
	~Base()
	{
		std::cout << "~Base()" << std::endl;		
	}
};
struct Derived : public Base
{
	DM dm;

	// ����� �ڵ�	// �����Ϸ��� ������ �ڵ�
	Derived()		// Derived() : Base(), dm()     // �ٽ� 
	{												// ��� ����Ÿ ���� ���Ŭ����
		std::cout << "Derived()" << std::endl;		// �����ڰ� ���� ȣ��
	}												// ����ڰ� �ٲܼ� �����ϴ�.
	~Derived()
	{
		std::cout << "~Derived()" << std::endl;
	}
};
int main()
{
	// ȭ�� ��� ������ �����غ�����
	// => ��Ȯ�� ������ �˾ƾ� �մϴ�.
	Derived d;	// call Derived::Derived()

}
