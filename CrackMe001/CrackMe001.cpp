// CrackMe001.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <stdio.h>
#include <string>
#define MAGIC -2
using namespace std;

int xxoo = 0;
const string welcome = "帓洘崨訔悗媻訃憢層潙殯=o?"; //please-input-your-code
const string refuse = "憪欈師崓墤寶肄帓洘崨迠寚逕櫉棎=赣释合";	//Wrong password, please try again=
const string access_alter = "+J0+K:M7GX?5]_=8夼鯿"; //这次真的成功了！
const string access = "GY1L]R1(*$++M7GX?5]R+J049+K:]R0,O](Z]_J._._._K:GF]R0,K:LWA3姂晽崯晽袏憥=";	//恭喜，现在真正成功了，这次是真的，我保证！\n打个小小小的广告，我的博客tokisaki.top
const string access2 = "6G:=E-.AJ60D0G[<*]RH>?\3M7H*J5綄煗暢汯:88C]R:9=JF0,I\\I-4BN/揶姂晽崯晽訖煉焼嚲弿袧憮_]=";	//如果你没有看任何攻略，独立完成对此CrackMe的破解，那么给我发封邮件把  tokisaki-galaxy@qq.com。
const string query = ":+K:M7GX?5<=?X@镒?";	//你真的成功了吗
const string key = "客问客唐蛹剖赣适位忧可赣释合记衔技歉=]R+J_J._._]R0, K:LWA3?5<=?X@镒?";	//A304A328-B84F-440E-9A7F-43D1B910BB9F
const string fakekey = "7D38D230-8F7F-4223-8CAC-D42C565FB551";
const string fakekey2 = "C2F022AE-06D9-469E-9676-E42A2DF8FCF6";
const string weapon = "訉抻娹任抻澽-7-$悮憠岶.<]R0,=9BJCU(&.<,KBB85E_]="; //-r -t 60 -c 由于Windows更新，我们即将重新引导计算机。

#pragma region 全局变量 

/*
	ZwSetInformationThread 第二个成员
*/
typedef enum _THREADINFOCLASS {
	ThreadBasicInformation,
	ThreadTimes,
	ThreadPriority,
	ThreadBasePriority,
	ThreadAffinityMask,
	ThreadImpersonationToken,
	ThreadDescriptorTableEntry,
	ThreadEnableAlignmentFaultFixup,
	ThreadEventPair,
	ThreadQuerySetWin32StartAddress,
	ThreadZeroTlsCell,
	ThreadPerformanceCount,
	ThreadAmILastThread,
	ThreadIdealProcessor,
	ThreadPriorityBoost,
	ThreadSetTlsArrayAddress,
	ThreadIsIoPending,
	ThreadHideFromDebugger
}THREAD_INFO_CLASS;

#pragma endregion

#pragma region 依赖函数 

/*
	ZwSetInformationThread
*/
typedef NTSTATUS(NTAPI* pZwSetInformationThread)(
	IN HANDLE ThreadHandle,							// 线程对象句柄 
	IN THREAD_INFO_CLASS ThreadInformaitonClass,	// 线程信息类型
	IN PVOID ThreadInformation,						// 线程信息指针
	IN ULONG ThreadInformationLength				// 线程信息大小
	);

#pragma endregion

#pragma region 功能函数 
#pragma endregion

string decode(string ret)
{
	if (ret.back()!='=')
	{
		for (size_t i = 0; i < ret.size(); i++)
		{
			if (ret.at(i)=='=')
			{
				ret.erase(i);
				break;
			}
		}
	}

	for (auto& i : ret)
	{
		i = i ^ MAGIC;
	}

	return ret;
}

string decode_only(string ret)
{
	if (ret.back() != '=')
	{
		for (size_t i = 0; i < ret.size(); i++)
		{
			if (ret.at(i) == '=')
			{
				ret.erase(i);
				break;
			}
		}
	}
	return ret;
}

int check(int i)
{
	if (i == 0) {
		xxoo = 1;
		Sleep(500);
		cout << decode(access) << endl << decode(access2) << endl << endl << endl;
		return 0;
	}
	return GetTickCount64();
}

int _tmain(int argc, _TCHAR* argv[])
{
	string tmp,input;

	BYTE IsDebug = 0;
	__asm {
		mov eax, dword ptr fs : [0x30]
		mov bl, byte ptr[eax + 0x2]
		mov IsDebug, bl
	}

	// 获取 ZwSetInformationThread 函数地址
	pZwSetInformationThread ZwSetInformationThread = (pZwSetInformationThread)GetProcAddress(LoadLibrary(L"ntdll.dll"), "ZwSetInformationThread");

	// 执行 ZwSetInformationThread 
	ZwSetInformationThread(GetCurrentThread(), ThreadHideFromDebugger, NULL, NULL);

	// 测试 ZwSetInformationThread 的效果
	//std::cout << "程序运行到了这里" << std::endl;

	if (IsDebug!=0)
		exit(1);

	while (1)
	{
		cout << decode(welcome) << endl;

		cin >> input;
		tmp = decode(input);

//		cout << input << tmp << endl << decode_only(key);
atab:
		if (input == fakekey)	//正常来说不可能触发，除非被调试改了jne
			goto other;

		if (decode_only(key) == tmp)
		{
			check(0);
			tmp = "arh";
			goto atab;
		}

		if (tmp.size() < 5) {
			if (tmp=="arh")
				goto other;
		}

		if (input == fakekey2)	//正常来说不可能触发，除非被调试改了jne
			goto other;

		cout << endl << decode(refuse) << endl << endl << endl << endl;
	}

other:
	cout << endl;
	if (xxoo == 1)
	{
		MessageBoxA(NULL, decode(access_alter).c_str(), decode(access_alter).c_str(), MB_OK | MB_ICONQUESTION);
		return 0;
	}
	cout << "非法访问内存地址" << endl;
	MessageBoxA(NULL, decode(query).c_str(), "恭喜恭喜,成功了", MB_OK | MB_ICONQUESTION);
	Sleep(2000);
	tmp.clear();
	tmp = decode(weapon).c_str();
//	ShellExecuteA(NULL, "open", "C:\\WINDOWS\\SYSTEM32\\shutdown.exe", tmp.c_str(), NULL, SWP_HIDEWINDOW);

	return 0;
}

