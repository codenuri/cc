// 5-3 복사하세요
#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// C++23 전까지는 아래 처럼 2개 만들어야 합니다.
//	      T& operator[](int idx)       { return buff[idx]; }
//	const T& operator[](int idx) const { return buff[idx]; }

	// C++23 부터는 아래 처럼 만들게 됩니다.
	// decltype(auto) : return 문 보고 추론해 달라.
	template<typename T>
	decltype(auto) operator[](this T& self, int idx)
	{
		return self->buff[idx]; // self 가 const 라면   : const T& 반환
								// self 가 const 아니면 : T& 반환
	}
};

int main()
{
	int n1 = 0;

	vector<int> v1(10);		  // R/W
	const vector<int> v2(10); // R 

	v1[0] = 0;	// O			
	v2[0] = 0;	// X			
	n1 = v1[0];	// O			
	n1 = v2[0];	// O			
}

// C++ 
class Test
{
public:
	void f1()
	{
		// 멤버 데이타를 R/W 가능한 함수
	}
	void f2() const
	{
		// 멤버 데이타를 R 만 가능한함수
	}
};
// const 멤버 함수가 더 많이 사용되는데
// C++은 디폴트가 non-const 이고, 필요할때 const 를 붙여야 합니다.

// swift : 모든 멤버 함수는 기본적으로 const 멤버 함수
//		   R/W 하고 싶으면 mut 키워드사용
class Test
{
	public void f1()
	{
		// 멤버 데이타를 R 가능한 함수
	}
	public void f2() mutable
	{
		// 멤버 데이타를 R/W 만 가능한함수
	}
};