
// SL.con.4: don��t use memset or memcpy for arguments that are not "trivially-copyable"

#include <iostream>

// special member function
// => ������, �Ҹ���, ���� ������, ���Կ�����, �̵� ������, �̵� ���� ������
// => ����ڰ� ������ ������ �����Ϸ��� ������ �ִ� ��� ��. 


// trivial : special member function �� �ϴ� ���� "�ڸ�(�θ� �˷��� ����Ʈ ��Ĵ�� ����)" �ϴٴ� �ǹ�.
// trivial ������      : �ƹ� �ϵ� ���� ���� ������
// trivial ���� ������ : ��� ����� ���� �����ϴ� ���� ������.
// trivial �Ҹ���     : �ƹ��ϵ� ���� ���� �Ҹ���!


// �����ڰ� "trivial(�ڸ�)" �ϴٴ� ���� 
// => �����ڰ� �ϴ� ���� �������� �ǹ� �մϴ�.

class A
{
};

// B�� �����ڴ� trivial �ұ�� ?
class B //: public A
{
	int data;
//	A member;
public:
//	virtual void foo() {}
};
// �����ڰ� trivial �Ϸ���
// 1. ����ڰ� ���� �����ڰ� ����
// 2. �����Լ��� ����
// 3. ��� Ŭ������ ���ų�, ��� Ŭ������ �����ڰ� trivial �ϰ�
// 4. ��ü�� ����� ���ų�, ��ü�� ����� �����ڰ� trivial 
// �Ҷ�... �����ڴ� trivial �մϴ�.




int main()
{
	// ������ ȣ�� ���� ��ü ����
	B* p = static_cast<B*>(operator new(sizeof(B)));

	new(p) B; // ������ ȣ��.

	p->foo();

	std::cout << "finish main" << std::endl;
}