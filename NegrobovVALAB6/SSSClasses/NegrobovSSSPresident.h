#pragma once

#include "NegrobovSSSMember.h"
#include "class_info.h"

class NegrobovSSSPresident : public NegrobovSSSMember
{
private:
	unsigned int experience = 0;
public:
	DECLARE_SERIAL(NegrobovSSSPresident)
	NegrobovSSSPresident() {};
	virtual ~NegrobovSSSPresident() = default;
	void to_class_info(class_info& ci);
	void from_class_info(class_info& ci);
	void Serialize(CArchive& ar) override;
};
