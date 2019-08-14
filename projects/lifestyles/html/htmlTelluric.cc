/**  htmlTelluric.cc  **********************************************************



changes log
when       who      what
3.20.99    Dan      Creation.

*******************************************************************************/


#include "../../library/lib/string/string.h"

#include "../html/htmlTelluric.h"


htmlTelluric_o::htmlTelluric_o()  {
    (void)init();
}

htmlTelluric_o::~htmlTelluric_o()  {}

void htmlTelluric_o::init()  {
    TransactionServerURL = "http://204.131.41.3:4111/";
    StaticServerURL = "http://www.InfoMechanics.com/";


    FontText   = "<font face='Courier' size='+0'>";
    FontSmall  = "<font face='Arial' size='-1'>";
    FontExSmall= "<font size='-2'>";
    FontEmph   = "<font face='Univers' size='+1'>";
    FontFix    = "<font face='Courier' size='-1'>";
    FontData   = "<font face='Courier' size='-2'>";
    FontGreen  = "<font face='Bookman Old Telluric' size='+1' color='#005210'>";
    FontRed    = "<font face='Bookman Old Telluric' size='+1' color='#DD1210'>";
}


int htmlTelluric_o::setTransactionServerURL(const char* tsurl)  {
    if(!tsurl)  return 0;
    TransactionServerURL = tsurl;
    return 1;
}

int htmlTelluric_o::setStaticServerURL(const char* ssurl)  {
    if(!ssurl)  return 0;
    StaticServerURL = ssurl;
    return 1;
}


int htmlTelluric_o::parse(input_o* input)  {
    int         x;
    string_o    message;
    string_o    ps(input->message());
    string_o    ps2(input->message());
    string_o    ps3(input->message());

    ps.upcut('/');
    ps.cut('?');


    ps2.upcut('/');
    ps2.upcut('?');
    ps2.cut(' ');
//    if(ps2.length() > 5)  input->setSession(ps2.string());

    x = 1;
    while(x++ < ps3.length())  {
        // Looking for two tildas in a row.
        if((ps3.charat(x)   == '%' &&
            ps3.charat(x+1) == '7' &&
            ps3.charat(x+2) == 'E' &&
            ps3.charat(x+3) == '%' &&
            ps3.charat(x+4) == '7' &&
            ps3.charat(x+5) == 'E') ||
           (ps3.charat(x)   == '~' &&
            ps3.charat(x+1) == '~'))  break;
    }
    ps3.upcut(x+5);
    unnet(ps3);
    ps3.transpose("&","~");

    ps3 << ps2;

    //input->setNodeValue(ps3.string());


return 0;
}


void htmlTelluric_o::unnet(string_o& string)  {
    int x;
    char ch;
    string_o t,hexs,ret;

    for(x=0;x<string.length();x++)  {
        t = "";
        ch = string.charat(x);
        if((ch >= 'A') && (ch <= 'Z'))  t = ch;
        else if((ch >= 'a') && (ch <= 'z'))  t = ch;
        else if((ch >= '0') && (ch <= '9'))  t = ch;
        else if(ch == '+')  t = ' ';
        else if(ch == '-')  t = '-';
        else if(ch == '&')  t = '&';
        else if(ch == '.')  t = '.';
        else if(ch == '=')  t = '=';
        else if(ch == '_')  t = '_';
        else if(ch == '%')  {
            x++;
            hexs = string.charat(x);
            x++;
            hexs << string.charat(x);
            if(hexs == "0D" || hexs == "0d")  t = '\n';
            else if(hexs == "0A" || hexs == "0a")  t = '\r';
            else if(hexs == "21")  t = '!';
            else if(hexs == "22")  t = '\"';
            else if(hexs == "23")  t = '#';
            else if(hexs == "24")  t = '$';
            else if(hexs == "25")  t = '%';
            else if(hexs == "26")  t = '&';
            else if(hexs == "27")  t = '\'';
            else if(hexs == "28")  t = '(';
            else if(hexs == "29")  t = ')';

            else if(hexs == "2A" || hexs == "2a")  t = '*';
            else if(hexs == "2B" || hexs == "2b")  t = '+';
            else if(hexs == "2C" || hexs == "2c")  t = ',';
            else if(hexs == "2D" || hexs == "2d")  t = '-';
            else if(hexs == "2E" || hexs == "2e")  t = '.';
            else if(hexs == "2F" || hexs == "2f")  t = '/';

            else if(hexs == "3A" || hexs == "3a")  t = ':';
            else if(hexs == "3B" || hexs == "3b")  t = ';';
            else if(hexs == "3C" || hexs == "3c")  t = '<';
            else if(hexs == "3D" || hexs == "3d")  t = '=';
            else if(hexs == "3E" || hexs == "3e")  t = '>';
            else if(hexs == "3F" || hexs == "3f")  t = '?';

            else if(hexs == "40")  t = '@';

            else if(hexs == "5B" || hexs == "5b")  t = '[';
            else if(hexs == "5C" || hexs == "5c")  t = '\\';
            else if(hexs == "5D" || hexs == "5d")  t = ']';
            else if(hexs == "5E" || hexs == "5e")  t = '^';
            else if(hexs == "5F" || hexs == "5f")  t = '_';

            else if(hexs == "60")  t = '`';

            else if(hexs == "7B" || hexs == "7b")  t = '{';
            else if(hexs == "7C" || hexs == "7c")  t = '|';
            else if(hexs == "7D" || hexs == "7d")  t = '}';
            else if(hexs == "7E" || hexs == "7e")  t = '~';

            else t << '`' << hexs << "'";
        }
        ret << t;
    }
    string = ret;
}


void htmlTelluric_o::ennet(string_o& string)  {
    int x;
    char ch;
    string_o t,ret;

    for(x=0;x<string.length();x++)  {
        t = "";
        ch = string.charat(x);
        if((ch >= 'A') && (ch <= 'Z'))  t = ch;
        else if((ch >= 'a') && (ch <= 'z'))  t = ch;
        else if((ch >= '0') && (ch <= '9'))  t = ch;
        else if(ch == '+')  t = ' ';
        else if(ch == '-')  t = '-';
        else if(ch == '&')  t = '&';
        else if(ch == '.')  t = '.';
        else if(ch == '=')  t = '=';
        else if(ch == '_')  t = '_';
        else if(ch == '\n')  t = "%0d";
        else if(ch == '\r')  t = "%0a";
        else if(ch == '!')  t = "%21";
        else if(ch == '\"')  t = "%22";
        else if(ch == '#')  t = "%23";
        else if(ch == '$')  t = "%24";
        else if(ch == '%')  t = "%25";
        else if(ch == '&')  t = "%26";
        else if(ch == '\'')  t = "%27";
        else if(ch == '(')  t = "%28";
        else if(ch == ')')  t = "%29";
        else if(ch == '*')  t = "%2a";
        else if(ch == '+')  t = "%2b";
        else if(ch == ',')  t = "%2c";
        else if(ch == '-')  t = "%2d";
        else if(ch == '.')  t = "%2e";
        else if(ch == '/')  t = "%2f";

        else if(ch == ':')  t = "%3a";
        else if(ch == ';')  t = "%3b";
        else if(ch == '<')  t = "%3c";
        else if(ch == '=')  t = "%3d";
        else if(ch == '>')  t = "%3e";
        else if(ch == '?')  t = "%3f";
        else if(ch == '@')  t = "%40";

        else if(ch == '[')  t = "%5b";
        else if(ch == '\\')  t = "%5c";
        else if(ch == ']')  t = "%5d";
        else if(ch == '^')  t = "%5e";
        else if(ch == '_')  t = "%5f";

        else if(ch == '`')  t = "%60";
        else if(ch == '{')  t = "%7b";
        else if(ch == '|')  t = "%7c";
        else if(ch == '}')  t = "%7d";
        else if(ch == '~')  t = "%7e";

        ret << t;
    }
    string = ret;
}


/******************************************************************************/
