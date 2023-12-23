// SSSClasses.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "SSSClasses.h"
#include "NegrobovSSS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CSSSClassesApp

BEGIN_MESSAGE_MAP(CSSSClassesApp, CWinApp)
END_MESSAGE_MAP()


// CSSSClassesApp construction

CSSSClassesApp::CSSSClassesApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CSSSClassesApp object

CSSSClassesApp theApp;


// CSSSClassesApp initialization

BOOL CSSSClassesApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

NegrobovSSS sss;

extern "C" {
	__declspec(dllexport) void __stdcall GetClassInfo_(class_info& ci, int i)
	{
		sss.get(i)->to_class_info(ci);
	}

	__declspec(dllexport) void __stdcall SetClassInfo(class_info& ci, int i)
	{
		sss.get(i)->from_class_info(ci);
	}

	__declspec(dllexport) int __stdcall GetSssSize()
	{
		return sss.get_size();
	}

	__declspec(dllexport) void __stdcall Erase(int i)
	{
		sss.delete_member(i);
	}

	__declspec(dllexport) void __stdcall AddMember()
	{
		sss.add_member(std::make_shared<NegrobovSSSMember>());
	}

	__declspec(dllexport) void __stdcall AddPresident()
	{
		sss.add_member(std::make_shared<NegrobovSSSPresident>());
	}

	__declspec(dllexport) void __stdcall GetFromFile(char* fileName)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		CFile f;
		if (!f.Open(fileName, CFile::modeRead))
			return;
		CArchive ar(&f, CArchive::load);
		sss.from_file(ar);
	}

	__declspec(dllexport) void __stdcall LoadToFile(char* fileName)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		CFile f;
		if (!f.Open(fileName, CFile::modeCreate | CFile::modeWrite))
			return;
		CArchive ar(&f, CArchive::store);
		sss.to_file(ar);
	}
}
