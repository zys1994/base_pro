#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int Canny_Test();
int Sobel_Test();
int main()
{
    //Canny_Test();
    //Sobel_Test();
    waitKey(0);
    return 0;
}
int Canny_Test()
{
    Mat src = imread("canny_test.png",0);  //工程目录下应该有一张名为1.jpg的素材图
    imshow("src", src);
    medianBlur(src,src,5);
    Canny( src, src, 150, 100,3 );
    imshow("dst", src);
}

int Sobel_Test()
{
    //【0】创建 grad_x 和 grad_y 矩阵
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y,dst;

    //【1】载入原始图
    Mat src = imread("sobel_test.jpg",0);  //工程目录下应该有一张名为1.jpg的素材图

    //【2】显示原始图
    imshow("s1", src);

    //【3】求 X方向梯度
    Sobel( src, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT );
    convertScaleAbs( grad_x, abs_grad_x );
    imshow("s2", abs_grad_x);

    //【4】求Y方向梯度
    Sobel( src, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT );
    convertScaleAbs( grad_y, abs_grad_y );
    imshow("s3", abs_grad_y);

    //【5】合并梯度(近似)
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst );
    imshow("s4", dst);
}