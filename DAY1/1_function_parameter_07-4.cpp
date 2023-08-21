// 1_function_parameter_07-4 => 7번 복사

#include <iostream>
#include <string>

class Person
{
	std::string name;
public:
	// move 를 지원하는 setter 만들기

	// 방법 1. 동일한 이름의 2개의 함수 제공
	void set_name(const std::string& n)
	{
		std::cout << "const std::string&" << std::endl;
		name = n;
	}
	void set_name(std::string&& n)
	{
		std::cout << "string&&" << std::endl;
		name = std::move(n);
	}
};

int main()
{
	Person p;

	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	p.set_name(s1);		
	p.set_name(std::move(s2));	

	std::cout << s1 << std::endl; 
	std::cout << s2 << std::endl; 
}

