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
	// C++11 ���ʹ� �Լ� ���ڸ� �Ʒ� ó�� �����ص� �˴ϴ�.
	fn( {} );
	fn( {1, 2} );
}


