class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}

	// ���ڰ� �Ѱ��� ������(explicit�� �ƴ�)
	// �ٸ� Ÿ�� => Point �� ��ȯ�� ���!!
	Point(int a) : x(a), y(0) {}

	// ��ȯ ������ : ��ü => �ٸ� Ÿ������ ��ȯ�� ���
	operator int() const { return x; }
};

int main()
{
	Point pt(1, 2);

	int n = 0;

	pt = n; // int => Point ���� ��ȯ�� �ʿ�
			// ��ȯ ������ �ʿ�(���ڰ� int �Ѱ��� ������)

	n = pt; // Point => int ���� ��ȯ
			// pt.operator int() �Լ��� ã�� ��.
			// "��ȯ ������" ��� �մϴ�.
}