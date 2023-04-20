#include "boolvector.h"


BoolVector::BoolVector() : _size(0), _capacity(1), memory(new bool[_capacity]) {}
BoolVector::BoolVector(size_t size) : _size(size), _capacity(size * 2), memory(new bool[size]) {}

// Конструктор копирования.
BoolVector::BoolVector(const BoolVector& vector) : _size(vector._size), _capacity(vector._capacity) {
	memory = new bool[_size];

	for (size_t i = 0; i < _size; i++) {
		memory[i] = vector.memory[i];
	}
}

// Конструктор со списком инициализации.
BoolVector::BoolVector(std::initializer_list<bool> list) {
	_size = list.size();
	_capacity = _size * 2;
	memory = new bool[_size];

	size_t index = 0;
	for (auto flag : list) {
		memory[index++] = flag;
	}
}

size_t BoolVector::size() const {
	return _size;
}

size_t BoolVector::capacity() const {
	return _capacity;
}

void BoolVector::append(bool value) {
	if (_size >= _capacity) resize();

	memory[_size++] = value;
}

bool BoolVector::is_precursor(const BoolVector& vector) {
	for (size_t i = 0; i < _size; i++) {
		if (memory[i] > vector.memory[i]) return false;
	}

	return true;
}

void BoolVector::fill_zeroes(size_t diff) {
	for (size_t i = 0; i < diff; i++) {
		append(false);
	}
}

bool& BoolVector::operator[](const int index) const {
	return memory[index];
}

std::ostream& operator<<(std::ostream& out, const BoolVector& vec) {
	out << "{ ";
	for (size_t i = 0; i < vec.size(); i++) {
		i != vec.size() - 1 ? out << vec[i] << ", " : out << vec[i] << " }";
	}

	return out;
}

BoolVector operator|(BoolVector& vector1, BoolVector& vector2) {

	BoolVector result;

	if (vector1.size() > vector2.size()) {
		vector2.fill_zeroes(vector1.size() - vector2.size());
	}
	else {
		vector1.fill_zeroes(vector2.size() - vector1.size());
	}

	for (size_t i = 0; i < vector1.size(); i++) {
		if (vector1[i] != vector2[i]) {
			result.append(vector1[i] + vector2[i]);
		}
		else {
			result.append(vector1[i]);
		}
	}

	return result;
}

BoolVector operator^(BoolVector& vector1, BoolVector& vector2) {
	BoolVector result;

	if (vector1.size() > vector2.size()) {
		vector2.fill_zeroes(vector1.size() - vector2.size());
	}
	else {
		vector1.fill_zeroes(vector2.size() - vector1.size());
	}

	for (size_t i = 0; i < vector1.size(); i++) {
		if (vector1[i] == vector2[i]) {
			result.append(false);
		}
		else {
			result.append(true);
		}
	}

	return result;
}

BoolVector::~BoolVector()
{
	delete[] memory;
}