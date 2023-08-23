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


	// 2. 이미 할당된 메모리 공간에 생성자 호출(객체생성한다고 표현)
	// 참고 : *p1 = Point(1,2) => 대입연산자 호출. 즉, 생성자 호출이 안된 객체에
	//							  대입연산자를 호출한것
	
//	new(p1) Point(1,2);		// ====> "placement new" 라는 이름을 가진 기술

	std::construct_at(p1, 1, 2); // C++20 부터 가능


	// 3. 메모리 해지 없이 소멸자만 호출
//	p1->~Point();
	std::destroy_at(p1); // C++17 부터 사용가능


	// 4. 메모리만 해지(소멸자호출없이) - free 와 유사
	operator delete(p1);
}

// malloc : 메모리 할당
// new    : 객체 생성 ( 메모리 할당 + 생성자 호출 ) 

// new Point       : 새로운 메모리에            객체를 생성해 달라
// new(주소) Point : 이미 할당된 메모리(주소) 에 객체를 생성해 달라
//					 => 결국, 생성자를 호출하는 표기법