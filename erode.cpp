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
	Mat structureElement=getStructuringElement(MORPH_RECT,Size(w/50+1,h/50+1),Point(-1,-1));
	//dilate(src,dst,structureElement,Point(-1,-1),1);
	erode(src,dst,structureElement);
	imshow("erode",dst);
	waitKey(0);
	imwrite("/home/yanwei/opencv_project/resources/erode.png",dst);
	return 0;
}

