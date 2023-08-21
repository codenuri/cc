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
// C++98 부터, rvalue 는 주소를 구할수 없었습니다.
// 그런데, ms 컴파일러에서는 "ATL" 라이브러리 만들때
// => 임시객체의 주소를 구할 필요가 있어서
// => vs 2017 까지는 가능했습니다. - 잘못된 컴파일러!