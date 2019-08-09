/**  hdmlInterface.cc  *********************************************************



changes log
when       who      what
9.9.99     Dan      Creation.


*******************************************************************************/

#include "../hdml/hdmlInterface.h"
#include "../../library/lib/string/string.h"
#include "../../library/lib/log/log.h"

extern log_o               log;


hdmlInterface_o::hdmlInterface_o()  {
    (void)init();
}

hdmlInterface_o::~hdmlInterface_o()  {}

void hdmlInterface_o::init()  {

    //TransactionServerPath = "http://www.infomechanics.com:8844/";
    TransactionServerPath = "http://204.131.41.107:8844/";
    StaticServerPath      = "http://www.infomechanics.com/~dhuffman/";

    if(::log.debug(901))  {
        string_o message;
        message << "hdmlInterface_o: transaction server path: " << TransactionServerPath << '.';
        message << "hdmlInterface_o: static server path: " << StaticServerPath << '.';
        ::log << message;
    }
}

int hdmlInterface_o::parse(pdaInput_o& pdaInput)  {
    string_o    message;

    if(::log.debug(902))  {
        message << "hdmlInterface_o: parse(pdaInput_o*) method:" << pdaInput.message();
        ::log << message;
    }

    int         x;
    string_o    ps(pdaInput.message());
    string_o    ps2(pdaInput.message());
    string_o    ps3(pdaInput.message());

    unnet(ps);
    ps.upcut("command=");
    ps.cut('~');
    ps.cut(' ');
    if(ps.contains("GET") || ps.contains("HTTP"))  pdaInput.setCommand("init");
    else  pdaInput.setCommand(ps.string());

    if(::log.debug(903))  {
        (message = "") << "hdmlInterface_o: command: " << ps;
        ::log << message;
    }

    ps2.upcut("x-up-subno:");
    ps2.cut('\n');
    ps2.cut(ps2.length()-1);//!!!!!!
    ps2.boxears();
    pdaInput.setPhone(ps2.string());

    if(::log.debug(904))  {
        (message = "") << "hdmlInterface_o: phone: " << ps2;
        ::log << message;
    }


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
    ps3.upcut(x+2);
ps3.cut(' ');//!!!!!!!!!!
    unnet(ps3);
    ps3.transpose("&","~");

    pdaInput.setNodeValue(ps3.string());

    if(::log.debug(905))  {
        (message = "") << "hdmlInterface_o: nodevalue: " << ps3;
        ::log << message;
    }

    return ERROR_OK;
}

void hdmlInterface_o::unnet(string_o& string)  {
    int x;
    char ch;
    string_o t,hexs,ret;

    for(x=0;x<string.length();x++)  {
        t = "";
        ch = string.charat(x);
        if((ch >= 'A') && (ch <= 'Z'))  t = ch;
        else if((ch >= 'a') && (ch <= 'z'))  t = ch;
        else if((ch >= '0') && (ch <= '9'))  t = ch;
        else if(ch == ' ')  t = ' ';
        else if(ch == '\n')  t = '\n';
        else if(ch == '+')  t = ' ';
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
            else if(hexs == "0A" || hexs == "0a");//  t = '\r';
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

/******************************************************************************/
