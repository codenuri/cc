#include <iostream>
#include <string_view>
#include <string>
#include <array>

class Person
{
	std::string name;
	std::string address;
	std::array<int, 32> data;
public:
	// ���� 1. �Ʒ� �Լ��� ���ڷ� ���޹��� ���� ����� ����(retain)
	//         ���� �ʰ�, �Լ� ���������θ� ��� �մϴ�.
	//         "in parameter" �Դϴ�.
	//		   string_view �� �ּ�, 
	//         C++17 �����̸� const std::string& �� ����� �˴ϴ�.
	//		   move �������� ������.
//	void print_msg(const std::string& msg)
	void print_msg(std::string_view msg)  // C++17 ���� �ּ� 
	{
		std::cout << msg << std::endl;
	}

	// ���� 2. retain �� �Ǵ���, move �� ȿ���� ���� Ÿ���� move�� ������� ������
	// => primitive type
	// => �ڿ��� ���� �Ҵ����� �ʴ� Ÿ�Ե�..
	// => std::array ��.
	void set_data(const std::array<int, 32>& d)
	{
		// �Ʒ� �ڵ�� �и��� ����� ����(retain) ������
		// const std::array �� move ȿ�� �����ϴ�.		
		data = d;
	}
	// move ���� �� setter �� ������ �ʿ� �����ϴ�.
	// �Ʒ� �ڵ�� ������ ������
	void set_data(std::array<int, 32>&& d)
	{
		data = std::move(d);
	}
};

// int n1 = 10;
// int n2 = std::move(n1); // ������ �ƴ�����,
						// move ȿ���� ���� �����ϴ�.
						// int n2 = n1 �� ������ ����
// Point p1(1, 2);
// Point p2 = std::move(p1); // move ȿ�� �����ϴ�.


int main()
{
	Person p;

	std::string s = "to be or no to be";
	std::array<int, 32> arr = { 0 };

	p.print_msg(s);
	p.set_data(arr);
}