#include <iostream>
#include <string>
#include <sstream>

class Point
{
	int x;
	int y;

	// mutable 멤버 데이타 : const 멤버 함수 안에서도
	//						값을 변경할수 있는 멤버데이타를 만들때사용
	//						반드시 필요한 경우가 있게 됩니다!!!
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
	// x, y 가 변경되면 cache_valid 를 false 로 변경!!
};

int main()
{
	Point pt(1, 2);
	std::cout << pt.to_string() << std::endl;
	std::cout << pt.to_string() << std::endl;
}

