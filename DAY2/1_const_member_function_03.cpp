#include <iostream>
#include <string>
#include <sstream>

class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// 객체의 상태를 std::string 형태로 변경해 주는 멤버 함수
	// => 내부적으로 객체의 상태를 변경하지 않고, 읽기만 하므로 
	//    상수 멤버 함수로 해야 합니다.
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

