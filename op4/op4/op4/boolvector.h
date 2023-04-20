#pragma once
#include <iostream>
class BoolVector
{
private:
	size_t _size;
	size_t _capacity;
	bool* memory;

	void resize() {
		bool* temp = memory;
		size_t capacity = _capacity;
		_capacity *= 2;
		memory = new bool[_capacity];

		for (size_t i = 0; i < capacity; i++) {
			memory[i] = temp[i];
		}

		delete[] temp;
	}
public:
	BoolVector();
	BoolVector(size_t size);
	BoolVector(const BoolVector& vector);
	~BoolVector();
	BoolVector(std::initializer_list<bool> list);
	size_t size() const;
	size_t capacity() const;
	void append(bool value);
	bool is_precursor(const BoolVector& vector);
	void fill_zeroes(size_t diff);
	bool& operator[](const int index) const;
	friend std::ostream& operator<<(std::ostream& out, const BoolVector& vec);
	friend BoolVector operator|(BoolVector& vector1, BoolVector& vector2);
	friend BoolVector operator^(BoolVector& vector1, BoolVector& vector2);

};

