#define rele1 1
#define rele2 2
#define rele3 3
int controle = 0;
bool null;
int readBluetooth; 


void setup() {
 Serial.begin(9600);
 pinMode(rele1, OUTPUT); 
 pinMode(rele2, OUTPUT);
 pinMode(rele3, OUTPUT);
}
 
void loop() {
controleRobo();
delay(1000);
enviaInformacao();
delay(1000);

}


 

void controleRobo(){
    
    if(Serial.available()>0){//Verifica se algo chegou via Bluetooth
    readBluetooth=Serial.read();//Grava esse algo lido na variável
    Serial.write(readBluetooth);
      switch(readBluetooth){
      case '6':
        controleRele(1,1,1);
        controle = 1;
        break;
      case '4':
        controleRele(1,1,0);
        controle = 1;
        break;
      case '5':
        controleRele(1,0,1);
        controle = 1;
        break;
      case '3':
        controleRele(1,0,0);
        controle = 1;
        break;   
      default: 
        break;
      }
    }
}

void controleRele(bool saida1, bool saida2, bool saida3){
    digitalWrite(rele1, saida1);
    digitalWrite(rele2, saida2);
    digitalWrite(rele3, saida3);
 }

 void enviaInformacao(){
      if (controle == 1){
          Serial.write(201);
          Serial.write(highByte(controle));
          Serial.write(lowByte(controle));
          delay(250);
          controle = 0;
      }
 }

 

