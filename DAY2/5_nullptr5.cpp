#include <iostream>

int main()
{
	// ��� ���ͷ��� Ÿ���� �ֽ��ϴ�.
	10;  // int
	3.4; // double
	false; // bool.  false �� ���ͷ��̰� Ű���� �Դϴ�.

	// nullptr �� ���ͷ�(��)�̰� Ű����(��ӵ� �ܾ�) �Դϴ�.
	nullptr; // std::nullptr_t Ÿ��

	std::nullptr_t mynull = nullptr; // ok

	// std::nullptr_t �� ��� Ÿ���� �����ͷ� �Ͻ��� ����ȯ �˴ϴ�.
	// nullptr ��� mynull ��밡��.

	int* p1 = mynull;
	char* p2 = mynull;

	void(*f)() = mynull;

}