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
	
}










void foo(std::shared_ptr<int> sp, int n) {}

int  goo() { return 10; }



