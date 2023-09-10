#pragma once

#include <string>
#include <iostream>
#include <fstream>


class NegrobovSSSMember
{
private:
	std::string name;
	std::string group;
	unsigned int rate;

public:
	friend std::istream& operator >> (std::istream& in, NegrobovSSSMember& member);
	friend std::ostream& operator << (std::ostream& out, const NegrobovSSSMember& member);
	friend std::ifstream& operator >> (std::ifstream& fin, NegrobovSSSMember& member);
	friend std::ofstream& operator << (std::ofstream& fout, const NegrobovSSSMember& member);

};

