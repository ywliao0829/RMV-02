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
	Rect rect;
	rect.x=100;
	rect.y=100;
	rect.width=250;
	rect.height=250;
	Mat bg=Mat::zeros(src.size(),src.type());
	rectangle(bg,rect,Scalar(255,0,0),-1,8,0);
	circle(bg,Point(300,400),100,Scalar(0,255,0),-1,8,0);
	addWeighted(src,0.7,bg,0.3,0,dst);
	imshow("shapes_drawing",dst);
	waitKey(0);
	imwrite("/home/yanwei/opencv_project/resources/shapes_drawing.png",dst);
	return 0;
}	
