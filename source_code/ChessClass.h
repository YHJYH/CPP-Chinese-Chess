#pragma once
#pragma once
#include <iostream>
#include <cmath>
#include "c_boardClass.h"
using namespace std;

class Chess {
public:
	int initial_y{};
	int initial_x{};
	virtual ~Chess() {}
	virtual int distance_squared(int x, int y) = 0;
	virtual bool obstacle(int x, int y) = 0;  //to check if the intermediate position of the movement is occupied
	virtual bool move_decision(int x, int y) = 0;  //if the obsacle position is not occupied, movement allowed, thus move_decision returns true
	virtual char get_mark() = 0;
};

//Abstract derived class
class Player1 :public Chess {
private:
	int initial_x;
	int initial_y;
protected:
	int team{ 1 };
	char mark{};
	c_board* c_b;
public:
	Player1() :initial_x{}, initial_y{}, c_b{}{}
	Player1(int xi, int yi, c_board* cb) : initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	virtual ~Player1() {}

	virtual int distance_squared(int x, int y) = 0;
	virtual bool obstacle(int x, int y) = 0;
	virtual bool move_decision(int x, int y) = 0;
	virtual char get_mark() = 0;
};

class Player2 :public Chess {
public:
	int initial_x;
	int initial_y;
protected:
	int team{ 2 };
	char mark{};
	c_board* c_b;
public:
	Player2() :initial_x{}, initial_y{}, c_b{}{}
	Player2(int xi, int yi, c_board* cb) :initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	virtual ~Player2() {}

	virtual int distance_squared(int x, int y) = 0;
	virtual bool obstacle(int x, int y) = 0;
	virtual bool move_decision(int x, int y) = 0;
	virtual char get_mark() = 0;
};

//Derived class for empty space, does not matter which player
class Empty :public Chess {
public:
	int initial_x;
	int initial_y;
private:
	char mark{ '-' };
	c_board* c_b;

public:
	//Empty(int x, int y) :initial_x{ x }, initial_y{ y }{}
	Empty(int x, int y, c_board* cb) :initial_x{ x }, initial_y{ y }, c_b{ cb }{}
	~Empty() {}
	int distance_squared(int x, int y) { return 0; }
	bool obstacle(int x, int y) { return 0; }
	bool move_decision(int x, int y) { return 0; }
	char get_mark() { return mark; }
};

//Derived class of each chess, for Player 1 and Player 2

//Player 1

//General (将)
class General1 :public Player1 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance{ 1 };
	char mark{ 'G' };
	c_board* c_b;
public:
	General1(int xi, int yi, c_board* cb) :initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	~General1() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int x, int y) { return false; }
	bool move_decision(int x, int y);
};


//Advisor (士)
class Advisor1 : public Player1 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance{ 2 };
	char mark{ 'A' };
	c_board* c_b;
public:
	Advisor1(int xi, int yi, c_board* cb) :initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	~Advisor1() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int x, int y) { return false; }
	bool move_decision(int x, int y);
};


//Elephant (象)
class Elephant1 : public Player1 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance{ 8 };
	char mark{ 'E' };
	c_board* c_b;
public:
	Elephant1(int xi, int yi, c_board* cb) :initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	~Elephant1() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int final_x, int final_y);
	bool move_decision(int x, int y);
};


//Horse (马)
class Horse1 :public Player1 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance{ 5 };
	char mark{ 'H' };
	c_board* c_b;
public:
	Horse1(int xi, int yi, c_board* cb) :initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	~Horse1() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int final_x, int final_y);
	bool move_decision(int x, int y);
};


//Chariot (车)
class Chariot1 :public Player1 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance_max{ 81 };
	char mark{ 'C' };
	c_board* c_b;
public:
	Chariot1(int xi, int yi, c_board* cb) : initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	~Chariot1() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int final_x, int final_y);
	bool move_decision(int final_x, int final_y);
};


//Cannon (砲) [F for fire]
class Cannon1 :public Player1 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance_max{ 81 };
	char mark{ 'F' };
	c_board* c_b;
public:
	Cannon1(int xi, int yi, c_board* cb) :initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	~Cannon1() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int x, int y);
	bool move_decision(int x, int y);
};


//Soldier (卒)
class Soldier1 :public Player1 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance{ 1 };
	char mark{ 'S' };
	c_board* c_b;
public:
	Soldier1(int xi, int yi, c_board* cb) :initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	~Soldier1() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int x, int y) { return false; }
	bool move_decision(int x, int y);
};


//Player 2

//General (帅)
class General2 :public Player2 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance{ 1 };
	char mark{ 'g' };
	c_board* c_b;
public:
	General2(int x, int y, c_board* cb) :initial_x{ x }, initial_y{ y }, c_b{ cb }{}
	~General2() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int x, int y) { return false; }
	bool move_decision(int x, int y);
};


//Advisor (仕)
class Advisor2 :public Player2 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance{ 2 };
	char mark{ 'a' };
	c_board* c_b;
public:
	Advisor2(int x, int y, c_board* cb) :initial_x{ x }, initial_y{ y }, c_b{ cb }{}
	~Advisor2() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int x, int y) { return false; }
	bool move_decision(int x, int y);
};


//Elephant (相)
class Elephant2 :public Player2 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance{ 8 };
	char mark{ 'e' };
	c_board* c_b;
public:
	Elephant2(int x, int y, c_board* cb) :initial_x{ x }, initial_y{ y }, c_b{ cb }{}
	~Elephant2() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int x, int y);
	bool move_decision(int x, int y);
};


//Horse (傌)
class Horse2 :public Player2 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance{ 5 };
	char mark{ 'h' };
	c_board* c_b;
public:
	Horse2(int xi, int yi, c_board* cb) :initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	~Horse2() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int x, int y);
	bool move_decision(int x, int y);
};


//Chariot (俥)
class Chariot2 :public Player2 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance_max{ 81 };
	char mark{ 'c' };
	c_board* c_b;
public:
	Chariot2(int xi, int yi, c_board* cb) : initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	~Chariot2() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int final_x, int final_y);
	bool move_decision(int final_x, int final_y);
};



//Cannon (炮)
class Cannon2 :public Player2 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance_max{ 81 };
	char mark{ 'f' };
	c_board* c_b;
public:
	Cannon2(int xi, int yi, c_board* cb) :initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	~Cannon2() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int x, int y);
	bool move_decision(int x, int y);
};


//Soldier (兵)
class Soldier2 :public Player2 {
public:
	int initial_x;
	int initial_y;
private:
	int squared_distance{ 1 };
	char mark{ 's' };
	c_board* c_b;
public:
	Soldier2(int xi, int yi, c_board* cb) :initial_x{ xi }, initial_y{ yi }, c_b{ cb }{}
	~Soldier2() {}

	int distance_squared(int x, int y);
	char get_mark() { return mark; }
	bool obstacle(int x, int y) { return false; }
	bool move_decision(int x, int y);
};



