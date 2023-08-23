// 25page. 
// F50 ~ F54 - 람다 표현식 사용한 관한 코딩 관례
// F.50 : Use a lambda when a function won't do 
//        (to capture local variables, or to write a local function)
// F.52 : Prefer capturing by reference in lambdas that will be used locally, including passed to algorithms
// F.53 : Avoid capturing by reference in lambdas that will be used non - locally, including returned, stored on the heap, or passed to another thread
// F.54 : If you capture this, capture all variables explicitly(no default capture)




#include <iostream>

struct plus
{
	int operator()(int a, int b) 
	{
		return a + b;
	}
};

int main()
{
	plus p; // p 는 plus 라는 타입의 객체 입니다.
			// p 는 함수가 아닙니다.

	int n1 = p(1, 2); // p를 마치 함수 처럼 사용합니다. - 함수 객체라고 합니다.
	int n2 = p.operator()(1, 2); // 위 코드를 이렇게 변경하는 것!
								 // 사용자가 이렇게 사용해도 됩니다.

	// 핵심 : operator() 연산자를 재정의 하면 객체를 함수 처럼 사용가능하다.
}