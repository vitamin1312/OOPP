#include "pch.h"
#include "NegrobovSSS.h"


bool NegrobovSSS::to_file(CArchive& ar) {


	ar << (int)members.size();

	std::for_each(members.begin(), members.end(),	[&](auto member) {
		ar << &member;});
	return true;
}


bool NegrobovSSS::from_file(CArchive& ar) {

	members.clear();

	int size = 0;
	ar >> size;

	for (int i = 0; i < size; i++) {
		NegrobovSSSMember* p_member;
		ar >> p_member;
		members.push_back(std::shared_ptr<NegrobovSSSMember>(p_member));
	}
	return true;
}


void draw_column_names(CDC* pDC, std::vector<CString> column_names, std::vector<int> x_coordinates, int top) {
	for (int i = 0; i < column_names.size(); ++i)
	    pDC->TextOut(x_coordinates[i], top, column_names[i]);
}


CSize NegrobovSSS::draw_members(CDC* pDC) {

	std::vector<CString> column_names = {
		_T("Name"),
		_T("Group"),
		_T("Rate"),
		_T("Experience")
	};

	int x_padding = 20;
	int y_height = 20;
	int top = 0;
	std::vector<int> coordinates = get_x_coordinates(pDC, x_padding, column_names);

	draw_column_names(pDC, column_names, coordinates, top);


	std::for_each(members.begin(), members.end(),
		std::bind(&NegrobovSSSMember::draw, std::placeholders::_1, pDC, coordinates, std::ref(top), y_height));

	POINT total_size;
	total_size.x = coordinates[coordinates.size() - 1];
	total_size.y = top + y_height;
	return total_size;
}


std::vector<int> NegrobovSSS::get_max_extents(CDC* pDC, std::vector<CString> column_names) {

	std::vector<int> max_extents;

	std::for_each(column_names.cbegin(), column_names.cend(), [&](CString column_name) {
		max_extents.push_back(pDC->GetTextExtent(column_name).cx); });

	for (auto& member : members) {
		std::vector<int> member_extents = member->get_extents(pDC, column_names.size());
		for (int i = 0; i < column_names.size(); ++i)
			max_extents[i] = max(max_extents[i], member_extents[i]);
	}

	return max_extents;
}


std::vector<int> NegrobovSSS::get_x_coordinates(CDC* pDC, int x_padding, std::vector<CString> column_names) {
	std::vector<int> x_coordinates;
	std::vector<int> max_extents = get_max_extents(pDC, column_names);

	x_coordinates.push_back(x_padding);

	for (int i = 0; i < max_extents.size(); ++i) 
		x_coordinates.push_back(max_extents[i] + x_coordinates[i] + x_padding);

	return x_coordinates;
}


void NegrobovSSS::clear() {
	members.clear();
}
