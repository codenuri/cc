#include <iostream>

class String
{
public:
	explicit String(const char* s) {}
};

void foo(String s) {}

int main()
{
	String s1 = "Hello"; // ���� �ʱ�ȭ
	String s2("Hello");  // ���� �ʱ�ȭ

	foo("Hello");		// String s = "Hello";  ��, ���� �ʱ�ȭ


	const String& r1 = "Hello";
						// 1. "Hello" �� ��ȯ �����ڸ� ����ؼ� String �ӽð�ü����
						// 2. �ӽð�ü�� r1 �� ����Ű�� �Ǵ� ���

	const String& r2 = String("Hello");
						// 1. ����ڰ� ��������� �ӽð�ü�� �����Ѱ�(�����ʱ�ȭ���)
						// 2. �ӽð�ü�� r2 �� ����Ű�� �Ǵ� ���
}

void f(const String& s) {}

f("hello");         // explicit ��� ����
f(String("hello")); // explicit �� ok..