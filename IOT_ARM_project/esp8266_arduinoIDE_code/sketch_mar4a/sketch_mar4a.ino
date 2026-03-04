#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);

  // Start Wi-Fi AP (no password)
  WiFi.softAP("ESP8285_RoboticArm");

  Serial.println("AP started");
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());

  // Main page
  server.on("/", []() {
    String html = "<!DOCTYPE html><html><head><title>IOT Robotic Arm</title>"
                  "<style>body{background-color:black;color:white;text-align:center;font-family:Arial;}"
                  "h1{color:#00ffcc;} .slider{width:300px;}</style></head><body>"
                  "<h1>🤖 IOT Robotic Arm</h1>"
                  "<p>Servo 1 <input type='range' min='0' max='180' value='90' class='slider' "
                  "onchange=\"fetch('/servo?S=1&angle='+this.value)\"></p>"
                  "<p>Servo 2 <input type='range' min='0' max='180' value='90' class='slider' "
                  "onchange=\"fetch('/servo?S=2&angle='+this.value)\"></p>"
                  "<p>Servo 3 <input type='range' min='0' max='180' value='90' class='slider' "
                  "onchange=\"fetch('/servo?S=3&angle='+this.value)\"></p>"
                  "<p>Servo 4 <input type='range' min='0' max='180' value='90' class='slider' "
                  "onchange=\"fetch('/servo?S=4&angle='+this.value)\"></p>"
                  "<br><button style='padding:10px 20px;font-size:16px;background:#00ffcc;color:black;' "
                  "onclick=\"fetch('/auto')\">Automode</button>"
                  "</body></html>";
    server.send(200, "text/html", html);
  });

  // Servo route
  server.on("/servo", []() {
    if (server.hasArg("S") && server.hasArg("angle")) {
      String servoID = server.arg("S");
      String angle = server.arg("angle");
      String cmd = "S" + servoID + ":" + angle;
      Serial.println(cmd);  // Send to UART for ATmega32
      server.send(200, "text/plain", "Command sent: " + cmd);
    } else {
      server.send(400, "text/plain", "Missing parameters");
    }
  });

  // Automode route
  server.on("/auto", []() {
    Serial.println("A");  // Send char 'A'
    server.send(200, "text/plain", "Automode activated");
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}