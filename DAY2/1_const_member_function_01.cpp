#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	// 사용자 코드				// 컴파일러가 변경한 코드
	void set(int a, int b)		// void set(Point* this, int a, int b)
	{
		x = a;					//		this->x = a;
		y = b;					//		this->y = b;
	}

//	void print()				// void print(Point* this)
	void print() const			// void print(const Point* this)
	{
//		x = 10; // error. 
				// this->x = 10 의 의미 인데, this 는 상수를 가리키는 포인터!
		std::cout << x << ", " << y << std::endl;
	}
};

int main()
{
//	Point pt(1, 2);
	const Point pt(1, 2);

	pt.x = 10;		// error. x 가 public 이지만, 상수 이므로
	pt.set(10, 20);	// error. 
					// set(&pt, 10, 20)

	pt.print();		// error. - print() 가 상수 함수가 아닌 경우
					// ok     - print() 가 상수 멤버 함수 인경우. 
					// print(&pt)
}

// 핵심 1. 상수 멤버 함수의 정확한 의미를 알아 두세요

//	void print()				// void print(Point* this)
//  void print() const			// void print(const Point* this)

// 핵심 2.
// non-const object : 일반 멤버 함수와 상수 멤버함수를 모두 호출 가능
//     const object : 상수 멤버함수만 호출가능