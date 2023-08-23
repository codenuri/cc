#include <iostream>

// trivial ���δ� "������ special member function" ���� �ٸ��ϴ�.
// �����ڴ� trivial ���� ������ ���� �����ڴ� trivial �Ҽ� �ֽ��ϴ�.

// ��� special member function �� trivial �ϸ�
// => trivial type �̶�� �մϴ�.
// => ��� primitive type(int, double, char��) �� trivial type �Դϴ�.
// => C ����� ����ü�� trivial type �Դϴ�.


class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}

	// ����ڰ� ���� �����ڸ� ����ٸ�, ��� ����� ���� �����ص�, "trivial"�� �ƴմϴ�.
//	Point(const Point& pt) : x(pt.x), y(pt.y) {}

	// move �����ڸ� ����� �����Ϸ��� ���� �����ڸ� �������� �ʽ��ϴ�.
	// => �̶�, ���� �������� �⺻ ������ �ʿ� �ߴٸ�
	// => ���� ���� ������ ����, �����Ϸ����� ��û�ϼ���
	Point(Point&& pt) {}
//	Point(const Point& pt) : x(pt.x), y(pt.y) {}
	Point(const Point& pt) = default;

//	~Point() {}  // C++ �Ҹ��ڸ� ���� ���, �ڿ� ������ �ϴ� Ŭ������� �����մϴ�.
				 // �׷��� ���� �����ڵ� trivial ���� �ʴٰ� �����ϰ� �˴ϴ�.
				 // �ʿ� ���� �Ҹ��ڴ� ���� ������ ������!!
//	~Point() = default;
};

// vector ���� ��ü�� ���� �Ҷ�
// memcpy �� �����ϴ� ��            : bit-wise copy ��� �մϴ�
// �� ����� ���� �����ڷ� �����ϴ°� : member-wise copy




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

	// vector �� ���� �����ڸ� ������ ���ô� - ���� ����� �����մϴ�.
	vector(const vector& other) : size(other.size)
	{
		// ���� ���縦 ���� �޸� �Ҵ�
		// �Ʒ� ó�� �ϸ�
		// 1. �޸� �Ҵ�� �ƴ϶� �����ڵ� ȣ��Ǿ(��ü�� �ڿ����Ҵ��ϰ� �˴ϴ�.)
		// 2. �׷���, �ᱹ, �ٽ� other.buff �� �����ϰ� �˴ϴ�.
//		buff = new T[size];	

		// ����, other.buff �� �����ϱ� ���� �޸𸮴� 
		// "�޸𸮸� ������ �˴ϴ�."
		buff = static_cast<T*>( operator new(sizeof(T)* size));


		// 2. other.buff ������ => buff �� ���� �ؾ� �մϴ�
		// ���� �����ڰ� trivial �ϸ�(��� ����� ���� ����) : memcpy()�� �ּ��� �ڵ�
		// ���� �����ڰ� trivial ���� ������ : ������ ��ü�� ���� ���� ������ ȣ��

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
				new(&buff[i]) T( other.buff[i] ); // ���� ������ ȣ��
			}
		}
	}
};











int main()
{
	Point pt(0, 0);
	vector<Point> v1(10, pt);

	vector<Point> v2 = v1; // �� ������ ������ ���ô�.

}