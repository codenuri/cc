#include <iostream>

int main()
{
	int n = 0;

	std::cin >> n; // 정수를 입력 받으려고 했는데, 만약 "a" 를 입력 한다면 ?

	std::cout << n << std::endl;
		// 1. 10      2. 0     3. -1     4. 97
		// ==> 답은 2.. 입력 실패!!

	// 입력 실패를 조사하는 방법
	if (std::cin.fail()) // 방법 1. fail() 멤버 함수 사용
	{
		// 입력 실패
	}

	if (std::cin)	// 방법 2. std::cin 자체를 if 로 조사 가능
	{				// C++98 : cin.operator void*() 를 사용해서 포인터로 변환
					// C++11 : cin.operator bool() 을 사용해서 bool 로 변환되는것
		// 입력 성공
	}

}