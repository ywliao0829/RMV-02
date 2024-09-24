#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc,char** argv){
	Mat src=imread("/home/yanwei/opencv_project/test/image/test_image.tif");
	if(src.empty()){
		printf("could not load image...");
		return -1;
	}
	imshow("input",src);
	waitKey(0);
	return 0;
}	
