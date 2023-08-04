/*
    @ Viranjan Bhattacharyya
    Publisher: publishes data to json file
*/

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "/home/optimal-student/vb/VIPR/Projects/test-nlohmann-json/json/single_include/nlohmann/json.hpp"

int main()
{
    for (int i=0; i<100; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::vector<float> pos;
        pos.push_back(i);
        pos.push_back(i+0.1*i);

        nlohmann::json jpos = pos;

        std::ofstream out("comm.json");
        out << jpos.dump();        
    }

    return 0;
}
