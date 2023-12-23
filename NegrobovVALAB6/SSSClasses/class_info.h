#pragma once

#include "pch.h"

struct class_info {
	byte is_base_class;
	char name[50];
	char group[50];
	unsigned int rate;
	unsigned int experience;
};
