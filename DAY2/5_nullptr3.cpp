#include <iostream>
#include <thread>

void foo(int* p) {}


int main()
{
	foo(0); // ok

//	std::thread t(&foo, 0); // error. 0�� foo�� ���� �������� �ʰ�
							// 0 ====> thread ������ ====> foo()�� ����
							//         ������ 0�� int���߷�
	std::thread t(&foo, nullptr); // ok

	t.join();
}