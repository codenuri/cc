// nullptr 의 원리
void f1(int*  p) {}
void f2(char* p) {}

// C++11 이 나오기전에 boost 라이브러리 팀에서 아래 클래스를 제공했습니다.
// => 모든 종류의 포인터로 암시적 변환 가능합니다.
// => 단, C++11에서는 nullptr이 아래 처럼 구현된것이 아니라, 아래 처럼 동작하는 
//    "키워드" 입니다.
struct nullptr_t
{
	template<typename T>
	operator T* () const { return 0; }	
};
nullptr_t mynullptr;

int main()
{
	f1(mynullptr); // mynullptr.operator int*()
	f2(mynullptr); // mynullptr.operator char*()
}