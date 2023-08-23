#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// F.10: If an operation can be reused, give it a name

// F.11 : Use an unnamed lambda 
//        if you need a simple function object in one place only

// T.141: Use an unnamed lambda 
//        if you need a simple function object in one place only


int main()
{
	// ���ٿ� Ÿ��
	// �ٽ� 1. ������ ������ ���� ǥ���� �Դϴ�. 
	// => ���� Ÿ���ϱ�� ? �ٸ� Ÿ���ϱ�� ?
	auto f1 = [](int a, int b) {return a + b; };
				// class xxx{ operator()}; xxx();


	auto f2 = [](int a, int b) {return a + b; };
				// class yyy{ operator()}; yyy();


	// ��� ���� ǥ������ "�ٸ� Ÿ��" �Դϴ�.
	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;



	//===========================================
	std::vector<int> v = { 1,3,5,2,4,6 };

	// ��� ���� ǥ������ �ٸ� Ÿ���̴� �� ���� �����ϰ�
	// �Ʒ� �ڵ带 ������.

	// sort() �Լ��� � �����Ǿ������ ? "3���� sort �Լ�" ����. 
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// ������ ����ǥ������ ������ ����Ѵٸ�, �̸��ִ� ������ ��Ƽ�����ϼ���
	auto cmp = [](int a, int b) { return a < b; };
				// class xx{}; xx();

	// �Ʒ� �ڵ�� ���ڵ�� ������, "sort �Լ�" �� "1��"�� �����˴ϴ�.
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
}
