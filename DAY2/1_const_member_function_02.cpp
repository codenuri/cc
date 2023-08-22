// ��� ��� �Լ���� ������

// 1. "����" �� �ƴ� "�ʼ�" �����Դϴ�.
// 
// 2. ��� �Լ��� ����(�������Ÿ)�� �������� ���� ��� ��� �Լ�(getter)��
//    "�ݵ��" ��� ��� �Լ��� �ؾ� �մϴ�

// 3. �Ʒ� Rect::get_area()�� "�ݵ��" ��� ����Լ� �̾�� �մϴ�.

// �Ϲ������� Ŭ�������� "setxxx" ���� "getxxx" �� �� �����ϴ�.
// => ����, ��� ��� �Լ��� �� ���� �˴ϴ�.

class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

//	int get_area() { return w * h; } // bad �� �ƴ� wrong �Դϴ�.. ������ Ʋ���ڵ�!

	int get_area() const { return w * h; } // good!!!
};

//void foo(Rect r) // call by value : ���纻�� ������� �ֽ��ϴ�. �����ڵ�
void foo(const Rect& r) // ���� ���� �ڵ�
{
	int n = r.get_area();
}

int main()
{
	Rect r(1, 2, 3, 4);		// ��� ��ü�� �ƴմϴ�.
	int n = r.get_area();	// ok. 
	foo(r);
}