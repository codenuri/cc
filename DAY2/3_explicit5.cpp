#include <iostream>

int main()
{
	int n = 0;

	std::cin >> n; // ������ �Է� �������� �ߴµ�, ���� "a" �� �Է� �Ѵٸ� ?

	std::cout << n << std::endl;
		// 1. 10      2. 0     3. -1     4. 97
		// ==> ���� 2.. �Է� ����!!

	// �Է� ���и� �����ϴ� ���
	if (std::cin.fail()) // ��� 1. fail() ��� �Լ� ���
	{
		// �Է� ����
	}

	if (std::cin)	// ��� 2. std::cin ��ü�� if �� ���� ����
	{				// C++98 : cin.operator void*() �� ����ؼ� �����ͷ� ��ȯ
					// C++11 : cin.operator bool() �� ����ؼ� bool �� ��ȯ�Ǵ°�
		// �Է� ����
	}

}