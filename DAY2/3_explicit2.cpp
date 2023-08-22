class Point
{
	int x{ 0 };
	int y{ 0 };
public:
	Point() = default;

	Point(int x, int y) : x{ x }, y{ y } {}
};
void fn(Point pt) {} 

int main()
{
	// C++11 부터는 함수 인자를 아래 처럼 전달해도 됩니다.
	fn( {} );
	fn( {1, 2} );
}


