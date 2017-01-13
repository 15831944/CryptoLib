// Demo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "windows.h"
#include "../CryptoLib/Include/CryptoLib.h"
#pragma comment(lib, "../CryptoLib/Lib/CryptoLib.lib")

using namespace CryptoLib;
int main()
{
	//ע����IDE�е���ʱGenerateFile����·��������ܻᱨ��ע�ͻ��þ���·������
	_tsetlocale(LC_ALL, _T("chs"));
	_tprintf(_T("CrytoLib����ԣ�UTF-8���룩\n---------------------------------------\n"));
	//���ù�ϣ
	LPCTSTR str = _T("abc123����");
	_tprintf(_T("	���ù�ϣ�������ַ�����abc123���ģ�\n	-----------------------------\n"));
	//MD5
	_tprintf(_T("	MD5 ���ȣ�32\n"));
	_tprintf(_T("	MD5ֵСд��%s\n"), Hash_MD5::Generate(str).GetTString().c_str());			//Ĭ�Ϸ���Сд
	_tprintf(_T("	MD5ֵ��д��%s\n"), _tcsupr((wchar_t*)Hash_MD5::Generate(str).GetTString().c_str()));	//ת���ɴ�д
	_tprintf(_T("	������MD5��%s\n"), Hash_MD5::GenerateFile(_T("Demo.exe")).GetTString().c_str());	//�ļ�MD5
	_tprintf(_T("\n"));
	//SHA1
	_tprintf(_T("	SHA1 ���ȣ�40\n"));
	_tprintf(_T("	SHA1ֵ��%s\n"), Hash_SHA1::Generate(str).GetTString().c_str());
	_tprintf(_T("	������SHA1��%s\n"), Hash_SHA1::GenerateFile(_T("Demo.exe")).GetTString().c_str());
	_tprintf(_T("\n"));
	//SHA1
	_tprintf(_T("	SHA256 ���ȣ�64\n"));
	_tprintf(_T("	SHA256ֵ��%s\n"), Hash_SHA256::Generate(str).GetTString().c_str());
	_tprintf(_T("	������SHA256��%s\n"), Hash_SHA256::GenerateFile(_T("Demo.exe")).GetTString().c_str());
	_tprintf(_T("\n"));
	//SHA1
	_tprintf(_T("	SHA512 ���ȣ�128\n"));
	_tprintf(_T("	SHA512ֵ��%s\n"), Hash_SHA512::Generate(str).GetTString().c_str());
	_tprintf(_T("	������SHA512��%s\n"), Hash_SHA512::GenerateFile(_T("Demo.exe")).GetTString().c_str());
	_tprintf(_T("\n"));
	//SHA1
	_tprintf(_T("	CRC32 ���ȣ�8\n"));
	_tprintf(_T("	CRC32ֵ��%s\n"), Hash_CRC32::Generate(str).GetTString().c_str());
	_tprintf(_T("	������CRC32��%s\n"), Hash_CRC32::GenerateFile(_T("Demo.exe")).GetTString().c_str());
	_tprintf(_T("\n"));
	
	//���ü���
	_tprintf(_T("	���ü��ܣ������ַ�����abc123���ģ�\n	-----------------------------\n"));
	//Base64
	_tprintf(_T("	Base64���룺%s\n"), Encode_Base64::Encode(str).GetTString().c_str());
	_tprintf(_T("	Base64���룺%s\n"), Encode_Base64::Decode(Encode_Base64::Encode(str)).GetTString().c_str());
	_tprintf(_T("\n"));
	//UrlEncode
	_tprintf(_T("	UrlEncode���룺%s\n"), Encode_UrlEncode::Encode(str).GetTString().c_str());
	_tprintf(_T("	UrlEncode���룺%s\n"), Encode_UrlEncode::Decode(Encode_UrlEncode::Encode(str)).GetTString().c_str());
	_tprintf(_T("\n"));

	//Ӳ����Ϣ
	_tprintf(_T("	Ӳ����Ϣ����Ҫ����ԱȨ�ޣ�\n	-----------------------------\n"));
	_tprintf(_T("	Ӳ�����кţ�%s\n"),Info_DiskSN::GetSN().GetTString().c_str());
	
	getchar();
    return 0;
}

