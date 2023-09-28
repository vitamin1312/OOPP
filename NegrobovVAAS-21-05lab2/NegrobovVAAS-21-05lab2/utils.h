#pragma once


template <typename T>
T get_num_value(T least, T great) {
	T val = 0;
	while (true) {
		if (std::cin >> val && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (val >= least) && (val <= great)) return val;
		else {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Please, input correct value: ";
		}
	}
}
