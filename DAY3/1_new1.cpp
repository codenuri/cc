#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point()			{ std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// new �� �ϴ� ��
	// 1. �޸� �Ҵ�
	// 2. ������ ȣ��
//	Point* p1 = new Point(1, 2);

	// delete �� �ϴ���
	// 1. �Ҹ��� ȣ��
	// 2. �޸� ����
//	delete p1;

	// 1. �޸𸮸� �Ҵ�(������ ȣ�����) - malloc �� ����
	Point* p1 = static_cast<Point*>( operator new(sizeof(Point)));


	// 4. �޸𸮸� ����(�Ҹ���ȣ�����) - free �� ����
	operator delete(p1);

}
