#include <iostream>

int main()
{
	// 모든 리터럴은 타입이 있습니다.
	10;  // int
	3.4; // double
	false; // bool.  false 는 리터럴이고 키워드 입니다.

	// nullptr 도 리터럴(값)이고 키워드(약속된 단어) 입니다.
	nullptr; // std::nullptr_t 타입

	std::nullptr_t mynull = nullptr; // ok

	// std::nullptr_t 은 모든 타입의 포인터로 암시적 형변환 됩니다.
	// nullptr 대신 mynull 사용가능.

	int* p1 = mynull;
	char* p2 = mynull;

	void(*f)() = mynull;

}