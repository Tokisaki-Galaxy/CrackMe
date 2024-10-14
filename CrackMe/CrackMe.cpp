// CrackMe.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <stdio.h>
#include <string>

using namespace std;

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

int _tmain(int argc, _TCHAR* argv[])
{
	string input;
	// 获取 ZwSetInformationThread 函数地址
	pZwSetInformationThread ZwSetInformationThread = (pZwSetInformationThread)GetProcAddress(LoadLibrary(L"ntdll.dll"), "ZwSetInformationThread");

	// 执行 ZwSetInformationThread 
	ZwSetInformationThread(GetCurrentThread(), ThreadHideFromDebugger, NULL, NULL);

	cin >> input;
	// 测试 ZwSetInformationThread 的效果
	std::cout << "程序运行到了这里" << std::endl;

	getchar();
	return 0;
}

