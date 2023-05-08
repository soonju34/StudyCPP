#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define PLAYER_HP_MAX 500

struct RangeInt {
	int min;
	int max;
};

struct PlayerState
{
	int hp;
	int att;
	RangeInt healRange;

};
struct MonsterState
{
	int hp;
	int att;
	RangeInt criticalRange;

};


void PlayerAttak(MonsterState *monster, PlayerState *player) 
{

	monster->hp = monster->hp - player->att;
	cout << "���� ���� ü�� : " << monster->hp << endl;
}

void PlayerHael(PlayerState* player)
{
	int heal = (rand() % player->healRange.max - player->healRange.min + 1) + player->healRange.min;

	if ((player->hp + heal) >= PLAYER_HP_MAX)
	{
		cout << "���� hp : " << player->hp << endl;
		player->hp = PLAYER_HP_MAX;
	}
	else {
		cout << "�� �� : " << heal << endl;
		player->hp = player->hp + heal;
		cout << "���� hp : " << player->hp << endl;
	}
}


int main() 
{
	srand((unsigned)time(0));


	MonsterState monster;
	monster.hp = 1000;
	monster.att = 10;
	monster.criticalRange.min = 0;
	monster.criticalRange.max = 10;

	PlayerState player;
	player.hp = PLAYER_HP_MAX;
	player.att = 50;
	player.healRange.min = 50;
	player.healRange.max = 100;

	while (true)
	{
		int num;
		cout << "1. ���� 2. ��" << endl;
		cout << "�Է� : ";
		scanf_s("%d", &num);
		switch (num)
		{
			case 1:
				PlayerAttak(&monster, &player);
				break;
			case 2:
				PlayerHael(&player);
				break;
			
		}
		int critical = (rand() % monster.criticalRange.max - monster.criticalRange.min + 1) + monster.criticalRange.min;
		int attack = (monster.att + critical);
		cout << "���Ͱ� " << attack << "�� �����߽��ϴ�" << endl;
		player.hp = player.hp - attack;
		cout << "�÷��̾� ���� ü�� : " << player.hp << endl;

		if (monster.hp <= 0) {
			cout << "���� ���" << endl;
			break;
		}
		else if (player.hp <= 0) {
			cout << "�÷��̾� ���" << endl;
			break;
		}
	}

	

	
	
	return  0;
}