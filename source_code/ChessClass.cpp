#include "ChessClass.h"

int::General1::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::General1::move_decision(int x, int y) {
	if (2 < x && x < 6 && y < 3 && distance_squared(x, y) == squared_distance && obstacle(x, y) == false) { return true; }
	else { return false; }
}

int::Advisor1::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::Advisor1::move_decision(int x, int y) {
	if (distance_squared(x, y) == squared_distance && obstacle(x, y) == false && 2 < x && x < 6 && y < 3) { return true; }
	else { return false; }
}

int::Elephant1::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}
bool::Elephant1::obstacle(int final_x, int final_y) {
	int occupied_x{};
	int occupied_y{};
	if (final_x > initial_x && final_y > initial_y) {
		occupied_x = initial_x + 1;
		occupied_y = initial_y + 1;
		if (c_b->occupation(occupied_y, occupied_x)) return true;
		else { return false; }
	}
	if (final_x > initial_x && final_y < initial_y) {
		occupied_x = initial_x + 1;
		occupied_y = initial_y - 1;
		if (c_b->occupation(occupied_y, occupied_x)) return true;
		else { return false; }
	}
	if (final_x < initial_x && final_y > initial_y) {
		occupied_x = initial_x - 1;
		occupied_y = initial_y + 1;
		if (c_b->occupation(occupied_y, occupied_x)) return true;
		else { return false; }
	}
	if (final_x < initial_x && final_y < final_x) {
		occupied_x = initial_x - 1;
		occupied_y = initial_y - 1;
		if (c_b->occupation(occupied_y, occupied_x)) return true;
		else { return false; }
	}
}

bool::Elephant1::move_decision(int x, int y) {
	if (distance_squared(x, y) == squared_distance && obstacle(x, y) == false && y < 5) return true;
	else { return false; }
}

int::Horse1::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::Horse1::obstacle(int final_x, int final_y) {
	int occupied_x{};
	int occupied_y{};
	if (final_x > initial_x && abs(final_y - initial_y) == 1) {
		occupied_x = initial_x + 1;
		occupied_y = initial_y;
		if (c_b->occupation(occupied_y, occupied_x)) return true; //occupation is a boolean function in ChessBoard, return true if there is a chess on the positiion, otherwise return false
		else { return false; }
	}
	if (final_y > initial_y && abs(final_x - initial_x) == 1) {
		occupied_x = initial_x;
		occupied_y = initial_y + 1;
		if (c_b->occupation(occupied_y, occupied_x)) return true;
		else { return false; }
	}
	if (final_x < initial_x && abs(final_y - initial_y) == 1) {
		occupied_x = initial_x - 1;
		occupied_y = initial_y;
		if (c_b->occupation(occupied_y, occupied_x)) return true;
		else { return false; }
	}
	if (final_y < initial_y && abs(final_x - initial_x) == 1) {
		occupied_x = initial_x;
		occupied_y = initial_y - 1;
		if (c_b->occupation(occupied_y, occupied_x)) return true;
		else { return false; }
	}
}

bool::Horse1::move_decision(int x, int y) {
	if (distance_squared(x, y) == squared_distance && obstacle(x, y) == false) {
		return true;
	}
	else { return false; }
}

int::Chariot1::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::Chariot1::obstacle(int final_x, int final_y) {
	if (final_y == initial_y && final_x != initial_x) {  //horizontal move
		if (c_b->occupation(initial_y, final_x) == false) { //empty destination
			if (abs(final_x - initial_x) == 1) { return false; }
			else {
				if (final_x > initial_x) { //moveing to right
					for (int i{ initial_x + 1 };i < final_x;i++) {
						if (c_b->occupation(initial_y, i) == true) { return true; }
					}
					return false;
				}
				if (final_x < initial_x) {  //moving to left
					for (int i{ final_x + 1 };i < initial_x;i++) {
						if (c_b->occupation(final_y, i) == true) { return true; }
					}
					return false;
				}
			}
		}
		else { //if not empty
			if (abs(final_x - initial_x) == 1) { return true; }
			else {
				if (final_x > initial_x) { //move to right
					int i{};
					for (int j{ initial_x + 1 };j < final_x;j++) {
						if (c_b->occupation(final_y, j) == true) {
							i = i + 1;
						}
					}
					if (i == 0) { return false; }
					else { return true; }
				}
				if (final_x < initial_x) { //move to left
					int i{};
					for (int j{ final_x + 1 };j < initial_x;j++) {
						if (c_b->occupation(final_y, j) == true) {
							i = i + 1;
						}
					}
					if (i == 0) { return false; }
					else { return true; }
				}
			}
		}
	}
	if (final_x == initial_x && final_y != initial_y) { //vertical move
		if (c_b->occupation(final_y, final_x) == false) { //empty destination
			if (abs(final_y - initial_y) == 1) { return false; }
			else {
				if (final_y > initial_y) { //move downwards
					for (int i{ initial_y + 1 };i < final_y;i++) {
						if (c_b->occupation(i, final_x) == true) { return true; }
					}
					return false;
				}
				if (final_y < initial_y) { //move upwards
					for (int i{ final_y + 1 };i < initial_y;i++) {
						if (c_b->occupation(i, initial_x) == true) { return true; }
					}
					return false;
				}
			}
		}
		else { //non empty destination
			if (abs(initial_y - final_y) == 1) { return true; }
			else {
				if (final_y > initial_y) { //move downwards
					int i{};
					for (int j{ initial_y + 1 };j < final_y;j++) {
						if (c_b->occupation(j, initial_x) == true) {
							i = i + 1;
						}
					}
					if (i == 0) { return false; }
					else { return true; }
				}
				if (final_y < initial_y) { //move upwards
					int i{};
					for (int j{ final_y + 1 };j < initial_y;j++) {
						if (c_b->occupation(j, initial_x) == true) { i = i + 1; }
					}
					if (i == 0) { return false; }
					else { return true; }
				}
			}
		}
	}
}

bool::Chariot1::move_decision(int final_x, int final_y) {
	if (((initial_x == final_x && initial_y != final_y) || (initial_x != final_x && initial_y == final_y))
		&& distance_squared(final_x, final_y) <= squared_distance_max
		&& obstacle(final_x, final_y) == false) {
		return true;
	}
	else { return false; }
}

int::Cannon1::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::Cannon1::obstacle(int final_x, int final_y) {
	if (final_y == initial_y && final_x != initial_x) {  //horizontal move
		if (c_b->occupation(initial_y, final_x) == false) { //empty destination
			if (abs(final_x - initial_x) == 1) { return false; }
			else {
				if (final_x > initial_x) { //moveing to right
					for (int i{ initial_x + 1 };i < final_x;i++) {
						if (c_b->occupation(initial_y, i) == true) { return true; }
					}
					return false;
				}
				if (final_x < initial_x) {  //moving to left
					for (int i{ final_x + 1 };i < initial_x;i++) {
						if (c_b->occupation(final_y, i) == true) { return true; }
					}
					return false;
				}
			}
		}
		else { //if not empty
			if (abs(final_x - initial_x) == 1) { return true; }
			else {
				if (final_x > initial_x) { //move to right
					int i{};
					for (int j{ initial_x + 1 };j < final_x;j++) {
						if (c_b->occupation(final_y, j) == true) {
							i = i + 1;
						}
					}
					if (i == 1) { return false; }
					else { return true; }
				}
				if (final_x < initial_x) { //move to left
					int i{};
					for (int j{ final_x + 1 };j < initial_x;j++) {
						if (c_b->occupation(final_y, j) == true) {
							i = i + 1;
						}
					}
					if (i == 1) { return false; }
					else { return true; }
				}
			}
		}
	}
	if (final_x == initial_x && final_y != initial_y) { //vertical move
		if (c_b->occupation(final_y, final_x) == false) { //empty destination
			if (abs(final_y - initial_y) == 1) { return false; }
			else {
				if (final_y > initial_y) { //move downwards
					for (int i{ initial_y + 1 };i < final_y;i++) {
						if (c_b->occupation(i, final_x) == true) { return true; }
					}
					return false;
				}
				if (final_y < initial_y) { //move upwards
					for (int i{ final_y + 1 };i < initial_y;i++) {
						if (c_b->occupation(i, initial_x) == true) { return true; }
					}
					return false;
				}
			}
		}
		else { //non empty destination
			if (abs(initial_y - final_y) == 1) { return true; }
			else {
				if (final_y > initial_y) { //move downwards
					int i{};
					for (int j{ initial_y + 1 };j < final_y;j++) {
						if (c_b->occupation(j, initial_x) == true) {
							i = i + 1;
						}
					}
					if (i == 1) { return false; }
					else { return true; }
				}
				if (final_y < initial_y) { //move upwards
					int i{};
					for (int j{ final_y + 1 };j < initial_y;j++) {
						if (c_b->occupation(j, initial_x) == true) { i = i + 1; }
					}
					if (i == 1) { return false; }
					else { return true; }
				}
			}
		}
	}
}

bool::Cannon1::move_decision(int final_x, int final_y) {
	if (((initial_x == final_x && initial_y != final_y) || (initial_x != final_x && initial_y == final_y))
		&& distance_squared(final_x, final_y) <= squared_distance_max
		&& obstacle(final_x, final_y) == false) {
		return true;
	}
	else { return false; }
}

int::Soldier1::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::Soldier1::move_decision(int x, int y) {
	if (initial_y > 4) {
		if (distance_squared(x, y) == squared_distance &&
			((y > initial_y && x == initial_x) || (y == initial_y && x != initial_x))) {
			return true;
		}
		else { return false; }
	}
	else {
		if (distance_squared(x, y) == squared_distance && y > initial_y && x == initial_x) { return true; }
		else { return false; }
	}
}

int::General2::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::General2::move_decision(int x, int y) {
	if (2 < x && x < 6 && y > 6 && distance_squared(x, y) == squared_distance && obstacle(x, y) == false) { return true; }
	else { return false; }
}

int::Advisor2::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::Advisor2::move_decision(int x, int y) {
	if (distance_squared(x, y) == squared_distance && obstacle(x, y) == false && 2 < x && x < 6 && y > 6) { return true; }
	else { return false; }
}

int::Elephant2::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::Elephant2::obstacle(int x, int y) {
	int occupied_x{};
	int occupied_y{};
	if (x > initial_x && y > initial_y) {
		occupied_x = initial_x + 1;
		occupied_y = initial_y + 1;
		if (c_b->occupation(occupied_y, occupied_x)) { return true; }
		else { return false; }
	}
	if (x > initial_x && y < initial_y) {
		occupied_x = initial_x + 1;
		occupied_y = initial_y - 1;
		if (c_b->occupation(occupied_y, occupied_x)) { return true; }
		else { return false; }
	}
	if (x < initial_x && y < initial_y) {
		occupied_x = initial_x - 1;
		occupied_y = initial_y - 1;
		if (c_b->occupation(occupied_y, occupied_x)) { return true; }
		else { return false; }
	}
	if (x < initial_x && y > initial_y) {
		occupied_x = initial_x - 1;
		occupied_y = initial_y + 1;
		if (c_b->occupation(occupied_y, occupied_x)) { return true; }
		else { return false; }
	}
}

bool::Elephant2::move_decision(int x, int y) {
	if (distance_squared(x, y) == squared_distance && obstacle(x, y) == false && y > 4) { return true; }
	else { return false; }
}

int::Horse2::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::Horse2::obstacle(int x, int y) {
	int occupied_x{};
	int occupied_y{};
	if (x > initial_x && abs(y - initial_y) == 1) {
		occupied_x = initial_x + 1;
		occupied_y = initial_y;
		if (c_b->occupation(occupied_y, occupied_x) == true) { return true; }
		else { return false; }
	}
	if (x < initial_x && abs(y - initial_y) == 1) {
		occupied_x = initial_x - 1;
		occupied_y = initial_y;
		if (c_b->occupation(occupied_y, occupied_x) == true) { return true; }
		else { return false; }
	}
	if (y > initial_y && abs(x - initial_x) == 1) {
		occupied_x = initial_x;
		occupied_y = initial_y + 1;
		if (c_b->occupation(occupied_y, occupied_x) == true) { return true; }
		else { return false; }
	}
	if (y < initial_y && abs(x - initial_x) == 1) {
		occupied_x = initial_x;
		occupied_y = initial_y - 1;
		if (c_b->occupation(occupied_y, occupied_x) == true) { return true; }
		else { return false; }
	}
}

bool::Horse2::move_decision(int x, int y) {
	if (distance_squared(x, y) == squared_distance && obstacle(x, y) == false) { return true; }
	else { return false; }
}

int::Chariot2::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::Chariot2::obstacle(int final_x, int final_y) {
	if (final_y == initial_y && final_x != initial_x) {  //horizontal move
		if (c_b->occupation(initial_y, final_x) == false) { //empty destination
			if (abs(final_x - initial_x) == 1) { return false; }
			else {
				if (final_x > initial_x) { //moveing to right
					for (int i{ initial_x + 1 };i < final_x;i++) {
						if (c_b->occupation(initial_y, i) == true) { return true; }
					}
					return false;
				}
				if (final_x < initial_x) {  //moving to left
					for (int i{ final_x + 1 };i < initial_x;i++) {
						if (c_b->occupation(final_y, i) == true) { return true; }
					}
					return false;
				}
			}
		}
		else { //if not empty
			if (abs(final_x - initial_x) == 1) { return true; }
			else {
				if (final_x > initial_x) { //move to right
					int i{};
					for (int j{ initial_x + 1 };j < final_x;j++) {
						if (c_b->occupation(final_y, j) == true) {
							i = i + 1;
						}
					}
					if (i == 0) { return false; }
					else { return true; }
				}
				if (final_x < initial_x) { //move to left
					int i{};
					for (int j{ final_x + 1 };j < initial_x;j++) {
						if (c_b->occupation(final_y, j) == true) {
							i = i + 1;
						}
					}
					if (i == 0) { return false; }
					else { return true; }
				}
			}
		}
	}
	if (final_x == initial_x && final_y != initial_y) { //vertical move
		if (c_b->occupation(final_y, final_x) == false) { //empty destination
			if (abs(final_y - initial_y) == 1) { return false; }
			else {
				if (final_y > initial_y) { //move downwards
					for (int i{ initial_y + 1 };i < final_y;i++) {
						if (c_b->occupation(i, final_x) == true) { return true; }
					}
					return false;
				}
				if (final_y < initial_y) { //move upwards
					for (int i{ final_y + 1 };i < initial_y;i++) {
						if (c_b->occupation(i, initial_x) == true) { return true; }
					}
					return false;
				}
			}
		}
		else { //non empty destination
			if (abs(initial_y - final_y) == 1) { return true; }
			else {
				if (final_y > initial_y) { //move downwards
					int i{};
					for (int j{ initial_y + 1 };j < final_y;j++) {
						if (c_b->occupation(j, initial_x) == true) {
							i = i + 1;
						}
					}
					if (i == 0) { return false; }
					else { return true; }
				}
				if (final_y < initial_y) { //move upwards
					int i{};
					for (int j{ final_y + 1 };j < initial_y;j++) {
						if (c_b->occupation(j, initial_x) == true) { i = i + 1; }
					}
					if (i == 0) { return false; }
					else { return true; }
				}
			}
		}
	}
}

bool::Chariot2::move_decision(int final_x, int final_y) {
	if (((initial_x == final_x && initial_y != final_y) || (initial_x != final_x && initial_y == final_y))
		&& distance_squared(final_x, final_y) <= squared_distance_max
		&& obstacle(final_x, final_y) == false) {
		return true;
	}
	else { return false; }
}

int::Cannon2::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::Cannon2::obstacle(int final_x, int final_y) {
	if (final_y == initial_y && final_x != initial_x) {  //horizontal move
		if (c_b->occupation(initial_y, final_x) == false) { //empty destination
			if (abs(final_x - initial_x) == 1) { return false; }
			else {
				if (final_x > initial_x) { //moveing to right
					for (int i{ initial_x + 1 };i < final_x;i++) {
						if (c_b->occupation(initial_y, i) == true) { return true; }
					}
					return false;
				}
				if (final_x < initial_x) {  //moving to left
					for (int i{ final_x + 1 };i < initial_x;i++) {
						if (c_b->occupation(final_y, i) == true) { return true; }
					}
					return false;
				}
			}
		}
		else { //if not empty
			if (abs(final_x - initial_x) == 1) { return true; }
			else {
				if (final_x > initial_x) { //move to right
					int i{};
					for (int j{ initial_x + 1 };j < final_x;j++) {
						if (c_b->occupation(final_y, j) == true) {
							i = i + 1;
						}
					}
					if (i == 1) { return false; }
					else { return true; }
				}
				if (final_x < initial_x) { //move to left
					int i{};
					for (int j{ final_x + 1 };j < initial_x;j++) {
						if (c_b->occupation(final_y, j) == true) {
							i = i + 1;
						}
					}
					if (i == 1) { return false; }
					else { return true; }
				}
			}
		}
	}
	if (final_x == initial_x && final_y != initial_y) { //vertical move
		if (c_b->occupation(final_y, final_x) == false) { //empty destination
			if (abs(final_y - initial_y) == 1) { return false; }
			else {
				if (final_y > initial_y) { //move downwards
					for (int i{ initial_y + 1 };i < final_y;i++) {
						if (c_b->occupation(i, final_x) == true) { return true; }
					}
					return false;
				}
				if (final_y < initial_y) { //move upwards
					for (int i{ final_y + 1 };i < initial_y;i++) {
						if (c_b->occupation(i, initial_x) == true) { return true; }
					}
					return false;
				}
			}
		}
		else { //non empty destination
			if (abs(initial_y - final_y) == 1) { return true; }
			else {
				if (final_y > initial_y) { //move downwards
					int i{};
					for (int j{ initial_y + 1 };j < final_y;j++) {
						if (c_b->occupation(j, initial_x) == true) {
							i = i + 1;
						}
					}
					if (i == 1) { return false; }
					else { return true; }
				}
				if (final_y < initial_y) { //move upwards
					int i{};
					for (int j{ final_y + 1 };j < initial_y;j++) {
						if (c_b->occupation(j, initial_x) == true) { i = i + 1; }
					}
					if (i == 1) { return false; }
					else { return true; }
				}
			}
		}
	}
}

bool::Cannon2::move_decision(int x, int y) {
	if (obstacle(x, y) == false &&
		distance_squared(x, y) <= squared_distance_max &&
		((y == initial_y && x != initial_x) ||
			(y != initial_y && x == initial_x))) {
		return true;
	}
	else { return false; }
}

int::Soldier2::distance_squared(int x, int y) {
	int ds = pow(x - initial_x, 2) + pow(y - initial_y, 2);
	return ds;
}

bool::Soldier2::move_decision(int x, int y) {
	if (initial_y < 5) {
		if (distance_squared(x, y) == squared_distance &&
			((y < initial_y && x == initial_x) || (y == initial_y && x != initial_x))) {
			return true;
		}
		else { return false; }
	}
	else {
		if (distance_squared(x, y) == squared_distance && y < initial_y && x == initial_x) { return true; }
		else { return false; }
	}
}
