#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char) {

	Mat mtx(4, 4, CV_32FC1);
	Mat cmtx(5, 1, CV_64FC2);
	// ����� ���� ���ÿ�

	Mat img(Size(3, 3), CV_8UC3);
	// size�� �̿��� ���� �� ����

	Mat mtx2;
	mtx2 = Mat(2, 4, CV_64FC1);
	// �̸� ���� �� ����

	Mat* mtx3 = new Mat(3, 3, CV_32F);
	delete mtx3;
	// �����͸� �̿��� ���� �� ����

	mtx.setTo(10);
	img.setTo(5);

	cout << mtx << endl << endl;
	cout << img << endl;

}