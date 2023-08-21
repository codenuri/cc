// QA1

// const Rect* 도 임시객체는 받을 수 없나요 ?
// => 안됩니다.
struct Rect
{
	int left, top, right, bottom;
};

void f(const Rect* p) {}

int main()
{
	f(&Rect()); // error
				// 임시객체는 rvalue 입니다.
				// rvalue 는 주소 연산자를 사용할수 없습니다.
}