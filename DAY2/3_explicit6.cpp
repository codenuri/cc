
class istream
{
public:
	bool fail()  { return true; }

	// cin 을 if 문에 넣고 싶었습니다.
	// 1. operator bool()
	// 문제점 : cin << 5 가 에러가 나지 않는다..
	// operator bool() { return fail() ? false : true; }

	// 2. operator void*() 로 하자!!!
	// => 포인터는 if()에 놓일수 있고, << 연산은 안된다.!
	// => C++98 시절에 실제로 이렇게 구현
	// 문제점 : delete cin 이 에러가 아니다!!!
	// operator void*() { return fail() ? 0 : this; }

	// 3. boost 라이브러리 팀에 제시한 해결책 - 표준은 아니지만
	// => 멤버 함수 포인터로의 변환
	// => 멤버 함수 주소는 if() 에 놓을수 있고, 다른 타입으로 변환은 거의 허용안됨
private:
	struct dummy
	{
		void true_function() {}  // 실제 호출하려는 것이 아니라.. 주소만 사용
	};
public:
	using F = void(dummy::*)();

	operator F() { return fail() ? 0 : &dummy::true_function; }
};

istream cin;

int main()
{	
	if (cin) { }

//	cin << 5;

	delete cin;
}