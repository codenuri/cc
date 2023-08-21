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

	// ���� ������ : ���⼭ �ڿ��� �����ϴ� �ڵ� �ۼ�
	Object(const Object&) { std::cout << "copy" << std::endl; }

	// move ������ : ���⼭ �ڿ��� �̵��ϴ� �ڵ� �ۼ�
	Object(Object&&)      { std::cout << "move" << std::endl; }
};

// C++ ǥ���� move�� ����� ���ô�.
/*
template<typename T>
T&& move(T& obj)
{
	return static_cast<T&&>(obj);
}
*/

// ���ø� ���鶧
// T&  : lvalue �� ���ڷ� �ްڴٴ� �� 
// T&& : lvalue, rvalue �� ��� �ްڴٴ� �� 

template<typename T>
T&& move(T&& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;				// ���� ������ ȣ��
//	Object o3 = std::move(o1);	// �̵� ������ ȣ��
//	Object o3 = static_cast<Object&&>(o1); // �ᱹ ���ڵ尡 ���� ������ �ڵ��Դϴ�.

	Object o3 = move(o1);
	Object o4 = move(Object()); // �ӽð�ü�� move�� ��� rvalue �̹Ƿ� �̵� ������ ȣ��
								// ������ move() �ȿ� rvalue �� ������ ����� �ұ�� ?
								//							   ������ �־�� �ұ�� ?
}
// �� �ڵ�� ������ ������, ����� �߸��˴ϴ�.
// �� �׷���� ??