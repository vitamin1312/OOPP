#pragma once

#include "pch.h"


class NegrobovSSSMember : public CObject
{
private:
	CString name = _T("null");
	CString group = _T("null");
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

	void set_name(CString name);

	void set_group(CString group);

	void set_rate(unsigned int rate);
};
