#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

					
	T& operator[](int idx) { return buff[idx]; }

	// v[0] = 0 �� ���������� �ϱ� ����
	// T ��ȯ        : 
	// const T& ��ȯ :
	T operator[](int idx) const { return buff[idx]; }
//	const T& operator[](int idx) const { return buff[idx]; }
};

int main()
{
	const vector<int> v(10);
	v[0] = 0;
}