#pragma once
#include "CFormDocTest3.h"
#include "CSDIViewChanger.h"


// CFormViewTest3 フォーム ビュー

class CFormViewTest3 : public CFormView
{
	DECLARE_DYNCREATE(CFormViewTest3)

protected:
	//CFormViewTest3();           // 動的生成で使用される protected コンストラクター
	virtual ~CFormViewTest3();

public:
	CFormViewTest3();           // 動的生成で使用される protected コンストラクター
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
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};


