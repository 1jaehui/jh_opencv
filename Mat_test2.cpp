#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char) {
	Mat m = Mat::ones(3, 3, CV_64F);
	m = m * 3;
	//cout << m << endl;

	double dm[3][3] = { {1,2,1}, {0,1,2}, {2,3,1} };
	Mat m2 = Mat(3, 3, CV_64F, dm);
	//cout << m2 << endl;

	//cout << m + m2 << endl;
	//cout << m - m2 << endl;
	//cout << m * m2 << endl;
	//cout << m.mul(m2) << endl;
	//cout << m / m2 << endl;
	//cout << m2.inv() << endl;
	//cout << m2.t() << endl;

}