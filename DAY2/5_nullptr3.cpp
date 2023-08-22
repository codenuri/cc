#include <iostream>
#include <thread>

void foo(int* p) {}


int main()
{
	foo(0); // ok

//	std::thread t(&foo, 0); // error. 0을 foo로 직접 전달하지 않고
							// 0 ====> thread 생성자 ====> foo()로 전달
							//         받을때 0을 int로추론
	std::thread t(&foo, nullptr); // ok

	t.join();
}