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
		// 깊은 복사를 위한 메모리 할당
		// 아래 처럼 하면
		// 1. 메모리 할당뿐 아니라 생성자도 호출되어서(객체의 자원이할당하게 됩니다.)
		// 2. 그런데, 결국, 다시 other.buff 를 복사하게 됩니다.
//		buff = new T[size];	

		// 따라서, other.buff 를 복사하기 위한 메모리는 
		// "메모리만 있으면 됩니다."
		buff = static_cast<T*>( operator new(sizeof(T)* size));


		// 2. other.buff 내용을 => buff 로 복사 해야 합니다
		// 복사 생성자가 trivial 하면(모든 멤버를 얕은 복사) : memcpy()가 최선의 코드
		// 복사 생성자가 trivial 하지 않으면 : 각각의 객체에 대해 복사 생성자 호출

		if (std::is_trivially_copy_constructible_v<T>)
		{
			memcpy(buff, other.buff, sizeof(T) * size);
			std::cout << "trivial copy, use memcpy" << std::endl;
		}
		else
		{
			std::cout << "not trivial copy, use copy ctor" << std::endl;

			for (int i = 0; i < size; ++i)
			{
				new(&buff[i]) T( other.buff[i] ); // 복사 생성자 호출
			}
		}

	}

};











int main()
{
	Point pt(0, 0);
	vector<Point> v1(10, pt);

	vector<Point> v2 = v1; // 이 한줄을 생각해 봅시다.

}