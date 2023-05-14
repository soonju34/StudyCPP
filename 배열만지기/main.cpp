#include <iostream>
using namespace std;

struct Guest
{
	char name;
	int age;
};
int main()
{
	// 1번 : 손님 추가
	// 2번 : 먼저 온 손님 나감(출력)
	// 3번 : 남아 있는 손님 전체 출력

	// 1 엔터
	// 손님 이름 : a

	// 1엔터
	// 손님 이름 : b	


	// 1엔터
	// 손님 이름 : z
	
	// 2번
	// 출력 : a


	// 2번
	// 출력 : b

	// 1번
	// 손님 이름 : f

	// 2번
	// z

	Guest guestContainer[5];
	int i = 0;
	while (true)
	{
		int num;
		
		cout << "입력 : ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "손님 이름 : ";
			cin >> guestContainer[i++].name;

			break;
		
		case 2:
			cout << "나간 손님 : " << guestContainer[0].name << endl;
			for (int j = 0; j < i - 1; j++)
			{
				guestContainer[j].name = guestContainer[j+1].name;				
			}
			
			i--;

			break;
		case 3:
			for (int j = 0; j < i; j++)
			{
				cout << "전체 손님 : " << guestContainer[j].name << endl;
			}
			break;
		}
	}
	return 0;
}