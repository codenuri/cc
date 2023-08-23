#include <iostream>
#include <type_traits> 

class Test
{
//	int data;
	int data = 0;	// "data=0" �� �ʱ�ȭ�� �ᱹ �����Ϸ��� �����ڷ� �ű�� �˴ϴ�.
					// ����, ���ڵ� ������ �����ڰ� trivial ���� �ʰԵ˴ϴ�.
public:
	//	virtual void foo() {} // �����Լ��� ������ �����ڰ� �ϴ����� ����

//	Test() {}	      // ����ڰ� �����ڸ� �����ϸ� trivial �� �ƴմϴ�.

	Test() = default; // �����Ϸ��� ����� trivial �� �ɼ� �ֽ��ϴ�.
					  // (��, �ٸ� ���ǵ� �����ؾ�)
};

int main()
{
	// trivial ���θ� �����ϴ� ���
	bool b = std::is_trivially_default_constructible_v<Test>;

	std::cout << std::boolalpha << b << std::endl;
}