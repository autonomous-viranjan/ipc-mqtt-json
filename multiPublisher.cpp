/*
    Viranjan Bhattacharyya
    EMC2 Lab Clemson University
*/

#include <iostream>
#include <mqtt/client.h>
#include <chrono>
#include <thread>

const std::string ip = "localhost:1883";

int main()
{
    // create publisher client
    mqtt::client pos_pub(ip, "pos_publisher",  mqtt::create_options(MQTTVERSION_5));
    mqtt::client con_pub(ip, "con_publisher",  mqtt::create_options(MQTTVERSION_5));

    // connect to broker
    pos_pub.connect();
    con_pub.connect();

    // Initialize an empty message with specified topic. 
    mqtt::message_ptr posPtr = mqtt::make_message("/position", "");   
    mqtt::message_ptr conPtr = mqtt::make_message("/control", "");

    for (int i=10; i > 0; i--) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
        posPtr->set_payload(std::to_string(i));
        conPtr->set_payload("0.0");

        pos_pub.publish(posPtr);
        std::cout << "[Published]: " << i << " on Topic: " << conPtr->get_topic() << std::endl;
        con_pub.publish(conPtr);
        std::cout << "[Published]: " << "0.0" << " on Topic: " << conPtr->get_topic() << std::endl;
    }
    pos_pub.disconnect();
    con_pub.disconnect();

    return 0;
}