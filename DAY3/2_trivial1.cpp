
// SL.con.4: don’t use memset or memcpy for arguments that are not "trivially-copyable"

#include <iostream>

// special member function
// => 생성자, 소멸자, 복사 생성자, 대입연산자, 이동 생성자, 이동 대입 연산자
// => 사용자가 만들지 않으면 컴파일러가 생성해 주는 멤버 들. 


// trivial : special member function 이 하는 일이 "자명(널리 알려진 디폴트 방식대로 동작)" 하다는 의미.
// trivial 생성자      : 아무 일도 하지 않은 생성자
// trivial 복사 생성자 : 모든 멤버를 얕은 복사하는 복사 생성자.
// trivial 소멸자     : 아무일도 하지 않은 소멸자!


// 생성자가 "trivial(자명)" 하다는 것은 
// => 생성자가 하는 일이 없을때를 의미 합니다.

class A
{
};

// B의 생성자는 trivial 할까요 ?
class B //: public A
{
	int data;
//	A member;
public:
//	virtual void foo() {}
};
// 생성자가 trivial 하려면
// 1. 사용자가 만든 생성자가 없고
// 2. 가상함수가 없고
// 3. 기반 클래스가 없거나, 기반 클래스의 생성자가 trivial 하고
// 4. 객체형 멤버가 없거나, 객체형 멤버의 생성자가 trivial 
// 할때... 생성자는 trivial 합니다.




int main()
{
	// 생성자 호출 없이 객체 생성
	B* p = static_cast<B*>(operator new(sizeof(B)));

	new(p) B; // 생성자 호출.

	p->foo();

	std::cout << "finish main" << std::endl;
}