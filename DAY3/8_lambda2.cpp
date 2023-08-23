#include <iostream>
#include <algorithm>
#include <vector>

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	// 1. 주어진 구간에서 첫번째 나오는 "3"을 찾아라
	auto ret1 = std::find(v.begin(), v.end(), 3);


	// 2. 주어진 구간에서 첫번째 나오는 "3의 배수"를 찾아라 ?
//  auto ret2 = std::find_if(v.begin(), v.end(), 단항함수);
	auto ret2 = std::find_if(v.begin(), v.end(), foo);
}