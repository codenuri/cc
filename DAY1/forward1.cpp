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
// => C++11 부터 가능. rvalue reference 문법 사용

// 방법 4. 2개의 함수 제공
// 특징 : 상수성 추가 없이 lvalue, rvalue 를 모두 받을수 있다.
//        결국, 한개의 함수가 아닌 2개의 함수!
// void foo(Point& p)  {}
// void foo(Point&& p) {}

// 방법 5. T&&(forwarding reference) 를 사용하면 위 2개 함수를
//         컴파일러가 자동 생성할수 있다.

// T&& 인자의 의도 : Point&, Point&& 버전의 함수를 자동생성하겠다는 의도

// foo(pt) 로 사용하면, pt는 lvalue 이므로 : T = Point&, T&& = Point& && => Point&, foo(Point&) 함수 생성
// foo(Point(1,2))는        rvalue 이므로 : T = Point,  T&& = Point&&			  foo(Point&&) 함수 생성

template<typename T>
void foo(T&& p)
{
}


int main()
{
	// foo 함수에 Point 객체를 전달하려고 합니다
	// => 단, lvalue, rvalue(임시객체)를 모두 받을수 있어야 합니다.
	Point pt(1, 2);

	foo(pt);          // lvalue
	foo(Point(1, 2)); // rvalue
}