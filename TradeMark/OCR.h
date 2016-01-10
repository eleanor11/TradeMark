
#include <baseapi.h>
#include <string>

#pragma comment(lib,"libtesseract302d.lib")

using namespace std;

string UTF8ToGBK(const std::string& strUTF8);
string img2chi(string name); 
string img2eng(string name);