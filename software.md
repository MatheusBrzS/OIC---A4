## Descrição Geral
O código implementa um sistema de monitoramento de nível de água baseado em ESP8266, que utiliza um sensor ultrassônico para medir a distância até a superfície da água. Os dados coletados são processados para calcular o nível percentual de preenchimento do reservatório, exibidos no monitor serial e enviados ao ThingSpeak para armazenamento e análise. Um LED acende quando o nível de água ultrapassa 90%.

## Principais Funções
1) Conexão Wi-Fi
- Configura o ESP8266 para se conectar a uma rede Wi-Fi usando as credenciais fornecidas.
- Verifica continuamente o status da conexão e tenta reconectar em caso de falha.

2) Leitura do Sensor Ultrassônico
- A função readUltrasonicDistance mede a distância entre o sensor e a superfície da água.
- Os valores são convertidos para centímetros.
  
3) Mapeamento de Valores
- A função mapDistance converte a distância medida em um valor percentual representando o nível de preenchimento.
  
4) Envio ao ThingSpeak
- Dados do nível são enviados ao ThingSpeak usando requisições HTTP.
- A frequência de envio é controlada por sendInterval (10 segundos).
  
5) Indicação com LED
- O LED acende quando o nível ultrapassa 90%, indicando um reservatório quase cheio.
  
## Fluxo do Programa
- setup:
   Configura os pinos do sensor e do LED.
   Conecta à rede Wi-Fi.
- loop:
   Mede a distância e calcula o nível.
   Atualiza o estado do LED.
   Envia dados ao ThingSpeak, respeitando o intervalo definido.
  
