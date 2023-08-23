// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. ( 8page)

#include <iostream>
#include <mutex>


std::mutex m;


// lock을 하는 생성자와 lock 하지 않은 생성자를 만드는 방법을 생각해 봅시다.

// 방법 1. flag 인자 사용
// => 옛날 스타일.. 요즘(2010년 이후 ~ )에는 이렇게 만들지 않습니다.
/*
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m, bool lock = true ) : mtx(m) 
	{ 
		if ( lock )
			mtx.lock(); 
	}
	~lock_guard()             { mtx.unlock(); }
};
*/
// 방법 2. 함수 오버로딩 기술 사용.

// 함수 오버로딩시, 함수를 구별하기 위해서만 사용할 타입을 설계 합니다.
// => 보통 empty class 로 설계 하게 됩니다
struct adopt_lock_t 
{
	// 컴파일러가 제공하는 생성자는 explicit 가 아닙니다.
	// 아래 코드를 만든 이유는 디폴트 생성자를 explicit 로 하기 위한 목적
	explicit adopt_lock_t() = default;
};

// 모든 객체는 기본적으로 const 또는 constexpr 로 하는것이 좋습니다.
constexpr adopt_lock_t adopt_lock;


template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m)                : mtx(m) { mtx.lock();}
	lock_guard(T& m, adopt_lock_t ) : mtx(m) { }

	~lock_guard() { mtx.unlock(); }
};
void foo()
{
	lock_guard<std::mutex> g1(m);             // 생성자에서 lock
	lock_guard<std::mutex> g2(m, adopt_lock); // 생성자에서 lock 수행 안함.
//	lock_guard<std::mutex> g3(m, {}); // 에러나게 할까요 ? 사용가능하게 할까요?
									  // => C++ 표준은 이 코드를 안되게 했습니다.
	// C++ 표준에 이미 위 코드가 있습니다.
	std::lock_guard<std::mutex> g2(m, std::adopt_lock);

}





int main()
{

}