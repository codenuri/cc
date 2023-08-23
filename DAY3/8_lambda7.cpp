// conversion function pointer
class CompilerGeneratedName
{
public:
	auto operator()(int a, int b) const { return a + b; }

	// �Լ� �����ͷ��� ��ȯ�� ���ؼ� �����Ϸ��� ����� Ŭ�������� �Ʒ� ����� 
	// �ֽ��ϴ�.
	using F = int(*)(int, int);

	operator F() { return �Լ� �ּ�; }
};



int main()
{
	int(*f1)(int, int) = CompilerGeneratedName();
						// �ӽð�ü.operator �Լ�������Ÿ��()




	// ���� ǥ������ �Լ� �����Ϳ� ��Ƶ� �˴ϴ�.
	int(*f)(int, int) = [](int a, int b) { return a + b; };
						// class xxx{}; xxx(); 
						// �ӽð�ü


}