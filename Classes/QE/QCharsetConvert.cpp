//#include "QCharsetConvert.h"
//
//#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//#include "external/win32-specific/icon/include/iconv.h"
//#else
//#include "iconv.h"
////#include "iconv/include/iconv.h"
//#endif
//
//int QCharsetConvert::IsTextUTF8(const char* str, int length)
//{
//	int i;
//	int nBytes = 0;//UFT8����1-6���ֽڱ���,ASCII��һ���ֽ�
//	char chr;
//	bool bAllAscii = true; //���ȫ������ASCII, ˵������UTF-8
//	for (i = 0; i < length; i++)
//	{
//		chr = *(str + i);
//		if ((chr & 0x80) != 0) // �ж��Ƿ�ASCII����,�������,˵���п�����UTF-8,ASCII��7λ����,����һ���ֽڴ�,���λ���Ϊ0,o0xxxxxxx
//			bAllAscii = false;
//		if (nBytes == 0) //�������ASCII��,Ӧ���Ƕ��ֽڷ�,�����ֽ���
//		{
//			if (chr >= 0x80)
//			{
//				if (chr >= 0xFC && chr <= 0xFD)
//					nBytes = 6;
//				else if (chr >= 0xF8)
//					nBytes = 5;
//				else if (chr >= 0xF0)
//					nBytes = 4;
//				else if (chr >= 0xE0)
//					nBytes = 3;
//				else if (chr >= 0xC0)
//					nBytes = 2;
//				else
//				{
//					return false;
//				}
//				nBytes--;
//			}
//		}
//		else //���ֽڷ��ķ����ֽ�,ӦΪ 10xxxxxx
//		{
//			if ((chr & 0xC0) != 0x80)
//			{
//				return false;
//			}
//			nBytes--;
//		}
//	}
//	if (nBytes > 0) //Υ������
//	{
//		return false;
//	}
//	if (bAllAscii) //���ȫ������ASCII, ˵������UTF-8
//	{
//		return false;
//	}
//	return true;
//}
//
//int QCharsetConvert::code_convert(const char* from_charset, const char* to_charset, const char* inbuf, size_t inlen, char* outbuf, size_t outlen)
//{
//	iconv_t cd;
//	const char* temp = inbuf;
//	const char** pin = &temp;
//	char** pout = &outbuf;
//	memset(outbuf, 0, outlen);
//	cd = iconv_open(to_charset, from_charset);
//	if (cd == 0) return -1;
//	if (iconv(cd, pin, &inlen, pout, &outlen) == -1) return -1;
//	iconv_close(cd);
//	return 0;
//}
//
//string QCharsetConvert::GBKToUTF8(const char* inbuf)
//{
//	size_t inlen = strlen(inbuf);
//	char* outbuf = new char[inlen * 2 + 2];
//	std::string strRet;
//	if (code_convert("gb2312", "utf-8", inbuf, inlen, outbuf, inlen * 2 + 2) == 0)
//	{
//		strRet = outbuf;
//	}
//	delete[] outbuf;
//	return strRet;
//}
//
//string QCharsetConvert::UTF8ToGBK(const char* inbuf)
//{
//	size_t inlen = strlen(inbuf);
//	char* outbuf = new char[inlen * 2 + 2];
//	std::string strRet;
//	if (code_convert("utf-8", "gb2312", inbuf, inlen, outbuf, inlen * 2 + 2) == 0)
//	{
//		strRet = outbuf;
//	}
//	delete[] outbuf;
//	return strRet;
//}