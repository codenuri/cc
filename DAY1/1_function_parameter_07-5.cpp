// 1_function_parameter_07-5 - 7-3복사

#include <iostream>
#include <string>

// 인자가 한개인 setter 일때 move 지원 하려면 
// => 2개의 함수를 만드세요
//    set_name(const std::string& s) {name = s;}
//    set_name(std::string&& s)      {name = std::move(s);}

// 인자가 2개 이상인 setter 일때 move 지원 하기.
class Person
{
	std::string name;
	std::string address;
public:
	/*
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
	void set(std::string&& n, std::string&& a)
	{
		name = std::move(n);
		address = std::move(a);
	}
	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}
	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}
	*/
	// 인자가 2개인 setter의 move 지원하려면 
	// => 위 처럼 직접 만들려면 2^2, 즉, 4개의 함수가 필요합니다.
	// => 이경우 아래 처럼 하는 것이 좋습니다.
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name    = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}

};

int main()
{
	Person p;

	std::string s1 = "lee";
	std::string s2 = "seoul";

	//	p.set(s1, s2);
	//	p.set(std::move(s1), std::move(s2));
	p.set(std::move(s1), s2);

}