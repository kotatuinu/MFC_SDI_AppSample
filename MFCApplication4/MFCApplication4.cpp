
// MFCApplication4.cpp : アプリケーションのクラス動作を定義します。
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCApplication4.h"
#include "MainFrm.h"

#include "MFCApplication4Doc.h"
//#include "MFCApplication4View.h"

#include "CFormViewTest1.h"
#include "CFormDocTest1.h"
#include "CFormViewTest2.h"
#include "CFormDocTest2.h"
#include "CFormViewTest3.h"
#include "CFormDocTest3.h"

#include "CViewFrameController.h"
#include "CSDIViewChanger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication4App

BEGIN_MESSAGE_MAP(CMFCApplication4App, CWinAppEx)
	//ON_COMMAND(ID_APP_ABOUT, &CMFCApplication4App::OnAppAbout)
	// 標準のファイル基本ドキュメント コマンド
	//ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	//ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
//	ON_UPDATE_COMMAND_UI(ID_APP_ABOUT, &CMFCApplication4App::OnChangeView)
END_MESSAGE_MAP()


// CMFCApplication4App コンストラクション

CMFCApplication4App::CMFCApplication4App()
{
	m_bHiColorIcons = TRUE;

	// 再起動マネージャーをサポートします
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// アプリケーションが共通言語ランタイム サポート (/clr) を使用して作成されている場合:
	//     1) この追加設定は、再起動マネージャー サポートが正常に機能するために必要です。
	//     2) 作成するには、プロジェクトに System.Windows.Forms への参照を追加する必要があります。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 下のアプリケーション ID 文字列を一意の ID 文字列で置換します。推奨される
	// 文字列の形式は CompanyName.ProductName.SubProduct.VersionInformation です
	SetAppID(_T("MFCApplication4.AppID.NoVersion"));

	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}

// 唯一の CMFCApplication4App オブジェクトです。

CMFCApplication4App theApp;


// CMFCApplication4App 初期化

BOOL CMFCApplication4App::InitInstance()
{
	CViewFrameController* pViewFrameController = CViewFrameController::getInstance();
	{
		CSingleDocTemplate* pNewDocTemplate = new CSingleDocTemplate(
			IDR_FORMVIEWTEST2_TMPL,
			RUNTIME_CLASS(CFormDocTest1),
			RUNTIME_CLASS(CMainFrame),
			RUNTIME_CLASS(CFormViewTest1));
		AddDocTemplate(pNewDocTemplate);
		pViewFrameController->addFrame(pNewDocTemplate);
	}

	// アプリケーション マニフェストが visual スタイルを有効にするために、
	// ComCtl32.dll Version 6 以降の使用を指定する場合は、
	// Windows XP に InitCommonControlsEx() が必要です。さもなければ、ウィンドウ作成はすべて失敗します。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// アプリケーションで使用するすべてのコモン コントロール クラスを含めるには、
	// これを設定します。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// OLE ライブラリを初期化します。
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// RichEdit コントロールを使用するには AfxInitRichEdit2() が必要です	
	// AfxInitRichEdit2();

	// 標準初期化
	// これらの機能を使わずに最終的な実行可能ファイルの
	// サイズを縮小したい場合は、以下から不要な初期化
	// ルーチンを削除してください。
	// 設定が格納されているレジストリ キーを変更します。
	// TODO: 会社名または組織名などの適切な文字列に
	// この文字列を変更してください。
	SetRegistryKey(_T("アプリケーション ウィザードで生成されたローカル アプリケーション"));
	LoadStdProfileSettings(4);  // 標準の INI ファイルのオプションをロードします (MRU を含む)

	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// アプリケーション用のドキュメント テンプレートを登録します。ドキュメント テンプレート
	//  はドキュメント、フレーム ウィンドウとビューを結合するために機能します。

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CFormDocTest1),
		RUNTIME_CLASS(CMainFrame),       // メイン SDI フレーム ウィンドウ
		RUNTIME_CLASS(CFormViewTest1));
	if (!pDocTemplate)
		return FALSE;
	pViewFrameController->addFrame(pDocTemplate);

	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CFormDocTest2),
		RUNTIME_CLASS(CMainFrame),       // メイン SDI フレーム ウィンドウ
		RUNTIME_CLASS(CFormViewTest2));
	if (!pDocTemplate)
		return FALSE;
	pViewFrameController->addFrame(pDocTemplate);

	// DDE、file open など標準のシェル コマンドのコマンド ラインを解析します。
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// コマンド ラインで指定されたディスパッチ コマンドです。アプリケーションが
	// /RegServer、/Register、/Unregserver または /Unregister で起動された場合、False を返します。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 切り替え用Viewの設定
	//x();
	CSDIViewChanger *pSDIViewChanger = CSDIViewChanger::getInstance();
	pSDIViewChanger->setMainWnd(m_pMainWnd);
	pSDIViewChanger->addActiveView(new CFormViewTest3());

	// メイン ウィンドウが初期化されたので、表示と更新を行います。
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

//SDI内のView切り替え
// http://www.softist.com/programming/sdi-multi-view/sdi-multi-view.htm からコピー
void CMFCApplication4App::x()
{
	CView* pActiveView = ((CFrameWnd*)m_pMainWnd)->GetActiveView();
	m_pView2 = pActiveView;
	m_pView3 = new CFormViewTest3();

	CDocument* pCurrentDoc = ((CFrameWnd*)m_pMainWnd)->GetActiveDocument();
	CCreateContext newContext;
	newContext.m_pNewViewClass = NULL;
	newContext.m_pNewDocTemplate = NULL;
	newContext.m_pLastView = NULL;
	newContext.m_pCurrentFrame = NULL;
	newContext.m_pCurrentDoc = pCurrentDoc;

	UINT viewID = AFX_IDW_PANE_FIRST + 1;
	CRect rect(0, 0, 0, 0); // gets resized later
	m_pView3->Create(NULL, _T("View3"), WS_CHILD, rect, m_pMainWnd, viewID, &newContext);

	m_pView3->ModifyStyleEx(0, WS_EX_CLIENTEDGE);
	m_pView3->OnInitialUpdate();

}

CView* CMFCApplication4App::SwitchView(CView* pNewView)
{
	CView* pActiveView = ((CFrameWnd*)m_pMainWnd)->GetActiveView();

	UINT temp = ::GetWindowLong(pActiveView->m_hWnd, GWL_ID);
	::SetWindowLong(pActiveView->m_hWnd, GWL_ID, ::GetWindowLong(pNewView->m_hWnd, GWL_ID));
	::SetWindowLong(pNewView->m_hWnd, GWL_ID, temp);

	pActiveView->ShowWindow(SW_HIDE);
	pNewView->ShowWindow(SW_SHOW);
	((CFrameWnd*)m_pMainWnd)->SetActiveView(pNewView);
	((CFrameWnd*)m_pMainWnd)->RecalcLayout();
	pNewView->Invalidate();
	return pActiveView;
}

void CMFCApplication4App::SwitchView(int no)
{
	switch (no)
	{
	case 1:
		break;

	case 2:
		SwitchView(m_pView2);
		break;

	case 3:
		SwitchView(m_pView3);
		break;

	default:
		break;
	}
}

int CMFCApplication4App::ExitInstance()
{
	//TODO: 追加したリソースがある場合にはそれらも処理してください
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CMFCApplication4App メッセージ ハンドラー


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ
/*
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// ダイアログを実行するためのアプリケーション コマンド
void CMFCApplication4App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}
*/
// CMFCApplication4App のカスタマイズされた読み込みメソッドと保存メソッド

void CMFCApplication4App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	//GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CMFCApplication4App::LoadCustomState()
{
}

void CMFCApplication4App::SaveCustomState()
{
}

// CMFCApplication4App メッセージ ハンドラー

