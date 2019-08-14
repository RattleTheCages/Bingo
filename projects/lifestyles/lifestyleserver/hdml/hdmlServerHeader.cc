/**  hdmlServerHeader.cc  **((**************************************************




*******************************************************************************/

#include "../hdml/hdmlServerHeader.h"

hdmlServerHeader_o::hdmlServerHeader_o()  {
    (void)init();
}

hdmlServerHeader_o::~hdmlServerHeader_o()  {}

void hdmlServerHeader_o::init()  {}

void hdmlServerHeader_o::page(string_o& s)  {

s<< "HTTP/1.1 200 OK\n";
s<< "Server: Lifestyles Server v0.2000\n";
s<< "Date: Today\n";
s<< "Content-Type: text/x-hdml\n";
s<< "ETag: \"0b0b0b0b0b0b0:bbbb\"\n";
s<< "\n";

}

/******************************************************************************/
