// p.set_name("literal")과 p.set_name(std::string("literal"))이 동일한가요 ?
// => 생성자 배울때 나옵니다. 내일 설명드리겠습니다.

// forward 와 move가 비슷한것 같습니다... ?
// => 아래 코드로 명확히 이해 하세요..
// => modern C++ 의 핵심 부분 입니다.


// QA4.cpp - git 에서 복사해 오세요


#include <iostream>
#include <type_traits>
class Object
{
public:
	Object() {}

	Object(const Object&) { std::cout << "copy" << std::endl; }

	Object(Object&&) { std::cout << "move" << std::endl; }
};

// 핵심 : 인자가 T&& 라면, lvalue, rvalue 모두 받을수 있는데, 
//        각각의 경우, T의 타입을 반드시 외워야 합니다.
// move(o1)			즉, lvalue 보내면 : T=Object&, T&&= Object& && => Object&
// move(Object()),  즉, rvalue 보내면 : T=Object,  T&&= Object&&

template<typename T>
std::remove_reference_t<T>&& move(T&& obj)
{
	// 아래 코드는 obj 를 "항상 rvalue" 로 캐스팅하는 코드일까요 ?=> 아닙니다.
	// move(lvalue 즉, o1) 라면 "static_cast<Object&>(obj)"
	// move(rvalue )       라면 "static_cast<Object&&>(obj)"
//	static_cast<T&&>(obj);

	// T&& 가 아닌 Object&& 처럼 명확한 타입을 적은 경우는 rvalue 캐스팅
//	static_cast<Object&&>(obj);

	// move 는 "항상 rvalue 캐스팅 되어야 합니다."
	// 방법 : T 가 가진 레퍼런스 타입을 제거한후 && 를 붙이면 됩니다.
	return static_cast< std::remove_reference_t<T> &&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = move(o1);		// move
	Object o4 = move(Object()); // move
}
