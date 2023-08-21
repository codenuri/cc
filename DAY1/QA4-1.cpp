// p.set_name("literal")�� p.set_name(std::string("literal"))�� �����Ѱ��� ?
// => ������ ��ﶧ ���ɴϴ�. ���� ����帮�ڽ��ϴ�.

// forward �� move�� ����Ѱ� �����ϴ�... ?
// => �Ʒ� �ڵ�� ��Ȯ�� ���� �ϼ���..
// => modern C++ �� �ٽ� �κ� �Դϴ�.


// QA4.cpp - git ���� ������ ������


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
