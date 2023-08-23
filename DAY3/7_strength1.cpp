// F.4: If a function might have to be evaluated at compile time, declare it constexpr
//
// F.5: If a function is very small and time - critical, declare it inline

// [[nodiscard]] : 리턴 값을 무시하면 경고를 발생해 달라. C++17

template<typename T>
[[nodiscard]] const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}
// 함수가 수행시간이 중요하면 inline 으로 만들어라.
template<typename T>
[[nodiscard]] inline const T& max2(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}
// 함수가 컴파일 시간에 연산가능하게 하려면 constexpr 을 붙여라!
template<typename T>
[[nodiscard]] constexpr const T& max3(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	int ret1 = max1(1, 2); // 실행시간에 함수 호출
						   // call max1

	int ret2 = max2(1, 2); // max2의 기계어 코드를 이곳에 치환
						   // mov eax, 1
						   // add eax, 2
						   // mov ret2, eax

	constexpr int ret3 = max3(1, 2); // "1+2" 를 컴파일 시간에 실행
									 // mov ret3, 3

	int ret4 = max3(1, 2); // 컴파일 할때 실행할지, 실행시간일지는 컴파일러에 따라 다름
						   // 대부분 컴파일 시간
}



