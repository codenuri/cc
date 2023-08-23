// F9. ������ ���� �Ķ���ʹ� �̸��� �־�� �ȵȴ�. ( 8page)

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

// �ٽ� 1. �ڿ� ������ ���� �ϴ� ���� ���� �ʽ��ϴ�.
//      2. �׻� RAII ����� �ڿ��� �����ϼ���

// RAII : Resource Acquision Is Initialization
// => �ڿ��� ȹ���ϴ� ��(m.lock) �� (�ڿ����� ��ü(lock_guard)��) �ʱ�ȭ �ɶ��̴�


// 2�� �̻��� �����尡 �Ʒ� foo�Լ��� ����.. 
void foo()
{
	lock_guard<std::mutex> g(m); // good
								 // 1. �����ڿ��� m.lock() ����
								 //	2. �Ҹ��ڿ��� m.unlock() ����
								 //	=> �Լ� ������ ���� ���� �߻��ص�
								 //	   ���������� �����ϰ� �ĵ� �˴ϴ�.
								 //	   ��, g�� �Ҹ��� ȣ���� ����˴ϴ�.
								 //    �ᱹ ���� �߻��ÿ��� m.unlock()�̵ȴٴ� �ǹ�
//	m.lock();

	shared_data = 100;

	// ���� �߻�..

//	m.unlock();  // bad
}


int main()
{

}