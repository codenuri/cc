#include <iostream>

// C170. ����ǥ������ �����ε��� �ʿ� �ϸ� generic ���ٸ� ����ض�. - C++14

int main()
{
	auto add = [](int a, int b) { return a + b; };

	std::cout << add(1,   2) << std::endl;   // 3
	std::cout << add(1.1, 2.2) << std::endl; // 3
	std::cout << add(1,   2.2) << std::endl; // 3
	std::cout << add(1.1, 2) << std::endl;   // 3

	// generic lambda : ���ڷ� auto �� ����ϴ� ���� ǥ���� - C++14 ���
	auto add1 = [](auto a, auto b) { return a + b; };

	std::cout << add1(1, 2) << std::endl;     // 3
	std::cout << add1(1.1, 2.2) << std::endl; // 3.3
	std::cout << add1(1, 2.2) << std::endl;   // 3.2
	std::cout << add1(1.1, 2) << std::endl;   // 3.1
}

// generic ������ ����
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b) const { return a + b; }
};


