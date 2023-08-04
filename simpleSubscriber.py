# Import the Paho MQTT package.
import paho.mqtt.client as mqtt
 
 
# The callback for when the client connects to the broker.
def on_connect(client, userdata, flags, rc):
    print("Connected To Broker")
    # After establishing a connection, subscribe to the input topic.
    client.subscribe("/in")
 
# The callback for when a message is received from the broker.
def on_message(client, userdata, msg):
    # Decode the message payload from Bytes to String.
    payload = msg.payload.decode('UTF-8')
    # Print the payload to the console.
    print(payload)
    # Check if payload is the quit signal.
    if (payload == "quit"):
        # If `quit` disconnect the client, ending the program.
        client.disconnect()
 
 
if __name__ == "__main__":
    # Define an Id for the client to use.
    Id = "consumerPy"
    # Define the Ip address of the broker.
    Ip = "localhost"
    # Create a client.
    client = mqtt.Client(Id)
    # Set the callback functions of the client for connecting and incoming messages.
    client.on_connect = on_connect
    client.on_message = on_message
    # Then, connect to the broker.
    client.connect(Ip, 1883, 60)
    # Finally, process messages until a `client.disconnect()` is called.
    client.loop_forever()