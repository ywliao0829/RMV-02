#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;
int main(int argc,char** argv){
	Mat dst,src=imread("/home/yanwei/opencv_project/resources/test_image.png");
	if(src.empty()){
		cout<<"could not load image..."<<endl;
		return -1;
	}
	int w=src.cols;
	int h=src.rows;
	GaussianBlur(src,dst,Size(w/50+1,h/50+1),11,11);
	imshow("gaussian_filtering",dst);
	waitKey(0);
	imwrite("/home/yanwei/opencv_project/resources/gaussian_filtering.png",dst);
	return 0;
}

