#include <iostream>
#include <string>
#include <sstream>

class Point
{
	int x;
	int y;

	std::string cache;
	bool cache_valid = false;
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
};

int main()
{
	Point pt(1, 2);
	std::cout << pt.to_string() << std::endl;
	std::cout << pt.to_string() << std::endl;
}

