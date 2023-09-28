#pragma once

#include "NegrobovSSSMember.h"

class NegrobovSSSPresident: public NegrobovSSSMember
{
private:
	unsigned int experience;
public:
	DECLARE_SERIAL(NegrobovSSSPresident)
	NegrobovSSSPresident() {};
	virtual ~NegrobovSSSPresident() = default;
	void input() override;
	void output() override;
	void Serialize(CArchive& ar) override;
};

