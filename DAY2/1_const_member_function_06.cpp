#include <iostream>

class Point
{
	int x, y;
public:
	void f1(int a, int b)		// void f1(Point* this, int a, int b)
	{
		x = a;
		y = b;
		std::cout << "f1" << std::endl;
	}
	// C++23 ���� "���ο� ����� ��� �Լ��� ����" �˴ϴ�. - ���� ū ��ȭ
	// => �Ʒ� f2�� �� f1�� ������ ���� �ǹ� �Դϴ�.
	// => "explicit object parameter" ��� �̸��� ����

	void f2(this Point& self, int a, int b)	
	{
		self.x = a;
		self.y = b;
		std::cout << "f2" << std::endl;
	}
};
int main()
{
	Point pt;
	pt.f1(1, 2);	// f1(&pt, 1, 2)
	pt.f2(1, 2);
}
// vs 2022 ���� ������ ����. "������Ʈ �Ӽ�â" ���� C++ ���� : c++latest �� ����
// g++ �ҽ�.cpp -std=c++23 �ε�.. �ֽ� ������ ����.. 
