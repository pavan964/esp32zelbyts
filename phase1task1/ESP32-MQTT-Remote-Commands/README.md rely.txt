ESP32 MQTT Subscribe & Remote Commands
 Objective

This project demonstrates MQTT-based remote control using an ESP32. The ESP32 subscribes to an MQTT topic and performs actions based on received commands.

 Components Used

- ESP32 Development Board
- Relay Module
- Wi-Fi Network
- MQTT Broker (HiveMQ Public Broker)
- MQTT Explorer
- Arduino IDE

MQTT Topic

```
zelbytes/bench/pavan/cmd
```

 Commands

| Command | Action |
|----------|----------|
| IRRIGATE | Relay ON |
| STOP | Relay OFF |

Working

1. ESP32 connects to the Wi-Fi network.
2. ESP32 connects to the MQTT broker.
3. ESP32 subscribes to the MQTT topic.
4. MQTT Explorer publishes commands to the topic.
5. ESP32 receives the commands and controls the relay.
6. The received commands and actions are displayed in the Serial Monitor.

 Output

 IRRIGATE Command

```
Received: IRRIGATE
Relay ON
```

 STOP Command

```
Received: STOP
Relay OFF
```

 Screenshots

Screenshots of:
- MQTT Explorer
- Serial Monitor Output
- Circuit Connection

are included in the `screenshots` folder.

Author

Pavan Kumar