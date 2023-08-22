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

	      vector<int> v1(10); // R/W 가능
	const vector<int> v2(10); // R 만 사용하겠다는것

	// 현재 상태 : operator[](int idx) 가 const 가 아닌 경우
	// 원하는 동작을 O(되야한다), X(안되야 한다) 로 표기해 보세요
	//			// 원하는 동작	// 현재 상태
	v1[0] = 0;	// O			O	
	v2[0] = 0;	// X			X
		
	n1 = v1[0];	// O			O
	n1 = v2[0];	// O			X
}