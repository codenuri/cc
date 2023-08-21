// 1_function_parameter_07-4 => 7번 복사

#include <iostream>
#include <string>

class Person
{
	std::string name;
public:
	// move 를 지원하는 setter 만들기

	// 방법 1. 동일한 이름의 2개의 함수 제공
//	void set_name(const std::string& n) { name = n;	}
//	void set_name(std::string&& n)      { name = std::move(n); }

	
	// 방법 2. T&& 를 사용하면 위 2개 버전을 자동 생성가능합니다.
	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것을 찾으세요
		name = n;					// 1
		name = std::move(n);		// 2
		name = std::forword<T>(n);	// 3
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

