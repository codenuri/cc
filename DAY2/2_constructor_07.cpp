class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {  }

	// �ƹ��ϵ� ���� ���� ���� ���� �����ڰ� �ʿ� �ϸ�

	// 1. ���� �����ϰų�
	Point() {}			// bad

	// 2. �����Ϸ����� ����� �޶�� ��û.
	// => �����Ϸ��� �������� �����θ� ��������Ƿ� 
	//    "����ȭ�� �ξ� �� ���� �մϴ�".!!
	// => trivial constructor �Դϴ�.!!!
//	Point() = default;	// good
};

int main()
{
	Point p1(1, 2); // ok

	Point p2; // ??
}