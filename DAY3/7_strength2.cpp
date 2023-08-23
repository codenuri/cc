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

	auto ret = max1(s1, s2);
}



