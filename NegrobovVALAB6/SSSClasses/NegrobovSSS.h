#pragma once

#include "NegrobovSSSMember.h"
#include "NegrobovSSSPresident.h"


class NegrobovSSS
{

private:
	std::vector<std::shared_ptr<NegrobovSSSMember>> members;
public:
	bool to_file(CArchive& ar);
	bool from_file(CArchive& ar);
	void delete_member(int idx);
	int get_size();
	void add_member(std::shared_ptr<NegrobovSSSMember> p_member);
	std::shared_ptr<NegrobovSSSMember> get(int i);
};