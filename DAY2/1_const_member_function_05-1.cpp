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

	      vector<int> v1(10); // R/W ����
	const vector<int> v2(10); // R �� ����ϰڴٴ°�

	// ���� ���� : operator[](int idx) �� const �� �ƴ� ���
	// ���ϴ� ������ O(�Ǿ��Ѵ�), X(�ȵǾ� �Ѵ�) �� ǥ���� ������
	//			// ���ϴ� ����	// ���� ����
	v1[0] = 0;	// O			O	
	v2[0] = 0;	// X			X
		
	n1 = v1[0];	// O			O
	n1 = v2[0];	// O			X
}