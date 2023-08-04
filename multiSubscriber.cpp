/* 
    Viranjan Bhattacharyya
    EMC2 Lab Clemson University
*/

#include <iostream>
#include <mqtt/client.h>

const std::string ip = "localhost:1883"; // all subscribers connect to same broker

void callback(mqtt::client &client, mqtt::const_message_ptr &msgPtr)
{
    if (client.try_consume_message(&msgPtr))
        {
            // Construct a string from the message payload.
            std::string messageString = msgPtr->get_payload_str();
            // Print payload string to console (debugging).
            std::cout << "[Received]: " << messageString << " on topic: " << msgPtr->get_topic() << std::endl;
        }
}

int main()
{
    // Construct a client using the Ip and Id, specifying usage of MQTT V5.
    mqtt::client pos_sub(ip, "pos_subscriber", mqtt::create_options(MQTTVERSION_5));
    mqtt::client con_sub(ip, "con_subscriber", mqtt::create_options(MQTTVERSION_5));
    // Use the connect method of the client to establish a connection to the broker.
    pos_sub.connect();
    con_sub.connect();
    // In order to receive messages from the broker, specify a topic to subscribe to.
    pos_sub.subscribe("/position");
    con_sub.subscribe("/control");
    // Begin the client's message processing loop, filling a queue with messages.
    pos_sub.start_consuming();
    con_sub.start_consuming();

    bool running = true;
    while (running)
    {
        // Construct a message pointer to hold an incoming message.
        mqtt::const_message_ptr posPtr;
        mqtt::const_message_ptr conPtr;

        callback(pos_sub, posPtr);
        callback(con_sub, conPtr);
    }

    return 0;
}