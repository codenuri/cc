#include <string>

class People1
{
	std::string name;
	int age;
public:
	// 아래 코드는
	// 1. string name(s) 로 초기화 된것. 
	// => 즉, 1회의 함수 호출
	People1(const std::string& s, int a) : name(s), age(a)  // good
	{	
	}
};

class People2
{
	std::string name;
	int age;
public:	
	// 아래 코드는 
	// 1. string name 에 대해서 디폴트 생성자 호출후
	// 2. name.operator=(s) 로 값을 넣은것
	// 즉, 2회의 함수 호출
										 // 컴파일러가 추가한 코드
	People2(const std::string& s, int a) //	: name()  <= name의 디폴트 생성자호출
	{										
		name = s;	// bad  
		age = a;
	}
};

// People2 p2(이름,2); // 이순간의 생성자 호출을 생각해 봅시다.
	


int main()
{
	std::string s = "john";
	People1 p1(s, 20);
	People2 p2(s, 20);

	//-------------------------
	// 초기화 vs 대입
	// primitive type 인 경우는 대부분 유사.
	// user define type 의 경우는 초기화가 빠릅니다.
	/*
	int a = 0;	// 초기화, 선언과 동시에 값 넣기

	int b;
	b = 0;		// 대입. 선언후에 넣는 것


	std::string s1 = "hello";	// std::string s1("hello")
								// 즉, 인자가 한개인 생성자 호출 1회로 초기화

	std::string s2;	// 1. string 디폴트 생성자 호출
	s2 = "hello";	// 2. s2.operator=("hello"). 즉, 대입 연산자 호출
					// => 2회의 함수 호출로 값을 넣은 것
	*/
}