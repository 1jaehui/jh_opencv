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

		Sobel(frame, frame, frame.depth(), 1, 0);
		imshow("videofile", frame);

		if (waitKey(10) == 27) {
			break;
		}

	}
	return 0;
}