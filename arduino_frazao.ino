/*

*/
//https://www.usinainfo.com.br/sensor-uv-ultravioleta/sensor-uv-ultravioleta-para-arduino-guva-s12sd-4614.html
#include <Servo.h> //  precisa dessa lib pra trabalhar com o SG90

const int dayAnalogUV = 100; // o GUVA retorna um valor analógico sobre a radiação, aqui vai ser o que tu define como dia

bool isOpen = false; // indica se está aberta ou fechada a janela

const float openAngle = 180.0f; // angulo da janela aberta
const float closedAngle = 0.0f; // angulo da janela fechada

const int pinoServo = 2; // vai ser o valor do pino que tu ligar o SG na imagem ta o 2

Servo SG90;

int currentUV; //vai receber o valor lido do sensor sobre a rad UV atual;



void setup() {
  Serial.begin(9600);
  SG90.attach(pinoServo);
  SG90.write(closedAngle);
}

void loop() {
  
  currentUV = analogRead(A0);//Aqui tu vai substituir o A0 pelo pino que tu ligar o sensor, OBS tem que ser um dos analogicos, eu usei o A3
  
  if(currentUV >= dayAnalogUV && !isOpen)// se o sensor passar do valor considerado dia, e ainda não tiver aberto as janelas
  { 
    openWindow();
    isOpen = true;
  }
  else if(currentUV < dayAnalogUV && isOpen) // se o sensor ficar abaixo do valor do dia e as janelas estiverem abertas
  {
    closeWindow();
    isOpen = false;
  }
}

void openWindow()
{
  SG90.write(openAngle);//tu vai mandar aqui só ele mudar o angulo pra o valor que vai ser a janela aberta
}

void closeWindow()
{
  SG90.write(closedAngle);//vai mandar ele girar até a posição da janela fechada
}
