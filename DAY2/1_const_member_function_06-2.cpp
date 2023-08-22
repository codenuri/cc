// 5-3 복사하세요
#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// C++23 전까지는 아래 처럼 2개 만들어야 합니다.
//	      T& operator[](int idx)       { return buff[idx]; }
//	const T& operator[](int idx) const { return buff[idx]; }

	// C++23 부터는 아래 처럼 만들게 됩니다.
	// decltype(auto) : return 문 보고 추론해 달라.
	template<typename T>
	decltype(auto) operator[](this T& self, int idx)
	{
		return self->buff[idx];
	}
};

int main()
{
	int n1 = 0;

	vector<int> v1(10);		  // R/W
	const vector<int> v2(10); // R 

	v1[0] = 0;	// O			
	v2[0] = 0;	// X			
	n1 = v1[0];	// O			
	n1 = v2[0];	// O			
}