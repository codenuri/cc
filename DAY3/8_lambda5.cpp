#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// F.10: If an operation can be reused, give it a name

// F.11 : Use an unnamed lambda 
//        if you need a simple function object in one place only

// T.141: Use an unnamed lambda 
//        if you need a simple function object in one place only


int main()
{
	// 람다와 타입
	// 핵심 1. 완전히 동일한 람다 표현식 입니다. 
	// => 같은 타입일까요 ? 다른 타입일까요 ?
	auto f1 = [](int a, int b) {return a + b; };
				// class xxx{ operator()}; xxx();


	auto f2 = [](int a, int b) {return a + b; };
				// class yyy{ operator()}; yyy();


	// 모든 람다 표현식은 "다른 타입" 입니다.
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;



	//===========================================
	std::vector<int> v = { 1,3,5,2,4,6 };

	// 모든 람다 표현식은 다른 타입이다 는 점을 생각하고
	// 아래 코드를 보세요.

	// sort() 함수는 몇개 생성되었을까요 ? "3개의 sort 함수" 생성. 
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// 동일한 람다표현식을 여러번 사용한다면, 이름있는 변수에 담아서사용하세요
	auto cmp = [](int a, int b) { return a < b; };
				// class xx{}; xx();

	// 아래 코드는 위코드와 같지만, "sort 함수" 가 "1개"만 생성됩니다.
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
}
