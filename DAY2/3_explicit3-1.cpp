class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}

	Point(int a) : x(a), y(0) {}


	operator int() const { return x; }
};

int main()
{
	Point pt(1, 2);

	int n1 = pt;

}