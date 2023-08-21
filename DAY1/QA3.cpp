// QA3
#include <string>
#include <iostream>

// 예전에 gcc에서는 std::string 복사에 대해 copy on write로 구현
// => C++98 시절
// => C++11에서 변경되었습니다.

// C++98
// 1. 문자열을 항상 힙에 보관

// C++11
// 1. 길이가 작은 문자열은 객체 자체(스택)에 보관
//    => 길이가 긴(보통 16자) 이상의 문자열만 힙에 보관

int main()
{
	std::string s1 = "abcd";
	std::string s2 = "to be or not to be";

	std::cout << &s1 << std::endl;				// 객체 주소
	std::cout << (void*)s1.data() << std::endl;	// 문자열 버퍼 주소

	std::cout << &s2 << std::endl;				// 스택 메모리 주소
	std::cout << (void*)s2.data() << std::endl;	// 힙 메모리 주소

	//-------------------------
	std::string s3 = s2; // C++98. reference counting, copy on write 
						 //        즉, 문자열 공유 기술 사용
						 // C++11. 깊은 복사, 문자열 자체를 새로운 메모리로 복사

	std::cout << (void*)s2.data() << std::endl;
	std::cout << (void*)s3.data() << std::endl;
}




