// forward1.cpp
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};


int main()
{
	// foo 함수에 Point 객체를 전달하려고 합니다
	// => 단, lvalue, rvalue(임시객체)를 모두 받을수 있어야 합니다.
	Point pt(1, 2);
	foo(pt);          // lvalue
	foo(Point(1, 2)); // rvalue
}