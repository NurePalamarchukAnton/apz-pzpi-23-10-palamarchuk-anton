#include <iostream>
#include <curl/curl.h>

using namespace std;

int main() {
    CURL* curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.example.com/music");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        CURLcode res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cerr << "Request failed: " << curl_easy_strerror(res) << endl;
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}

////////////////////////////////////////////////////////
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

int main() {
    string response = R"({
        "track": "Blinding Lights",
        "artist": "The Weeknd"
    })";

    json data = json::parse(response);

    cout << "Track: " << data["track"] << endl;
    cout << "Artist: " << data["artist"] << endl;

    return 0;
}

////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string filename = "cache.txt";

    // Запис у кеш
    ofstream out(filename);
    out << "Last played: Song A";
    out.close();

    // Читання з кешу
    ifstream in(filename);
    string data;
    getline(in, data);
    in.close();

    cout << data << endl;

    return 0;
}

