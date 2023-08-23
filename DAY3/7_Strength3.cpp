#include <string>
#include <iostream>

template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

// STL 로 부터 상속받는 것은 좋지 않습니다. 실전에서는 사용하지 마세요
// 단지, 테스트용
class String : public std::string
{
public:
	using std::string::basic_string; // 생성자 상속

	~String() { std::cout << "~String" << std::endl; }
};

int main()
{
//	const String& ret3 = max1(String("AAA"),String("BBB"));
	const String& ret3 = std::max(String("AAA"), String("BBB"));

	std::cout << "-------------" << std::endl;

}

// 권장 : 구글에서 "C++ lifetime herb sutter " 검색해서 나오는 PDF 읽어 보세요



