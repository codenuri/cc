// T44. Use function templates to deduce class template argument types

template<typename T> T square(T a)
{
	return a * a;
}

template<typename T1, typename T2> 
struct PAIR
{
	T1 first;
	T2 second;

	PAIR(const T1& a, const T2& b) : first(a), second(b) {}
};

int main()
{
	// ������ ���� ���̴� ���� ?
	square<int>(3);	// ���ø� Ÿ�����ڸ� ���� �����ϴ� �ڵ� - ������ ���Դϴ�.
	square(3);		// Ÿ�� ���ڸ� �����ϸ� �Լ� ���ڸ� ���� Ÿ���� �߷�
					// => ������ ���Դϴ�.
					
	// �ٽ� 1. �Լ� ���ø��� Ÿ�����ڸ� �����Ҽ� �ִ�
	
	// �ٽ� 2. Ŭ���� ���ø��� "������ ���ڸ� ���� Ÿ���߷�" �� C++17 ���� ����.

	PAIR<int, double> p1(1, 3.4);

	PAIR p2(1, 3.4); // �����ڸ� ���� Ÿ�� �߷� ? - C++17 ���� ����
					 // C++14 ������ ����!
}







