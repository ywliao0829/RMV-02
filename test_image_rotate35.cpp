#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;
int main(int argc,char** argv){
	Mat M,dst,src=imread("/home/yanwei/opencv_project/resources/test_image.png");
	if(src.empty()){
		cout<<"could not load image...";
		return -1;
	}
	int w=src.cols;
	int h=src.rows;
	M=getRotationMatrix2D(Point(w/2,h/2),35,1.0);//parameter : central point location , angle of rotation , scale factor
	//create new_wide && new_height
	double sin=abs(M.at<double>(0,1));
	double cos=abs(M.at<double>(0,0));
	int nw=w*cos+h*sin;
	int nh=w*sin+h*cos;
	M.at<double>(0,2)+=(nw/2-w/2);
	M.at<double>(1,2)+=(nh/2-h/2);
	warpAffine(src,dst,M,Size(nw,nh));
	imshow("image_rotate35",dst);
	waitKey(0);
	imwrite("/home/yanwei/opencv_project/resources/image_rotate35.png",dst);
	return 0;
}

