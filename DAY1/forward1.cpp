// forward1.cpp
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

// ��� 1. call by value
// Ư¡ : ���纻 ����, 
// void foo(Point p) {}

// ��� 2. call by lvalue reference
// Ư¡ : ���纻 ���� �ȵ�����, rvalue(�ӽð�ü)�� ������ ����.
// void foo(Point& p) {}

// ��� 3. call by const lvalue reference
// Ư¡ 1. lvalue �� rvalue �� ��� ������ �ִ�.
//      2. �׷���, �����鼭 ������� �߰� �ȴ�. write �Ұ���.
void foo(const Point& p) {}

// ����� �߰����� lvalue, rvalue �� ��� ������ ������ ?
// => C++98 �� �Ұ���!!


int main()
{
	// foo �Լ��� Point ��ü�� �����Ϸ��� �մϴ�
	// => ��, lvalue, rvalue(�ӽð�ü)�� ��� ������ �־�� �մϴ�.
	Point pt(1, 2);

	foo(pt);          // lvalue
	foo(Point(1, 2)); // rvalue
}