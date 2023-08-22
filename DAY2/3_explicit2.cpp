class Point
{
	int x{ 0 };
	int y{ 0 };
public:
	explicit Point() = default;

	explicit Point(int x, int y) : x{ x }, y{ y } {}
};

void fn(Point pt) {} 

int main()
{
	// C++11 ���ʹ� �Լ� ���ڸ� �Ʒ� ó�� �����ص� �˴ϴ�.
	// => �Ʒ� 2���� ǥ�⸦ ������� �������� explicit �� �Ͻø� �˴ϴ�.
	// => ��, ������ ���ڰ� ���ų� ������ �� explicit ��밡���մϴ�
	fn( {} );		
	fn( {1, 2} );	

	fn(Point());   //ok
	fn(Point(1, 2)); // ok
				   
	fn({ 1,2 }); // 1. {1,2} �� ������ ��ȯ �������� �ǹ̷� �ӽð�ü����
				 //    => explicit �̹Ƿ� ��ȯ������ �ȵ�
	fn(Point(1, 2)); // 1. �ӽð�ü ������
					 // 2. ����(�̵�) �����ڷ� pt�� ����(Point pt = �ӽð�ü)
}


