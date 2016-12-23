// Demo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "../CryptoLib/Include/CryptoLib.h"
#pragma comment(lib, "../CryptoLib/Lib/CryptoLib.lib")

using namespace CryptoLib;

int main()
{
	_tsetlocale(LC_ALL, _T("chs"));
	_tprintf(_T("CrytoLib�����\n---------------------------------------\n"));
	//���ù�ϣ
	LPCTSTR str = _T("123456");
	_tprintf(_T("	���ù�ϣ�������ַ�����123456��\n	-----------------------------\n"));
	//MD5
	_tprintf(_T("	MD5 ���ȣ�32\n"));
	_tprintf(_T("	MD5ֵСд��%s\n"),Hash_MD5::Generate(str));				//Ĭ�Ϸ���Сд
	_tprintf(_T("	MD5ֵ��д��%s\n"), _tcsupr(const_cast<wchar_t*>(Hash_MD5::Generate(str))));	//ת���ɴ�д
	_tprintf(_T("	������MD5��%s\n"), Hash_MD5::GenerateFile(_T("Demo.exe")));	//�ļ�MD5
	_tprintf(_T("\n"));
	//SHA1
	_tprintf(_T("	SHA1 ���ȣ�40\n"));
	_tprintf(_T("	SHA1ֵ��%s\n"), Hash_SHA1::Generate(str));				//Ĭ�Ϸ���Сд
	_tprintf(_T("	������SHA1��%s\n"), Hash_SHA1::GenerateFile(_T("Demo.exe")));	//�ļ�MD5
	_tprintf(_T("\n"));
	//SHA1
	_tprintf(_T("	SHA256 ���ȣ�64\n"));
	_tprintf(_T("	SHA256ֵ��%s\n"), Hash_SHA256::Generate(str));				//Ĭ�Ϸ���Сд
	_tprintf(_T("	������SHA256��%s\n"), Hash_SHA256::GenerateFile(_T("Demo.exe")));	//�ļ�MD5
	_tprintf(_T("\n"));
	//SHA1
	_tprintf(_T("	SHA512 ���ȣ�128\n"));
	_tprintf(_T("	SHA512ֵ��%s\n"), Hash_SHA512::Generate(str));				//Ĭ�Ϸ���Сд
	_tprintf(_T("	������SHA512��%s\n"), Hash_SHA512::GenerateFile(_T("Demo.exe")));	//�ļ�MD5
	_tprintf(_T("\n"));
	getchar();
    return 0;
}

