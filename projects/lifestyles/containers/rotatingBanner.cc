/**  rotatingBanner.cc  ********************************************************




changes log
when       who     what
12.22.99   Dan     Creation. 

*******************************************************************************/


#include "../../library/lib/parse/parse.h"
#include "../containers/rotatingBanner.h"


rotatingBanner_o::rotatingBanner_o()  {}

rotatingBanner_o::~rotatingBanner_o()  {}

void rotatingBanner_o::clear()  {
    int x;

    Id = "";
    LogoURL = "";
    NumberOfBanners = 0;

    for(x=0;x<ROTATINGBANNER_MAX_NUMBER_OF_BANNERS;x++)  {
        BannerURL[x] = "";
        BackgroundURL[x] = "";
        BannerFrequency[x] = "";
    }
}

void rotatingBanner_o::setLogoURL(const char* n)  {
    LogoURL = n;
}

void rotatingBanner_o::setBannerURL(int i,const char* n)  {
    if(i >= 0 && i < ROTATINGBANNER_MAX_NUMBER_OF_BANNERS && n)  {
        BannerURL[i] = n;
    }
}

void rotatingBanner_o::setBackgroundURL(int i,const char* n)  {
    if(i >= 0 && i < ROTATINGBANNER_MAX_NUMBER_OF_BANNERS && n)  {
        BackgroundURL[i] = n;
    }
}

void rotatingBanner_o::setBannerFrequency(int i,const char* n)  {
    if(i >= 0 && i < ROTATINGBANNER_MAX_NUMBER_OF_BANNERS && n)  {
        BannerFrequency[i] = n;
    }
}

void rotatingBanner_o::setNumberOfBanners(int i)  {
    if(i >= 0 && i < ROTATINGBANNER_MAX_NUMBER_OF_BANNERS)  {
        NumberOfBanners = i;
    }
}

const char* rotatingBanner_o::logoURL() const  {
    return LogoURL.string();
}

const char* rotatingBanner_o::bannerURL(int i) const  {
    if(i > 0 && i < ROTATINGBANNER_MAX_NUMBER_OF_BANNERS)  {
        return BannerURL[i].string();
    }
    return BannerURL[0].string();
}

const char* rotatingBanner_o::backgroundURL(int i) const  {
    if(i > 0 && i < ROTATINGBANNER_MAX_NUMBER_OF_BANNERS)  {
        return BackgroundURL[i].string();
    }
    return BackgroundURL[0].string();
}

rotatingBanner_o& rotatingBanner_o::operator = (const rotatingBanner_o& r)  {
    int x;

    Id              = r.Id;
    LogoURL         = r.LogoURL;
    NumberOfBanners = r.NumberOfBanners;

    for(x=0;x<ROTATINGBANNER_MAX_NUMBER_OF_BANNERS;x++)  {
        BannerURL[x] = r.BannerURL[x];
        BackgroundURL[x] = r.BackgroundURL[x];
        BannerFrequency[x] = r.BannerFrequency[x];
    }

    return *this;
}

void rotatingBanner_o::operator >> (string_o& s) const  {
    int x;

    s << "\n" << ROTATINGBANNER_OBJECT;
    s << '\n' << ROTATINGBANNER_ID << '=' << Id;
    s << '\n' << ROTATINGBANNER_LOGO_URL << '=' << LogoURL;
    s << '\n' << ROTATINGBANNER_NUMBER_OF_BANNERS << '=' << NumberOfBanners;

    for(x=0;x<ROTATINGBANNER_MAX_NUMBER_OF_BANNERS;x++)  {
        s << '\n' << ROTATINGBANNER_BANNER_URL << '[' << x << ']' << '=' << BannerURL[x];
        s << '\n' << ROTATINGBANNER_BACKGROUND_URL << '[' << x << ']' << '=' << BackgroundURL[x];
        s << '\n' << ROTATINGBANNER_BANNER_FREQUENCY << '[' << x << ']' << '=' << BannerFrequency[x];
    }

    s << '\n';
}

void rotatingBanner_o::operator << (const char* cc)  {
    int x;
    string_o s;
    parse_o parse(cc);

    (void)parse.it(ROTATINGBANNER_ID,Id);
    (void)parse.it(ROTATINGBANNER_LOGO_URL,LogoURL);
    (void)parse.it(ROTATINGBANNER_NUMBER_OF_BANNERS,NumberOfBanners);

    for(x=0;x<ROTATINGBANNER_MAX_NUMBER_OF_BANNERS;x++)  {
        s = ROTATINGBANNER_BANNER_URL;
        s << '[' << x << ']';
        (void)parse.it(s.string(),BannerURL[x]);
        s = ROTATINGBANNER_BACKGROUND_URL;
        s << '[' << x << ']';
        (void)parse.it(s.string(),BackgroundURL[x]);
        s = ROTATINGBANNER_BANNER_FREQUENCY;
        s << '[' << x << ']';
        (void)parse.it(s.string(),BannerFrequency[x]);
    }
}


/******************************************************************************/
