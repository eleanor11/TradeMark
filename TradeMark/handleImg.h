#include <opencv2\opencv.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;

IplImage* loadImg(string str){

	IplImage *img = cvLoadImage(str.c_str());

	return img;
}

void saveImg(IplImage* img, string str){

	cvSaveImage(str.c_str(), img);

}

string removeWaterMark(string str){
	Mat img = imread(str);
	cvtColor(img, img, CV_RGB2GRAY);
	//Mat newImg0, newImg1;
	//threshold(img, newImg0, 180, 255, THRESH_BINARY);
	//threshold(img, newImg1, 190, 255, THRESH_BINARY);
	//imwrite("new.png", newImg0 - newImg1);

	Mat lut(1, 256, CV_8U);
	for (int i = 0; i < 256; i++) {
		lut.at<uchar>(i) = i;
	}
	lut.at<uchar>(184) = 255;

	LUT(img, lut, img);

	imwrite("new.png", img);

	return "new.png";
	//return str;
}
