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

	// make_pair 도 템플릿 이므로 정확한 표기법은 아래 코드 입니다.
	auto p2 = make_pair<int, double>(1, 3.4); 

	// 하지만 make_pair은 함수 템플릿 이므로 "C++17 이전에도 타입 생략" 가능합니다.
	auto p3 = make_pair(1, 3.4);
}

// make_pair 같은 기술을 "Object Generator" 라고 하는데,
// cppreference.com 에서는 "convenient function template" 이라는 용어를 사용합니다.






