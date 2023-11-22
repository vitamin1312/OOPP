#pragma once

#include "NegrobovSSSMember.h"

class NegrobovSSSPresident : public NegrobovSSSMember
{
private:
	unsigned int experience = 0;
public:

	DECLARE_SERIAL(NegrobovSSSPresident)

	NegrobovSSSPresident() {};

	virtual ~NegrobovSSSPresident() = default;

	std::vector<int> get_extents(CDC* pDC, int num);

	void draw(CDC* pDC, std::vector<int> x_coordinates, int& top, int y_height);

	void Serialize(CArchive& ar) override;

	unsigned int get_experience();

	void set_experience(unsigned int experience);
};
