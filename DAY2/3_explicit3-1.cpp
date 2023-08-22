class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}

	Point(int a) : x(a), y(0) {}

	// C++11 부터, 생성자뿐 아니라 변환연산자에도 explicit 사용가능합니다
	// "암시적 변환은 허용하지 않고, 명시적 변환만 허용"
	explicit operator int() const { return x; }
};

int main()
{
	Point pt(1, 2);

//	int n1 = pt;                   // error. explicit 이므로!
	int n2 = static_cast<int>(pt); // ok

}