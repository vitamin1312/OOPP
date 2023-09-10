#include "NegrobovSSS.h"

void NegrobovSSS::add_member() {

	NegrobovSSSMember* p_member = new NegrobovSSSMember();
	std::cin>>*p_member;
	members.push_back(p_member);
}


std::ostream& operator << (std::ostream& out, const NegrobovSSS& sss) {
	if (sss.members.size() == 0)
		std::cout << "There are no members in sss" << std::endl;
	else {
		for (auto p_member : sss.members)
			std::cout << *p_member;
	}

	return out;
}


bool NegrobovSSS::to_file(std::string file_name) {
	std::ofstream fout(file_name);
	if (members.size() == 0) {
		std::cout << "There are no members in sss!" << std::endl;
		return false;
	}
	else if (fout.is_open()) {
		fout << members.size() << std::endl;
		for (auto p_member : members)
			fout << *p_member;
		return true;
	}
	else
		return false;
}


bool NegrobovSSS::from_file(std::string file_name) {

	std::ifstream fin(file_name);
	if (fin.is_open()) {

		int num;
		fin >> num;

		for (int i = 0; i < num; i++) {
			NegrobovSSSMember* p_member = new NegrobovSSSMember();
			fin >> *p_member;
			members.push_back(p_member);
		}

		return true;
	}
	return false;
}


void NegrobovSSS::clear() {
	for (auto p_member : members)
		delete p_member;
	members.clear();
}