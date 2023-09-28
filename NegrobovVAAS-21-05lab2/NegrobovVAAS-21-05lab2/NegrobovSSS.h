#pragma once

#include "NegrobovSSSMember.h"
#include "NegrobovSSSPresident.h"


class NegrobovSSS
{

private:
	std::vector<std::shared_ptr<NegrobovSSSMember>> members;
public:
	bool to_file(std::string file_name);
	bool from_file(std::string file_name);
	void clear();
	void add_member();
	void add_president();

	friend std::ostream& operator << (std::ostream& out, const NegrobovSSS& sss);
};
