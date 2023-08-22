
// Con.1 : By default, make objects immutable => 상수!
// Con.2 : By default, make member functions const => 핵심 !!
// Con.3 : By default, pass pointers and references to consts

int main()
{
	// max 을 읽기만 한다면
//	int max = 10;		// bad.  변수 보다는 
//	const int max = 10; // good. 상수가 좋습니다.
	constexpr int max = 10; // good. 초기값을 컴파일 시간에 알수 있다면
							// const 보다는 constexpr 좋다

	// 변수 보다 상수의 장점
	// 1. 멀티 스레드에 안전
	// 2. 컴파일러 최적화가 훨씬 잘됩니다
	// 3. 상수는 배열이나 템플릿 인자로도 사용가능 합니다.
	int arr[max];

	// 변수 보다, 상수가 좋습니다.
	// 그런데, C/C++ 디폴트가 변수!
	int n1 = 0;       // R/W 가능
	const int n2 = 0; // R

	// 함수형언어, Rust 등은 디폴트가 상수입니다.
	// Rust 코드
//	let n1 = 0;     // R
//	let mut n2 = 0; // R/W
}

// constexpr 과 전처리기 매크로(? ) 차이는 무엇인가요 ? ?
// constexpr : 컴파일러가 처리
// 매크로     : 전처리가 처리

constexpr int MAX1 = 10;
#define MAX2 10

// MAX 관련 컴파일 에러 발생시
// MAX1 : 에러창에 "MAX1" 이라고 출력
// MAX2 : 에러창에 "10"   이라고 출력





// github.com/codenuri/cc 에서

// DAY2.zip 받으시면 됩니다.

// 압축풀고, vs 열고, 버전 설정


