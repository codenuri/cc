// conversion function pointer
class CompilerGeneratedName
{
public:


};



int main()
{
	int(*f1)(int, int) = CompilerGeneratedName();






	// ���� ǥ������ �Լ� �����Ϳ� ��Ƶ� �˴ϴ�.
	int(*f)(int, int) = [](int a, int b) { return a + b; };
						// class xxx{}; xxx(); 
						// �ӽð�ü


}