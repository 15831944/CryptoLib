#include "stdafx.h"
#include "stringx.h"

/************************************************************************
���캯��
************************************************************************/
stringx::stringx(SXCWCH ch, const UINT rep /*= 1*/) { SetString(ch, rep); }
stringx::stringx(SXCSTR src)					{ assert(src); SetString(src); }
stringx::stringx(SXCWSTR src)					{ assert(src); SetString(src); }
stringx::stringx(const string& src)				{ SetString(src); }
stringx::stringx(const wstring& src)			{ SetString(src); }
stringx::stringx(const stringx& src)			{ SetString(src); }

/************************************************************************
�����ַ���ֵ
����ֵ����ǰstringx����
************************************************************************/
stringx& stringx::SetString(SXCWCH ch, const UINT rep /*= 1*/) {
	str_.assign(rep, ch);
	return *this;
}

stringx& stringx::SetString(SXCSTR src) {
	assert(src);
	
	SXWSTR wstr = new SXWCH[GetAWConvertLength(src)];
	str_ = Str2WStr(src, wstr);
	delete[] wstr;
	wstr = NULL;
	return *this;
}

stringx& stringx::SetString(SXCWSTR src) {
	assert(src);

	str_ = src;
	return *this;
}

stringx& stringx::SetString(const string& src) {
	SetString(src.c_str());
	return *this;
}

stringx& stringx::SetString(const wstring& src) {
	SetString(src.c_str());
	return *this;
}

stringx& stringx::SetString(const stringx& src) {
	str_ = src.str_;
	isutf8_ = src.isutf8_;
	return *this;
}

/************************************************************************
����ת�ַ���
digit:��ת�����֣�������18446744073709551615
����ֵ����ǰstringx����
************************************************************************/
stringx& stringx::SetDigit(SXCULL digit) {
	SXWSTR str = new SXWCH[128];
	_ui64tow(digit, str, 10);
	str_ = str;
	delete[] str;
	str = NULL;
	return *this;
}

/************************************************************************
ȡ�ַ���
����ֵ��ȡֵ���string/wstring
************************************************************************/
string stringx::GetString() const {
	SXSTR str = new SXCH[GetAWConvertLength(str_.c_str())];
	WStr2Str(str_.c_str(), str);
	string ret = str;
	delete[] str;
	str = NULL;
	return ret;
}

wstring stringx::GetWString() const {
	return str_;
}

tstring stringx::GetTString() const {
#ifdef _UNICODE
	return GetWString();
#else
	return GetString();
#endif
}

/************************************************************************
ȡ�ַ���
out:�����ַ�����ָ�룬��ҪԤ�ȳ�ʼ��
����ֵ�������ַ���ָ��
************************************************************************/
SXSTR stringx::GetData(SXSTR out) const {
	WStr2Str(str_.c_str(), out);
	return out;
}

SXWSTR stringx::GetData(SXWSTR out) const {
	wcscpy(out, str_.c_str());
	return out;
}

/************************************************************************
ȡ���ֽ��ַ���
����ֵ�����ֽ��ַ���
************************************************************************/
SXCWSTR stringx::GetData() const {
	return str_.c_str();
}

/************************************************************************
�ַ���ת����
����ֵ��ת�������֣�������18446744073709551615
************************************************************************/
SXULL stringx::GetDigit() const {
	return wcstoull(str_.c_str(), NULL, 10);
}

/************************************************************************
ȡ��ʵwstring����
����ֵ��wstring��������ã�����ĸĶ���ͬʱӰ��stringx�е�ֵ
************************************************************************/
wstring& stringx::GetBuffer() {
	return str_;
}

/************************************************************************
ȡ�ַ����������ȣ����ڳ�ʼ������ȣ�
����ֵ���ַ�����������
************************************************************************/
int stringx::GetADataLength() {
	return GetAWConvertLength(str_.c_str());
}

int stringx::GetWDataLength() {
	return (int)GetLength() + 1;
}

/************************************************************************
�ж��Ƿ��Ǵ�����
���أ�true�� false ��
************************************************************************/
bool stringx::IsDigit() const {
	for (UINT i = 0; i < (UINT)GetLength(); ++i) {
		if (i == 0 && str_[i] == L'-')
			continue;
		if (str_[i] < L'0' || str_[i] > L'9')
			return false;
	}
	return true;
}

/************************************************************************
����ַ���
************************************************************************/
void stringx::Empty() {
	str_.clear();
}

/************************************************************************
�ж��ַ����Ƿ�Ϊ��
����ֵ��true�� false�ǿ�
************************************************************************/
bool stringx::IsEmpty() const {
	return str_.empty();
}

/************************************************************************
ȡ�ַ������ȣ����ĳ�����1
************************************************************************/
SXULL stringx::GetLength() const {
	return str_.length();
}

/************************************************************************
ȡ�ַ���ĳһλ
index:�ַ�λ�ã���0��ʼ
����ֵ��λ���ϵ��ַ�����������wchar����
************************************************************************/
SXWCH stringx::GetAt(const int index) const {
	return str_[index];
}

/************************************************************************
�����ַ���ĳһλ
index:�ַ�λ�ã���0��ʼ
ch:�����ַ�����������wchar����
************************************************************************/
void stringx::SetAt(const int index, SXCWCH ch) {
	str_[index] = ch;
}

/************************************************************************
׷���ַ���
������������ַ���
����ֵ����ǰstringx����
************************************************************************/
stringx& stringx::Append(const stringx& src) { str_.append(src.GetWString()); return *this; }
stringx& stringx::Append(SXCWCH ch, const UINT rep /*= 1*/) { str_.append(rep, ch); return *this; }

/************************************************************************
����[]
************************************************************************/
SXWCH stringx::operator[] (const UINT index) const {
	return str_[index];
}

/************************************************************************
����= + +=
************************************************************************/
stringx& stringx::operator=(const stringx&  src) { SetString(src); return *this; }
stringx stringx::operator+(const stringx&  src) const { stringx temp = *this; temp.Append(src); return temp; }
const stringx& stringx::operator+=(const stringx&  src)	{ Append(src); return *this; }

/************************************************************************
�ַ����Ƚ�
src:���Ƚ��ַ���
************************************************************************/
int stringx::Compare(const stringx& src) const  { return str_.compare(src.GetWString()); }

/************************************************************************
�ַ������Ӵ�Сд�Ƚ�
src:���Ƚ��ַ���
************************************************************************/
int stringx::CompareNoCase(const stringx& src) const { return _wcsicmp(str_.c_str(), src.GetWString().c_str()); }

/************************************************************************
����== != < <= > >=
************************************************************************/
bool stringx::operator == (const stringx& src) const { return (Compare(src) == 0); };
bool stringx::operator != (const stringx& src) const { return (Compare(src) != 0); };
bool stringx::operator <= (const stringx& src) const { return (Compare(src) <= 0); };
bool stringx::operator < (const stringx& src)  const { return (Compare(src) < 0); };
bool stringx::operator >= (const stringx& src) const { return (Compare(src) >= 0); };
bool stringx::operator > (const stringx& src)  const { return (Compare(src) > 0); };

/************************************************************************
�Զ����Сдת������
c:��ת���ַ�
����ֵ������ĸ��ת�������򷵻�ԭֵ
************************************************************************/
int stringx::ToUpper(int c) {
	if (isalpha(c))
		return toupper(c);
	else return c;
}

int stringx::ToLower(int c) {
	if (isalpha(c))
		return tolower(c);
	else return c;
}

/************************************************************************
��Сдת��
����ֵ����ǰstringx����
************************************************************************/
stringx& stringx::MakeUpper() {
	transform(str_.begin(), str_.end(), str_.begin(), ToUpper);
	return *this;
}

stringx& stringx::MakeLower() {
	transform(str_.begin(), str_.end(), str_.begin(), ToLower);
	return *this;
}

/************************************************************************
ȡ�ַ������Ӵ�
from:��ʼλ�ã�������������β�˷��ؿ�
to:����λ�ã�������������β��ȫ��ȡ
����ֵ��ȡ�õ�stringx����
************************************************************************/
stringx stringx::SubStr(UINT from, UINT to) const {
	SXULL len = GetLength();
	if (from >= len)
		return stringx();
	if (to >= len)
		to = (UINT)len - 1;
	return stringx(str_.substr(from, to - from + 1));
}

/************************************************************************
ȡ��߿�ʼ���ַ���
length:�ַ������ȣ�����β��ȫ��ȡ
����ֵ��ȡ�õ�stringx����
************************************************************************/
stringx stringx::Left(UINT length) const {
	if (length == 0)
		return stringx();
	SXULL len = GetLength();
	if (length > len)
		length = (UINT)len;
	return stringx(str_.substr(0, length));
}

/************************************************************************
ȡ�м俪ʼ���ַ���
pos:��ʼλ��
length:�ַ������ȣ���ֵ��ǰȡ������ʣ�೤����ȫ��ȡ
����ֵ��ȡ�õ�stringx����
************************************************************************/
stringx stringx::Mid(UINT pos, int length) const {
	SXULL len = GetLength();
	int start, end;
	if (pos >= len)
		return stringx();
	if (length < 0) {
		start = pos - length + 1;
		if (start < 0)
			start = 0;
		end = pos;
	} else {
		start = pos;
		end = pos + length - 1;
		if (end >= len)
			end = (int)len - 1;
	}
	return SubStr(start, end);
}

/************************************************************************
ȡ�ұ߿�ʼ���ַ���
length:�ַ������ȣ�����ԭ������ȫ��ȡ
����ֵ��ȡ�õ�stringx����
************************************************************************/
stringx stringx::Right(UINT length) const {
	if (length == 0)
		return stringx();
	SXULL len = GetLength();
	int pos = (int)(len - length);
	if (pos < 0) {
		pos = 0;
		length = (UINT)len;
	}
	return stringx(str_.substr(pos, length));
}

/************************************************************************
�����ַ�/�ַ�������λ��
src:�����ַ���
ch:�����ַ�
pos:��ʼ���ҵ�λ��
����ֵ��-1�����ڷ��򷵻ص�һ�γ���λ��
************************************************************************/
int stringx::Find(const stringx& src, const UINT pos /*= 0*/) const {
	if (pos < 0 || pos >= GetLength())
		return -1;
	return str_.find(src.GetWString(), pos);
}

/************************************************************************
�滻�ַ���
src:���滻�ַ���
ch:���滻�ַ�
����ֵ���滻����
************************************************************************/
int stringx::Replace(const stringx& src, const stringx& dest) {
	int ret = 0;
	int pos = Find(src);
	UINT len = wcslen(src.GetData());
	UINT lendest = wcslen(dest.GetData());
	while (pos != -1) {
		str_.replace(pos, len, dest.GetWString());
		pos = Find(src, pos + lendest);
		ret++;
	}
	return ret;
}

/************************************************************************
ȥ����߿ո�
����ֵ����ǰstringx����
************************************************************************/
stringx& stringx::TrimRight() {
	str_.erase(str_.find_last_not_of(L' ') + 1);
	return *this;
}

/************************************************************************
ȥ���ұ߿ո�
����ֵ����ǰstringx����
************************************************************************/
stringx& stringx::TrimLeft() {
	str_.erase(0, str_.find_first_not_of(L' '));
	return *this;
}

/************************************************************************
ɾ���ַ�
����ֵ��ɾ������
************************************************************************/
int stringx::DeleteChar(SXWCH ch) {
	wstring tmp(1, ch);
	return Replace(tmp.c_str(), L"");
}

/************************************************************************
��ʽ���ַ���
str:��ʽ�ַ���
ע������ַ�����Ҫ�ÿ��ֽڰ汾������֧������
����ֵ����ǰstringx����
************************************************************************/
stringx& stringx::Format(SXCWSTR str, ...) {
	const int buflen = MAX_PATH * 2;
	SXWCH buf[buflen] = { 0 };
	va_list ap;
	va_start(ap, str);
	const int len = _vsnwprintf_s(buf, buflen - 1, str, ap);
	va_end(ap);
	str_ = buf;
	return *this;
}

/************************************************************************
GBK/UTF8���뻥ת
����ֵ����ǰstringx����
************************************************************************/
stringx& stringx::Encode2GBK() {
	if (isutf8_) {
		SXSTR tmp = new SXCH[GetGUConvertLength(str_.c_str())];
		UTF82GBK(str_.c_str(), tmp);
		SXWSTR tmp2 = new SXWCH[GetAWConvertLength(tmp)];
		Str2WStr(tmp, tmp2);
		str_ = tmp2;
		delete[] tmp;
		delete[] tmp2;
		tmp = NULL;
		tmp2 = NULL;
		isutf8_ = false;
	}
	return *this;
}

stringx& stringx::Encode2UTF8() {
	if (!isutf8_) {
		SXSTR tmp = new SXCH[GetAWConvertLength(str_.c_str())];
		WStr2Str(str_.c_str(), tmp);
		SXWSTR tmp2 = new SXWCH[GetGUConvertLength(tmp)];
		GBK2UTF8(tmp, tmp2);
		str_ = tmp2;
		delete[] tmp;
		delete[] tmp2;
		tmp = NULL;
		tmp2 = NULL;
		isutf8_ = true;
	}
	return *this;
}

/************************************************************************
ȡ�ö��ֽ� ���ֽڻ�ת���賤��
************************************************************************/
int stringx::GetAWConvertLength(SXCSTR str) {
	return MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
}

int stringx::GetAWConvertLength(SXCWSTR str) {
	return WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
}

/************************************************************************
ȡ��GBK UTF8��ת���賤��
************************************************************************/
int stringx::GetGUConvertLength(SXCSTR str) {
	return MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
}

int stringx::GetGUConvertLength(SXCWSTR str) {
	return WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
}

/************************************************************************
���ֽ�/���ֽڻ�ת
str:��ת���ַ���
out:����ַ���
����ֵ������ַ���ָ��
************************************************************************/
SXWSTR stringx::Str2WStr(SXCSTR str, SXWSTR out) {
	assert(str);
	assert(out);
	
	MultiByteToWideChar(CP_ACP, 0, str, -1, out, GetAWConvertLength(str));
	return out;
}

SXSTR stringx::WStr2Str(SXCWSTR str, SXSTR out) {
	assert(str);
	assert(out);

	WideCharToMultiByte(CP_ACP, 0, str, -1, out, GetAWConvertLength(str),
						NULL, NULL);
	return out;
}

/************************************************************************
GBK/UTF8��ת
str:��ת���ַ���
out:����ַ���
����ֵ������ַ���ָ��
************************************************************************/
SXSTR stringx::GBK2UTF8(SXCSTR str, SXSTR out) {
	assert(str);
	assert(out);

	SXWSTR wstr = new SXWCH[GetAWConvertLength(str)];
	Str2WStr(str, wstr);
	GBK2UTF8(wstr, out);
	delete[] wstr;
	wstr = NULL;
	return out;
}

SXWSTR stringx::GBK2UTF8(SXCSTR str, SXWSTR out) {
	assert(str);
	assert(out);

	SXWSTR wstr = new SXWCH[GetAWConvertLength(str)];
	Str2WStr(str, wstr);
	GBK2UTF8(wstr, out);
	delete[] wstr;
	wstr = NULL;
	return out;
}

SXSTR stringx::GBK2UTF8(SXCWSTR str, SXSTR out) {
	assert(str);
	assert(out);

	WideCharToMultiByte(CP_UTF8, 0, str, -1, out,
						GetGUConvertLength(str),
						NULL, NULL);
	return out;
}

SXWSTR stringx::GBK2UTF8(SXCWSTR str, SXWSTR out) {
	assert(str);
	assert(out);

	const int len = GetGUConvertLength(str);
	SXSTR utfstr = new SXCH[len];
	WideCharToMultiByte(CP_UTF8, 0, str, -1, utfstr, len, NULL, NULL);
	Str2WStr(utfstr, out);
	delete[] utfstr;
	utfstr = NULL;
	return out;
}

SXWSTR stringx::UTF82GBK(SXCWSTR str, SXWSTR out) {
	assert(str);
	assert(out);

	SXSTR tmp = new SXCH[GetAWConvertLength(str)];
	WStr2Str(str, tmp);
	UTF82GBK(tmp, out);
	delete[] tmp;
	tmp = NULL;
	return out;
}

SXSTR stringx::UTF82GBK(SXCWSTR str, SXSTR out) {
	assert(str);
	assert(out);
	
	SXSTR tmp = new SXCH[GetAWConvertLength(str)];
	WStr2Str(str, tmp);
	UTF82GBK(tmp, out);
	delete[] tmp;
	tmp = NULL;
	return out;
}

SXWSTR stringx::UTF82GBK(SXCSTR str, SXWSTR out) {
	assert(str);
	assert(out);

	MultiByteToWideChar(CP_UTF8, 0, str, -1, out,
						MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0));
	return out;
}

SXSTR stringx::UTF82GBK(SXCSTR str, SXSTR out) {
	assert(str);
	assert(out);

	int len = GetGUConvertLength(str);
	SXWSTR gbkstr = new SXWCH[len];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, gbkstr, len);
	WStr2Str(gbkstr, out);
	delete[] gbkstr;
	gbkstr = NULL;
	return out;
}