#include <iostream>
using namespace std;

struct Guest
{
	char name;
	int age;
};
int main()
{
	// 1�� : �մ� �߰�
	// 2�� : ���� �� �մ� ����(���)
	// 3�� : ���� �ִ� �մ� ��ü ���

	// 1 ����
	// �մ� �̸� : a

	// 1����
	// �մ� �̸� : b	


	// 1����
	// �մ� �̸� : z
	
	// 2��
	// ��� : a


	// 2��
	// ��� : b

	// 1��
	// �մ� �̸� : f

	// 2��
	// z

	Guest guestContainer[5];
	int i = 0;
	while (true)
	{
		int num;
		
		cout << "�Է� : ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "�մ� �̸� : ";
			cin >> guestContainer[i++].name;

			break;
		
		case 2:
			cout << "���� �մ� : " << guestContainer[0].name << endl;
			for (int j = 0; j < i - 1; j++)
			{
				guestContainer[j].name = guestContainer[j+1].name;				
			}
			
			i--;

			break;
		case 3:
			for (int j = 0; j < i; j++)
			{
				cout << "��ü �մ� : " << guestContainer[j].name << endl;
			}
			break;
		}
	}
	return 0;
}