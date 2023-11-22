#pragma once

#include "pch.h"


class NegrobovSSSMember : public CObject
{
private:
	CString name = _T("");
	CString group = _T("");
	unsigned int rate = 0;

public:
	DECLARE_SERIAL(NegrobovSSSMember)

	NegrobovSSSMember() {};

	virtual ~NegrobovSSSMember() = default;

	virtual std::vector<int> get_extents(CDC* pDC, int num);

	virtual void draw(CDC* pDC, std::vector<int> x_coordinates, int& top, int y_height);

	virtual void Serialize(CArchive& ar);

	CString get_name();

	CString get_group();

	unsigned int get_rate();
};
