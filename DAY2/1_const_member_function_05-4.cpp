#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

					
	T& operator[](int idx) { return buff[idx]; }

	// v[0] = 0 을 에러나오게 하기 위해
	// T 반환        : 버퍼에 있는 것을 복사본을 만들어서 반환하는 것
	//					=> 임시 객체 생성에 의한 오버헤드
	//					=> 임시 객체 또는 값(3같은)은 rvalue, 
	//					   rvalue 는 주소를 구할수 없다.
	// const T& 반환 : 버퍼의 별명 반환, 별명은 lvalue
	//					=> lvalue 는 주소를 구할수 있다.
//	T operator[](int idx) const { return buff[idx]; }
	const T& operator[](int idx) const { return buff[idx]; }
};

int main()
{
	const vector<int> v(10);
//	v[0] = 0; //error

	std::cout << &v[0] << std::endl; // T 라면 error
									// &임시객체 또는  &3  등이 표기법!!!
									// 3의 주소를 구할수는 없다
									// const T& 라면 ok!!
}