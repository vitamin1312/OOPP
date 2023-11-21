#include "pch.h"
#include "NegrobovSSSPresident.h"

const int min_experience = 0;
const int max_experience = 10;

IMPLEMENT_SERIAL(NegrobovSSSPresident, NegrobovSSSMember, VERSIONABLE_SCHEMA | 0)


std::vector<int> NegrobovSSSPresident::get_extents(CDC* pDC, int num) {
    std::vector<int> extents = NegrobovSSSMember::get_extents(pDC, num);
    extents[3] = pDC->GetTextExtent(to_cstring(experience)).cx;
    return extents;
}

void NegrobovSSSPresident::draw(CDC* pDC, std::vector<int> x_coordinates, int& top, int y_height) {
    NegrobovSSSMember::draw(pDC, x_coordinates, top, y_height);
    pDC->TextOut(x_coordinates[3], top, to_cstring(experience));
}


void NegrobovSSSPresident::Serialize(CArchive& ar) {

    NegrobovSSSMember::Serialize(ar);

    if (ar.IsStoring()) {
        ar << experience;
    }
    else {
        ar >> experience;
    }

}