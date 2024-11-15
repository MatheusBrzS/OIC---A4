# OIC---A4
Repositório para a atividade de "Aplicando Conhecimento 4" da matéria de Objetos Inteligentes e Conectados

# Descrição (Materiais):
1) NodeMCU ESP8266 - Placa de desenvolvimento com conectividade Wi-Fi. 
2) Sensor de Nível de Água de Flutuação - Dispositivo para monitoramento do nível de água. 
3) Bateria de 5V ou 9V - Fonte de alimentação para o circuito. 
4) Protoboard - Para a montagem temporária do circuito. 
5) LED – Atuador visual para indicar os níveis da água 
6) Resistor 
7) Fios Jumper - Para realizar as conexões entre os componentes. 
8) Software Fritzing - Utilizado para modelagem e simulação do circuito eletrônico. 
9) ThingSpeak - Plataforma para armazenamento e visualização dos dados enviados via MQTT. 
10) IDE Arduino - Ambiente de programação para desenvolver o código do NodeMCU.

# Funcionamento:
- O NodeMCU é responsável por monitorar o sensor ultrassônico. Quando o sensor detecta variações na altura da água, ele envia sinais ao pino A0 do NodeMCU. 
- O código programado na IDE Arduino processa as leituras do sensor e, se o nível de água estiver abaixo de um valor crítico, o LED é acionado, acendendo para alertar visualmente que o nível está baixo. 
- Além disso, as leituras do nível de água são enviadas em intervalos regulares para a plataforma ThingSpeak usando o protocolo MQTT. 
- O sistema permite o monitoramento remoto dos níveis de água por meio da visualização dos dados em gráficos na plataforma ThingSpeak.


