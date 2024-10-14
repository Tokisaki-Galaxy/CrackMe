
// CrackMe1Dlg.h: 头文件
//

#pragma once


// CCrackMe1Dlg 对话框
class CCrackMe1Dlg : public CDialogEx
{
// 构造
public:
	CCrackMe1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CRACKME1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 输入的key
	CString INPUT_KEY;
	afx_msg void OnBnClickedOk();
	int check(int a);
private:
	int xxoo;
public:
	// 加密或解密
	CString edcode(CString str);
	// 去除干扰项
//	CString remove_interfere(CString ret);
//	const CString access = _T("GY1L:]RBZE<+6I=棹$a鶹w");	//恭喜你，激活码正确
	CString access;
	const CString refuse = _T("BZE<LE+6I]R9(&4*=啫_");	//激活码错误，请重试
	const CString query = _T("8G(?5]RF.@G(G(K:=险8DRG嚎");	// 好像有哪里错了
	const CString key = _T("雀绞酵胶邮拖陀侍喝涌钙视吞教嚎蓟晃胶");	//6FC4C3CD-4313-42D6-AF84-32C2DABEE0CD
	const CString fakekey = _T("9FE3688C-EF18-4056-B356-83B10BD81FB6");
	const CString fakekey2 = _T("BCE8D0EA-D9F4-4DE4-B1D9-8ACE7A0FD0E4");
};
