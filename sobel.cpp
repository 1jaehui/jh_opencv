#include <iostream>
#include <opencv2\opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib, "opencv_world450d.lib")
#else
#pragma comment(lib, "opencv_world450.lib")
#endif

using namespace cv;
using namespace std;

void main() 
{

	VideoCapture stream1(0);

	if (!stream1.isOpened()) {
		cout << "cannot open camera";
	}

	namedWindow("Processing");
	namedWindow("Origin");

	while (true) {
		Mat cameraFrame;
		stream1.read(cameraFrame);
		imshow("Origin", cameraFrame);

		Sobel(cameraFrame, cameraFrame, CV_8U, 1, 0);
		imshow("Processing", cameraFrame);

		if (waitKey(30) >= 0) {
			break;
		}
	}
	
	destroyAllWindows();
	//
} 
