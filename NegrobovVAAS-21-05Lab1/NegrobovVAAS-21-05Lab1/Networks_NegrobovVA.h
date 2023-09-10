#pragma once

#include <string>
#include <iostream>#include fstream

class Networks_NegrobovVA
{
	private:
		std::string name;
		std::string task;
		unsigned int num_params;
	public:
		friend std::istream& operator >> (std::istream& in, Networks_NegrobovVA& nw);
		friend std::ostream& operator << (std::ostream& out, const Networks_NegrobovVA& nw);
		friend std::ifstream& operator >> (std::ifstream& fin, Networks_NegrobovVA& nw);
		friend std::ofstream& operator << (std::ofstream& fout, const Networks_NegrobovVA& nw);

};

