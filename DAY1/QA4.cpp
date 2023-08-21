// p.set_name("literal")과 p.set_name(std::string("literal"))이 동일한가요 ?
// => 생성자 배울때 나옵니다. 내일 설명드리겠습니다.

// forward 와 move가 비슷한것 같습니다... ?
// => 아래 코드로 명확히 이해 하세요..
// => modern C++ 의 핵심 부분 입니다.


// QA4.cpp - git 에서 복사해 오세요


#include <iostream>

class Object
{
public:
	Object() {}

	// 복사 생성자 : 여기서 자원을 복사하는 코드 작성
	Object(const Object&) { std::cout << "copy" << std::endl; }

	// move 생성자 : 여기서 자원을 이동하는 코드 작성
	Object(Object&&)      { std::cout << "move" << std::endl; }
};

// C++ 표준의 move를 만들어 봅시다.
/*
template<typename T>
T&& move(T& obj)
{
	return static_cast<T&&>(obj);
}
*/

// 템플릿 만들때
// T&  : lvalue 만 인자로 받겠다는 것 
// T&& : lvalue, rvalue 를 모두 받겠다는 것 

template<typename T>
T&& move(T&& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;				// 복사 생성자 호출
//	Object o3 = std::move(o1);	// 이동 생성자 호출
//	Object o3 = static_cast<Object&&>(o1); // 결국 이코드가 위와 동일한 코드입니다.

	Object o3 = move(o1);
	Object o4 = move(Object()); // 임시객체는 move가 없어도 rvalue 이므로 이동 생성자 호출
								// 하지만 move() 안에 rvalue 를 넣을수 없어야 할까요 ?
								//							   넣을수 있어야 할까요 ?
}
// 위 코드는 에러는 없지만, 결과가 잘못됩니다.
// 왜 그럴까요 ??