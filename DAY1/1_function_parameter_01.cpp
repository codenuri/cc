// �Լ��� ���� ���޿� ���� ��Ģ��
// 
// F16 ~ F21  ( 10 page ~)
// F.16 : For "in" parameters, pass cheaply - copied types by value and others by reference to const
// F.17 : For "in-out" parameters, pass by reference to non - const
// F.18 : For "will-move-from" parameters, pass by X&& and std::move the parameter
// F.19 : For "forward" parameters, pass by TP&& and only std::forward the parameter
// F.20 : For "out" output values, prefer return values to output parameters
// F.21 : To return multiple ��out�� values, prefer returning a struct or tuple
// F.60 : Prefer T* over T& when ��no argument�� is a valid option



// day1.zip ���� Ǯ�� ������.

// visual studio ����Ͻô� ���� vs(visual studio) 
// ���� day1.sln ���� ������

// 1. ���� �����ؾ� �մϴ�.
//    ������Ʈ �޴��� �Ӽ� �޴� ����

// 2. ���� �ϴ� �� : ctrl + F5
// => �Ʒ� �ڵ� ���� �߰��ϰ� ������ ������
int main() {}

// 3. ������ ���忡 ����/���� �ϴ� ���
// => ���� ������, ���콺 ������ ��ư ������, �Ӽ� �޴� ����

// 4. �ٸ� ������(�����Ϸ�)����Ͻô� ���� 