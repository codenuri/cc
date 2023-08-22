class Point
{
	int x{ 0 };
	int y{ 0 };
public:
	explicit Point() = default;

	explicit Point(int x, int y) : x{ x }, y{ y } {}
};

void fn(Point pt) {} 

int main()
{
	// C++11 부터는 함수 인자를 아래 처럼 전달해도 됩니다.
	// => 아래 2개의 표기를 허용하지 않으려면 explicit 로 하시면 됩니다.
	// => 즉, 생성자 인자가 없거나 여러개 라도 explicit 사용가능합니다
	fn( {} );		
	fn( {1, 2} );	

	fn(Point());   //ok
	fn(Point(1, 2)); // ok
				   
	fn({ 1,2 }); // 1. {1,2} 를 가지고 변환 생성자의 의미로 임시객체생성
				 //    => explicit 이므로 변환생성자 안됨
	fn(Point(1, 2)); // 1. 임시객체 생성후
					 // 2. 복사(이동) 생성자로 pt에 복사(Point pt = 임시객체)
}


