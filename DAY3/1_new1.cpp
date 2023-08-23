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


	// 2. �̹� �Ҵ�� �޸� ������ ������ ȣ��(��ü�����Ѵٰ� ǥ��)
	// ���� : *p1 = Point(1,2) => ���Կ����� ȣ��. ��, ������ ȣ���� �ȵ� ��ü��
	//							  ���Կ����ڸ� ȣ���Ѱ�
	
//	new(p1) Point(1,2);		// ====> "placement new" ��� �̸��� ���� ���

	std::construct_at(p1, 1, 2); // C++20 ���� ����


	// 3. �޸� ���� ���� �Ҹ��ڸ� ȣ��
//	p1->~Point();
	std::destroy_at(p1); // C++17 ���� ��밡��


	// 4. �޸𸮸� ����(�Ҹ���ȣ�����) - free �� ����
	operator delete(p1);
}

// malloc : �޸� �Ҵ�
// new    : ��ü ���� ( �޸� �Ҵ� + ������ ȣ�� ) 

// new Point       : ���ο� �޸𸮿�            ��ü�� ������ �޶�
// new(�ּ�) Point : �̹� �Ҵ�� �޸�(�ּ�) �� ��ü�� ������ �޶�
//					 => �ᱹ, �����ڸ� ȣ���ϴ� ǥ���