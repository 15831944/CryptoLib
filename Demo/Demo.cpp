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
	TCHAR res[1024] = { 0 };					//���չ�ϣֵ���飬��С��ȹ�ϣֵ���ȴ󣬱��ⲻ����Խ����
	_tprintf(_T("	���ù�ϣ�������ַ�����123456��\n	-----------------------------\n"));
	//MD5
	_tprintf(_T("	MD5ֵСд��%s\n"),Hash_MD5::Generate(str,res));				//Ĭ�Ϸ���Сд
	_tprintf(_T("	MD5ֵ��д��%s\n"), _tcsupr(Hash_MD5::Generate(str,res)));	//ת���ɴ�д
	_tprintf(_T("	������MD5��%s\n"), Hash_MD5::GenerateFile(_T("Demo.exe"),res));	//�ļ�MD5
	getchar();
    return 0;
}

