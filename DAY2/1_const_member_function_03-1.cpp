#include <iostream>
#include <string>
#include <sstream>

class Point
{
	int x;
	int y;

	// mutable ��� ����Ÿ : const ��� �Լ� �ȿ�����
	//						���� �����Ҽ� �ִ� �������Ÿ�� ���鶧���
	//						�ݵ�� �ʿ��� ��찡 �ְ� �˴ϴ�!!!
	mutable std::string cache;
	mutable bool cache_valid = false;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	std::string to_string() const
	{
		if (cache_valid == false)
		{
			std::stringstream oss;
			oss << x << ", " << y;
			cache = oss.str();
			cache_valid = true;
		}
		return cache;
	}
	// x, y �� ����Ǹ� cache_valid �� false �� ����!!
};

int main()
{
	Point pt(1, 2);
	std::cout << pt.to_string() << std::endl;
	std::cout << pt.to_string() << std::endl;
}

