#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point()			{ std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// new 가 하는 일
	// 1. 메모리 할당
	// 2. 생성자 호출
//	Point* p1 = new Point(1, 2);

	// delete 가 하는일
	// 1. 소멸자 호출
	// 2. 메모리 해지
//	delete p1;

	// 1. 메모리만 할당(생성자 호출없이) - malloc 과 유사
	Point* p1 = static_cast<Point*>( operator new(sizeof(Point)));


	// 4. 메모리만 해지(소멸자호출없이) - free 와 유사
	operator delete(p1);

}
