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
							  // �̼���, v2��ü�� ����̰� ���۴� ����� �ƴմϴ�
							  // �׷���, ����ڿ��Դ� ���۵� ��� ó�� ���̰�
							  // �ϴ� ���� ���� ���� �Դϴ�.

	// ���� ���� : operator[](int idx) const
	//			// ���ϴ� ����	// ���� ����
	v1[0] = 0;	// O			O
	v2[0] = 0;	// X			O		<== ����, ��� vector�ε� ���氡��!!

	n1 = v1[0];	// O			O
	n1 = v2[0];	// O			O
}