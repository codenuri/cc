#include <iostream>
#include <algorithm>
#include <vector>

// �Ʒ� foo �Լ������� main �Լ��� �������� k �� ����Ҽ� �����ϴ�.
// => �Ϲ� �Լ��� ���������� ĸ���Ҽ� �����ϴ�.
bool foo(int n) { return n % 3 == 0; }
// �Լ� ��ü�� "���������� ĸ��" �ϴ� �ɷ��� �ֽ��ϴ�.
struct IsDivide
{
	int value;
	IsDivide(int n) : value(n) {}

	bool operator()(int n) { return n % value == 0; }
};

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k = 3; 

	IsDivide f(k);  // f�� ���ڰ� �Ѱ��� �Լ� ó�� ��밡���մϴ�.
					// �׷���, �߰������� k�� ���� ����(ĸ��) �մϴ�.
//	bool b = f(10); // 10 % 3 ��, 10 % k �� �ǹ�!!

	auto ret3 = std::find_if(v.begin(), v.end(), f);

	// IsDivide ��ü�� �ѹ��� ����Ѵٸ� �Ʒ� ó�� �ӽð�ü�� �ϸ� �˴ϴ�.
	auto ret3 = std::find_if(v.begin(), v.end(), IsDivide(k) );

	//==================================================
	// ���� ǥ������ "�Լ���ü�� ����� �ӽð�ü�� ����" �ϴ� ǥ����Դϴ�.

	auto ret4 = std::find_if(v.begin(), v.end(), [k](int n) { return n % k == 0; });

	// �� ������ �����Ϸ��� ���ؼ� �Ʒ� ó�� ����˴ϴ�.

	struct CompilerGeneratedName
	{
		int k;

		CompilerGeneratedName(int n) : k(n) {}

		auto operator()(int n) { return n % k == 0; }
	};
	auto ret4 = std::find_if(v.begin(), v.end(), CompilerGeneratedName(k));
	//--------------------------------------------------------------------------

}