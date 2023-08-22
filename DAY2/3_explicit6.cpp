
class istream
{
public:
	bool fail()  { return true; }

	// cin �� if ���� �ְ� �;����ϴ�.
	// 1. operator bool()
	// ������ : cin << 5 �� ������ ���� �ʴ´�..
	// operator bool() { return fail() ? false : true; }

	// 2. operator void*() �� ����!!!
	// => �����ʹ� if()�� ���ϼ� �ְ�, << ������ �ȵȴ�.!
	// => C++98 ������ ������ �̷��� ����
	// ������ : delete cin �� ������ �ƴϴ�!!!
	// operator void*() { return fail() ? 0 : this; }

	// 3. boost ���̺귯�� ���� ������ �ذ�å - ǥ���� �ƴ�����
	// => ��� �Լ� �����ͷ��� ��ȯ
	// => ��� �Լ� �ּҴ� if() �� ������ �ְ�, �ٸ� Ÿ������ ��ȯ�� ���� ���ȵ�
private:
	struct dummy
	{
		void true_function() {}  // ���� ȣ���Ϸ��� ���� �ƴ϶�.. �ּҸ� ���
	};
public:
	using F = void(dummy::*)();

	operator F() { return fail() ? 0 : &dummy::true_function; }
};

istream cin;

int main()
{	
	if (cin) { }

//	cin << 5;

	delete cin;
}