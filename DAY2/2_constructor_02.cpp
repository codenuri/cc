#include <iostream>

// C.47: Define and initialize member variables 
//       in the order of member declaration

// �Ʒ� Ŭ������ � ������ ������� ?
struct vector
{
	int* buff;
	int size;
public:
	// �ʱ�ȭ ����Ʈ�� 
	// 1. �ڵ尡 ���� ���� ��� ����Ǵ� ���� �ƴ϶�
	// 2. ��� ����Ÿ�� ���� ������� ����˴ϴ�.
	// �׷��� �Ʒ� �ڵ�� 
	//					(2)			(1)
//	vector(int sz) : size(sz), buff(new int[size]) // bad...
	vector(int sz) : buff(new int[sz]), size(sz)   // good...
	{
	}
	~vector()
	{
		delete[] buff;
	}
};
int main()
{
	vector v(10);
}