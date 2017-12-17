// CFormViewTest2.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "CFormViewTest2.h"
#include "CFormDocTest2.h"

// CFormViewTest2

IMPLEMENT_DYNCREATE(CFormViewTest2, CFormView)

CFormViewTest2::CFormViewTest2()
	: CFormView(IDD_FORMVIEW1)
{
	CSDIViewChanger* pSDIViewChanger = NULL;
	pSDIViewChanger->addView(this);
}

CFormViewTest2::~CFormViewTest2()
{
}

void CFormViewTest2::setSDIViewChanger(CSDIViewChanger* pSDIViewChanger)
{
	pSDIViewChanger->addView(this);
}

void CFormViewTest2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormViewTest2, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CFormViewTest2::OnBnClickedButton1)
END_MESSAGE_MAP()

BOOL CFormViewTest2::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View 描画

void CFormViewTest2::OnDraw(CDC* /*pDC*/)
{
	CFormDocTest2* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}

// CFormViewTest2 診断

#ifdef _DEBUG
void CFormViewTest2::AssertValid() const
{
	CFormView::AssertValid();
}
#ifndef _WIN32_WCE
void CFormViewTest2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormViewTest2 メッセージ ハンドラー
void CFormViewTest2::OnBnClickedButton1()
{
	CSDIViewChanger* pSDIViewChanger = NULL;
	pSDIViewChanger->SwitchView(0UL);
}
