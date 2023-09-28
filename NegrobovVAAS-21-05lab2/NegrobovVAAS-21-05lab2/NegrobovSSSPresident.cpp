#include "pch.h"
#include "NegrobovSSSPresident.h"

const int min_experience = 0;
const int max_experience = 10;

IMPLEMENT_SERIAL(NegrobovSSSPresident, NegrobovSSSMember, VERSIONABLE_SCHEMA | 0)

void NegrobovSSSPresident::input() {

    NegrobovSSSMember::input();
    std::cout << "Input experience(min: 0; max: 10): ";
    experience = get_num_value(0, 10);
}


void NegrobovSSSPresident::output() {
    std::cout << "=======================================" << std::endl;
    std::cout << "President" << std::endl;
    NegrobovSSSMember::output();
    std::cout << "Experience: "
        << experience << std::endl
        << "=======================================" << std::endl;
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
