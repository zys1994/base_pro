//
// Created by zysC on 2018/1/14.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

void imrotate(Mat& img, Mat& newIm, double angle)
{
    int len = max(img.cols, img.rows);
    Point2f pt(len/2.,len/2.);
    Mat r = getRotationMatrix2D(pt,angle,1.0);
    warpAffine(img,newIm,r,Size(len,len));
}
int main()
{
    Mat img = imread("rotate.png");
    Mat newIm;
    Mat newIm_size;
    imrotate(img,newIm,15);
    resize(img,newIm_size,Size(img.rows/2,img.cols/2));
    imshow("src",img);
    //imshow("Rotate",newIm);
    imshow("Risize",newIm_size);
    waitKey(0);
    return 0;
}
