// QA1

// const Rect* �� �ӽð�ü�� ���� �� ������ ?
// => �ȵ˴ϴ�.
struct Rect
{
	int left, top, right, bottom;
};

void f(const Rect* p) {}

int main()
{
	f(&Rect()); // error
				// �ӽð�ü�� rvalue �Դϴ�.
				// rvalue �� �ּ� �����ڸ� ����Ҽ� �����ϴ�.
}