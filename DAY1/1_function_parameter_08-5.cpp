#include <iostream>

void f1(int& a) { a = 10; } // �߿��� �˰��� �ۼ�
void f2(double d) { }
void f3(double d, int a, int b) { }

// �Լ��� ����ð��� �����ϴ� �Լ�
// => ���� �Ϻ��� ������ "�������� ���ø�"�� �Բ� ����մϴ�.
template<typename F, typename ... T>
void chronometry(F f, T&& ... arg)
{
	// =============> �ð� ���
	f( std::forward<T>(arg) ... );
	// =============> ���� �ð� ���
}

int main()
{
	int n = 10;

//	f1(n); // ����ð��� �˰� �ʹ�!

	chronometry(f1, n); // f1(n) �� ����ð��� ����� �޶�.
	chronometry(f3, 3.4, 1, 2); // f3(3.4, 1, 2) �� ����ð�
}
