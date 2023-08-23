
// SL.con.4: don’t use memset or memcpy for arguments that are not "trivially-copyable"

#include <iostream>

// special member function
// => 생성자, 소멸자, 복사 생성자, 대입연산자, 이동 생성자, 이동 대입 연산자
// => 사용자가 만들지 않으면 컴파일러가 생성해 주는 멤버 들. 


// trivial : special member function 이 하는 일이 "자명(널리 알려진 디폴트 방식대로 동작)" 하다는 의미.
// trivial 생성자      : 아무 일도 하지 않은 생성자
// trivial 복사 생성자 : 모든 멤버를 얕은 복사하는 복사 생성자.
// trivial 소멸자     : 아무일도 하지 않은 소멸자!

class A
{
};

// B의 생성자는 trivial 할까요 ?
class B 
{
	int data;
public:
	virtual void foo() {}
};


int main()
{

}