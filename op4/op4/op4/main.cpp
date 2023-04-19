#include <iostream>
#include <cmath>

class BoolVector {
private:
    bool* data_;
    size_t size_;

public:
    BoolVector() : data_(nullptr), size_(0) {}
    BoolVector(size_t size) : data_(new bool[size]), size_(size) {}
    BoolVector(const BoolVector& other) : data_(new bool[other.size_]), size_(other.size_) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    ~BoolVector() {
        delete[] data_;
    }

    bool operator[](size_t index) const {
        return data_[index];
    }
    bool& operator[](size_t index) {
        return data_[index];
    }
    BoolVector operator|(const BoolVector& other) const {
        if (size_ != other.size_) {
            throw std::invalid_argument("Vectors must have the same size");
        }
        BoolVector result(size_);
        for (size_t i = 0; i < size_; ++i) {
            result[i] = data_[i] || other[i];
        }
        return result;
    }
    BoolVector operator^(const BoolVector& other) const {
        if (size_ != other.size_) {
            throw std::invalid_argument("Vectors must have the same size");
        }
        BoolVector result(size_);
        for (size_t i = 0; i < size_; ++i) {
            result[i] = data_[i] != other[i];
        }
        return result;
    }

    bool is_predecessor(const BoolVector& other) const {
        if (size_ != other.size_) {
            return false;
        }
        for (size_t i = 0; i < size_; ++i) {
            if (data_[i] > other[i]) {
                return false;
            }
        }
        return true;
    }

    size_t size() const {
        return size_;
    }
};

int main() {
    BoolVector v1(4);
    v1[0] = false;
    v1[1] = true;
    v1[2] = true;
    v1[3] = false;

    BoolVector v2 = ( true, true, false, false );

    BoolVector v3 = v1 | v2;

    BoolVector v4 = v3 ^ v1;

    std::cout << v4.is_predecessor(v3) << std::endl; // Output: 1

    return 0;
}
