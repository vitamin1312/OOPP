#include "pch.h"
#include "utils.h"

CString to_cstring(int num) {
	CString str_num;
	str_num.Format(_T("%d"), num);
	return str_num;
}
