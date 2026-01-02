#include <iostream>
#include <curl/curl.h>

struct Config {

};

class DirectoriesBuster {

public:
    bool run() {

        curl_global_init(CURL_GLOBAL_DEFAULT); /*global DNS cache*/

        return;

    }

};

int main() {

    try {


    } catch (const std::exception& exception) {
        std::cerr << exception.what() << std::endl;
    }


}
