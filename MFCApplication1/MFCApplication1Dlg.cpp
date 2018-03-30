
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include<conio.h>
#include "CompileMXF.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EditVideo);
	DDX_Control(pDX, IDC_EDIT2, m_EditAudio);
	DDX_Control(pDX, IDC_EDIT3, m_EditOut);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	AllocConsole();
	// TODO: 在此添加额外的初始化代码

	m_EditAudio.SetWindowText(L"F:\\Avid MediaFiles\\MXF\\A01.5AB88DEA_55AB88DE9.mxf");
	m_EditOut.SetWindowText(L"F:\\Avid MediaFiles\\MXF\\1");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//Video
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strExt(_T("*"));
	CString strFilter(_T("Input文件(*.mxf)|*.mxf||"));

	CFileDialog filedialog(TRUE, strExt, NULL, OFN_FILEMUSTEXIST, strFilter, this);

	if (filedialog.DoModal() != IDOK)
		return;

	m_EditVideo.SetWindowText(filedialog.GetPathName());
	
}

//Audio
void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strExt(_T("*"));
	CString strFilter(_T("Input文件(*.mxf)|*.mxf||"));

	CFileDialog filedialog(TRUE, strExt, NULL, OFN_FILEMUSTEXIST, strFilter, this);

	if (filedialog.DoModal() != IDOK)
		return;

	m_EditAudio.SetWindowText(filedialog.GetPathName());
}

//Out
void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	BROWSEINFO bInfo = { 0 };
	LPITEMIDLIST lpDlist;
	TCHAR szPathName[MAX_PATH] = {0};

	lpDlist = SHBrowseForFolder(&bInfo);

	SHGetPathFromIDList(lpDlist, szPathName);

	m_EditOut.SetWindowText(szPathName);
}

//Read
void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CCompileAudioMXF oMyCompileAudio;
	CString csAudio,csOut;
	DWORD dwMinSize;
	
	m_EditAudio.GetWindowText(csAudio);
	m_EditOut.GetWindowText(csOut);

	dwMinSize = WideCharToMultiByte(CP_ACP, NULL, csAudio, -1, NULL, 0, NULL, FALSE);
	char * chRead = new char[dwMinSize];
	WideCharToMultiByte(CP_OEMCP, NULL, csAudio, -1, chRead, dwMinSize, NULL, FALSE);

	dwMinSize = WideCharToMultiByte(CP_ACP, NULL, csOut, -1, NULL, 0, NULL, FALSE);
	char * chOut = new char[dwMinSize];
	WideCharToMultiByte(CP_OEMCP, NULL, csOut, -1, chOut, dwMinSize, NULL, FALSE);
	

	oMyCompileAudio.SetRWMXFPath(chRead,chOut);

	delete[] chRead; chRead = nullptr;
	delete[] chOut; chOut = nullptr;

	oMyCompileAudio.CompileHeader();
	
	char *chData = new char[1920];
	FILE *fpRead = nullptr;
	fopen_s(&fpRead, "F:\\Avid MediaFiles\\MXF\\A02.5AB88DEB_55AB88DE9.mxf", "rb+");
	for (int i = 0; i < 10; i++)
	{
		_fseeki64(fpRead,266240+i*1920,SEEK_SET);
		fread_s(chData, 1920, 1, 1920, fpRead);
		oMyCompileAudio.CompileAudioData(chData, 1920);
	}
	oMyCompileAudio.Flush();
	delete[] chData; chData = nullptr;
}
