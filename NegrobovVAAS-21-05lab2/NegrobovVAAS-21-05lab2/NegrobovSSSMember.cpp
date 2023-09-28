#include "pch.h"
#include "NegrobovSSSMember.h"

const int min_rate = 0;
const int max_rate = 100;

IMPLEMENT_SERIAL(NegrobovSSSMember, CObject, 0)

void NegrobovSSSMember::input() {

	std::string inp_name, inp_group;

	std::cout << "Input name: ";
	std::cin.ignore();
	std::getline(std::cin, inp_name);
	name = inp_name.c_str();
	std::cout << "Input group: ";
	std::getline(std::cin, inp_group);
	group = inp_group.c_str();
	std::cout << "Input rate(min: 0; max: 100) : ";
	rate = get_num_value(min_rate, max_rate);
}

void NegrobovSSSMember::output() {

	std::cout << "=======================================" << std::endl
		<< "Name: " << name << std::endl
		<< "Group: " << group << std::endl
		<< "Rate: " << rate << std::endl
		<< "=======================================" << std::endl;
}

void NegrobovSSSMember::Serialize(CArchive& ar) {

	if (ar.IsStoring()) {
		ar << name
		   << group
		   << rate;
	}
	else {
		ar >> name
		   >> group
		   >> rate;

	}
}
