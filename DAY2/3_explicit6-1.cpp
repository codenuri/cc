class istream
{
public:
	bool fail() const { return true; }

	// �ٽ� : ��ü�� if () �� �־ ��ȿ�� �׽�Ʈ�� �Ϸ���
	//       "explicit operator bool()" �� ����ض�!
	explicit operator bool() const { return !fail(); }
};
istream cin;

int main()
{
	bool b1 = cin; // error. explicit bool �̹Ƿ� �Ͻ��� ��ȯ �ȵ�.
	bool b2 = static_cast<bool>(cin); // ok

	cin << 5; // error. cin �� �Ͻ������δ� bool�� ��ȯ �ȵ�

	// ��, explicit ���п� side effect�� ��κ� ���ŵ�!

	if (cin) // ok.!! �ٽ�!
	{		 // explicit bool �̶� if () �ȿ��� ���ϼ� �ִٴ� ���� �ٽ�!
	}
	// �׷���.. �� ? 
	// if(cin) �ϳ��� ? 
	// if( cin.fail()) �ϸ� �Ǵµ�!!! - C++ Ư¡!!
}