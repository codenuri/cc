#include <iostream>
#include <string>
#include <sstream>

// const member function ���� ��� ����Ÿ�� ���� �����ϰ� �ʹٸ�
// 1. mutable Ű���� ���
// 2. �޸��� �и�!
//		=> mutable Ű���尡 ���� ������ �θ� ���Ǵ� ���
//		=> �ʱ� C++���� mutable Ű���尡 �������ϴ�.

// const ��� �Լ����� ���� �����ϰ� ���� ���� ������ ����ü�� �����.
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

