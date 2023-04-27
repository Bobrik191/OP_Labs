#include "boolvector.h"

BoolVector::BoolVector() {
	this->X;
	this->Y;
	this->Z;
}

BoolVector::BoolVector(bool v1, bool v2, bool v3) {
	this->X = v1;
	this->Y = v2;
	this->Z = v3;

	this->cordinates[0] = X;
	this->cordinates[1] = Y;
	this->cordinates[2] = Z;
}

BoolVector BoolVector::operator|(BoolVector& other) {
	BoolVector temp;

	temp.cordinates[0] = this->cordinates[0] || other.cordinates[0];
	temp.cordinates[1] = this->cordinates[1] || other.cordinates[1];
	temp.cordinates[2] = this->cordinates[2] || other.cordinates[2];

	temp.X = cordinates[0];
	temp.Y = cordinates[1];
	temp.Z = cordinates[2];
	
	return temp;
}

BoolVector BoolVector::operator^(BoolVector& other) {
	BoolVector temp;

	temp.cordinates[0] = (this->cordinates[0] || other.cordinates[0]) && !(this->cordinates[0] && other.cordinates[0]);
	temp.cordinates[1] = (this->cordinates[1] || other.cordinates[1]) && !(this->cordinates[1] && other.cordinates[1]);
	temp.cordinates[2] = (this->cordinates[2] || other.cordinates[2]) && !(this->cordinates[2] && other.cordinates[2]);

	temp.X = cordinates[0];
	temp.Y = cordinates[1];
	temp.Z = cordinates[2];

	return temp;
}

void BoolVector::setXYZ(bool value1, bool value2, bool value3) {
	this->X = value1;
	this->Y = value2;
	this->Z = value3;
	setCord();
}


void BoolVector::setCord() {
	this->cordinates[0] = X;
	this->cordinates[1] = Y;
	this->cordinates[2] = Z;
}

bool BoolVector::is_predecessor(BoolVector& other) {
	if (this->cordinates[0] >= other.cordinates[0] || this->cordinates[1] >= other.cordinates[1] || this->cordinates[2] >= other.cordinates[2]) {
		return false;
	}
	return true;
}

void BoolVector::printCord() {
	cout << "(" << cordinates[0] << ";" << cordinates[1] << ";" << cordinates[2] << ")" << endl;
}

BoolVector::~BoolVector() {}