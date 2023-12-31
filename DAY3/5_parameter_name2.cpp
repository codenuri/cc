// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. ( 8page)

#include <iostream>
#include <mutex>




std::mutex m;
int shared_data = 0;


template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard() { mtx.unlock(); }
};

void foo()
{
//	lock_guard<std::mutex> g(m); // g의 생성자에서 m.lock() 수행

	// m.lock() 이 아닌 다른 방법으로 lock 획득
	if ( m.try_lock() )
	{
		// 다른 방법으로 lock 을 했지만, 
		// unlock 은 lock_guard 를 사용해서 안전하게 하고 싶다.
		lock_guard<std::mutex> g(m);// 생성자에서 다시 m.lock()하게된다.
									// 결국, lock() 을 하지 않은 생성자도 필요


		shared_data = 100;

		
	}

}





int main()
{

}