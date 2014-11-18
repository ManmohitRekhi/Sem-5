#include "MyDialog.h"


BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	sDriver = "MICROSOFT ACCESS DRIVER (*.mdb)";
	sFile = "C:\\Users\\Dell\\Documents\\Visual Studio 2012\\Projects\\Ultimate Tic Tac Toe\\Ultimate Tic Tac Toe\\cust_database1.mdb";
	sDsn.Format(_T("ODBC;DRIVER={%s};DSN='';DBQ=%s"), sDriver, sFile);
	TRY
	{
		// Open the database
		database.Open(NULL, false, false, sDsn);
	}
	CATCH(CDBException, e)
	{
		// If a database exception occured, show error msg
		AfxMessageBox("Database error: " + e->m_strError);
	}
	END_CATCH;
	p_id = (CEdit *)GetDlgItem(IDC_PID);
	cust_fn = (CEdit *)GetDlgItem(IDC_FN);
	cust_ln = (CEdit *)GetDlgItem(IDC_LN);
	cust_cn = (CEdit *)GetDlgItem(IDC_CN);
	cust_em = (CEdit *)GetDlgItem(IDC_EM);
	cust_ntn = (CEdit *)GetDlgItem(IDC_NT);
	cust_st = (CEdit *)GetDlgItem(IDC_STRT);
	cust_zc = (CEdit *)GetDlgItem(IDC_ZC);
	cust_ct = (CEdit *)GetDlgItem(IDC_CT);
	rec_index = 1;

	return TRUE;
}

afx_msg void CMyDialog::OnClose()
{
	MessageBox("YOU WILL RECIEVE INFORMATION ABOUT THE FULL VERSION SHORTLY!!", "NOTICE");
	EndDialog(0);
}
afx_msg void CMyDialog::OnCustAdd()
{
	
	CString SqlString;
	CMyRecordSet recset(11, &database);
	CString var_id, var_fname, var_lname, var_cno, var_eid, var_nation, var_pid, var_regid, var_ct,var_st,var_zc,var_strt;

	SqlString = "SELECT * FROM Customer_data";
	recset.Open(CRecordset::dynaset, SqlString, CRecordset::none);

	recset.SetAbsolutePosition(rec_index);
	if (recset.CanAppend())
	{
		recset.AddNew();
		p_id->GetWindowText(var_id);
		recset.m_P_ID = var_id;
		cust_fn->GetWindowText(var_fname);
		recset.m_FN = var_fname;
		cust_ln->GetWindowText(var_lname);
		recset.m_LN = var_lname;
		cust_cn->GetWindowText(var_cno);
		recset.m_CN = var_cno;
		cust_em->GetWindowText(var_eid);
		recset.m_EA = var_eid;
		cust_ntn->GetWindowText(var_nation);
		recset.m_NTN = var_nation;
		cust_st->GetWindowText(var_st);
		recset.m_ST = var_st;
		cust_ct->GetWindowText(var_ct);
		recset.m_CT = var_ct;
		cust_zc->GetWindowText(var_zc);
		recset.m_ZC = var_zc;
		cust_strt->GetWindowText(var_strt);
		recset.m_STRT = var_strt;
		if (recset.Update())
			 MessageBox(_T("Success."));
		else
			 MessageBox(_T("Failed"));
	}
	else
	{
	MessageBox(_T("Addition of record not allowed."));
	}
}

BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_COMMAND(IDEXIT, OnClose)
	ON_COMMAND(IDREGS, OnCustAdd)
END_MESSAGE_MAP()
