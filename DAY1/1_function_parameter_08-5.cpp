#include <iostream>

void f1(int& a) { a = 10; } // �߿��� �˰��� �ۼ�
void f2(double d) { }
void f3(double d, int a, int b) { }

// �Լ��� ����ð��� �����ϴ� �Լ�
template<typename F, typename T>
void chronometry(F f, T arg)
{
	// =============> �ð� ���
	f(arg);
	// =============> ���� �ð� ���
}

int main()
{
	int n = 10;

//	f1(n); // ����ð��� �˰� �ʹ�!
	chronometry(f1, n);
}
