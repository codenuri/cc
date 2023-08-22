#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// [] ������ ������ : ��ü�� �迭ó�� ��밡���ϰ� �Ѵ�.
	// => ���������� ���� Ÿ������ ��ȯ�ؾ� �մϴ�.
	// T  ��ȯ : buff[idx] �� �ִ� "��" ��ȯ,      v[0] = 0 ǥ����� ����!!
	// T& ��ȯ : buff[idx] �� �޸�  "����" ��ȯ, v[0] = 0 ǥ��� ��밡��
	T& operator[](int idx) { return buff[idx]; }
};
int main()
{
	int n1 = 0;

	vector<int> v(10);

	v[0] = 0;	// v.operator[](0) = 0
	n1 = v[0];
}