#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int, char) {

	VideoCapture capture(".\\Meditation.mp4"); // read videofile (동영상 파일 읽기), capture 라는 변수에 동영상 파일 삽입
	Mat frame; // 한 프레임씩 받기 위한 변수

	int askFileTypeBox = 0;
	int Color = 1;
	Size S = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), 
		(int)capture.get(CAP_PROP_FRAME_HEIGHT)); //원본 동영상과 동일한 크기(같은 폭, 높이)로 이용


	VideoWriter outVideo; //클래스가 VideoWriter인 변수 생성
	outVideo.open(".\\outVideo.avi", askFileTypeBox, capture.get(CAP_PROP_FPS), S, Color);
		//저장할 파일 이름, 코덱박스를 띄울것인지, 1초에 몇 프레임 설정, 비디오 가로세로 크기,  색
		//CV_CAP_PROP_FPS : 원본 그대로의 프레임

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

		//Sobel(frame, frame, frame.depth(), 1, 0);
		imshow("videofile", frame);
		outVideo << frame; //한 프레임을 outVideo변수에 저장 → 데이터가 while문을 돌면서 한 프레임씩 저장됨 


		if (waitKey(10) == 27) {
			break;
		}

	}
	return 0;
}