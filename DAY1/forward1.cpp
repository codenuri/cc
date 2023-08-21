// forward1.cpp
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

// 방법 1. call by value
// 특징 : 복사본 생성, 
// void foo(Point p) {}

// 방법 2. call by lvalue reference
// 특징 : 복사본 생성 안되지만, rvalue(임시객체)를 받을수 없다.
// void foo(Point& p) {}

// 방법 3. call by const lvalue reference
// 특징 1. lvalue 와 rvalue 를 모두 받을수 있다.
//      2. 그런데, 받으면서 상수성이 추가 된다. write 불가능.
void foo(const Point& p) {}

// 상수성 추가없이 lvalue, rvalue 를 모두 받을수 없을까 ?
// => C++98 은 불가능!!


int main()
{
	// foo 함수에 Point 객체를 전달하려고 합니다
	// => 단, lvalue, rvalue(임시객체)를 모두 받을수 있어야 합니다.
	Point pt(1, 2);

	foo(pt);          // lvalue
	foo(Point(1, 2)); // rvalue
}