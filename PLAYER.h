#ifndef PLAYER_H
#define PLAYER_H

#include "CAVE.h"
#include <string>
#include <vector>

using namespace std;

class PLAYER {
public:
	PLAYER();
	vector<int> position;
	string facing;
	bool hasArrow;
	bool hasGold;
	bool alive;
	bool eaten;
	bool fell;
	bool escaped;
	vector<int> Get_Position();
	string Get_Facing();
	void Turn_Left();
	void Turn_Right();
	vector<int> Get_Next_Square();
	void Move_Forward();
	bool Has_Arrow();
	bool Shoot_Arrow(CAVE &cave);
	bool Pickup_Gold(CAVE &cave);
	void Climb_Ladder();
	bool Update_Player_Status(CAVE &cave);
	bool Escaped();
	bool Eaten();
	bool Fell();
	bool Has_Gold();
};
#endif
