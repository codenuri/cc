// R.22 : Use make_shared() to make shared_ptrs
// R.23 : Use make_unique() to make unique_ptrs

#include <iostream>
#include <memory>

void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

struct Point
{
	int x;
	int y;

	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// 아래 코드는 몇번의 동적 메모리 할당이 있을까요 ?
	// 1. new Point => 8 바이트 할당
	// 2. sp 의 생성자에서 관리객체 생성(20~30바이트정도)
//	std::shared_ptr<Point> sp1(new Point(1, 2));

	// 관리 객체는 결국 Point 객체를 관리하는 용도 입니다.
	// 2개를 떨어뜨리지 말고, 같이 한번에 할당하는게 메모리가 효율적입니다.

	// std::make_shared<T>(T의 생성자인자)

	// 1. sizeof(T) + sizeof(관리객체) 를 operator new()로 한번에 할당
	// 2. placement new로 객체 부분의 메모리에 생성자 호출
	// 3. shared_ptr 만들어서 반환
	
	std::shared_ptr<Point> sp1 = std::make_shared<Point>(1, 2);
	

	// 장점 2. 안전성
	// => 아래 코드는 아무 문제가 없을까요 ?

	// 아래 코드는 foo() 호출전에 3가지 작업을 하게 됩니다.
	//             (B)               (A)            (C)
	foo( std::shared_ptr<Point>(new Point(1, 2)),  goo() );

	// 위코드가
	// (A)-(B)-(C) 순서로 실행되면 문제 없습니다.

	// (A)-(C)-(B) 순서로 실행되었는데, (C) 에서 예외가 발생한 다면 ??

	// 핵심 : 자원을 할당하고, 자원의 핸들(주소)를 자원관리 객체에 전달하는 작업은
	//	     반드시 한번에 이루어 져야 합니다.
	//       중간에 다른 작업을 하게 되면 문제가 발생할수 있습니다.
	// 
	// 그래서, "자원의 할당의 자원 관리 객체를 만들때(RAII) 해야 합니다."

	foo(std::make_shared<Point>(1,2), goo());
}


void foo(std::shared_ptr<Point> sp, int n) {}

int  goo() { return 10; }



