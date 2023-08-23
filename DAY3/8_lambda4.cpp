#include <iostream>

// ������ ����

int main()
{
	int v1 = 10, v2 = 10;

	auto f1 = [](int a, int b) { return a + b; };

	// === �� ������ �Ʒ� �ڵ�� �����մϴ�.
	class CompilerGeneratedName1
	{
	public:
		inline auto operator()(int a, int b) const 
		{ 
			return a + b; 
		};
	};

	auto f1_1 = CompilerGeneratedName1();


	//======================================================
	// ���������� ĸ���ϴ� ���
//	auto f2 = [v1, v2](int a, int b) { return a + b + v1 + v2; };
//	auto f2 = [v1, v2](int a, int b) { v1 = 100; return a + b + v1 + v2; };
									// �� �������� ������ ������

	// mutable ���� ǥ���� : operator() �� const �Լ��� ���� ����� �ǵ�
	// => ��, v1 = 100 �� ������ �ƴ�����, main �� v1�� �ƴ� ���纻�� �����Ѱ�
	auto f2 = [v1, v2](int a, int b) mutable { v1 = 100; return a + b + v1 + v2; };

	class CompilerGeneratedName2
	{
		int v1;
		int v2; // �������� ĸ�� �ϸ� �����Ǵ� ��� ����Ÿ
	public:
		CompilerGeneratedName2(int a, int b) : v1(a), v2(b) {}

		inline auto operator()(int a, int b) // const
		{
			v1 = 100;  // ��� ��� �Լ����� �� ������ �ȵǹǷ� ����
						// ��, mutable ���ٶ�� ���� �ƴ�.
			return a + b + v1 + v2;
		};
	};

	auto f2_1 = CompilerGeneratedName2(v1, v2); 




	//=======================================================
	auto f3 = [&v1, &v2](int a, int b) { v1 = 100;  return a + b + v1 + v2; };

	class CompilerGeneratedName3
	{
		int& v1;
		int& v2; // v1�� main �Լ��� v1�� ����Ű�� ����!!
	public:
		CompilerGeneratedName3(int& a, int& b) : v1(a), v2(b) {}

		inline auto operator()(int a, int b)  const
		{
			v1 = 100; // main �� ���������� ���� ��. 
					  // ���� v1�� ��ü�� int �� �ƴ� int& 
					  // ��, ���ڵ�� v1�� ������ �ƴ� v1�� ����Ű�� ���� ����
					  // ����, ��� ��� �Լ��� ����

			return a + b + v1 + v2;
		};
	};

	auto f3_1 = CompilerGeneratedName3(v1, v2);
}