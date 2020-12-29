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

	//bitwise_not(img, img); //이미지 반전 효과
	imshow("img", img);
	/*
	//1. 값을 참조 = 참조된 이미지, 참조한 이미지 둘 중 하나가 바뀌면 모두 바뀜
	Mat img_s = img;
	bitwise_not(img_s, img_s);
	imshow("img_s", img_s); 
	

	
	//2. 값을 복사 = 복사된 이미지가 바뀌더라도 복사한 이미지는 변경x
	Mat img2 = img.clone();
	imshow("img2", img2);



	//3. rect를 이용하여 특정 사각형 부분만 복사, Rect (x,y,width, height)
	Rect r(img.cols / 4, img.rows / 4, img.cols / 4 * 2, img.rows / 4 * 2);

	Mat img3 = img(r).clone(); // r구역에 해당하는 이미지만 복사
	imshow("img3", img3);

	//4. copyTo를 이용한 복사
	Mat cimg;
	img.copyTo(cimg);
	imshow("cimg", cimg);

	//5. 일부영역을 copyTo를 이용한 복사
	Mat cimg2;
	img(r).copyTo(cimg2);
	imshow("cimg2", cimg2);
	
	//6.이미지 2개 이어붙이기
	Mat cimg3(Size(img.cols*2, img.rows), img.type());
	// img의 가로길이 2배, 높이 그대로, 타입 그대로 > cimg3 생성

	cimg3.setTo(255); //cimg3 흰색으로 초기화
	//bitwise_not(img, img); // img 반전

	img.copyTo(cimg3(Range::all(), Range(0, img.cols))); // cimg3 우측 절반은 img
	img2.copyTo(cimg3(Range::all(), Range(img2.cols, img2.cols * 2))); // cimg3 좌측 절반은 img2

	imshow("cimg3", cimg3);
	
	*/
	//7. 이미지 일부를 참조(원본 이미지와 서로 영향o)
	Rect r(img.cols / 4, img.rows / 4, img.cols / 4 * 2, img.rows / 4 * 2);
	Mat roi(img, r); // roi변수에 img의 r영역만큼 이미지 참조
	bitwise_not(roi, roi);
	
	imshow("img", img);
	imshow("roi", roi);
	

	waitKey(0);
	destroyAllWindows();

}

