// 1_const_member_functin_06-1

// explicit object parameter 문법을 만든 이유
// 1. deducing this!!
// 2. 그외 다양한 장점이 있습니다.
class Test
{
public:
	// C++98 ~ C++20 스타일
	void f1()       {}
	void f1() const {}
};

int main()
{

}