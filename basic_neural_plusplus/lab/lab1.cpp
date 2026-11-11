#include <iostream>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>

int main(){
    Eigen::MatrixXf mat = Eigen::MatrixXf::Random(3,4);
    Eigen::VectorXf vec = Eigen::VectorXf::Random(4);

    Eigen::VectorXf res = mat * vec;
    //provo a stampare il risultato
    std::cout << res << std::endl;

    //ora una prima funzione di attivazione banale
    Eigen::VectorXf res_relu = res.array().max(0.0f);
    std::cout << "Facendo la funzione di attivazione si ottiene:\n" << res_relu << std::endl;
    //infatti prende il massimo rispetto a 0 e quindi è come moltiplicare per la theta

    //seconda parte lavoro invece con la libreria OpenCV
    std::cout << "Seconda parte del laboratorio" << std::endl;
    cv::Mat img(28,28, CV_8UC1, cv::Scalar(128));
    cv::imshow("Test MNIST size", img);
    cv::waitKey(0);

    return 0;
}