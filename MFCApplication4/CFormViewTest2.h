#pragma once
#include "CFormDocTest2.h"



// CFormViewTest2 �t�H�[�� �r���[

class CFormViewTest2 : public CFormView
{
	DECLARE_DYNCREATE(CFormViewTest2)

protected:
	CFormViewTest2();           // ���I�����Ŏg�p����� protected �R���X�g���N�^�[
	virtual ~CFormViewTest2();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW1};
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
	inline CFormDocTest2* CFormViewTest2::GetDocument() const
	{
		return reinterpret_cast<CFormDocTest2*>(m_pDocument);
	}
#endif
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
};


