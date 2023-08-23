// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. ( 8page)

#include <iostream>
#include <mutex>


template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard() { mtx.unlock(); }
};

std::mutex m;
int shared_data = 0;

// 핵심 1. 자원 관리는 직접 하는 것은 좋지 않습니다.
//      2. 항상 RAII 기술로 자원을 관리하세요

// RAII : Resource Acquision Is Initialization
// => 자원을 획득하는 것(m.lock) 은 (자원관리 객체(lock_guard)가) 초기화 될때이다


// 2개 이상의 스레드가 아래 foo함수를 실행.. 
void foo()
{
	lock_guard<std::mutex> g(m); // good
								 // 1. 생성자에서 m.lock() 수행
								 //	2. 소멸자에서 m.unlock() 수행
								 //	=> 함수 실행중 예외 등이 발생해도
								 //	   지역변수는 안전하게 파되 됩니다.
								 //	   즉, g의 소멸자 호출이 보장됩니다.
								 //    결국 예외 발생시에도 m.unlock()이된다는 의미
//	m.lock();

	shared_data = 100;

	// 예외 발생..

//	m.unlock();  // bad
}


int main()
{

}