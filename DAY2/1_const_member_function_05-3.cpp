#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// �ٽ�
	// "const vector" �̰� "non-const vector" �̰�
	// ���� ��ü�� ��� �޸𸮰� �ƴմϴ�.
	// �׷���, const vector �϶��� ���۰� ���ó�� ���̰� �ؾ� �մϴ�.

	// 1. non-const vector : v[0] = 0 �� ǥ����� �����ؾ� �մϴ�.
	// => T& ��ȯ						
	T& operator[](int idx)       { return buff[idx]; }

	// 2. const vector : v[0] = 0 �� ǥ����� ���� ���;� �մϴ�.
	// => const T& �� ��ȯ
	const T& operator[](int idx) const { return buff[idx]; }
};

int main()
{
	int n1 = 0;

	vector<int> v1(10);		  // R/W
	const vector<int> v2(10); // R 

	// ���� ���� : 2�� ���� ����
	//			// ���ϴ� ����	// ���� ����
	v1[0] = 0;	// O			O
	v2[0] = 0;	// X			X		

	n1 = v1[0];	// O			O
	n1 = v2[0];	// O			O
}