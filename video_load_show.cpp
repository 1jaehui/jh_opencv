#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char) {

	VideoCapture capture(0); // read videofile (������ ���� �б�), capture ��� ������ ������ ���� ����
	Mat frame; // ��� ����

	if (!capture.isOpened()) { 
		printf("MP4 file can not open. \n");
		return 0;
	} //�������� ���� ���� �� ��Ÿ�� �޼���

	namedWindow("videofile", 0); //������ ����� â ����

	while (1) {
		capture >> frame; //������ ����(���� : capture)�� frame�̶�� ������ �̵���Ŵ
	
			if (frame.empty()) {
				break;
		}  //������ ������ ������ while�� ����

		Sobel(frame, frame, frame.depth(), 1, 0);
		imshow("videofile", frame);

		if (waitKey(10) == 27) {
			break;
		}

	}
	return 0;
}