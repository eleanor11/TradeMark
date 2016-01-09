#include <opencv2\opencv.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <math.h>
#include <list>
#include <strstream>

using namespace cv;

const string strs[12] = {
	"imgs/1456_1_168EB22AA162501EE053640B503A501E",
	"imgs/1456_1_168EB22AA165501EE053640B503A501E",
	"imgs/1456_1_168EB22AA16A501EE053640B503A501E",
	"imgs/1456_1_168EB22AA16C501EE053640B503A501E",
	"imgs/1456_1_168EB22AA16D501EE053640B503A501E",
	"imgs/1456_1_168EB22AA16E501EE053640B503A501E",
	"imgs/1456_1_168EB22AA16F501EE053640B503A501E",
	"imgs/1456_5_168EB22AA1AB501EE053640B503A501E",
	"imgs/1456_5_168EB22AA1AC501EE053640B503A501E",
	"imgs/1456_11_168EB22AA1F9501EE053640B503A501E",
	"imgs/1456_13_168EB22AA221501EE053640B503A501E",
	"imgs/1456_15_168EB22AA23B501EE053640B503A501E",
};
const string addition[8] = {
	".png",
	"_re_water.png",
	"_mark.png",
	"_cut_edge.png",
	"_column1.png",
	"_column2.png",
	"_column1_mark.png",
	"_column2_mark.png"
};

const int boundary = 4;
const int imgNum = 12;

class HandleImg {

public:
	HandleImg() {
		images.clear();
	}
	~HandleImg() {

	}

	int getImgNum() {
		return images.size();
	}
	int getMarkerNum() {
		return newImages.size();
	}

	IplImage* loadImg(string str);
	void saveImg(IplImage* img, string str);

	void loadImages();
	void removeWaterMark();
	void markImages();
	void cutEdges();
	void cutColumns();
	void cutMarkers();
	void getInfo();

	void cutImages();

	string removeWaterMark(string str);
	string cutImages(string str);
	string getInfo(string str);


private: 
		vector<Mat> images;
		vector<Mat> newImages;
		vector<std::list<int>> imageRows;

};