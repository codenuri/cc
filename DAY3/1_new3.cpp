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

		int cnt = 0;
		try
		{
			for (int i = 0; i < sz; ++i)
			{
	//			new( &buff[i] ) T;      // ����Ʈ ������!!
				new(&buff[i]) T(value); // ���� ������ ���
				++cnt;
			}
		}
		catch (...)
		{
			// ��������� ȣ�⿡ �����ߴ� ��ü�� �Ҹ��ڸ� ȣ���ؾ� �Ѵ�.
			for (int i = 0; i < cnt; i++)
				buff[i].~T();

			operator delete(buff);
			size = 0;

			throw; // �ٽ� ���� ����!
		}
	}
	~vector()
	{
		for (int i = 0; i < size; i++)
			buff[i].~T();

		operator delete(buff);
		size = 0;
	}
};

int main()
{
	Point pt(0, 0);
	vector<Point> v(10, pt);

}