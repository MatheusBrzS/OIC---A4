## Componentes Utilizados
1) Microcontrolador:
- ESP8266 NodeMCU: Responsável pela comunicação Wi-Fi e execução do código.

2) Sensor de Nível:
- Sensor ultrassônico HC-SR04: Mede a distância da superfície da água ao sensor.

  Pinos:
   - Trig conectado ao pino D1 do ESP8266.
   - Echo conectado ao pino D2 do ESP8266.
  
  Faixa de Operação:
   - Distância: 2 cm a 400 cm.
   - Tensão: 5V DC (usando divisor de tensão para o sinal Echo).
 
     
3) Atuador:
- LED Vermelho: Indica o nível alto do reservatório.
   - Conectado ao pino D3 do ESP8266 com resistor de 220Ω.
     
4) Alimentação:
- Fonte 5V/1A para o ESP8266.
  
5) Protoboard e Jumpers:
- Para conexões temporárias entre os componentes.

  
## Esquema de Conexão
*Componente*	    |    *Pino do ESP8266*	|    *Descrição*
Sensor HC-SR04    |  D1 (Trig)	          | Envia pulso para iniciar a medição.
Sensor HC-SR04    |	 D2 (Echo)	          | Recebe o pulso de retorno.
LED Vermelho      |	 D3                   |	Indica nível de água alto.
Alimentação	      |  Vin e GND	          | Fonte de energia do ESP8266.


## Diagrama de Circuito
![image](https://github.com/user-attachments/assets/577fcafa-3eac-4563-8ce5-a450323309c7)


## Montagem Física
1) Fixe o sensor ultrassônico na parte superior do reservatório.
2) Conecte o ESP8266 à protoboard para facilitar as ligações.
3) Verifique as conexões de alimentação e a polaridade dos componentes.
