#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
int main()
{
    cv::Mat img=cv::imread("/home/liyuxuan/vscode/res/dacapo.png");
    cv::imshow("window1",img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    cout<<"helloopencv"<<endl;
    return 0;
}
