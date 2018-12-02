#include "PLAYER.h"

using namespace std;

PLAYER::PLAYER()
{
	position = {1,1};
	facing = "right";
	hasArrow = true;
	hasGold = false;
	alive = true;
	eaten = false;
	fell = false;
	escaped = false;
}

// return current position of the player
vector<int> PLAYER::Get_Position()
{
	return position;
}

// return direction the player is facing
string PLAYER::Get_Facing()
{
	return facing;
}

// turn direction player is facing to the left
void PLAYER::Turn_Left()
{
	if (facing == "up")
	{
		facing = "left";
	}
	else if (facing == "down")
	{
		facing = "right";
	}
	else if (facing == "left")
	{
		facing = "down";
	}
	else
	{
		facing = "up";
	}
}

// turn direction player is facing to the right
void PLAYER::Turn_Right()
{
	if (facing == "up")
	{
		facing = "right";
	}
	else if (facing == "down")
	{
		facing = "left";
	}
	else if (facing == "left")
	{
		facing = "up";
	}
	else
	{
		facing = "down";
	}
}

// returns the square directly in front of the player
vector<int> PLAYER::Get_Next_Square()
{
	vector<int> next = position;

	if (facing == "up")
	{
		next[0] = position[0] - 1;
	}
	else if (facing == "down")
	{
		next[0] = position[0] + 1;
	}
	else if (facing == "left")
	{
		next[1] = position[1] - 1;
	}
	else
	{
		next[1] = position[1] + 1;
	}
	return next;
}

// moves the player to the square directly in front of the player
void PLAYER::Move_Forward()
{
	position = Get_Next_Square();
}

bool PLAYER::Has_Arrow()
{
	return hasArrow;
}

bool PLAYER::Shoot_Arrow(CAVE &cave)
{
	if (hasArrow)
	{
		if (facing == "up")
		{
			vector<int> arrow_pos = position;
			arrow_pos[0] -= 1;
			while (cave.Is_Square_Valid(arrow_pos))
			{
				if (cave.Square_Contains_Living_Wumpus(arrow_pos))
				{
					cave.Shoot_Square(arrow_pos);
					return true;
				}
				arrow_pos[0]--;
			}
		}
		else if (facing == "down")
		{
			vector<int> arrow_pos = position;
			arrow_pos[0] += 1;
			while (cave.Is_Square_Valid(arrow_pos))
			{
				if (cave.Square_Contains_Living_Wumpus(arrow_pos))
				{
					cave.Shoot_Square(arrow_pos);
					return true;
				}
				arrow_pos[0]++;
			}
		}
		else if (facing == "left")
		{
			vector<int> arrow_pos = position;
			arrow_pos[1] -= 1;
			while (cave.Is_Square_Valid(arrow_pos))
			{
				if (cave.Square_Contains_Living_Wumpus(arrow_pos))
				{
					cave.Shoot_Square(arrow_pos);
					return true;
				}
				arrow_pos[1]--;
			}
		}
		else
		{
			vector<int> arrow_pos = position;
			arrow_pos[1] += 1;
			while (cave.Is_Square_Valid(arrow_pos))
			{
				if (cave.Square_Contains_Living_Wumpus(arrow_pos))
				{
					cave.Shoot_Square(arrow_pos);
					return true;
				}
				arrow_pos[1]++;
			}
		}
	}
	hasArrow = false;
	return false;
}

// returns true if the player is in the same square as the gold, false otherwise
bool PLAYER::Pickup_Gold(CAVE &cave)
{
	if (cave.Square_Contains_Gold(position))
	{
		hasGold = true;
		cave.Remove_Gold(position);
		return hasGold;
	}
	return false;
}

// player is marked as escaped and the game exits
void PLAYER::Climb_Ladder()
{
	escaped = true;
}

// checks the player's current status; returns true if alive, false otherwise
bool PLAYER::Update_Player_Status(CAVE &cave)
{
	if (cave.Square_Contains_Living_Wumpus(position))
	{
		alive = false;
		eaten = true;
		return false;
	}
	else if (cave.Square_Contains_Pit(position))
	{
		alive = false;
		fell = true;
		return false;
	}
	return true;
}

// returns true if the player has escaped
bool PLAYER::Escaped()
{
	return (alive && escaped);
}

// return true if the player has been eaten
bool PLAYER::Eaten()
{
	return eaten;
}

// returns true if the player has fallen into a pit
bool PLAYER::Fell()
{
	return fell;
}

// returns true if the player has picked up the gold
bool PLAYER::Has_Gold()
{
	return hasGold;
}
