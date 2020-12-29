#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int, char) {

	Mat img = imread("Iphone12_pro.jpg");
	Mat img2;

	namedWindow("img", 0); 
	namedWindow("img2", 0); // ��� �̹����� ������ ������â �߰�
	
	//Sobel(img, img2, img.depth(), 1, 0); // sobel filter
	flip(img, img2, 1); // �¿��Ī (1 >> 0 : ���ϴ�Ī)

	imshow("img", img); // img��� â�� img��� �̹��� �����͸� �Խ�
	imshow("img2", img2);
	
	waitKey(0);

	destroyAllWindows();

}