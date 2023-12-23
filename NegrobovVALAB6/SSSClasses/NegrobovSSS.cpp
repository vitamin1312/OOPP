#include "pch.h"
#include "NegrobovSSS.h"

void NegrobovSSS::add_member(std::shared_ptr<NegrobovSSSMember> p_member) {

	members.push_back(p_member);
}


bool NegrobovSSS::to_file(CArchive& ar) {


	ar << (int)members.size();
	for (auto& member : members) {
		ar << member.get();
	}
	return true;
}


bool NegrobovSSS::from_file(CArchive& ar) {

	members.clear();


	int size = 0;
	ar >> size;

	for (int i = 0; i < size; i++) {
		NegrobovSSSMember* p_member;
		ar >> p_member;
		members.push_back(std::shared_ptr<NegrobovSSSMember>(p_member));
	}
	return true;
}


std::shared_ptr<NegrobovSSSMember> NegrobovSSS::get(int i) {
	return members[i];
}


void NegrobovSSS::delete_member(int idx) {
	members.erase(members.begin() + idx, members.begin() + idx + 1);
}


int NegrobovSSS::get_size() {
	return (int)members.size();
}
