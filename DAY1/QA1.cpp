// QA1

// const Rect* 도 임시객체는 받을 수 없나요 ?

struct Rect
{
	int left, top, right, bottom;
};

void f(const Rect* p) {}

int main()
{
	f(&Rect());
}