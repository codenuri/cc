#include <iostream>

// 람다의 원리

int main()
{
	int v1 = 10, v2 = 10;

	auto f1 = [](int a, int b) { return a + b; };

	// === 위 한줄은 아래 코드와 동일합니다.
	class CompilerGeneratedName1
	{
	public:
		inline auto operator()(int a, int b) const 
		{ 
			return a + b; 
		};
	};

	auto f1_1 = CompilerGeneratedName1();


	//======================================================
	// 지역변수를 캡쳐하는 경우
//	auto f2 = [v1, v2](int a, int b) { return a + b + v1 + v2; };
//	auto f2 = [v1, v2](int a, int b) { v1 = 100; return a + b + v1 + v2; };
									// 왜 에러인지 생각해 보세요

	// mutable 람다 표현식 : operator() 를 const 함수로 하지 말라는 의도
	// => 단, v1 = 100 이 에러는 아니지만, main 의 v1이 아닌 복사본을 변경한것
	auto f2 = [v1, v2](int a, int b) mutable { v1 = 100; return a + b + v1 + v2; };

	class CompilerGeneratedName2
	{
		int v1;
		int v2; // 지역변수 캡쳐 하면 생성되는 멤버 데이타
	public:
		CompilerGeneratedName2(int a, int b) : v1(a), v2(b) {}

		inline auto operator()(int a, int b) // const
		{
			v1 = 100;  // 상수 멤버 함수에서 값 변경이 안되므로 에러
						// 단, mutable 람다라면 에러 아님.
			return a + b + v1 + v2;
		};
	};

	auto f2_1 = CompilerGeneratedName2(v1, v2); 




	//=======================================================
	auto f3 = [&v1, &v2](int a, int b) { v1 = 100;  return a + b + v1 + v2; };

	class CompilerGeneratedName3
	{
		int& v1;
		int& v2; // v1은 main 함수의 v1을 가리키는 참조!!
	public:
		CompilerGeneratedName3(int& a, int& b) : v1(a), v2(b) {}

		inline auto operator()(int a, int b)  const
		{
			v1 = 100; // main 의 지역변수가 변경 됨. 
					  // 현재 v1의 정체는 int 가 아닌 int& 
					  // 즉, 이코드는 v1의 변경이 아닌 v1이 가리키는 곳을 변경
					  // 따라서, 상수 멤버 함수라도 가능

			return a + b + v1 + v2;
		};
	};

	auto f3_1 = CompilerGeneratedName3(v1, v2);
}