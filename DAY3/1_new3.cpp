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

		for (int i = 0; i < sz; ++i)
		{
//			new( &buff[i] ) T;      // 디폴트 생성자!!
			new(&buff[i]) T(value); // 복사 생성자 사용
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