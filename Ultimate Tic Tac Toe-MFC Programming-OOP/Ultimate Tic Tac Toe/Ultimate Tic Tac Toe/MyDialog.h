#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "afxdb.h"
#include "odbcinst.h"
#include "resource.h"
#include "MyRecordSet.h"

class CMyDialog :
	public CDialog
{
public:
	CMyDialog(LPCTSTR DialogName, CWnd* Owner):CDialog(DialogName, Owner){};
	BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnCustAdd();
	DECLARE_MESSAGE_MAP()
private:
	CDatabase database;
	CString sDriver;
	CString sFile;
	CString sDsn;
	int rec_index;
	//CString m_custid, m_custname;
	CEdit *p_id, *reg_id,*cust_fn, *cust_ln, *cust_cn, *cust_em,*cust_st,*cust_ct,*cust_zc,*cust_ntn,*cust_strt;
};

