
// MFCApplication4View.cpp : CMFCApplication4View �N���X�̎���
//

#include "stdafx.h"
// SHARED_HANDLERS �́A�v���r���[�A�k���ŁA����ь����t�B���^�[ �n���h���[���������Ă��� ATL �v���W�F�N�g�Œ�`�ł��A
// ���̃v���W�F�N�g�Ƃ̃h�L�������g �R�[�h�̋��L���\�ɂ��܂��B
#ifndef SHARED_HANDLERS
#include "MFCApplication4.h"
#endif

#include "MFCApplication4Doc.h"
#include "MFCApplication4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication4View

IMPLEMENT_DYNCREATE(CMFCApplication4View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication4View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication4View �R���X�g���N�V����/�f�X�g���N�V����

CMFCApplication4View::CMFCApplication4View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CMFCApplication4View::~CMFCApplication4View()
{
}

BOOL CMFCApplication4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View �`��

void CMFCApplication4View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
}

void CMFCApplication4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
//	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication4View �f�f

#ifdef _DEBUG
void CMFCApplication4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication4Doc* CMFCApplication4View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication4Doc)));
	return (CMFCApplication4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication4View ���b�Z�[�W �n���h���[
