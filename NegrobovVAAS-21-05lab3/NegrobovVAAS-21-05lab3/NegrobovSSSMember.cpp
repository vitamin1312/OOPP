#include "pch.h"
#include "NegrobovSSSMember.h"

const int min_rate = 0;
const int max_rate = 100;

IMPLEMENT_SERIAL(NegrobovSSSMember, CObject, 0)

std::vector<int> NegrobovSSSMember::get_extents(CDC* pDC,int num) {

	std::vector<int> extents(num, 0);
	extents[0] = pDC->GetTextExtent(name).cx;
	extents[1] = pDC->GetTextExtent(group).cx;

	extents[2] = pDC->GetTextExtent(to_cstring(rate)).cx;

	return extents;
}


void NegrobovSSSMember::draw(CDC* pDC, std::vector<int> x_coordinates, int& top, int y_height) {

	top += y_height;
	pDC->TextOut(x_coordinates[0], top, name);
	pDC->TextOut(x_coordinates[1], top, group);
	pDC->TextOut(x_coordinates[2], top, to_cstring(rate));
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


CString NegrobovSSSMember::get_name() {
	return name;
}

CString NegrobovSSSMember::get_group() {
	return group;
}

unsigned int NegrobovSSSMember::get_rate() {
	return rate;
}