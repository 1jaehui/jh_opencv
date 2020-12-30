#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int, char) {

	VideoCapture capture(".\\Meditation.mp4"); // read videofile (������ ���� �б�), capture ��� ������ ������ ���� ����
	Mat frame; // �� �����Ӿ� �ޱ� ���� ����

	int askFileTypeBox = 0;
	int Color = 1;
	Size S = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), 
		(int)capture.get(CAP_PROP_FRAME_HEIGHT)); //���� ������� ������ ũ��(���� ��, ����)�� �̿�


	VideoWriter outVideo; //Ŭ������ VideoWriter�� ���� ����
	outVideo.open(".\\outVideo.avi", askFileTypeBox, capture.get(CAP_PROP_FPS), S, Color);
		//������ ���� �̸�, �ڵ��ڽ��� ��������, 1�ʿ� �� ������ ����, ���� ���μ��� ũ��,  ��
		//CV_CAP_PROP_FPS : ���� �״���� ������

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

		//Sobel(frame, frame, frame.depth(), 1, 0);
		imshow("videofile", frame);
		outVideo << frame; //�� �������� outVideo������ ���� �� �����Ͱ� while���� ���鼭 �� �����Ӿ� ����� 


		if (waitKey(10) == 27) {
			break;
		}

	}
	return 0;
}