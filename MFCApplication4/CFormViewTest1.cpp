// CFormViewTest1.cpp : �����t�@�C��
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
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View �`��

void CFormViewTest1::OnDraw(CDC* /*pDC*/)
{
	//CFormDocTest1* pDoc = GetDocument();
	CDocument* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}

// CFormViewTest1 �f�f

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


// CFormViewTest1 ���b�Z�[�W �n���h���[


void CFormViewTest1::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	CString string;
	m_Edit1.GetWindowTextW(string);
	CWnd *h = this->GetDlgItem(IDC_STATIC);
	h->SetWindowTextW(string);
	((CFormDocTest1*)GetDocument())->OnFormviewChange();
	//BOOL b = PostMessage(ID_FORMVIEW_CHANGE);
	//BOOL b = SendMessage(ID_FORMVIEW_CHANGE);

}
