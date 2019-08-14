/**  htmlInterface.cc  *********************************************************



changes log
when       who      what
3.20.99    Dan      Creation.

*******************************************************************************/


#include "../../../library/lib/string/string.h"

#include "../html/htmlInterface.h"


htmlInterface_o::htmlInterface_o()  {
    (void)init();
}

htmlInterface_o::~htmlInterface_o()  {}

void htmlInterface_o::init()  {
    rotatingBannerIndex = 0;
}

int htmlInterface_o::setRotatingBanner(const rotatingBanner_o& rb)  {

    Mutex.lock();
        rotatingBanner = rb;
    Mutex.unlock();


    return ERROR_OK;
}

const char* htmlInterface_o::logoURL()  {
    return rotatingBanner.logoURL();
}

const char* htmlInterface_o::rotatingBannerURL()  {
    int index;
    string_o s;

    Mutex.lock();
        rotatingBannerIndex++;
        if(rotatingBannerIndex >= rotatingBanner.numberOfBanners())  rotatingBannerIndex = 0;
        index = rotatingBannerIndex;
    Mutex.unlock();

    return rotatingBanner.bannerURL(index);
}


const char* htmlInterface_o::rotatingBackgroundURL()  {
    int index;

    Mutex.lock();
        index = rotatingBannerIndex;
    Mutex.unlock();

    return rotatingBanner.backgroundURL(index);
}



/******************************************************************************/
