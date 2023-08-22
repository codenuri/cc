// 상수 멤버 함수라는 문법은

// 1. "선택" 이 아닌 "필수" 문법입니다.
// 
// 2. 멤버 함수중 상태(멤버데이타)를 변경하지 않은 모든 멤버 함수(getter)는
//    "반드시" 상수 멤버 함수로 해야 합니다

// 3. 아래 Rect::get_area()는 "반드시" 상수 멤버함수 이어야 합니다.

// 일반적으로 클래스에는 "setxxx" 보다 "getxxx" 이 더 많습니다.
// => 따라서, 상수 멤버 함수가 더 많게 됩니다.

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

//	int get_area() { return w * h; } // bad 가 아닌 wrong 입니다.. 완전히 틀린코드!

	int get_area() const { return w * h; } // good!!!
};

//void foo(Rect r) // call by value : 복사본의 오버헤드 있습니다. 나쁜코드
void foo(const Rect& r) // 가장 좋은 코드
{
	int n = r.get_area();
}

int main()
{
	Rect r(1, 2, 3, 4);		// 상수 객체는 아닙니다.
	int n = r.get_area();	// ok. 
	foo(r);
}