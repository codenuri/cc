#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 : Point 는 디폴트 생성자가 없다.
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};

// Point pt; // error. 디폴트 생성자가 없습니다.


// 핵심 : 디폴트 생성자가 없는 타입을 멤버 데이타로 가질때. 
class Rect1
{
	Point ptFrom;
	Point ptTo;
public:
	// 사용자 코드	// 컴파일러가 변경한 코드
//	Rect1()			// Rect1() : ptFrom(), ptTo()  <== 이부분에서 에러

	// 해결책 : 초기화 리스트에서 직접 멤버데이타 생성자 호출
	Rect1() : ptFrom(0,0), ptTo{10, 10}  // () 또는 {} 초기화 사용
	{
		std::cout << "Rect()" << std::endl;
	}
};
// C++11 부터는 아래 처럼도 가능
class Rect
{
	Point ptFrom{ 0, 0 };
	Point ptTo{ 0, 0 };

//	Point ptTo(0, 0); //error. ()로 하지 말고, {}로 하세요
public:
};



int main()
{
	Rect1 r;
}




