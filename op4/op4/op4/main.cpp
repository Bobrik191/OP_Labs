#include "boolvector.h"

int main() {

	BoolVector vec1;
	//BoolVector vec2 = { true, false, true, false, false, true };
	BoolVector vec2 = { true, false, true, true, true, false};

	// Простое заполнение первого вектора чередованием.
	for (size_t i = 0; i < vec2.size(); i++) {
		if (i % 2 == 0) {
			vec1.append(false);
		}
		else {
			vec1.append(true);
		}
	}

	std::cout << "Vector1: ";
	std::cout << vec1 << std::endl;
	std::cout << "Vector2: ";
	std::cout << vec2 << std::endl;

	BoolVector vec3(vec1 | vec2);

	std::cout << "V1 | V2: ";
	std::cout << vec3 << std::endl;
	BoolVector vec4(vec3 ^ vec1);
	std::cout << "V3 ^ V1: ";
	std::cout << vec4 << std::endl;
	std::cout << "Vec4 is precursor of Vec3? " << vec4.is_precursor(vec3) << std::endl;


	return 0;
}