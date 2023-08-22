#include <iostream>

// C.47: Define and initialize member variables 
//       in the order of member declaration

// 아래 클래스는 어떤 문제가 있을까요 ?
struct vector
{
	int* buff;
	int size;
public:
	// 초기화 리스트는 
	// 1. 코드가 놓인 순서 대로 실행되는 것이 아니라
	// 2. 멤버 데이타의 선언 순서대로 실행됩니다.
	// 그래서 아래 코드는 
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