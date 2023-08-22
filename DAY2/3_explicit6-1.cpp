class istream
{
public:
	bool fail() const { return true; }

	// 핵심 : 객체를 if () 에 넣어서 유효성 테스트를 하려면
	//       "explicit operator bool()" 을 사용해라!
	explicit operator bool() const { return fail() ? false : true; }
};
istream cin;

int main()
{
	cin >> 5;
}