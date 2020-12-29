#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int, char) {

	Mat img = imread("Iphone12_pro.jpg");
	Mat img2;

	namedWindow("img", 0); 
	namedWindow("img2", 0); // 결과 이미지를 보여줄 윈도우창 추가
	
	//Sobel(img, img2, img.depth(), 1, 0); // sobel filter
	flip(img, img2, 1); // 좌우대칭 (1 >> 0 : 상하대칭)

	imshow("img", img); // img라는 창에 img라는 이미지 데이터를 게시
	imshow("img2", img2);
	
	waitKey(0);

	destroyAllWindows();

}