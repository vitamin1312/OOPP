// NegrobovVAAS-21-05lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "NegrobovVAAS-21-05lab2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#include <iostream>
#include "NegrobovSSS.h"
#include "utils.h"

void do_command(int choice, NegrobovSSS& sss);


// The one and only application object

CWinApp theApp;


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	NegrobovSSS sss;
	int choice;

	while (true) {

		std::cout << "1: add member" << std::endl
			<< "2: add president" << std::endl
			<< "3: print members" << std::endl
			<< "4: get members from file" << std::endl
			<< "5: write members to file" << std::endl
			<< "6: clear all members" << std::endl
			<< "0: exit" << std::endl;

		std::cout << "-> ";

		choice = get_num_value(0, 6);
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
	else if (choice == 2) {
		sss.add_president();
		std::cout << "President was added" << std::endl;
	}
	else if (choice == 3)
		std::cout << sss;
	else if (choice == 4) {
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

	else if (choice == 5) {

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

	else if (choice == 6) {
		sss.clear();
		std::cout << "Members was deleted form sss" << std::endl;
	}
}

