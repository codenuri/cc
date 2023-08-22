// 5-3 �����ϼ���
#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// C++23 �������� �Ʒ� ó�� 2�� ������ �մϴ�.
//	      T& operator[](int idx)       { return buff[idx]; }
//	const T& operator[](int idx) const { return buff[idx]; }

	// C++23 ���ʹ� �Ʒ� ó�� ����� �˴ϴ�.
	// decltype(auto) : return �� ���� �߷��� �޶�.
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