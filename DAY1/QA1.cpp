// QA1

// const Rect* �� �ӽð�ü�� ���� �� ������ ?

struct Rect
{
	int left, top, right, bottom;
};

void f(const Rect* p) {}

int main()
{
	f(&Rect());
}