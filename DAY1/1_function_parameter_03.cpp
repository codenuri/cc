#include <iostream>

// in-parameter 
// #1. user define type

struct Rect
{
	int left, top, right, bottom;
};

// 인자를 읽기만 할것이라면
// 1. call by value
// => 복사본 생성의 오버헤드가 있고
// => 복사 생성자 호출의 오버헤드가 있습니다.
void bad1(Rect rc) {}


// 2. call by non-const reference
// => 실수로 객체의 상태를 변경할수있다.
// => 임시객체를 받을수 없다.
void bad2(Rect& rc) 
{
	rc.left = 10;
}

// 방법 3. call by const reference
// => 대부분의 경우에 좋은 선택!!
void good(const Rect& rc)
{
	rc.left = 10;
}

int main()
{
	Rect rc;
	bad1(rc);
	bad2(Rect()); // 임시객체 전달.
	good(Rect()); // ok. 
}
