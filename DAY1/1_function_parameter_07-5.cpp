// 1_function_parameter_07-5 - 7-3����

#include <iostream>
#include <string>

// ���ڰ� �Ѱ��� setter �϶� move ���� �Ϸ��� 
// => 2���� �Լ��� ���弼��
//    set_name(const std::string& s) {name = s;}
//    set_name(std::string&& s)      {name = std::move(s);}

// ���ڰ� 2�� �̻��� setter �϶� move ���� �ϱ�.
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
	// ���ڰ� 2���� setter�� move �����Ϸ��� 
	// => �� ó�� ���� ������� 2^2, ��, 4���� �Լ��� �ʿ��մϴ�.
	// => �̰�� �Ʒ� ó�� �ϴ� ���� �����ϴ�.
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