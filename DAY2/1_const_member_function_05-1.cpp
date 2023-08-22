#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	T& operator[](int idx) { return buff[idx]; }
};
int main()
{
	int n1 = 0;

	      vector<int> v1(10);
	const vector<int> v2(10);

	// 원하는 동작을 O, X 로 표기해 보세요
	//			// 원하는 동작	// 현재 상태
	v1[0] = 0;	//
	v2[0] = 0;	//

	n1 = v1[0];	//
	n1 = v2[0];	// 
}