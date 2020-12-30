#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char) {

	VideoCapture capture(0); // read videofile (동영상 파일 읽기), capture 라는 변수에 동영상 파일 삽입
	Mat frame; // 행렬 선언

	if (!capture.isOpened()) {
		printf("MP4 file can not open. \n");
		return 0;
	} //영상파일 존재 안할 때 나타날 메세지

	namedWindow("videofile", 0); //동영상 재생할 창 설정

	while (1) {
		capture >> frame; //동영상 파일(변수 : capture)을 frame이라는 변수로 이동시킴

		if (frame.empty()) {
			break;
		}  //동영상 파일이 끝나면 while문 종료


		//좌측상단 반전
		for (int y1 = 0; y1 < frame.rows / 3; y1++) {
			for (int x1 = 0; x1 < frame.cols / 3; x1++) {
				unsigned char r1, g1, b1;
				
				b1 = frame.data[y1* frame.step + x1 * frame.elemSize() + 0];
				g1 = frame.data[y1* frame.step + x1 * frame.elemSize() + 1];
				r1 = frame.data[y1* frame.step + x1 * frame.elemSize() + 2];

				frame.data[y1* frame.step + x1 * frame.elemSize() + 0] = unsigned(255 - b1);
				frame.data[y1* frame.step + x1 * frame.elemSize() + 1] = unsigned(255 - g1);
				frame.data[y1* frame.step + x1 * frame.elemSize() + 2] = unsigned(255 - r1);
			}
		}

		// 가운데 반전
		for (int y2 = frame.rows / 3; y2 < frame.rows / 3 * 2; y2++) {
			for (int x2 = frame.cols / 3; x2 < frame.cols / 3 * 2; x2++) {
				unsigned r2, g2, b2;

				b2 = frame.at<cv::Vec3b>(y2, x2)[0]; 
				g2 = frame.at<cv::Vec3b>(y2, x2)[1]; 
				r2 = frame.at<cv::Vec3b>(y2, x2)[2];
				
				frame.at<cv::Vec3b>(y2, x2)[0] = unsigned char(255 - b2);
				frame.at<cv::Vec3b>(y2, x2)[1] = unsigned char(255 - g2);
				frame.at<cv::Vec3b>(y2, x2)[2] = unsigned char(255 - r2);
			}
		}


		//좌측하단 반전
		for (int y3 = frame.rows / 3 * 2; y3 < frame.rows; y3++) {

			cv::Vec3b* ptr = frame.ptr<cv::Vec3b>(y3);  //img의 y번째 행 데이터 ptr에 대입
			
			for (int x3 = frame.cols/3*2; x3 < frame.cols; x3++) {
				//방법1
				unsigned char b3 = ptr[x3][0]; 
				unsigned char g3 = ptr[x3][1];
				unsigned char r3 = ptr[x3][2];


				/*방법2
				cv::Vec3b bgr = ptr[x]; 
				unsigned char b2 = bgr[0];
				unsigned char g2 = bgr[1];
				unsigned char r2 = bgr[2];
					//이미지 반전
				*/

				ptr[x3] = cv::Vec3b(255 - b3, 255 - g3, 255 - r3);
			}

		}



		//Sobel(frame, frame, frame.depth(), 1, 0);
		imshow("videofile", frame);

		if (waitKey(10) == 27) {
			break;
		}

	}
	return 0;
}