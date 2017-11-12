// CFormViewTest1.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "CFormViewTest1.h"
#include "CFormDocTest1.h"


// CFormViewTest1

IMPLEMENT_DYNCREATE(CFormViewTest1, CFormView)

CFormViewTest1::CFormViewTest1()
	: CFormView(IDD_FORMVIEW)
{

}

CFormViewTest1::~CFormViewTest1()
{
}

void CFormViewTest1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
}

BEGIN_MESSAGE_MAP(CFormViewTest1, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CFormViewTest1::OnBnClickedButton1)
END_MESSAGE_MAP()

BOOL CFormViewTest1::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View 描画

void CFormViewTest1::OnDraw(CDC* /*pDC*/)
{
	//CFormDocTest1* pDoc = GetDocument();
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}

// CFormViewTest1 診断

#ifdef _DEBUG
void CFormViewTest1::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormViewTest1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormViewTest1 メッセージ ハンドラー


void CFormViewTest1::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CString string;
	m_Edit1.GetWindowTextW(string);
	CWnd *h = this->GetDlgItem(IDC_STATIC);
	h->SetWindowTextW(string);
	((CFormDocTest1*)GetDocument())->OnFormviewChange();
	//BOOL b = PostMessage(ID_FORMVIEW_CHANGE);
	//BOOL b = SendMessage(ID_FORMVIEW_CHANGE);

}
