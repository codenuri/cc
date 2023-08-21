// �ٽ� ����
// ���ڸ� �б⸸(in parameter) �Ѵٸ�

// 1. user define type �� ���
// => "��κ�" const reference �� �����ϴ� 
// => void foo(const Rect& rc)

// 2. primitive type(int,double, char ��) �� ���
// => call by value �� �����ϴ�
// => void foo(int n)



// in-parameter 
// #2. primitive

// godbolt.org ����Ʈ�� ������ ������
// => �پ��� ���α׷��� �� "�����"�� Ȯ�� ������ ����Ʈ
// 
// ���ڸ� �б⸸ �Ϸ��� �մϴ�.
// ������ ���� �ڵ�� ??
void good(int n)
{
	int local = n;
}

void bad(const int& n)
{
	int local = n;
}

int main()
{
	int n = 10;

	bad(n);
	good(n);
}