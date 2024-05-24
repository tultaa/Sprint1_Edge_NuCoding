# Sprint1 Edge Computing 
Equipe NuCoding
# Projeto Formula E - Sprint 1 - Documentação

Este projeto utiliza um Arduino Uno R3 e componentes diversos para criar um circuito simulador relacionado à Formula E, uma categoria de corrida de carros elétricos.

## Descrição do Projeto

O projeto consiste em um circuito que monitora temperatura, umidade e luminosidade, exibindo esses dados em um display LCD e também no Serial Monitor do Arduino IDE. Além disso, o circuito aciona LEDs indicadores e um buzzer em caso de problemas detectados nos sensores.

## Componentes Utilizados

- Arduino Uno R3
- Sensor de Temperatura e Umidade DHT22
- Sensor de Luminosidade (LDR)
- Display LCD 16x2
- LEDs (vermelho, verde e azul)
- Buzzer
- Resistores
- Protoboard
- Jumpers

## Configuração do Ambiente de Desenvolvimento

1. Instale o Arduino IDE em seu computador.
2. Abra o Arduino IDE e configure a placa para Arduino Uno R3.
3. Conecte o Arduino Uno R3 ao computador via cabo USB.
4. Abra o arquivo do código-fonte do projeto (.ino) no Arduino IDE.
5. Compile e faça o upload do código para o Arduino Uno R3.

## Pinagem

### Pinagem do Arduino Uno R3:

- DHT22: Conectado ao pino 6 (DHTPIN)
- Display LCD: Conectado aos pinos 12 (RS), 11 (EN), 10 (D4), 9 (D5), 8 (D6) e 7 (D7)
- LDR (Sensor de Luminosidade): Conectado ao pino A0 (lightSensor)
- LEDs: Conectados aos pinos 2 (vermelho), 3 (verde) e 4 (azul)
- Buzzer: Conectado ao pino 5

## Funcionamento do Projeto

1. Ao ser inicializado, o display LCD exibe "Nu Coding" e "Formula E" de forma dinâmica.
2. O projeto monitora temperatura, umidade e luminosidade.
3. Os dados são exibidos no display LCD e também no Serial Monitor.
4. LEDs indicam problemas detectados nos sensores: vermelho para temperatura alta, verde para umidade alta e azul para luminosidade alta.
5. Um buzzer é acionado quando há algum problema detectado, tocando intermitentemente.
