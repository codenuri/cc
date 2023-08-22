#include <iostream>

class Point
{
	int x, y;
public:
	// �ٽ� : Point �� ����Ʈ �����ڰ� ����.
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};

// Point pt; // error. ����Ʈ �����ڰ� �����ϴ�.


// �ٽ� : ����Ʈ �����ڰ� ���� Ÿ���� ��� ����Ÿ�� ������. 
class Rect1
{
	Point ptFrom;
	Point ptTo;
public:
	// ����� �ڵ�	// �����Ϸ��� ������ �ڵ�
//	Rect1()			// Rect1() : ptFrom(), ptTo()  <== �̺κп��� ����

	// �ذ�å : �ʱ�ȭ ����Ʈ���� ���� �������Ÿ ������ ȣ��
	Rect1() : ptFrom(0,0), ptTo{10, 10}  // () �Ǵ� {} �ʱ�ȭ ���
	{
		std::cout << "Rect()" << std::endl;
	}
};
// C++11 ���ʹ� �Ʒ� ó���� ����
class Rect
{
	Point ptFrom{ 0, 0 };
	Point ptTo{ 0, 0 };

//	Point ptTo(0, 0); //error. ()�� ���� ����, {}�� �ϼ���
public:
};



int main()
{
	Rect1 r;
}




