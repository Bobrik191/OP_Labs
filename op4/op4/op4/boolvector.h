#pragma once
#include <iostream>

using namespace std;

class BoolVector
{
private:
	bool X;
	bool Y;
	bool Z;
	bool cordinates[3];

public:
	BoolVector();
	BoolVector(bool, bool, bool);
	bool is_predecessor(BoolVector& other);
	void setXYZ(bool, bool, bool);
	void setCord();
	void printCord();
	BoolVector operator|(BoolVector&);
	BoolVector operator^(BoolVector&);
	~BoolVector();
};

