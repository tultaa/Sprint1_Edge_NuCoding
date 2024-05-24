# Sprint1 Edge Computing 
#### Equipe NuCoding
- Integrantes: Arthur Fellipe(553320), Eduardo Pires(556527), Leonardo Munhoz(556824)
# Projeto Formula E - Sprint 1 - Documentação

Este projeto utiliza um Arduino Uno R3 e componentes diversos para criar um circuito simulador relacionado à Formula E, uma categoria de corrida de carros elétricos.

## Descrição do Projeto

O projeto consiste em um circuito que monitora temperatura, umidade e luminosidade, exibindo esses dados em um display LCD e também no Serial Monitor do Arduino IDE. Além disso, o circuito aciona LEDs indicadores e um buzzer em caso de problemas detectados nos sensores.

Este projeto consiste em um circuito simulador que pode ser útil em uma situação real de corrida, especialmente em corridas elétricas, como a Formula E, por diversas razões:

- **Monitoramento Ambiental**: O circuito é capaz de monitorar variáveis ambientais como temperatura, umidade e luminosidade. Essas informações são cruciais para garantir o conforto e segurança dos pilotos e equipes durante a corrida, especialmente em ambientes ao ar livre onde as condições climáticas podem mudar rapidamente.

- **Detecção de Condições de Pista**: O sensor de luminosidade pode detectar variações na iluminação da pista, o que pode ser útil para alertar os organizadores sobre áreas com pouca visibilidade ou risco de reflexos, ajudando na tomada de decisões para garantir a segurança dos pilotos.

- **Alerta de Problemas**: Os LEDs indicadores e o buzzer podem alertar as equipes sobre problemas detectados nos sensores, como temperaturas anormalmente altas, umidade elevada ou baixa luminosidade. Esses alertas podem ser úteis para identificar e resolver problemas técnicos nos carros ou na pista antes que eles se tornem mais graves.

- **Documentação e Análise de Dados**: O circuito é capaz de exibir os dados captados no display LCD e no Serial Monitor do Arduino IDE. Isso permite que as equipes coletem e analisem dados em tempo real durante os treinos e corridas, ajudando na tomada de decisões estratégicas para maximizar o desempenho dos carros e pilotos.

Em resumo, este circuito simulador oferece uma solução acessível e versátil para monitoramento ambiental, detecção de problemas e análise de dados em corridas elétricas, contribuindo para a segurança, eficiência e competitividade das equipes e pilotos.

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

## Visão do Circuito Pronto
### O Código utilizado esta na pasta codigo_sprint1
![Screenshot_13](https://github.com/tultaa/Sprint1_Edge_NuCoding/assets/78042666/9c9a9eff-db43-4a1a-99ba-d14cdf24a432)


