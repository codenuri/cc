// 1_function_parameter_05-2
#include <iostream>
#include <string>
#include <string_view>

void good(const std::string& s)
{
}



void best(std::string_view s)
{
}



int main()
{
	std::string s = "to be or not to be";

	// 아래의 경우는 "const string&" 도 나쁘지 않습니다
	good(s);
	best(s);

	// 그런데, 아래 코드를 생각해 보세요
	good("to be or not to be");
	best("to be or not to be");
}