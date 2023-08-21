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
	void set(const std::string& n, const std::string& a) 
	{ 
		name = n; 
		address = a;
	}
	void set(std::string&& n, std::string&& a)
	{
		name    = std::move(n);
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
	// 결국 인자가 N개인 setter 를 move 지원 하려면
	// N^2 개의 함수를 제공해야 합니다.
	// 함수가 너무 많아 집니다.
	// => 이 경우 알아야 하는 것이 T&& 와 std::forward<> 입니다.
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