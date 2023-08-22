#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	T& operator[](int idx) const { return buff[idx]; }
};
int main()
{
	int n1 = 0;

	vector<int> v1(10);		  // R/W
	const vector<int> v2(10); // R 

	// 현재 상태 : operator[](int idx) const
	//			// 원하는 동작	// 현재 상태
	v1[0] = 0;	// O			
	v2[0] = 0;	// X			

	n1 = v1[0];	// O			
	n1 = v2[0];	// O			
}