// nullptr �� ����
void f1(int*  p) {}
void f2(char* p) {}

// C++11 �� ���������� boost ���̺귯�� ������ �Ʒ� Ŭ������ �����߽��ϴ�.
// => ��� ������ �����ͷ� �Ͻ��� ��ȯ �����մϴ�.
// => ��, C++11������ nullptr�� �Ʒ� ó�� �����Ȱ��� �ƴ϶�, �Ʒ� ó�� �����ϴ� 
//    "Ű����" �Դϴ�.
struct nullptr_t
{
	template<typename T>
	operator T* () const { return 0; }	
};
nullptr_t mynullptr;

int main()
{
	f1(mynullptr); // mynullptr.operator int*()
	f2(mynullptr); // mynullptr.operator char*()
}