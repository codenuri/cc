#include <iostream>

// in-parameter 
// #1. user define type

struct Rect
{
	int left, top, right, bottom;
};

// ���ڸ� �б⸸ �Ұ��̶��
// 1. call by value
// => ���纻 ������ ������尡 �ְ�
// => ���� ������ ȣ���� ������尡 �ֽ��ϴ�.
void bad1(Rect rc) {}


// 2. call by non-const reference
// => �Ǽ��� ��ü�� ���¸� �����Ҽ��ִ�.
// => �ӽð�ü�� ������ ����.
void bad2(Rect& rc) 
{
	rc.left = 10;
}

// ��� 3. call by const reference
// => ��κ��� ��쿡 ���� ����!!
void good(const Rect& rc)
{
	rc.left = 10;
}

int main()
{
	Rect rc;
	bad1(rc);
	bad2(Rect()); // �ӽð�ü ����.
	good(Rect()); // ok. 
}
