#pragma once
#include "afxwin.h"
//#include "CFormDocTest1.h"
#include "MFCApplication4Doc.h"
#include "controller.h"

// CFormViewTest1 �t�H�[�� �r���[

class CFormViewTest1 : public CFormView
{
	DECLARE_DYNCREATE(CFormViewTest1)

private:
	controller m_controller;

protected:
	CFormViewTest1();           // ���I�����Ŏg�p����� protected �R���X�g���N�^�[
	virtual ~CFormViewTest1();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
	//inline CFormDocTest1* CFormViewTest1::GetDocument() const
	inline CDocument* CFormViewTest1::GetDocument() const
	{
		//return reinterpret_cast<CFormDocTest1*>(m_pDocument);
		return reinterpret_cast<CDocument*>(m_pDocument);
	}
#endif
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit m_Edit1;
	afx_msg void OnBnClickedButton2();
};


