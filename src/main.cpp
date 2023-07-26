#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

int main(int argc, char **argv)
{
    // load onnx model
    try
    {
        cv::dnn::Net net = cv::dnn::readNetFromONNX("C:/Users/XiZhu/source/repos/opencv-onnx-ocr/src/model.onnx");
        // check if model is loaded
        if (net.empty())
        {
            std::cout << "Can't load network by using the following files: " << std::endl;
            std::cout << "model.onnx" << std::endl;
            exit(-1);
        }
        std::cout << "Model loaded successfully" << std::endl;
    }
    catch (const cv::Exception &err)
    {
        std::cerr << err.msg << std::endl;
        //OpenCV(4.8.0) Error: Unspecified error 
        //      (> Node [Concat@ai.onnx]:(onnx_node!p2o.Concat.2) parse error: 
        //          OpenCV(4.8.0) opencv\modules\dnn\src\layers\concat_layer.cpp:109: error: 
        //              (-201:Incorrect size of input array) Inconsistent shape for ConcatLayer in function 'cv::dnn::ConcatLayerImpl::getMemoryShapes'
        //> ) in cv::dnn::dnn4_v20230620::ONNXImporter::handleNode, file opencv\modules\dnn\src\onnx\onnx_importer.cpp, line 1083
        //OpenCV(4.8.0) opencv\modules\dnn\src\onnx\onnx_importer.cpp:1083: error: 
        //      (-2:Unspecified error) in function 'cv::dnn::dnn4_v20230620::ONNXImporter::handleNode'
        //> Node [Concat@ai.onnx]:(onnx_node!p2o.Concat.2) parse error: 
        //      OpenCV(4.8.0) opencv\modules\dnn\src\layers\concat_layer.cpp:109: error: 
        //          (-201:Incorrect size of input array) Inconsistent shape for ConcatLayer in function 'cv::dnn::ConcatLayerImpl::getMemoryShapes'
        //>
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }


    return 0;
}