#include <iostream>
#include <string>

// in-parameter 
// #3. std::string 

// call by value
// => string 객체 자체가 복사되고
// => string 의 복사 생성자에서 문자열도 복사
void f1(std::string s) // worst
{
}

// call by const reference
// good 이지만, C++17 부터는 "best" 는 아닙니다.
void f2(const std::string& s)
{
}

int main()
{
	std::string s = "to be or not to be";

	f1(s);
	f2(s);
}