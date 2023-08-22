#include <iostream>

// 생성자 호출순서

struct BM	// Base Member 라는 의미로 "BM" 이라고 했습니다
{
	BM() { std::cout << "BM()" << std::endl; }
	~BM() { std::cout << "~BM()" << std::endl; }
};

struct DM	// Derived Member
{
	DM() { std::cout << "DM()" << std::endl; }
	~DM() { std::cout << "~DM()" << std::endl; }
};

struct Base
{
	BM bm;
	
	// 사용자 코드		// 컴파일러가 변경한 코드
	Base()				// Base() : bm()
	{						
		std::cout << "Base()" << std::endl;
	}
	~Base()
	{
		std::cout << "~Base()" << std::endl;		
	}
};
struct Derived : public Base
{
	DM dm;

	// 사용자 코드	// 컴파일러가 변경한 코드
	Derived()		// Derived() : Base(), dm()     // 핵심 
	{												// 멤버 데이타 보다 기반클래스
		std::cout << "Derived()" << std::endl;		// 생성자가 먼저 호출
	}												// 사용자가 바꿀수 없습니다.
	~Derived()
	{
		std::cout << "~Derived()" << std::endl;
	}
};
int main()
{
	// 화면 출력 순서를 예측해보세요
	// => 정확한 원리를 알아야 합니다.
	Derived d;	// call Derived::Derived()

}
