
// SL.con.4: don��t use memset or memcpy for arguments that are not "trivially-copyable"

#include <iostream>

// special member function
// => ������, �Ҹ���, ���� ������, ���Կ�����, �̵� ������, �̵� ���� ������
// => ����ڰ� ������ ������ �����Ϸ��� ������ �ִ� ��� ��. 


// trivial : special member function �� �ϴ� ���� "�ڸ�(�θ� �˷��� ����Ʈ ��Ĵ�� ����)" �ϴٴ� �ǹ�.
// trivial ������      : �ƹ� �ϵ� ���� ���� ������
// trivial ���� ������ : ��� ����� ���� �����ϴ� ���� ������.
// trivial �Ҹ���     : �ƹ��ϵ� ���� ���� �Ҹ���!

class A
{
};

// B�� �����ڴ� trivial �ұ�� ?
class B 
{
	int data;
public:
	virtual void foo() {}
};


int main()
{

}