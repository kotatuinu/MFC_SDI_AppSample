#pragma once
#include "CFormDocTest3.h"
#include "CSDIViewChanger.h"


// CFormViewTest3 �t�H�[�� �r���[

class CFormViewTest3 : public CFormView
{
	DECLARE_DYNCREATE(CFormViewTest3)

protected:
	//CFormViewTest3();           // ���I�����Ŏg�p����� protected �R���X�g���N�^�[
	virtual ~CFormViewTest3();

public:
	CFormViewTest3();           // ���I�����Ŏg�p����� protected �R���X�g���N�^�[
	void setSDIViewChanger(CSDIViewChanger* pSDIViewChanger);
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW2 };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
	inline CFormDocTest3* CFormViewTest3::GetDocument() const
	{
		return reinterpret_cast<CFormDocTest3*>(m_pDocument);
	}
#endif
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};


