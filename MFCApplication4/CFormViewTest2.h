#pragma once
#include "CFormDocTest2.h"



// CFormViewTest2 フォーム ビュー

class CFormViewTest2 : public CFormView
{
	DECLARE_DYNCREATE(CFormViewTest2)

protected:
	CFormViewTest2();           // 動的生成で使用される protected コンストラクター
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
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
};


