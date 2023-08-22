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
							  // 이순간, v2객체만 상수이고 버퍼는 상수는 아닙니다
							  // 그런데, 사용자에게는 버퍼도 상수 처럼 보이게
							  // 하는 것이 보통 관례 입니다.

	// 현재 상태 : operator[](int idx) const
	//			// 원하는 동작	// 현재 상태
	v1[0] = 0;	// O			O
	v2[0] = 0;	// X			O		<== 문제, 상수 vector인데 변경가능!!

	n1 = v1[0];	// O			O
	n1 = v2[0];	// O			O
}