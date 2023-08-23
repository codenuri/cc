// R.22 : Use make_shared() to make shared_ptrs
// R.23 : Use make_unique() to make unique_ptrs

#include <iostream>
#include <memory>

struct Point
{
	int x;
	int y;
	
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// 1. C++ 스마트 포인터는 explicit 생성자 입니다.
//	std::shared_ptr<Point> sp1 = new Point(1, 2);  // error
	std::shared_ptr<Point> sp2(new Point(1, 2));   // ok
												

	// 2. 스마트 포인터를 사용하기로 했다면
	// => new 를 직접 사용하지 말고
	// => std::make_shared() 를 사용하세요 
	std::shared_ptr<Point> sp3(new Point(1, 2)); // bad

	std::shared_ptr<Point> sp4 = std::make_shared<Point>(1, 2); // good
}






