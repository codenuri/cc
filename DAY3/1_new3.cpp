#include <iostream>

class Point
{
	int x;
	int y;
public:
	// Point 는 디폴트 생성자가 없습니다.
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
//		buff = new T;	// 이렇게 하면 T 는 반드시 디폴트 생성자가 있어야 합니다
		buff = static_cast<T*>(operator new(sizeof(T) * sz));

		int cnt = 0;
		try
		{
			for (int i = 0; i < sz; ++i)
			{
	//			new( &buff[i] ) T;      // 디폴트 생성자!!
				new(&buff[i]) T(value); // 복사 생성자 사용
				++cnt;
			}
		}
		catch (...)
		{
			// 복사생성자 호출에 성공했던 객체는 소멸자를 호출해야 한다.
			for (int i = 0; i < cnt; i++)
				buff[i].~T();

			operator delete(buff);
			size = 0;

			throw; // 다시 예외 전달!
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