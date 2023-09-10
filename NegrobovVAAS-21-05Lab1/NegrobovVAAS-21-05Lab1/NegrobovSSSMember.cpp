#include "NegrobovSSSMember.h"
#include "utils.h"

#define min_rate 0
#define max_rate 100


std::istream& operator >> (std::istream& in, NegrobovSSSMember& member) {

	std::cout << "Input members name: ";
	std::cin >> member.name;
	std::cout << "Input members group: ";
	std::cin >> member.group;
	std::cout << "Input members rate (min: 0; max: 100): ";
	member.rate = get_num_value(min_rate, max_rate);

	return in;
}

std::ostream& operator << (std::ostream& out, const NegrobovSSSMember& member) {

	std::cout << "=======================================" << std::endl
			  << "Members name: " << member.name << std::endl
			  << "Members group: " << member.group << std::endl
			  << "Members rate: " << member.rate << std::endl
			  << "=======================================" << std::endl;

	return out;
}

std::ifstream& operator >> (std::ifstream& fin, NegrobovSSSMember& member) {
	fin >> member.name
	   >> member.group
	   >> member.rate;

	return fin;
}

std::ofstream& operator << (std::ofstream& fout, const NegrobovSSSMember& member) {
	fout << member.name << std::endl
		<< member.group << std::endl
		<< member.rate << std::endl;

	return fout;
}