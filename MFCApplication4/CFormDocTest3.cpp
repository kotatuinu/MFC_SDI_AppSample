#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.h"
#endif

#include "CFormDocTest3.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CFormDocTest3

IMPLEMENT_DYNCREATE(CFormDocTest3, CDocument)

BEGIN_MESSAGE_MAP(CFormDocTest3, CDocument)
	ON_COMMAND(ID_FORMVIEW_CHANGE, &CFormDocTest3::OnFormviewChange)
END_MESSAGE_MAP()


// CFormDocTest3 コンストラクション/デストラクション

CFormDocTest3::CFormDocTest3()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CFormDocTest3::~CFormDocTest3()
{
}

BOOL CFormDocTest3::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。

	return TRUE;
}




// CFormDocTest3 シリアル化

void CFormDocTest3::Serialize(CArchive& ar)
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
void CFormDocTest3::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// このコードを変更してドキュメントのデータを描画します
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 検索ハンドラーのサポート
void CFormDocTest3::InitializeSearchContent()
{
	CString strSearchContent;
	// ドキュメントのデータから検索コンテンツを設定します。
	// コンテンツの各部分は ";" で区切る必要があります

	// 例:      strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CFormDocTest3::SetSearchContent(const CString& value)
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

// CFormDocTest3 診断

#ifdef _DEBUG
void CFormDocTest3::AssertValid() const
{
	CDocument::AssertValid();
}

void CFormDocTest3::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFormDocTest3 コマンド


void CFormDocTest3::OnFormviewChange()
{
	// TODO: ここにコマンド ハンドラー コードを追加します。
	CMFCApplication4App*  pApp = (CMFCApplication4App*)AfxGetApp();
	CSingleDocTemplate* p1 = pApp->m_viewArray[1];

	p1->InitialUpdateFrame(p1->CreateNewFrame(this, 0), 0);
}
