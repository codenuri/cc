// QA3
#include <string>
#include <iostream>

// 예전에 gcc에서는 std::string 복사에 대해 copy on write로 구현
// => C++98 시절
// => C++11에서 변경되었습니다.

int main()
{
	std::string s1 = "abcd";
	std::string s2 = "to be or not to be";
}