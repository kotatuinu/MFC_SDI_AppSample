#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.h"
#endif

#include "CFormDocTest1.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CFormDocTest1

IMPLEMENT_DYNCREATE(CFormDocTest1, CDocument)

BEGIN_MESSAGE_MAP(CFormDocTest1, CDocument)
	ON_COMMAND(ID_FORMVIEW_CHANGE, &CFormDocTest1::OnFormviewChange)
END_MESSAGE_MAP()


// CFormDocTest1 コンストラクション/デストラクション

CFormDocTest1::CFormDocTest1()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CFormDocTest1::~CFormDocTest1()
{
}

BOOL CFormDocTest1::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。

	return TRUE;
}




// CFormDocTest1 シリアル化

void CFormDocTest1::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 格納するコードをここに追加してください。
	}
	else
	{
		// TODO: 読み込むコードをここに追加してください。
	}
}

#ifdef SHARED_HANDLERS

//縮小版のサポート
void CFormDocTest1::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// このコードを変更してドキュメントのデータを描画します
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 検索ハンドラーのサポート
void CFormDocTest1::InitializeSearchContent()
{
	CString strSearchContent;
	// ドキュメントのデータから検索コンテンツを設定します。
	// コンテンツの各部分は ";" で区切る必要があります

	// 例:      strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CFormDocTest1::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CFormDocTest1 診断

#ifdef _DEBUG
void CFormDocTest1::AssertValid() const
{
	CDocument::AssertValid();
}

void CFormDocTest1::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFormDocTest1 コマンド


void CFormDocTest1::OnFormviewChange()
{
	CMFCApplication4App*  pApp = (CMFCApplication4App*)AfxGetApp();
	CSingleDocTemplate* p1 = pApp->m_viewArray[1];

	p1->InitialUpdateFrame(p1->CreateNewFrame(this, 0), 0);
}
