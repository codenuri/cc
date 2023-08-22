#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// 핵심
	// "const vector" 이건 "non-const vector" 이건
	// 버퍼 자체는 상수 메모리가 아닙니다.
	// 그런데, const vector 일때는 버퍼가 상수처럼 보이게 해야 합니다.

	// 1. non-const vector : v[0] = 0 의 표기법이 가능해야 합니다.
	// => T& 반환						
	T& operator[](int idx)       { return buff[idx]; }

	// 2. const vector : v[0] = 0 의 표기법이 에러 나와야 합니다.
	// => const T& 로 반환
	const T& operator[](int idx) const { return buff[idx]; }
};

int main()
{
	int n1 = 0;

	vector<int> v1(10);		  // R/W
	const vector<int> v2(10); // R 

	// 현재 상태 : 2개 버전 제공
	//			// 원하는 동작	// 현재 상태
	v1[0] = 0;	// O			O
	v2[0] = 0;	// X			X		

	n1 = v1[0];	// O			O
	n1 = v2[0];	// O			O
}