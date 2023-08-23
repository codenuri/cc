// T44. Use function templates to deduce class template argument types

template<typename T1, typename T2>
struct PAIR
{
	T1 first;
	T2 second;

	PAIR(const T1& a, const T2& b) : first(a), second(b) {}
};

// Ŭ���� ���ø��� ���� ����ϸ� "Ÿ�� ����" ������ ������ ���ϼ� �ֽ��ϴ�.
// �� ��� �Լ� ���ø����� Ÿ���� �߷��ϰ� �ϸ� ���մϴ�.
template<typename T1, typename T2>
PAIR<T1, T2> make_pair(const T1& a, const T2& b)
{
	return PAIR<T1, T2>(a, b);
}

int main()
{
	PAIR<int, double> p1(1, 3.4);

//	PAIR p2(1, 3.4);

	// make_pair �� ���ø� �̹Ƿ� ��Ȯ�� ǥ����� �Ʒ� �ڵ� �Դϴ�.
	auto p2 = make_pair<int, double>(1, 3.4); 

	// ������ make_pair�� �Լ� ���ø� �̹Ƿ� "C++17 �������� Ÿ�� ����" �����մϴ�.
	auto p3 = make_pair(1, 3.4);
}

// make_pair ���� ����� "Object Generator" ��� �ϴµ�,
// cppreference.com ������ "convenient function template" �̶�� �� ����մϴ�.






