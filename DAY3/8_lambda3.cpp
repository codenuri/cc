#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// local function

int main()
{
	// C#, swift : �Լ��ȿ� �Լ��� ����� �ֽ��ϴ�. 
	//             local function �Ǵ� nested function �̶�� �մϴ�.
	//             local function ���� outer function �� ������������ �����Ҽ��־
	//			   �پ��� ����� Ȱ�� �����մϴ�.
	/*
	int add(int a, int b) 
	{ 
		return a + b; 
	};
	*/

	// C++ : �Լ� �ȿ� �Լ������ �����ϴ�.
	//       ������, �Լ� �ȿ� �Լ� ��ü ����� �ֽ��ϴ�.
	struct Add
	{
		int operator()(int a, int b) const { return a + b; }
	};
	Add add; // �ᱹ add ��� �Լ� �Դϴ�.

	int n = add(1, 2);
}