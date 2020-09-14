#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include <curl/curl.h>
#include <json/json.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long ll;

#define pb push_back
#define mp make_pair

#define ip(arr) for(int i=0; i<arr.size(); i++) cin>>arr[i];
#define ip1(arr) for(int i=1; i<=arr.size(); i++) cin>>arr[i];
#define op(arr) for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";

#define MAX 10000000
#define mod 100000007


void testcases(){


	// const std::string url("http://date.jsontest.com/");

 //    CURL* curl = curl_easy_init();

 //    // Set remote URL.
 //    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

 //    // Don't bother trying IPv6, which would increase DNS resolution time.
 //    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

 //    // Don't wait forever, time out after 10 seconds.
 //    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

 //    // Follow HTTP redirects if necessary.
 //    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

 //    // Response information.
 //    long httpCode(0);
 //    std::unique_ptr<std::string> httpData(new std::string());

 //    // Hook up data handling function.
 //    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

 //    // Hook up data container (will be passed as the last parameter to the
 //    // callback handling function).  Can be any pointer type, since it will
 //    // internally be passed as a void pointer.
 //    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

 //    // Run our HTTP GET command, capture the HTTP response code, and clean up.
 //    curl_easy_perform(curl);
 //    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
 //    curl_easy_cleanup(curl);

 //    if (httpCode == 200)
 //    {
 //        std::cout << "\nGot successful response from " << url << std::endl;

 //        // Response looks good - done using Curl now.  Try to parse the results
 //        // and print them out.
 //        Json::Value jsonData;
 //        Json::Reader jsonReader;

 //        if (jsonReader.parse(*httpData.get(), jsonData))
 //        {
 //            std::cout << "Successfully parsed JSON data" << std::endl;
 //            std::cout << "\nJSON data received:" << std::endl;
 //            std::cout << jsonData.toStyledString() << std::endl;

 //            const std::string dateString(jsonData["date"].asString());
 //            const std::size_t unixTimeMs(
 //                    jsonData["milliseconds_since_epoch"].asUInt64());
 //            const std::string timeString(jsonData["time"].asString());

 //            std::cout << "Natively parsed:" << std::endl;
 //            std::cout << "\tDate string: " << dateString << std::endl;
 //            std::cout << "\tUnix timeMs: " << unixTimeMs << std::endl;
 //            std::cout << "\tTime string: " << timeString << std::endl;
 //            std::cout << std::endl;
 //        }

	

}

select * 
from Artist

minus

select Artist.Artistid, Artist.namespace
from Artist natural join Album


int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin>> t;

	while(t--){
		testcases();
		cout<<endl;
	}

	return 0;
}