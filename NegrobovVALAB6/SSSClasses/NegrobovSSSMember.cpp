#include "pch.h"
#include "NegrobovSSSMember.h"

const int min_rate = 0;
const int max_rate = 100;

IMPLEMENT_SERIAL(NegrobovSSSMember, CObject, 0)

void NegrobovSSSMember::to_class_info(class_info& ci) {
	strcpy_s(ci.name, CStringA(name).GetString());
	strcpy_s(ci.group, CStringA(group).GetString());
	ci.rate = rate;
	ci.is_base_class = 1;
}

void NegrobovSSSMember::from_class_info(class_info& ci) {
	name = ci.name;
	group = ci.group;
	rate = ci.rate;
}

void NegrobovSSSMember::Serialize(CArchive& ar) {

	if (ar.IsStoring()) {
		ar << name
			<< group
			<< rate;
	}
	else {
		ar >> name
			>> group
			>> rate;

	}
}
