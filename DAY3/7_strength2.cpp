#include <string>
#include <iostream>

template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	std::string s1 = "AAA";
	std::string s2 = "BBB";

	auto ret1 = max1(s1, s2); // ret1 결국 s2의 복사본 입니다.

	const std::string& ret2 = max1(s1, s2);
							  // ret2 는 s2의 별명 입니다.
	//=====================================
	// 이 예제의 핵심 - 2개의 인자가 임시객체(rvalue) 일때
	// 아래 처럼 받는 ret3은 안전할까요 ?
	const std::string& ret3 = max1(std::string("AAA"),
								   std::string("BBB"));
}



