#include "object_finder.hpp"

namespace lucidy{

    

    ObjectFinder::ObjectFinder(settings::OBF::data & settings):
        comparator(settings),
        matchThreshold(settings.matchThreshold)
    {initFinder();}

    void ObjectFinder::initFinder(){
        /// initialize object finder with custom things. The nessecary has been done in constructor so
        /// this is optional!
    }

    void ObjectFinder::drawLine(cv::Mat & output, const cv::Point2f & start, const cv::Point2f & end, const cv::Scalar & color, const int & lineWidth){
        cv::line( output, start, end, color, lineWidth );
    }

    void ObjectFinder::drawSquare(const cv::Mat & input, cv::Mat & output, AffineMatrix & T, const cv::Scalar & color ){
        PixelCoordinates sampleCorners(4);
		sampleCorners[0] = cv::Point(0, 0);
		sampleCorners[1] = cv::Point(input.cols, 0);
		sampleCorners[2] = cv::Point(input.cols, input.rows);
		sampleCorners[3] = cv::Point(0, input.rows);
        PixelCoordinates rootCorners(4);
 
		try{ cv::perspectiveTransform(sampleCorners, rootCorners, T); }catch(cv::Exception & err){}
	
        for (int i = 0, j=0; i < 4; i++){
            j = i+1;
            if (j == 4){j = 0;}
            drawLine(
                output, 
                rootCorners[i],
                rootCorners[j],
                color
            );
        }
    }

    void ObjectFinder::drawTriangle(PixelCoordinates & input, cv::Mat & output, const cv::Scalar & color ){
        drawLine( output, input[0], input[1], color );
        drawLine( output, input[1], input[2], color );
        drawLine( output, input[2], input[0], color );
    }

    void ObjectFinder::drawCircle(MatchList & input, RootImage & output, const int & radius, const cv::Scalar & color){
        if ( input.size() < 2 ){return;}
        cv::Mat image = output.get();
        PixelCoordinates all = comparator.getPixelCoordinates(input, output, IMAGE_TYPE::ROOT_IMAGE);
        const int number = std::rand() % input.size();
        cv::circle(image, all[number], radius, color, 4, 8);
        output.set(image);
    }

    void ObjectFinder::drawMatch(SampleImage & input, RootImage & output, MatchList & goodMatches){
        int size = goodMatches.size();
        AffineMatrix T = comparator.calcAffineMatrix(output, input);
        cv::Mat image = output.get();
        if (size >= 4){
            if (!T.data){ return; }
            const double det = T.at<double>(0, 0) * T.at<double>(1, 1) - T.at<double>(1, 0) * T.at<double>(0, 1);
            if (det < 0) {return; }
            if( std::fabs(det) > 1 ){ return; }
            drawSquare(input.get(), image, T );
        }else if(size <= 3){
            drawCircle(goodMatches, output,  20 , cv::Scalar(255,0,0) );
        }
        
    }

    float ObjectFinder::calcMatch(RootImage & sourceImage, SampleImage & sampleImage){
        MatchList good = comparator.getMatchList( sourceImage, sampleImage );
        
        float result;
        if (good.size() > 0){ result = good.size() * 1.0; }else{ result = 0.0; }

        return result;
    }

    MatchList ObjectFinder::getMatches(){ return comparator.getMatchList(); }

    bool ObjectFinder::isMatch(RootImage & sourceImage, SampleImage & sampleImage){
        /// use a complex algorithm to decide wether the match results are valid. return true of false
        return calcMatch(sourceImage, sampleImage) >= matchThreshold;

    }

    FoundImageData ObjectFinder::checkMatch(RootImage & sourceImage, SampleImage & sampleImage){
        /// check weather sample image isMatch and change its validy if it valid
        /// return FoundImageData of sampleImage
        bool valid = false;
        if ( isMatch( sourceImage, sampleImage ) ){ valid = true; }
        
        FoundImageData temp;
        temp.id = 1;
        temp.matrix = comparator.calcAffineMatrix(sourceImage, sampleImage);
        temp.match = valid;
            
        return temp;     
    }

    FoundImageList ObjectFinder::checkMatch(RootImage & sourceImage, SampleImageList & sampleImages){
        /// iterate trough a series of sample images to check wether they match the root image. 
        /// append all image data to a FoundImageList with the member function call checkMatch()
        /// return FoundImageList

        FoundImageList tmp;
        for (SampleImage & img : sampleImages){
            tmp.push_back( checkMatch(sourceImage, img) );
        }

        return tmp;
    }


}