#include "MyRecordSet.h"


CMyRecordSet::CMyRecordSet(int n_fields, CDatabase* pDatabase) :CRecordset(pDatabase)
{
	m_nFields = n_fields;
}

void CMyRecordSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[P_ID]"), m_P_ID);
	RFX_Text(pFX, _T("[REG_ID]"), m_RID);
	RFX_Text(pFX, _T("[FN]"), m_FN);
	RFX_Text(pFX, _T("[LN]"), m_LN);
	RFX_Text(pFX, _T("[CN]"), m_CN);
	RFX_Text(pFX, _T("[EA]"), m_EA);
	RFX_Text(pFX, _T("[STRT]"), m_STRT);
	RFX_Text(pFX, _T("[CITY]"), m_CT);
	RFX_Text(pFX, _T("[ST]"), m_ST);
	RFX_Text(pFX, _T("[NTN]"), m_NTN);
	RFX_Text(pFX, _T("[ZC]"), m_ZC);
	

}

