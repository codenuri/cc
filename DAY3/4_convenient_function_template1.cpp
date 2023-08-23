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
	// 다음중 쉬워 보이는 것은 ?
	square<int>(3);	// 템플릿 타입인자를 직접 전달하는 코드 - 복잡해 보입니다.
	square(3);		// 타입 인자를 생략하면 함수 인자를 보고 타입을 추론
					// => 간결해 보입니다.
					
	// 핵심 1. 함수 템플릿은 타입인자를 생략할수 있다
	
	// 핵심 2. 클래스 템플릿의 "생성자 인자를 통한 타입추론" 은 C++17 부터 가능.

	PAIR<int, double> p1(1, 3.4);

	PAIR p2(1, 3.4); // 생성자를 통한 타입 추론 ? - C++17 부터 가능
					 // C++14 까지는 에러!
}







