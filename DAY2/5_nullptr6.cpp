#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg) // std::nullptr_t&& arg = nullptr;
{							   // �ٽ� : T�� std::nullptr_t �� �߷�
	f(std::forward<T>(arg));   // foo(arg) �ε�... arg��  std::nullptr_t �̹Ƿ�
}							   // ��� Ÿ���� �����ͷ� ����ȯ ����

void foo(int* p) {}

int main()
{	
//	chronometry(foo, 0); // T �� int�� �߷еǹǷ� error
	chronometry(foo, nullptr); 
}