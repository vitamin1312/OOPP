#include <iostream>
#include "NegrobovSSS.h"
#include "utils.h"

void do_command(int choice, NegrobovSSS &sss);

int main() {
	NegrobovSSS sss;
	int choice;

	while (true) {

		std::cout << "1: add member" << std::endl
				  << "2: print members" << std::endl
				  << "3: get members from file" << std::endl
				  << "4: write members to file" << std::endl
				  << "5: clear all members" << std::endl
			      << "0: exit" << std::endl;
		          
		std::cout << "-> ";

		choice = get_num_value(1, 5);
		if (choice == 0) break;
		else do_command(choice, sss);
	}

	return 0;
}


void do_command(int choice, NegrobovSSS& sss) {
	if (choice == 1) {
		sss.add_member();
		std::cout << "Member was added" << std::endl;
	}
	else if (choice == 2)
		std::cout << sss;
	else if (choice == 3) {
		std::string file_name;
		std::cout << "Input file name: ";
		std::cin >> file_name;

		if (sss.from_file(file_name))
			std::cout << "Members was loaded from "
			<< file_name << " file" << std::endl;
		else
			std::cout << "failed to load members from "
			<< file_name << " file" << std::endl;
	}

	else if (choice == 4) {

		std::string file_name;
		std::cout << "Input file name: ";
		std::cin >> file_name;

		if (sss.to_file(file_name))
			std::cout << "Members was written to "
			<< file_name << " file" << std::endl;
		else
			std::cout << "failed to write members to "
			<< file_name << " file" << std::endl;
	}

	else if (choice == 5) {
		sss.clear();
		std::cout << "Members was deleted form sss" << std::endl;
	}
}
