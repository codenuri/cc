#include <iostream>

class Point
{
	int x, y;
public:
	void f1(int a, int b)
	{
		x = a;
		y = b;
		std::cout << f1 << std::endl;
	}
};

int main()
{
	Point pt;
	pt.f1(1, 2);
}