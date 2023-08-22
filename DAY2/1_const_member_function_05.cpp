#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// [] 연산자 재정의 : 객체를 배열처럼 사용가능하게 한다.
	// => 관례적으로 참조 타입으로 반환해야 합니다.
	// T  반환 : buff[idx] 에 있는 "값" 반환,      v[0] = 0 표기법이 에러!!
	// T& 반환 : buff[idx] 의 메모리  "별명" 반환, v[0] = 0 표기법 사용가능
	T& operator[](int idx) { return buff[idx]; }
};
int main()
{
	int n1 = 0;

	vector<int> v(10);

	v[0] = 0;	// v.operator[](0) = 0
	n1 = v[0];
}