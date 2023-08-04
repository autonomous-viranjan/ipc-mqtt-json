/*
    @ Viranjan Bhattacharyya
*/

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "/home/optimal-student/vb/VIPR/Projects/test-nlohmann-json/json/single_include/nlohmann/json.hpp"

int main()
{
    nlohmann::json jpos;

    while (true) {      
        std::ifstream in("comm.json");
        in >> jpos; 
        
        auto msg = jpos.template get<std::vector<double>>();

        std::cout << "[Received]: " << msg[0] << " , " << msg[1] << std::endl;

        in.close();
        std::this_thread::sleep_for(std::chrono::milliseconds(1100));
    }

    return 0;
}