class istream
{
public:
	bool fail() const { return true; }

	// 핵심 : 객체를 if () 에 넣어서 유효성 테스트를 하려면
	//       "explicit operator bool()" 을 사용해라!
	explicit operator bool() const { return !fail(); }
};
istream cin;

int main()
{
	bool b1 = cin; // error. explicit bool 이므로 암시적 변환 안됨.
	bool b2 = static_cast<bool>(cin); // ok

	cin << 5; // error. cin 이 암시적으로는 bool로 변환 안됨

	// 즉, explicit 덕분에 side effect가 대부분 제거됨!

	if (cin) // ok.!! 핵심!
	{		 // explicit bool 이라도 if () 안에는 놓일수 있다는 것이 핵심!
	}
	// 그런데.. 왜 ? 
	// if(cin) 하나요 ? 
	// if( cin.fail()) 하면 되는데!!! - C++ 특징!!
}