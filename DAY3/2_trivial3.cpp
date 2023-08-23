#include <iostream>

// trivial 여부는 "각각의 special member function" 별로 다릅니다.
// 생성자는 trivial 하지 않지만 복사 생성자는 trivial 할수 있습니다.

// 모든 special member function 이 trivial 하면
// => trivial type 이라고 합니다.
// => 모든 primitive type(int, double, char등) 은 trivial type 입니다.
// => C 언어의 구조체가 trivial type 입니다.


class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}

	// 사용자가 복사 생성자를 만든다면, 모든 멤버를 얕은 복사해도, "trivial"이 아닙니다.
//	Point(const Point& pt) : x(pt.x), y(pt.y) {}

	// move 생성자를 만들면 컴파일러는 복사 생성자를 제공하지 않습니다.
	// => 이때, 복사 생성자의 기본 동작이 필요 했다면
	// => 절대 직접 만들지 말고, 컴파일러에게 요청하세요
	Point(Point&& pt) {}
//	Point(const Point& pt) : x(pt.x), y(pt.y) {}
	Point(const Point& pt) = default;

//	~Point() {}  // C++ 소멸자를 만든 경우, 자원 관리를 하는 클래스라고 생각합니다.
				 // 그래서 복사 생성자도 trivial 하지 않다고 생각하게 됩니다.
				 // 필요 없는 소멸자는 절때 만들지 마세요!!
//	~Point() = default;
};

// vector 같은 객체를 복사 할때
// memcpy 로 복사하는 것            : bit-wise copy 라고 합니다
// 각 요소의 복사 생성자로 복사하는것 : member-wise copy




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