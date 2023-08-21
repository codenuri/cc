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

	Object(const Object&) { std::cout << "copy" << std::endl; }

	Object(Object&&) { std::cout << "move" << std::endl; }
};

template<typename T>
T&& move(T&& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = move(o1);		// move
	Object o4 = move(Object()); // move
}
