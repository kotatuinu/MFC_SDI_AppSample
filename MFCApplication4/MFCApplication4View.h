
// MFCApplication4View.h : CMFCApplication4View クラスのインターフェイス
//

#pragma once


class CMFCApplication4View : public CView
{
protected: // シリアル化からのみ作成します。
	CMFCApplication4View();
	DECLARE_DYNCREATE(CMFCApplication4View)

// 属性
public:
	CMFCApplication4Doc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 実装
public:
	virtual ~CMFCApplication4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication4View.cpp のデバッグ バージョン
inline CMFCApplication4Doc* CMFCApplication4View::GetDocument() const
   { return reinterpret_cast<CMFCApplication4Doc*>(m_pDocument); }
#endif

