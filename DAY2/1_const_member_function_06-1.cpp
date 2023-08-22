// 1_const_member_functin_06-1

// explicit object parameter ������ ���� ����
// 1. deducing this!!
// 2. �׿� �پ��� ������ �ֽ��ϴ�.
class Test
{
public:
	// C++98 ~ C++20 ��Ÿ��
	void f1()       {} // void f1(Test* this) 
	void f1() const {} // void f1(const Test* this) 

	// C++23 ���ο� �������� �� �ڵ�ó�� 2�� �����!
	// => �ٽ� : const Ű���尡 �Լ� () �ڰ� �ƴ�, �Լ� ���ڷ� ���̰� �˴ϴ�.
	void f2(this Test&       self) {}
	void f2(this const Test& self) {}

	// �ٽ� : const �� ���ڿ� ���Եǰ� �Ǿ����ϴ�.
	// => template �� ����ϸ� �� 2�� �Լ��� �ڵ� �����˴ϴ�
	template<typename T>
	void f3(this T& self) {}
};

int main()
{
	Test t;
	const Test ct;

	t.f3();		// f3(this Test&)       ��, f3() ����
	ct.f3();    // f3(this const Test&) ��, f3() const ����

}