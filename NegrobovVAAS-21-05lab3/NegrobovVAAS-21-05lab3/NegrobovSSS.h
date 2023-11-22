#pragma once

#include "NegrobovSSSMember.h"
#include "NegrobovSSSPresident.h"


class NegrobovSSS
{

public:
	std::vector<std::shared_ptr<NegrobovSSSMember>> members;

	bool to_file(CArchive& ar);

	bool from_file(CArchive& ar);

	CSize draw_members(CDC* pDC);

	std::vector<int> get_max_extents(CDC* pDC, std::vector<CString> column_names);

	std::vector<int> get_x_coordinates(CDC* pDC, int x_padding, std::vector<CString> column_names);

	void clear();

	void delete_member(int idx);

	void to_CLBMembers(CListBox& CLBMembers);

	size_t get_size();
};

