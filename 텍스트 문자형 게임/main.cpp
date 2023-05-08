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
	cout << "몬스터 남은 체력 : " << monster->hp << endl;
}

void PlayerHael(PlayerState* player)
{
	int heal = (rand() % player->healRange.max - player->healRange.min + 1) + player->healRange.min;

	if ((player->hp + heal) >= PLAYER_HP_MAX)
	{
		cout << "남은 hp : " << player->hp << endl;
		player->hp = PLAYER_HP_MAX;
	}
	else {
		cout << "힐 량 : " << heal << endl;
		player->hp = player->hp + heal;
		cout << "남은 hp : " << player->hp << endl;
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
		cout << "1. 공격 2. 힐" << endl;
		cout << "입력 : ";
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
		cout << "몬스터가 " << attack << "로 공격했습니다" << endl;
		player.hp = player.hp - attack;
		cout << "플레이어 남은 체력 : " << player.hp << endl;

		if (monster.hp <= 0) {
			cout << "몬스터 사망" << endl;
			break;
		}
		else if (player.hp <= 0) {
			cout << "플레이어 사망" << endl;
			break;
		}
	}

	

	
	
	return  0;
}