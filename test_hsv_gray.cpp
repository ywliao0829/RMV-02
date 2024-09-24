#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;
int main(int argc,char** argv){
	Mat gray,hsv,src=imread("/home/yanwei/opencv_project/resources/test_image.png");
	if(src.empty()){
		cout<<"could not load image...";
		return -1;
	}
	cvtColor(src,hsv,COLOR_BGR2HSV);
	cvtColor(src,gray,COLOR_BGR2GRAY);
	imshow("HSV",hsv);
	waitKey(0);
	imshow("gray",gray);
	waitKey(0);
	imwrite("/home/yanwei/opencv_project/resources/hsv.png",hsv);
	imwrite("/home/yanwei/opencv_project/resources/gray.png",gray);
	return 0;
}

