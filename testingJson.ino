//si usas esp32
#include <WiFi.h>
#include <ArduinoJson.h>
//si usas esp8266
//#include <ESP8266WiFiMulti.h>
//#include <ESP8266HTTPClient.h>

const char* ssid = "INFINITUM9576_2.4";
const char* password =  "ht6pwZnQAv";

void setup() {
  delay(10);
  Serial.begin(115200);


  WiFi.begin(ssid, password);

  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(500);
    Serial.print(".");
  }

  Serial.print("Conectado con éxito, mi IP es: ");
  Serial.println(WiFi.localIP());

}

void loop() {

  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status

    HTTPClient http;
    String datos_a_enviar = "{\"data\" : 410}";

    http.begin("http://192.168.1.129:5000/");        //Indicamos el destino
    http.addHeader("Content-Type", "application/json"); //Preparamos el header json
    //int codigo_respuesta = http.POST(datos_a_enviar);   //Enviamos el post pasándole, los datos que queremos enviar. (esta función nos devuelve un código que guardamos en un int)


    DynamicJsonDocument doc(200); // <- 200 bytes in the heap

    doc["accelX"] = 0;
    doc["accelY"] = 50;
    doc["accelZ"] = 100;
    doc["status"] = "world";
    doc["line"] = 0.0;

    String output = doc.as<String>();
    Serial.println(output);
    int codigo_respuesta = http.POST(output);   //Enviamos el post pasándole, los datos que queremos enviar. (esta función nos devuelve un código que guardamos en un int)

    if(codigo_respuesta>0){
      Serial.println("Código HTTP: " + String(codigo_respuesta));   //Print return code
      if(codigo_respuesta == 200){
        String cuerpo_respuesta = http.getString();
        Serial.println("El servidor respondió:");
        Serial.println(cuerpo_respuesta);
      }
    }else{
     Serial.print("Error enviando POST, código: ");
     Serial.println(codigo_respuesta);
    }
    http.end();  //libero recursos
  }else{
     Serial.println("Error en la conexión WIFI");
  }

   delay(2000);
}
