#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char) {
	
	namedWindow("img", 0);
	Mat img = imread("Certificate.jpg");

	/*
	// data 를 이용하여 이미지 데이터에 접근하여 이미지 (일부) 반전시키기 
	for (int y = img.rows/3; y < img.rows/3*2; y++) {
		for (int x = img.cols/3; x < img.cols/3*2; x++) {

			unsigned r, g, b;

			// 하나의 픽셀의 색상정보를 변수 b,g,r에 대입
			b = img.data[y*img.step + x * img.elemSize() + 0]; // step : 행렬 1행의 바이트 수, elemSize : 행렬 요소 하나의 바이트 수
			g = img.data[y*img.step + x * img.elemSize() + 1];
			r = img.data[y*img.step + x * img.elemSize() + 2];

			// 입력받은 b,g,r을 이용하여 반전시키기
			img.data[y*img.step + x * img.elemSize() + 0] = unsigned char(255 - b);
			img.data[y*img.step + x * img.elemSize() + 1] = unsigned char(255 - g);
			img.data[y*img.step + x * img.elemSize() + 2] = unsigned char(255 - r);
		}
	} 

	// at을 이용하여 이미지 데이터에 접근하여 이미지 (일부) 반전시키기 
	for (int y = img.rows / 3; y < img.rows / 3 * 2; y++) {
		for (int x = img.cols / 3; x < img.cols / 3 * 2; x++) {

			unsigned r, g, b;

			// 하나의 픽셀의 색상정보를 변수 b,g,r에 대입
			b = img.at<cv::Vec3b>(y, x)[0]; //y행 x열, 0번째 채널(B)의 데이터를 b에 대입
			g = img.at<cv::Vec3b>(y, x)[1]; //y행 x열, 1번째 채널(G)의 데이터를 g에 대입
			r = img.at<cv::Vec3b>(y, x)[2]; //y행 x열, 2번째 채널(R)의 데이터를 r에 대입

			// 입력받은 b,g,r을 이용하여 반전시키기
			img.at<cv::Vec3b>(y, x)[0] = unsigned char(255 - b);
			img.at<cv::Vec3b>(y, x)[1] = unsigned char(255 - g);
			img.at<cv::Vec3b>(y, x)[2] = unsigned char(255 - r);
		}
	} 

	// ptr을 이용하여 이미지 데이터에 접근하여 이미지 (일부) 반전시키기 
	for (int y = img.rows / 10 * 5; y < img.rows / 10 * 6; y++) {
		
		cv::Vec3b* ptr = img.ptr<cv::Vec3b>(y);  //img의 y번째 행 데이터 ptr에 대입

		for (int x = 0; x < img.cols; x++) {

			//방법1
			unsigned char b1 = ptr[x][0]; // 앞서서 추출한 y번째 행 데이터에서 x번째+0채널(B)인 데이터를 b1에 대입
			unsigned char g1 = ptr[x][1]; // 앞서서 추출한 y번째 행 데이터에서 x번째+1채널(G)인 데이터를 g1에 대입
			unsigned char r1 = ptr[x][2]; // 앞서서 추출한 y번째 행 데이터에서 x번째+2채널(R)인 데이터를 r1에 대입
		
			//방법2
			cv::Vec3b bgr = ptr[x]; // 앞서서 추출한 i번째 행 데이터에서 x번쨰 데이터 bgr에 대입 
			unsigned char b2 = bgr[0]; // bgr의 0채널(B)인 데이터 b2에 대입
			unsigned char g2 = bgr[1]; // bgr의 1채널(G)인 데이터 g2에 대입
			unsigned char r2 = bgr[2]; // bgr의 2채널(R)인 데이터 r2에 대입

				//이미지 반전
				ptr[x] = cv::Vec3b(255 - b1, 255 - g1, 255 - r1);

		}
	


	}

	*/

	// iteration을 이용하여 이미지 데이터에 접근하여 이미지 반전시키기 
	cv::MatIterator_<cv::Vec3b> itd = img.begin<cv::Vec3b>(), itd_end = img.end<cv::Vec3b>(); //itd : 이미지 시작지점, itd_end : 이미지 끝지점 선언 및 초기화

	for (int i = 0; itd != itd_end; ++itd, ++i) {

		cv::Vec3b bgr = (*itd); // itd포인터 값을 변수 bgr에 대입

		(*itd)[0] = 255 - bgr[0]; // 이미지 0번채널(B) 반전
		(*itd)[1] = 255 - bgr[1]; // 이미지 1번채널(G) 반전
		(*itd)[2] = 255 - bgr[2]; // 이미지 2번채널(R) 반전

	}


	imshow("img", img);
	waitKey(0);
	destroyAllWindows();
}