// T44. Use function templates to deduce class template argument types

template<typename T1, typename T2>
struct PAIR
{
	T1 first;
	T2 second;

	PAIR(const T1& a, const T2& b) : first(a), second(b) {}
};

// 클래스 템플릿을 직접 사용하면 "타입 인자" 때문에 복잡해 보일수 있습니다.
// 이 경우 함수 템플릿으로 타입을 추론하게 하면 편리합니다.
template<typename T1, typename T2>
PAIR<T1, T2> make_pair(const T1& a, const T2& b)
{
	return PAIR<T1, T2>(a, b);
}

int main()
{
	PAIR<int, double> p1(1, 3.4);

//	PAIR p2(1, 3.4);

	auto p2 = make_pair(1, 3.4);
}








