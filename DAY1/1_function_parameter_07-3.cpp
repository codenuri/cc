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
	// �ᱹ ���ڰ� N���� setter �� move ���� �Ϸ���
	// N^2 ���� �Լ��� �����ؾ� �մϴ�.
	// �Լ��� �ʹ� ���� ���ϴ�.
	// => �� ��� �˾ƾ� �ϴ� ���� T&& �� std::forward<> �Դϴ�.
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