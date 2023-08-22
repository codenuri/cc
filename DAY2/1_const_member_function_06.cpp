#include <iostream>

class Point
{
	int x, y;
public:
	void f1(int a, int b)		// void f1(Point* this, int a, int b)
	{
		x = a;
		y = b;
		std::cout << "f1" << std::endl;
	}
	// C++23 부터 "새로운 모양의 멤버 함수가 도입" 됩니다. - 가장 큰 변화
	// => 아래 f2는 위 f1과 완전히 같은 의미 입니다.
	// => "explicit object parameter" 라는 이름의 문법

	void f2(this Point& self, int a, int b)	
	{
		self.x = a;
		self.y = b;
		std::cout << "f2" << std::endl;
	}
};
int main()
{
	Point pt;
	pt.f1(1, 2);	// f1(&pt, 1, 2)
	pt.f2(1, 2);
}
// vs 2022 부터 컴파일 가능. "프로젝트 속성창" 에서 C++ 버전 : c++latest 로 설정
// g++ 소스.cpp -std=c++23 인데.. 최신 버전만 가능.. 
