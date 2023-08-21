// 핵심 정리
// 인자를 읽기만(in parameter) 한다면

// 1. user define type 의 경우
// => "대부분" const reference 가 좋습니다 
// => void foo(const Rect& rc)

// 2. primitive type(int,double, char 등) 의 경우
// => call by value 가 좋습니다
// => void foo(int n)



// in-parameter 
// #2. primitive

// godbolt.org 사이트에 접속해 보세요
// => 다양한 프로그래밍 언어를 "어셈블리"로 확인 가능한 사이트
// 
// 인자를 읽기만 하려고 합니다.
// 다음중 좋은 코드는 ??
void good(int n)
{
	int local = n;
}

void bad(const int& n)
{
	int local = n;
}

int main()
{
	int n = 10;

	bad(n);
	good(n);
}