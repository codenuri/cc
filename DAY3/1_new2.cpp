#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 : Point 는 디폴트 생성자가 없습니다.
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point()			{ std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// Point 객체를 힙에 한개만 만들어 보세요
	Point* p1 = new Point(1, 2);

	// Point 객체를 힙에 10개 만들어 보세요
//	Point* p2 = new Point[10];	// error. 디폴트 생성자를 10번 호출해야 하는데
								// Point 는 디폴트 생성자가 없습니다.

	// 메모리 할당과 생성자 호출을 분리하면 "유연하게 객체 생성"이 가능합니다.

	// 1. 10개의 메모리 공간 할당
	Point* p2 = static_cast<Point*>( operator new(sizeof(Point) * 10) );

	// 2. 10 개의 메모리 공간에 10개의 객체를 생성
	for (int i = 0; i < 10; i++)
	{
		new(&p2[i]) Point(0, 0);
	}

	// 3. 개체 파괴(소멸자 호출)
	for (int i = 0; i < 10; i++)
	{
		p2[i].~Point();
	}
	// 4. 메모리 해지
	operator delete(p2);
	
}