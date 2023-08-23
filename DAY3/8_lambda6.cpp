#include <iostream>

// C170. 람다표현식이 오버로딩이 필요 하면 generic 람다를 사용해라. - C++14

int main()
{
	auto add = [](int a, int b) { return a + b; };

	std::cout << add(1,   2) << std::endl;   // 3
	std::cout << add(1.1, 2.2) << std::endl; // 3
	std::cout << add(1,   2.2) << std::endl; // 3
	std::cout << add(1.1, 2) << std::endl;   // 3

	// generic lambda : 인자로 auto 를 사용하는 람다 표현식 - C++14 기술
	auto add1 = [](auto a, auto b) { return a + b; };

	std::cout << add1(1, 2) << std::endl;     // 3
	std::cout << add1(1.1, 2.2) << std::endl; // 3.3
	std::cout << add1(1, 2.2) << std::endl;   // 3.2
	std::cout << add1(1.1, 2) << std::endl;   // 3.1
}

// generic 람다의 원리
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b) const { return a + b; }
};


