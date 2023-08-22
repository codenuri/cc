#include <iostream>
#include <string>
#include <sstream>

class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// ��ü�� ���¸� std::string ���·� ������ �ִ� ��� �Լ�
	// => ���������� ��ü�� ���¸� �������� �ʰ�, �б⸸ �ϹǷ� 
	//    ��� ��� �Լ��� �ؾ� �մϴ�.
	std::string to_string() const
	{
		std::stringstream oss;
		oss << x << ", " << y;
		return oss.str(); // "1, 2"
	}
};

int main()
{
	Point pt(1, 2);
	std::cout << pt.to_string() << std::endl;
	std::cout << pt.to_string() << std::endl;
}

