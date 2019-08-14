/**  rotatingBanner.h  *********************************************************

    Rotating Banner Container Object.


changes log
when       who     what
12.22.99   Dan     Creation. 
12.24.99   Dan     Added:    Background.

*******************************************************************************/


#ifndef ROTATINGBANNEROBJECT_CONTAINER
#define ROTATINGBANNEROBJECT_CONTAINER

#include "../../library/lib/string/string.h"


#define ROTATINGBANNER_OBJECT            "rotatingBanner_o:"
#define ROTATINGBANNER_ID                "rotatingBanner_o.id"
#define ROTATINGBANNER_LOGO_URL          "rotatingBanner_o.logourl"
#define ROTATINGBANNER_NUMBER_OF_BANNERS "rotatingBanner_o.numberOfBanners"
#define ROTATINGBANNER_BANNER_URL        "rotatingBanner_o.bannerurl"
#define ROTATINGBANNER_BACKGROUND_URL    "rotatingBanner_o.backgroundurl"
#define ROTATINGBANNER_BANNER_FREQUENCY  "rotatingBanner_o.frequency"

#define ROTATINGBANNER_ID_MAX                 42
#define ROTATINGBANNER_LOGO_URL_MAX          512
#define ROTATINGBANNER_BANNER_URL_MAX        512
#define ROTATINGBANNER_BACKGOUND_URL_MAX     512
#define ROTATINGBANNER_MAX_NUMBER_OF_BANNERS  24


class rotatingBanner_o  {
  protected:
    string_o Id;
    string_o LogoURL;
    int      NumberOfBanners;
    string_o BannerURL[ROTATINGBANNER_MAX_NUMBER_OF_BANNERS];
    string_o BackgroundURL[ROTATINGBANNER_MAX_NUMBER_OF_BANNERS];
    string_o BannerFrequency[ROTATINGBANNER_MAX_NUMBER_OF_BANNERS];

  public:   
    rotatingBanner_o();                                 // Default constructor.
    rotatingBanner_o(const rotatingBanner_o&);          // Copy constructor.
   ~rotatingBanner_o();                                 // Default destructor.
    rotatingBanner_o& operator = (const rotatingBanner_o&);
                                                        // Assignment operator.
    void            operator >> (string_o&) const;      // OLP representation.
    void            operator << (const char*);          // Reconstruct.
    void            clear();
    int             blank()                     const;

    const char*     id()                        const;
    const char*     logoURL()                   const;
    int             numberOfBanners()           const;
    const char*     bannerURL(int)              const;
    const char*     backgroundURL(int)          const;
    const char*     bannerFrequency(int)        const;

    void            setId(const char*);
    void            setLogoURL(const char*);
    void            setNumberOfBanners(int);
    void            setBannerURL(int,const char*);
    void            setBackgroundURL(int,const char*);
    void            setBannerFrequency(int,const char*);

};


/******************************************************************************/

inline const char* rotatingBanner_o::id() const  {
    return Id.string();
}

inline int rotatingBanner_o::numberOfBanners() const  {
    return NumberOfBanners;
}


inline void rotatingBanner_o::setId(const char* id)  {
    Id = id;
    Id.cut(ROTATINGBANNER_ID_MAX);
}


#endif

/******************************************************************************/
