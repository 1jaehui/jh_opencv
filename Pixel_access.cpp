#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char) {
	
	namedWindow("img", 0);
	Mat img = imread("Certificate.jpg");

	/*
	// data �� �̿��Ͽ� �̹��� �����Ϳ� �����Ͽ� �̹��� (�Ϻ�) ������Ű�� 
	for (int y = img.rows/3; y < img.rows/3*2; y++) {
		for (int x = img.cols/3; x < img.cols/3*2; x++) {

			unsigned r, g, b;

			// �ϳ��� �ȼ��� ���������� ���� b,g,r�� ����
			b = img.data[y*img.step + x * img.elemSize() + 0]; // step : ��� 1���� ����Ʈ ��, elemSize : ��� ��� �ϳ��� ����Ʈ ��
			g = img.data[y*img.step + x * img.elemSize() + 1];
			r = img.data[y*img.step + x * img.elemSize() + 2];

			// �Է¹��� b,g,r�� �̿��Ͽ� ������Ű��
			img.data[y*img.step + x * img.elemSize() + 0] = unsigned char(255 - b);
			img.data[y*img.step + x * img.elemSize() + 1] = unsigned char(255 - g);
			img.data[y*img.step + x * img.elemSize() + 2] = unsigned char(255 - r);
		}
	} 

	// at�� �̿��Ͽ� �̹��� �����Ϳ� �����Ͽ� �̹��� (�Ϻ�) ������Ű�� 
	for (int y = img.rows / 3; y < img.rows / 3 * 2; y++) {
		for (int x = img.cols / 3; x < img.cols / 3 * 2; x++) {

			unsigned r, g, b;

			// �ϳ��� �ȼ��� ���������� ���� b,g,r�� ����
			b = img.at<cv::Vec3b>(y, x)[0]; //y�� x��, 0��° ä��(B)�� �����͸� b�� ����
			g = img.at<cv::Vec3b>(y, x)[1]; //y�� x��, 1��° ä��(G)�� �����͸� g�� ����
			r = img.at<cv::Vec3b>(y, x)[2]; //y�� x��, 2��° ä��(R)�� �����͸� r�� ����

			// �Է¹��� b,g,r�� �̿��Ͽ� ������Ű��
			img.at<cv::Vec3b>(y, x)[0] = unsigned char(255 - b);
			img.at<cv::Vec3b>(y, x)[1] = unsigned char(255 - g);
			img.at<cv::Vec3b>(y, x)[2] = unsigned char(255 - r);
		}
	} 

	// ptr�� �̿��Ͽ� �̹��� �����Ϳ� �����Ͽ� �̹��� (�Ϻ�) ������Ű�� 
	for (int y = img.rows / 10 * 5; y < img.rows / 10 * 6; y++) {
		
		cv::Vec3b* ptr = img.ptr<cv::Vec3b>(y);  //img�� y��° �� ������ ptr�� ����

		for (int x = 0; x < img.cols; x++) {

			//���1
			unsigned char b1 = ptr[x][0]; // �ռ��� ������ y��° �� �����Ϳ��� x��°+0ä��(B)�� �����͸� b1�� ����
			unsigned char g1 = ptr[x][1]; // �ռ��� ������ y��° �� �����Ϳ��� x��°+1ä��(G)�� �����͸� g1�� ����
			unsigned char r1 = ptr[x][2]; // �ռ��� ������ y��° �� �����Ϳ��� x��°+2ä��(R)�� �����͸� r1�� ����
		
			//���2
			cv::Vec3b bgr = ptr[x]; // �ռ��� ������ i��° �� �����Ϳ��� x���� ������ bgr�� ���� 
			unsigned char b2 = bgr[0]; // bgr�� 0ä��(B)�� ������ b2�� ����
			unsigned char g2 = bgr[1]; // bgr�� 1ä��(G)�� ������ g2�� ����
			unsigned char r2 = bgr[2]; // bgr�� 2ä��(R)�� ������ r2�� ����

				//�̹��� ����
				ptr[x] = cv::Vec3b(255 - b1, 255 - g1, 255 - r1);

		}
	


	}

	*/

	// iteration�� �̿��Ͽ� �̹��� �����Ϳ� �����Ͽ� �̹��� ������Ű�� 
	cv::MatIterator_<cv::Vec3b> itd = img.begin<cv::Vec3b>(), itd_end = img.end<cv::Vec3b>(); //itd : �̹��� ��������, itd_end : �̹��� ������ ���� �� �ʱ�ȭ

	for (int i = 0; itd != itd_end; ++itd, ++i) {

		cv::Vec3b bgr = (*itd); // itd������ ���� ���� bgr�� ����

		(*itd)[0] = 255 - bgr[0]; // �̹��� 0��ä��(B) ����
		(*itd)[1] = 255 - bgr[1]; // �̹��� 1��ä��(G) ����
		(*itd)[2] = 255 - bgr[2]; // �̹��� 2��ä��(R) ����

	}


	imshow("img", img);
	waitKey(0);
	destroyAllWindows();
}