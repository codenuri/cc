#include <iostream>
#include <tuple>

int main()
{
	std::pair<int, double> p1(3, 3.4);
	std::tuple<int, double, int, double> t1(3, 3.4, 3, 3.4);

	// C++ 표준에 "convenient function template" 을 사용하는 코드는
	// 상당히 많이 있습니다.
	auto t2 = std::make_tuple(3, 3.4, 3, 3.4); // t2가 위의 t1과 동일 합니다

}