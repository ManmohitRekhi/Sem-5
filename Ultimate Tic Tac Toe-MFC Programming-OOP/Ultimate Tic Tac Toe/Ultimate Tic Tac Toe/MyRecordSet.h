#pragma once
#include "afxwin.h"
#include "afxdb.h"

class CMyRecordSet :
	public CRecordset
{
public:
	public:
	CString m_P_ID, m_FN, m_LN, m_CN, m_NTN, m_CT, m_STRT , m_ST, m_ZC,m_RID,m_EA;
	CMyRecordSet(int n_fields, CDatabase* pDatabase = NULL);
	virtual void DoFieldExchange(CFieldExchange* pFX);
};

