// CFormViewTest3.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MFCApplication4.h"

#include "CFormViewTest3.h"
#include "CFormDocTest2.h"


// CFormViewTest3

IMPLEMENT_DYNCREATE(CFormViewTest3, CFormView)

CFormViewTest3::CFormViewTest3()
	: CFormView(IDD_FORMVIEW2)
{

}

CFormViewTest3::~CFormViewTest3()
{
}

void CFormViewTest3::setSDIViewChanger(CSDIViewChanger* pSDIViewChanger)
{
	pSDIViewChanger->addView(this);
}

void CFormViewTest3::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormViewTest3, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CFormViewTest3::OnBnClickedButton1)
END_MESSAGE_MAP()

BOOL CFormViewTest3::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View 描画

void CFormViewTest3::OnDraw(CDC* /*pDC*/)
{
	CFormDocTest3* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}

// CFormViewTest3 診断

#ifdef _DEBUG
void CFormViewTest3::AssertValid() const
{
	CFormView::AssertValid();
}
#ifndef _WIN32_WCE
void CFormViewTest3::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormViewTest3 メッセージ ハンドラー


void CFormViewTest3::OnBnClickedButton1()
{
	CSDIViewChanger *pSDIViewChanger = NULL;
	pSDIViewChanger->SwitchView(0UL);
}
