// forward1.cpp
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};


int main()
{
	// foo �Լ��� Point ��ü�� �����Ϸ��� �մϴ�
	// => ��, lvalue, rvalue(�ӽð�ü)�� ��� ������ �־�� �մϴ�.
	Point pt(1, 2);
	foo(pt);          // lvalue
	foo(Point(1, 2)); // rvalue
}