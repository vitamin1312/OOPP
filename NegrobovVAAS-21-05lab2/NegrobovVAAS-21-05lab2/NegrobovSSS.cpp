#include "pch.h"
#include "NegrobovSSS.h"

void NegrobovSSS::add_member() {

	std::shared_ptr<NegrobovSSSMember> p_member = std::make_shared<NegrobovSSSMember>();
	p_member->input();
	members.push_back(p_member);
}


void NegrobovSSS::add_president() {

	std::shared_ptr<NegrobovSSSMember> p_member = std::make_shared<NegrobovSSSPresident>();
	p_member->input();
	members.push_back(p_member);
}


std::ostream& operator << (std::ostream& out, const NegrobovSSS& sss) {
	if (sss.members.size() == 0)
		std::cout << "There are no members in sss" << std::endl;
	else {
		for (auto &p_member : sss.members)
			p_member.get()->output();
	}

	return out;
}


bool NegrobovSSS::to_file(std::string file_name) {

	CFile f(file_name.c_str(), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&f, CArchive::store);

	ar << (int)members.size();
	for (auto &member : members) {
		ar << member.get();
	}
	return true;
}


bool NegrobovSSS::from_file(std::string file_name) {

	members.clear();

	CFile f(file_name.c_str(), CFile::modeRead);
	CArchive ar(&f, CArchive::load);

	int size = 0;
	ar >> size;

	for (int i = 0; i < size; i++) {
		NegrobovSSSMember* p_member;
		ar >> p_member;
		members.push_back(std::shared_ptr<NegrobovSSSMember>(p_member));
	}
	return true;
}


void NegrobovSSS::clear() {
	members.clear();
}