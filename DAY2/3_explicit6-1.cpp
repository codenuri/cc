class istream
{
public:
	bool fail() const { return true; }

	// �ٽ� : ��ü�� if () �� �־ ��ȿ�� �׽�Ʈ�� �Ϸ���
	//       "explicit operator bool()" �� ����ض�!
	explicit operator bool() const { return fail() ? false : true; }
};
istream cin;

int main()
{
	cin >> 5;
}