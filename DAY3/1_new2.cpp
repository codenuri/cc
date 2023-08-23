#include <iostream>

class Point
{
	int x, y;
public:
	// �ٽ� : Point �� ����Ʈ �����ڰ� �����ϴ�.
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point()			{ std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// Point ��ü�� ���� �Ѱ��� ����� ������
	Point* p1 = new Point(1, 2);

	// Point ��ü�� ���� 10�� ����� ������
//	Point* p2 = new Point[10];	// error. ����Ʈ �����ڸ� 10�� ȣ���ؾ� �ϴµ�
								// Point �� ����Ʈ �����ڰ� �����ϴ�.

	// �޸� �Ҵ�� ������ ȣ���� �и��ϸ� "�����ϰ� ��ü ����"�� �����մϴ�.

	// 1. 10���� �޸� ���� �Ҵ�
	Point* p2 = static_cast<Point*>( operator new(sizeof(Point) * 10) );

	// 2. 10 ���� �޸� ������ 10���� ��ü�� ����
	for (int i = 0; i < 10; i++)
	{
		new(&p2[i]) Point(0, 0);
	}

	// 3. ��ü �ı�(�Ҹ��� ȣ��)
	for (int i = 0; i < 10; i++)
	{
		p2[i].~Point();
	}
	// 4. �޸� ����
	operator delete(p2);
	
}