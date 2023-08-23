// conversion function pointer
class CompilerGeneratedName
{
public:
	auto operator()(int a, int b) const { return a + b; }

	// �Լ� �����ͷ��� ��ȯ�� ���ؼ� �����Ϸ��� ����� Ŭ�������� �Ʒ� ����� 
	// �ֽ��ϴ�.
	using F = int(*)(int, int);

//	operator F() { return &CompilerGeneratedName::operator(); }
					// => error
					// => ��� �Լ��� "this"�� �߰��Ǵ� �Լ� �Դϴ�.
					// => ���� �Ϲ� �Լ� �����Ϳ� ��� �Լ� �ּ� ������ �����ϴ�

	// �Լ� �����ͷ��� ��ȯ�� ���ؼ� "operator()" �� ������ ���� �ϴ� 
	// static ��� �Լ��� �ʿ�
	static auto helper(int a, int b) { return a + b; }

	operator F() { return &CompilerGeneratedName::helper; }
};

int main()
{
	int(*f1)(int, int) = CompilerGeneratedName();
						// �ӽð�ü.operator �Լ�������Ÿ��()


	// ���� ǥ������ �Լ� �����Ϳ� ��Ƶ� �˴ϴ�.
	int(*f)(int, int) = [](int a, int b) { return a + b; };
						// class xxx{}; xxx(); 
						// �ӽð�ü

	// �ٽ� : ĸ���� ����ǥ������ �Լ������ͷ� ��ȯ�ɼ� �����ϴ�.
	int k = 10;
	int(*f2)(int, int) = [k](int a, int b) { return a + b + k; }; // error
}

class CompilerGeneratedName2
{
	int k;
public:
	CompilerGeneratedName2(int n) : k(n) {}

	auto operator()(int a, int b) const { return a + b + k; }

	using F = int(*)(int, int);

	// �Լ� �����ͷ��� ��ȯ�� ���� static �Լ����� �������Ÿ k���� �ȵ˴ϴ�.
	// �� ���� ������, ĸ���� ����ǥ������ �Լ� ������ ��ȯ�� �ȵ˴ϴ�.
	static auto helper(int a, int b) { return a + b + k; }

	operator F() { return &CompilerGeneratedName::helper; }
};