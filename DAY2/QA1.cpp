// QA1
#define MAX1 10
constexpr int MAX2 = 10;

#define SQUARE(n)  n * n

int main()
{
	int n1 = MAX1;
	int n2 = MAX2;

	int s = SQUARE(++n1); // 
}
// 매크로 : 컴파일을 하기 전에 전처리기가 소스를 변경하는것
// g++ QA1.cpp -E -P
// cl  QA1.cpp /EP

// 시작 버튼