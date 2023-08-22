class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {  }

	// 아무일도 하지 않은 인자 없는 생성자가 필요 하면

	// 1. 직접 구현하거나
	Point() {}			// bad

	// 2. 컴파일러에게 만들어 달라고 요청.
	// => 컴파일러가 생성자의 구현부를 만들었으므로 
	//    "최적화를 훨씬 잘 지원 합니다".!!
	// => trivial constructor 입니다.!!!
//	Point() = default;	// good
};

int main()
{
	Point p1(1, 2); // ok

	Point p2; // ??
}