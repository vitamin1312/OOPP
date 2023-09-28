#pragma once

#include "pch.h"


class NegrobovSSSMember: public CObject
{
private:
	CString name;
	CString group;
	unsigned int rate;

public:
	DECLARE_SERIAL(NegrobovSSSMember)
	NegrobovSSSMember() {};
	virtual ~NegrobovSSSMember() = default;
	virtual void input();
	virtual void output();
	virtual void Serialize(CArchive& ar);
};

