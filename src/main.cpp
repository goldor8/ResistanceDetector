#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
    std::cout << "hello world" << std::endl;
    cv::Mat img = cv::imread(argv[1]);
    cv::imshow("Fenetre", img);
    cv::waitKey(0);
    return 0;
}