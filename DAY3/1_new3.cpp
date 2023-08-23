#include <iostream>

class Point
{
	int x;
	int y;
public:
	// Point �� ����Ʈ �����ڰ� �����ϴ�.
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

template<typename T> class vector
{
	T* buff;
	int size;	
public:
	vector(int sz, const T& value) : size(sz)
	{
//		buff = new T;	// �̷��� �ϸ� T �� �ݵ�� ����Ʈ �����ڰ� �־�� �մϴ�
	
		buff = static_cast<T*>(operator new(sizeof(T) * sz));

		for (int i = 0; i < sz; ++i)
		{
//			new( &buff[i] ) T;      // ����Ʈ ������!!
			new(&buff[i]) T(value); // ���� ������ ���
		}
	}
	~vector()
	{

	}
};

int main()
{
	Point pt(0, 0);
	vector<Point> v(10, pt);

}