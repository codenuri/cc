// QA3
#include <string>
#include <iostream>

// ������ gcc������ std::string ���翡 ���� copy on write�� ����
// => C++98 ����
// => C++11���� ����Ǿ����ϴ�.

int main()
{
	std::string s1 = "abcd";
	std::string s2 = "to be or not to be";
}