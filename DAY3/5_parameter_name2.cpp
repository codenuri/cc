// F9. ������ ���� �Ķ���ʹ� �̸��� �־�� �ȵȴ�. ( 8page)

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
//	lock_guard<std::mutex> g(m); // g�� �����ڿ��� m.lock() ����

	// m.lock() �� �ƴ� �ٸ� ������� lock ȹ��
	if ( m.try_lock() )
	{
		// �ٸ� ������� lock �� ������, 
		// unlock �� lock_guard �� ����ؼ� �����ϰ� �ϰ� �ʹ�.
		lock_guard<std::mutex> g(m);

		shared_data = 100;

		
	}

}





int main()
{

}