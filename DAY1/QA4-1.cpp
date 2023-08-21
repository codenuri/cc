// p.set_name("literal")�� p.set_name(std::string("literal"))�� �����Ѱ��� ?
// => ������ ��ﶧ ���ɴϴ�. ���� ����帮�ڽ��ϴ�.

// forward �� move�� ����Ѱ� �����ϴ�... ?
// => �Ʒ� �ڵ�� ��Ȯ�� ���� �ϼ���..
// => modern C++ �� �ٽ� �κ� �Դϴ�.


// QA4.cpp - git ���� ������ ������


#include <iostream>
#include <type_traits>
class Object
{
public:
	Object() {}

	Object(const Object&) { std::cout << "copy" << std::endl; }

	Object(Object&&) { std::cout << "move" << std::endl; }
};

// �ٽ� : ���ڰ� T&& ���, lvalue, rvalue ��� ������ �ִµ�, 
//        ������ ���, T�� Ÿ���� �ݵ�� �ܿ��� �մϴ�.
// move(o1)			��, lvalue ������ : T=Object&, T&&= Object& && => Object&
// move(Object()),  ��, rvalue ������ : T=Object,  T&&= Object&&

template<typename T>
std::remove_reference_t<T>&& move(T&& obj)
{
	// �Ʒ� �ڵ�� obj �� "�׻� rvalue" �� ĳ�����ϴ� �ڵ��ϱ�� ?=> �ƴմϴ�.
	// move(lvalue ��, o1) ��� "static_cast<Object&>(obj)"
	// move(rvalue )       ��� "static_cast<Object&&>(obj)"
//	static_cast<T&&>(obj);

	// T&& �� �ƴ� Object&& ó�� ��Ȯ�� Ÿ���� ���� ���� rvalue ĳ����
//	static_cast<Object&&>(obj);

	// move �� "�׻� rvalue ĳ���� �Ǿ�� �մϴ�."
	// ��� : T �� ���� ���۷��� Ÿ���� �������� && �� ���̸� �˴ϴ�.
	return static_cast< std::remove_reference_t<T> &&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = move(o1);		// move
	Object o4 = move(Object()); // move
}
