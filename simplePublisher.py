# First, import the Paho MQTT package.
import paho.mqtt.client as mqtt
# Also, import time for adding a timed delay.
import time
 
if __name__ == "__main__":
    # Next, define an Id for the client to use.
    Id = "producerPy"
    # And define the Ip address of the broker.
    Ip = "localhost"
    # Then, create a client.
    client = mqtt.Client(Id)
    # Connect to the broker.
    client.connect(Ip, 1883, 60)
    # Next, begin a loop that will countdown from 10.
    for i in range(10, 0, -1):
        # Before sending a message, format the message with the remaining time.
        message = F"Time Left: {i}"
        # Now, publish the message to the consumer's in topic.
        client.publish("/in", message)
        # Then, sleep for one second to satisfy the countdown timer.
        time.sleep(1)
    
    # Finally, after counting down, send the quit signal to any listeners.
    client.publish("/in", "quit")
    client.disconnect()