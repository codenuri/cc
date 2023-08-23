#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// local function

int main()
{
	// C#, swift : 함수안에 함수를 만들수 있습니다. 
	//             local function 또는 nested function 이라고 합니다.
	//             local function 에서 outer function 의 지역변수등을 접근할수있어서
	//			   다양한 기법을 활용 가능합니다.
	/*
	int add(int a, int b) 
	{ 
		return a + b; 
	};
	*/

	// C++ : 함수 안에 함수만들수 없습니다.
	//       하지만, 함수 안에 함수 객체 만들수 있습니다.
	struct Add
	{
		int operator()(int a, int b) const { return a + b; }
	};
	Add add; // 결국 add 라는 함수 입니다.

	int n = add(1, 2);
}