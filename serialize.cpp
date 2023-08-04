#include <iostream>
#include "/home/optimal-student/vb/VIPR/Projects/test-nlohmann-json/json/single_include/nlohmann/json.hpp"

int main() {
    // Create data
    double arr[] = {1.2, 2.3, 3.4, 4.5, 5.6};
    std::vector<double> v;
    for (int i=0; i<10; i++) {
        v.push_back(i);
    }

    // Convert to a json object
    nlohmann::json jarr = arr;
    nlohmann::json jv = v;

    // Serialize the json object to a string
    std::string serialized_arr = jarr.dump();
    std::string serialized_vector = jv.dump();

    // Print the serialized string
    std::cout << "Serialized arr: " << serialized_arr << std::endl;
    std::cout << "Serialized vector: " << serialized_vector << std::endl;

    return 0;
}