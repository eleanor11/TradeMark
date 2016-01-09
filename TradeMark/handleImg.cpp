#include "handleImg.h"

IplImage* HandleImg::loadImg(string str){

	IplImage *img = cvLoadImage(str.c_str());

	return img;
}

void HandleImg::saveImg(IplImage* img, string str){

	cvSaveImage(str.c_str(), img);

}

void HandleImg::loadImages() {

	for (int i = 0; i < imgNum; i++) {
		Mat img = imread(strs[i] + addition[0]);
		images.push_back(img);
	}
}

void HandleImg::removeWaterMark() {
	
	Mat lut(1, 256, CV_8U);
	for (int i = 0; i < 256; i++) {
		lut.at<uchar>(i) = i;
	}
	lut.at<uchar>(184) = 255;

	for (int i = 0; i < imgNum; i++) {
		Mat img = images[i];
		cvtColor(img, img, CV_RGB2GRAY);
		LUT(img, lut, img);
		imwrite(strs[i] + addition[1], img);
		newImages.push_back(img);
	}
}

int min(int x, int y) {
	if (x < y) return x;
	else return y;
}
int max(int x, int y) {
	if (x > y) return x;
	else return y;
}
void getVerticleLines(std::vector<Vec4i> lines, std::vector<Vec4i> &verticle, std::vector<Vec4i> &horizontal){
	for (int i = 0; i < lines.size(); i++) {
		Vec4i l = lines[i];
		if (l[0] == l[2]) {
			verticle.push_back(l);
		}
		if (l[1] == l[3]) {
			horizontal.push_back(l);
		}
	}
}
void getPoints(std::vector<Vec4i> lines, int &xmin, int &xmid, int &xmax, int &ymin, int &ymax) {
	vector<Vec4i> verticle, horizontal;
	verticle.clear(); horizontal.clear();
	getVerticleLines(lines, verticle, horizontal);

	int x1, x2;
	int y1 = verticle[0][3];
	int y2 = verticle[0][1];
	for (int i = 0; i < verticle.size(); i++) {
		Vec4i l = verticle[i];
		x1 += l[0];
		y1 = min(y1, l[3]);
		y2 = max(y2, l[1]);
	}
	xmid = x1 / verticle.size();
	ymin = y1;
	ymax = y2;

	x1 = x2 = 0;
	int t = 0;
	for (int i = 0; i < horizontal.size(); i++) {
		Vec4i l = horizontal[i];
		if (std::abs(l[1] - ymin) < 5) {
			x1 += l[0];
			x2 += l[2];
			t++;
		}
		if (std::abs(l[1] - ymax) < 5) {
			x1 += l[0];
			x2 += l[2];
			t++;
		}
	}
	xmin = x1 / t;
	xmax = x2 / t;
}
std::list<int> selectLines(std::vector<Vec4i> &lines, int max) {
	vector<Vec4i> tmpLines = lines;
	lines.clear();
	std::list<int> rows;
	rows.clear();
	for (int i = 0; i < tmpLines.size(); i++) {
		Vec4i l = tmpLines[i];
		if (l[1] == l[3]){
			lines.push_back(l);
			rows.push_back(l[1]);
		}
	}
	rows.sort();

	int t = 0;
	std::list<int>::iterator it = rows.begin();
	while (it != rows.end()) {
		while (it != rows.end()) {
			int t2 = *it;
			if (t2 - t < 5) {
				it++;
				rows.remove(t2);
			}
			else if (max - t2 < 5) {
				it++;
				rows.remove(t2);
			}
			else {
				break;
			}
		}
		if (it == rows.end()) break;
		t = *it;
		it++;
	}

	return rows;
}

int getInfoNum(Mat img) {

	int num = 0;

	int t = img.channels();

	int last = -1;
	for (int i = 0; i < img.rows; i++) {
		int s = -1, e = -1;
		for (int j = 1; j < img.cols - 1; j++) {
			if (img.at<uchar>(i, j) < 255) {
				if (s < 0) {
					s = j;
				}
				e = j;
			}
		}

		if (s > 1){
			if (s < 30) {
				if (last < 0 || i - last > 1) {
					num++;
				}
				last = i;
			}
		}

	}
	return num;
}

void HandleImg::markImages() {
	Mat contours;
	std::vector<Vec4i> lines;
	for (int i = 0; i < imgNum; i++) {
		Mat img = newImages[i];
		Canny(img, contours, 125, 350);
		HoughLinesP(contours, lines, 1, CV_PI / 180, 200, 450, 10);
		for (int i = 0; i < lines.size(); i++){
			Vec4i l = lines[i];
			line(img, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, CV_AA);
		}

		int xmin, xmid, xmax, ymin, ymax;
		getPoints(lines, xmin, xmid, xmax, ymin, ymax);

		line(img, Point(xmin, ymin), Point(xmin, ymax), Scalar(0, 0, 255), 3, CV_AA);
		line(img, Point(xmid, ymin), Point(xmid, ymax), Scalar(0, 0, 255), 3, CV_AA);
		line(img, Point(xmax, ymin), Point(xmax, ymax), Scalar(0, 0, 255), 3, CV_AA);
		line(img, Point(xmin, ymin), Point(xmax, ymin), Scalar(0, 0, 255), 3, CV_AA);
		line(img, Point(xmin, ymax), Point(xmax, ymax), Scalar(0, 0, 255), 3, CV_AA);

		imwrite(strs[i] + addition[2], img);
		newImages[i] = img;
	}
}
void HandleImg::cutEdges() {
	Mat contours;
	std::vector<Vec4i> lines;
	for (int i = 0; i < imgNum; i++) {
		Mat img = newImages[i];
		Canny(img, contours, 125, 350);
		HoughLinesP(contours, lines, 1, CV_PI / 180, 200, 450, 10);

		int xmin, xmid, xmax, ymin, ymax;
		getPoints(lines, xmin, xmid, xmax, ymin, ymax);

		Rect rect(xmin, ymin, xmax - xmin, ymax - ymin);
		img(rect).copyTo(img);

		imwrite(strs[i] + addition[3], img);

		newImages[i] = img;
	}
}
void HandleImg::cutColumns() {

	vector<Mat> tmpImages = newImages;
	newImages.clear();

	Mat contours;
	std::vector<Vec4i> lines;
	for (int i = 0; i < imgNum; i++) {
		Mat img = tmpImages[i];
		Canny(img, contours, 125, 350);
		HoughLinesP(contours, lines, 1, CV_PI / 180, 200, 450, 10);

		int xmin, xmid, xmax, ymin, ymax;
		getPoints(lines, xmin, xmid, xmax, ymin, ymax);
		Rect rect(xmin, ymin, xmax - xmin, ymax - ymin);
		img(rect).copyTo(img);

		Rect rect1(0, 0, xmid - xmin, ymax - ymin);
		Rect rect2(xmid - xmin, 0, xmax - xmid, ymax - ymin);
		Mat img1, img2;
		img(rect1).copyTo(img1);
		img(rect2).copyTo(img2);

		//imwrite(strs[i] + addition[4], img1);
		//imwrite(strs[i] + addition[5], img2);

		newImages.push_back(img1);
		newImages.push_back(img2);
	}

}
void HandleImg::cutMarkers() {

	cutColumns();

	vector<Mat> tmpImages = newImages;
	newImages.clear();

	Mat contours;
	std::vector<Vec4i> lines;
	bool save = true;
	Mat lastImg;
	int lastNum;
	for (int i = 0; i < tmpImages.size(); i++) {
		Mat img = tmpImages[i];
		Canny(img, contours, 125, 350);
		HoughLinesP(contours, lines, 1, CV_PI / 180, 200, 250, 10);
		std::list<int> rows = selectLines(lines, img.rows);
		std::list<int>::iterator it = rows.begin();
		int xmin = 0, h;
		int ymin = 0, w = img.cols;
		while (it != rows.end()) {
			h = *it - xmin;

			if (h > 5) {

				Rect rect(ymin, xmin, w, h);
				Mat img1;
				img(rect).copyTo(img1);

				if (!save) {
					if (lastNum + getInfoNum(img1) < 10) {
						Mat newImg = Mat(lastImg.rows + img1.rows, max(lastImg.cols, img1.cols), img1.type());
						lastImg.copyTo(newImg(Rect(0, 0, lastImg.cols, lastImg.rows)));
						img1.copyTo(newImg(Rect(0, lastImg.rows, img1.cols, img1.rows)));
						img1 = newImg;
						save = true;
					}
					else {
						int tmp = newImages.size();
						std::stringstream ss;
						ss << tmp;
						String str = "markers/marker_" + ss.str() + ".png";
						imwrite(str, lastImg);
						newImages.push_back(lastImg);
						save = true;
					}
				}
				if (save) {
					int tmp = newImages.size();
					std::stringstream ss;
					ss << tmp;
					String str = "markers/marker_" + ss.str() + ".png";
					imwrite(str, img1);
					newImages.push_back(img1);
				}
			}

			xmin += h;
			it++;
		}
		h = img.rows - xmin; 
		
		if (h > 5) {

			Rect rect(ymin, xmin, w, h);
			Mat img1;
			img(rect).copyTo(img1);

			if (!save) {
				Mat newImg = Mat(lastImg.rows + img1.rows, max(lastImg.cols, img1.cols), img1.type());
				lastImg.copyTo(newImg(Rect(0, 0, lastImg.cols, lastImg.rows)));
				img1.copyTo(newImg(Rect(0, lastImg.rows, img1.cols, img1.rows)));
				img1 = newImg;
				save = true;
			}
			else {
				int num = getInfoNum(img1);
				if (getInfoNum(img1) < 8) {
					//imwrite("img.png", img1);
					save = false;
					lastImg = img1;
					lastNum = num;
				}
			}

			if (save) {
				int tmp = newImages.size();
				std::stringstream ss;
				ss << tmp;
				String str = "markers/marker_" + ss.str() + ".png";
				imwrite(str, img1);
				newImages.push_back(img1);
			}
		}


	}
}
void HandleImg::getInfo() {

}

string HandleImg::removeWaterMark(string str){
	Mat img = imread(str);
	cvtColor(img, img, CV_RGB2GRAY);

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
string HandleImg::cutImages(string str) {
	Mat img = imread(str);
	
	Mat contours;
	Canny(img, contours, 125, 350);
	std::vector<Vec4i> lines;
	HoughLinesP(contours, lines, 1, CV_PI / 180, 200, 250, 10);
	for (int i = 0; i < lines.size(); i++){
		Vec4i l = lines[i];
		line(img, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, CV_AA);
	}

	imwrite("new.png", img);

	//int xmin, xmid, xmax, ymin, ymax;
	//getPoints(lines, xmin, xmid, xmax, ymin, ymax);

	//line(img, Point(xmin, ymin), Point(xmin, ymax), Scalar(0, 0, 255), 3, CV_AA);
	//line(img, Point(xmid, ymin), Point(xmid, ymax), Scalar(0, 0, 255), 3, CV_AA);
	//line(img, Point(xmax, ymin), Point(xmax, ymax), Scalar(0, 0, 255), 3, CV_AA);
	//line(img, Point(xmin, ymin), Point(xmax, ymin), Scalar(0, 0, 255), 3, CV_AA);
	//line(img, Point(xmin, ymax), Point(xmax, ymax), Scalar(0, 0, 255), 3, CV_AA);

	//Rect rect(xmin, ymin, xmax - xmin, ymax - ymin);
	//img(rect).copyTo(img);

	//imwrite("new.png", img);
	return "new.png";
}
string HandleImg::getInfo(string str) {
	Mat img = imread(str);

	int t = img.channels();

	std::vector<Vec2i> lines;

	std::vector<int> lines2;

	int last = -1;
	for (int i = 0; i < img.rows; i++) {
		int s = -1, e = -1;
		for (int j = 1; j < img.cols - 1; j++) {
			Vec3b &rgb = img.at<Vec3b>(i, j);
			if (rgb[0] < 255) {
				if (s < 0) {
					s = j;
				}
				e = j;
			}
		}
		
		if (s > 1){
			if (s < 30) {
				if (last < 0 || i - last > 1) {
					lines2.push_back(i - 1);
				}
				last = i;
			}

		}
		lines.push_back(Vec2i(s, e));

	}

	//for (int i = 0; i < lines2.size(); i++) {
	//	line(img, Point(0, lines2[i]), Point(img.cols, lines2[i]), Scalar(0, 0, 255), 1, CV_AA);
	//}

	for (int i = 0; i < img.rows; i++) {
		int s = lines[i][0];
		int e = lines[i][1];
		line(img, Point(s, i), Point(e, i), Scalar(0, 0, 255), 1, CV_AA);
	}

	imwrite("new.png", img);
	return "new.png";
}