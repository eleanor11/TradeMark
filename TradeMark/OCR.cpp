#include "OCR.h"

using namespace std;

string UTF8ToGBK(const std::string& strUTF8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, NULL, 0);
	unsigned short * wszGBK = new unsigned short[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, LPCSTR(strUTF8.c_str()), -1, LPWSTR(wszGBK), len);

	len = WideCharToMultiByte(CP_ACP, 0, LPCTSTR(wszGBK), -1, NULL, 0, NULL, NULL);
	char *szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, LPCTSTR(wszGBK), -1, szGBK, len, NULL, NULL);
	//strUTF8 = szGBK;  
	string strTemp(szGBK);
	delete[]szGBK;
	delete[]wszGBK;
	return strTemp;
}

string img2chi(string name) {

	tesseract::TessBaseAPI api;
	api.Init(NULL, "chi_sim", tesseract::OEM_DEFAULT);
	STRING text_out;
	if (!api.ProcessPages(name.c_str(), NULL, 0, &text_out)) {
		return "";
	}
	string str = string(text_out.string());

	//return UTF8ToGBK(str);
	return str;
}

string img2eng(string name) {

	tesseract::TessBaseAPI api;
	api.Init(NULL, "eng", tesseract::OEM_DEFAULT);
	STRING text_out;
	if (!api.ProcessPages(name.c_str(), NULL, 0, &text_out)) {
		return "";
	}
	string str = string(text_out.string());

	//return UTF8ToGBK(str);
	return str;
}