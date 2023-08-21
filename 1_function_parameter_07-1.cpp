#include <iostream>
#include <vector>


int main()
{
	std::vector<std::string> v;

	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	v.push_back(s1);
	v.push_back(std::move(s1));

	// push_back 에서 마우스 오른쪽 버튼을 누르고, 
	// "정의"로 이동해서
	// push_back() 함수가 2개 있는것 확인해 보세요.

}