#include <iostream>

class Point
{
	int x;
	int y;
public:
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
		buff = static_cast<T*>(operator new(sizeof(T) * sz));

		int cnt = 0;
		try
		{
			for (int i = 0; i < sz; ++i)
			{
				new(&buff[i]) T(value); 
				++cnt;
			}
		}
		catch (...)
		{
			for (int i = 0; i < cnt; i++)
				buff[i].~T();

			operator delete(buff);
			size = 0;
			buff = nullptr;

			throw; 
		}
	}
	~vector()
	{
		for (int i = 0; i < size; i++)
			buff[i].~T();

		operator delete(buff);
		size = 0;
	}

	// vector 의 복사 생성자를 생각해 봅시다 - 많은 기법이 등장합니다.
	vector(const vector& other) : size(other.size)
	{

	}

};

int main()
{
	Point pt(0, 0);
	vector<Point> v1(10, pt);

	vector<Point> v2 = v1; // 이 한줄을 생각해 봅시다.

}