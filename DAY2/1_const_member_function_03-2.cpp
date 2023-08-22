#include <iostream>
#include <string>
#include <sstream>

// const member function 에서 멤버 데이타의 값을 변경하고 싶다면
// 1. mutable 키워드 사용
// 2. 메모리의 분리!
//		=> mutable 키워드가 없던 시절에 널리 사용되던 기술
//		=> 초기 C++에는 mutable 키워드가 없었습니다.

// const 멤버 함수에서 값을 변경하고 싶은 것은 별도의 구조체로 만든다.
struct CACHE
{
	std::string cache;
	bool cache_valid = false;
};

class Point
{
	int x;
	int y;
	CACHE* cache;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) 
	{
		cache = new CACHE;
	}

	std::string to_string() const
	{
		if (cache->cache_valid == false)
		{
			std::stringstream oss;
			oss << x << ", " << y;
			cache->cache = oss.str();
			cache->cache_valid = true;
		}
		return cache->cache;
	}
	
};

int main()
{
	Point pt(1, 2);
	std::cout << pt.to_string() << std::endl;
	std::cout << pt.to_string() << std::endl;
}

