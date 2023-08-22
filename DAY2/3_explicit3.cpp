class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}

	// 인자가 한개인 생성자(explicit가 아닌)
	// 다른 타입 => Point 로 변환을 허용!!
	Point(int a) : x(a), y(0) {}

	// 변환 연산자 : 객체 => 다른 타입으로 변환을 허용
	operator int() const { return x; }
};

int main()
{
	Point pt(1, 2);

	int n = 0;

	pt = n; // int => Point 로의 변환이 필요
			// 변환 생성자 필요(인자가 int 한개인 생성자)

	n = pt; // Point => int 로의 변환
			// pt.operator int() 함수를 찾게 됨.
			// "변환 연산자" 라고 합니다.
}