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
	// T ��ȯ        : ���ۿ� �ִ� ���� ���纻�� ���� ��ȯ�ϴ� ��
	//					=> �ӽ� ��ü ������ ���� �������
	//					=> �ӽ� ��ü �Ǵ� ��(3����)�� rvalue, 
	//					   rvalue �� �ּҸ� ���Ҽ� ����.
	// const T& ��ȯ : ������ ���� ��ȯ, ������ lvalue
	//					=> lvalue �� �ּҸ� ���Ҽ� �ִ�.
//	T operator[](int idx) const { return buff[idx]; }
	const T& operator[](int idx) const { return buff[idx]; }
};

int main()
{
	const vector<int> v(10);
//	v[0] = 0; //error

	std::cout << &v[0] << std::endl; // T ��� error
									// &�ӽð�ü �Ǵ�  &3  ���� ǥ���!!!
									// 3�� �ּҸ� ���Ҽ��� ����
									// const T& ��� ok!!
}