// F9. ������ ���� �Ķ���ʹ� �̸��� �־�� �ȵȴ�. ( 8page)

#include <iostream>
#include <mutex>


std::mutex m;


// lock�� �ϴ� �����ڿ� lock ���� ���� �����ڸ� ����� ����� ������ ���ô�.

// ��� 1. flag ���� ���
// => ���� ��Ÿ��.. ����(2010�� ���� ~ )���� �̷��� ������ �ʽ��ϴ�.
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
// ��� 2. �Լ� �����ε� ��� ���.

// �Լ� �����ε���, �Լ��� �����ϱ� ���ؼ��� ����� Ÿ���� ���� �մϴ�.
// => ���� empty class �� ���� �ϰ� �˴ϴ�
struct adopt_lock_t 
{
	// �����Ϸ��� �����ϴ� �����ڴ� explicit �� �ƴմϴ�.
	// �Ʒ� �ڵ带 ���� ������ ����Ʈ �����ڸ� explicit �� �ϱ� ���� ����
	explicit adopt_lock_t() = default;
};

// ��� ��ü�� �⺻������ const �Ǵ� constexpr �� �ϴ°��� �����ϴ�.
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
	lock_guard<std::mutex> g1(m);             // �����ڿ��� lock
	lock_guard<std::mutex> g2(m, adopt_lock); // �����ڿ��� lock ���� ����.
//	lock_guard<std::mutex> g3(m, {}); // �������� �ұ�� ? ��밡���ϰ� �ұ��?
									  // => C++ ǥ���� �� �ڵ带 �ȵǰ� �߽��ϴ�.
	// C++ ǥ�ؿ� �̹� �� �ڵ尡 �ֽ��ϴ�.
	std::lock_guard<std::mutex> g2(m, std::adopt_lock);

}
// QA. lock_guard �����ڿ��� m�� lock �������� 
// �ƴ��� �����ؼ� �˾Ƽ� ó�����ֵ��� �Ҽ��� ������?
// => C++ ���� std::recursive_mutex ���� ����� "2�� lock" �����մϴ�.
// => ����, �̹� lock �� �Ǿ� �־ �ٽ� lock ����/������ ����� �����ϰ��ؾ� �մϴ�.



int main()
{

}