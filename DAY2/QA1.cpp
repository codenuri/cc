// QA1
#define MAX1 10
constexpr int MAX2 = 10;

#define SQUARE(n)  n * n

int main()
{
	int n1 = MAX1;
	int n2 = MAX2;

	int s = SQUARE(++n1); // 
}
// ��ũ�� : �������� �ϱ� ���� ��ó���Ⱑ �ҽ��� �����ϴ°�
// g++ QA1.cpp -E -P
// cl  QA1.cpp /EP

// ���� ��ư