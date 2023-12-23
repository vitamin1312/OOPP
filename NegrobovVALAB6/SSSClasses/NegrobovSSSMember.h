#pragma once

#include "pch.h"
#include "class_info.h"


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
	virtual void to_class_info(class_info& ci);
	virtual void from_class_info(class_info& ci);
	virtual void Serialize(CArchive& ar);
};
