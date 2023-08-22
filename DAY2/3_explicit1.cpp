// C46.인자가 한개인 생성자는 explicit 로 하는 것이 좋다.

class Vector
{
public:
//	Vector(int sz) {}

	// explicit 생성자 : 직접 초기화만 사용할수 있다.
	// 1. 복사 초기화(copy initialization) 을 할수 없고
	// 2. 생성자에 의한 변환도 할수 없다!!

	explicit 	Vector(int sz) {}
};

void fn(Vector v) {} // Vector v = 10

int main()
{
	// 핵심 1. 인자가 한개인 생성자가 있다면 
	//         아래 처럼 4가지 형태로 객체 생성이 가능합니다.
	Vector v1(10);		// C++98 스타일, direct initialization
	Vector v2 = 10;		// C++98 스타일, copy   initialization
	Vector v3{ 10 };	// C++11 스타일, direct initialization
	Vector v4 = { 10 }; // C++11 스타일, copy   initialization

	// 핵심 2. 인자가 한개인 생성자 있다면 "객체 생성" 뿐 아니라
	//         "변환의 용도"로도 사용가능합니다

	v1 = 10; // 초기화가 아닌 대입 코드 입니다.
			 // "10" 을 가지고 Vector 의 임시객체 생성후, v1에 대입!
			 // v1.operator=(Vector(10)) 의 의미!
			 // 마치 10 => Vector 변환처럼 보이게 됩니다.
			 // 그래서 인자가 한개인 생성자를 "변환 생성자" 라고도 합니다.

	// 핵심 3. 복사 초기화나 생성자에 의한 변환은 항상 버그의 위험이 있습니다
	fn(10); // 왜?? 에러가 없을지 생각해 보세요
			// 함수의 인자 전달은 "복사 초기화" 과정입니다
			// Vector v = 10
}