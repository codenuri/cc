#include <iostream>
#include <algorithm>
#include <vector>

// 아래 foo 함수에서는 main 함수의 지역변수 k 를 사용할수 없습니다.
// => 일반 함수는 지역변수를 캡쳐할수 없습니다.
bool foo(int n) { return n % 3 == 0; }
// 함수 객체는 "지역변수를 캡쳐" 하는 능력이 있습니다.
struct IsDivide
{
	int value;
	IsDivide(int n) : value(n) {}

	bool operator()(int n) { return n % value == 0; }
};

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k = 3; 

	IsDivide f(k);  // f는 인자가 한개인 함수 처럼 사용가능합니다.
					// 그런데, 추가적으로 k의 값도 보관(캡쳐) 합니다.
//	bool b = f(10); // 10 % 3 즉, 10 % k 의 의미!!

	auto ret3 = std::find_if(v.begin(), v.end(), f);

	// IsDivide 객체를 한번만 사용한다면 아래 처럼 임시객체로 하면 됩니다.
	auto ret3 = std::find_if(v.begin(), v.end(), IsDivide(k) );

	//==================================================
	// 람다 표현식은 "함수객체를 만들고 임시객체를 생성" 하는 표기법입니다.

	auto ret4 = std::find_if(v.begin(), v.end(), [k](int n) { return n % k == 0; });

	// 위 한줄은 컴파일러에 의해서 아래 처럼 변경됩니다.

	struct CompilerGeneratedName
	{
		int k;

		CompilerGeneratedName(int n) : k(n) {}

		auto operator()(int n) { return n % k == 0; }
	};
	auto ret4 = std::find_if(v.begin(), v.end(), CompilerGeneratedName(k));
	//--------------------------------------------------------------------------

}