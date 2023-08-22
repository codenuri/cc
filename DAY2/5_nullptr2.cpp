#include <iostream>

template<typename F, typename ARG>
void chronometry(F f, ARG&& arg)
{
	f( std::forward<T>(arg) );
}

void foo(int* p) {}

int main()
{
	int n = 0;
	foo(0); // ok. ���ͷ� 0 �� "int" Ÿ��������, �����ͷ� �Ͻ��� ��ȯ ����
//	foo(n); // error. 0 �� ���� ������ ������ �����ͷ� �Ͻ��� ��ȯ �ȵ˴ϴ�.

	// �� �ڵ带 �����ؼ�, �Ʒ� �ڵ带 ������ ���ô�.(���� ��� �Ϻ�������)
	chronometry(foo, 0); // foo(0) �����ش޶�� ��
	
}