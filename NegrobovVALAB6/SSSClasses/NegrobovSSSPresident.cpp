#include "pch.h"
#include "NegrobovSSSPresident.h"

const int min_experience = 0;
const int max_experience = 10;

IMPLEMENT_SERIAL(NegrobovSSSPresident, NegrobovSSSMember, VERSIONABLE_SCHEMA | 0)


void NegrobovSSSPresident::Serialize(CArchive& ar) {

    NegrobovSSSMember::Serialize(ar);

    if (ar.IsStoring()) {
        ar << experience;
    }
    else {
        ar >> experience;
    }
}

void NegrobovSSSPresident::to_class_info(class_info& ci) {
    NegrobovSSSMember::to_class_info(ci);
    ci.is_base_class = 0;
    ci.experience = experience;
}

void  NegrobovSSSPresident::from_class_info(class_info& ci) {

    NegrobovSSSMember::from_class_info(ci);
    experience = ci.experience;
}
