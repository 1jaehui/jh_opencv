#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat img = imread("Iphone12_pro.jpg");

	namedWindow("img", 0);
	//namedWindow("img_s", 0);
	//namedWindow("img2", 0);
	//namedWindow("img3", 0);
	//namedWindow("cimg", 0);
	//namedWindow("cimg2", 0);
	//namedWindow("cimg3", 0);
	namedWindow("roi", 0);

	//bitwise_not(img, img); //�̹��� ���� ȿ��
	imshow("img", img);
	/*
	//1. ���� ���� = ������ �̹���, ������ �̹��� �� �� �ϳ��� �ٲ�� ��� �ٲ�
	Mat img_s = img;
	bitwise_not(img_s, img_s);
	imshow("img_s", img_s); 
	

	
	//2. ���� ���� = ����� �̹����� �ٲ���� ������ �̹����� ����x
	Mat img2 = img.clone();
	imshow("img2", img2);



	//3. rect�� �̿��Ͽ� Ư�� �簢�� �κи� ����, Rect (x,y,width, height)
	Rect r(img.cols / 4, img.rows / 4, img.cols / 4 * 2, img.rows / 4 * 2);

	Mat img3 = img(r).clone(); // r������ �ش��ϴ� �̹����� ����
	imshow("img3", img3);

	//4. copyTo�� �̿��� ����
	Mat cimg;
	img.copyTo(cimg);
	imshow("cimg", cimg);

	//5. �Ϻο����� copyTo�� �̿��� ����
	Mat cimg2;
	img(r).copyTo(cimg2);
	imshow("cimg2", cimg2);
	
	//6.�̹��� 2�� �̾���̱�
	Mat cimg3(Size(img.cols*2, img.rows), img.type());
	// img�� ���α��� 2��, ���� �״��, Ÿ�� �״�� > cimg3 ����

	cimg3.setTo(255); //cimg3 ������� �ʱ�ȭ
	//bitwise_not(img, img); // img ����

	img.copyTo(cimg3(Range::all(), Range(0, img.cols))); // cimg3 ���� ������ img
	img2.copyTo(cimg3(Range::all(), Range(img2.cols, img2.cols * 2))); // cimg3 ���� ������ img2

	imshow("cimg3", cimg3);
	
	*/
	//7. �̹��� �Ϻθ� ����(���� �̹����� ���� ����o)
	Rect r(img.cols / 4, img.rows / 4, img.cols / 4 * 2, img.rows / 4 * 2);
	Mat roi(img, r); // roi������ img�� r������ŭ �̹��� ����
	bitwise_not(roi, roi);
	
	imshow("img", img);
	imshow("roi", roi);
	

	waitKey(0);
	destroyAllWindows();

}

