#include <iostream>
#include <string>
#include <string_view>	// C++17
						// g++ 소스이름.cpp -std=c++17 필요

int main()
{
	std::string s = "to be or not to be";

	// #1. 아래 2줄의 메모리 그림 알아 두세요
	std::string      ss1 = s; // 깊은 복사(복사 생성자에서 메모리(문자열) 자체를 복사)
	std::string_view sv1 = s; // sv1 은 s의 문자열을 같이 사용
							  // "const char* + size(unsigned int)" 입니다.
							  // 크기가 크지 않은 타입

	// #2. 아래 2줄의 메모리 그림을 이해 하는것이 핵심 입니다.
	// => "string literal 로 직접 초기화 하는 경우"
	std::string      ss2 = "to be or not to be";
						// string 의 생성자가 힙 메모리 할당후
						// 상수 메모리에 있던 문자열을 힙메모리로 복사 한것
						// 즉, ss2 가 자신만의 문자열을 소유 한것

	std::string_view sv2 = "to be or not to be"; // 상수메모리에 있던 문자열을 가리키기만 한것
	// const char* p = "to be or not to be";	 // C언어의 이코드의 의미.
	// unsigned int size						 // 문자열의 복사본 생성 안됨
}