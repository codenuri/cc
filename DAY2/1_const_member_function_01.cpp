#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	// ����� �ڵ�				// �����Ϸ��� ������ �ڵ�
	void set(int a, int b)		// void set(Point* this, int a, int b)
	{
		x = a;					//		this->x = a;
		y = b;					//		this->y = b;
	}

//	void print()				// void print(Point* this)
	void print() const			// void print(const Point* this)
	{
//		x = 10; // error. 
				// this->x = 10 �� �ǹ� �ε�, this �� ����� ����Ű�� ������!
		std::cout << x << ", " << y << std::endl;
	}
};

int main()
{
//	Point pt(1, 2);
	const Point pt(1, 2);

	pt.x = 10;		// error. x �� public ������, ��� �̹Ƿ�
	pt.set(10, 20);	// error. 
					// set(&pt, 10, 20)

	pt.print();		// error. - print() �� ��� �Լ��� �ƴ� ���
					// ok     - print() �� ��� ��� �Լ� �ΰ��. 
					// print(&pt)
}

// �ٽ� 1. ��� ��� �Լ��� ��Ȯ�� �ǹ̸� �˾� �μ���

//	void print()				// void print(Point* this)
//  void print() const			// void print(const Point* this)

// �ٽ� 2.
// non-const object : �Ϲ� ��� �Լ��� ��� ����Լ��� ��� ȣ�� ����
//     const object : ��� ����Լ��� ȣ�Ⱑ��