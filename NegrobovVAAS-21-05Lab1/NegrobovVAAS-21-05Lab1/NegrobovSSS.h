#pragma once

#include <vector>
#include "NegrobovSSSMember.h"


class NegrobovSSS
{

private:
	std::vector <NegrobovSSSMember*> members;
public:
	void add_member();
	bool to_file(std::string file_name);
	bool from_file(std::string file_name);
	void clear();

	friend std::ostream& operator << (std::ostream& out, const NegrobovSSS& sss);
};

