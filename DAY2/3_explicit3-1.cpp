class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}

	Point(int a) : x(a), y(0) {}

	// C++11 ����, �����ڻ� �ƴ϶� ��ȯ�����ڿ��� explicit ��밡���մϴ�
	// "�Ͻ��� ��ȯ�� ������� �ʰ�, ������ ��ȯ�� ���"
	explicit operator int() const { return x; }
};

int main()
{
	Point pt(1, 2);

//	int n1 = pt;                   // error. explicit �̹Ƿ�!
	int n2 = static_cast<int>(pt); // ok

}