# Controle de Servomotor com Raspberry Pi Pico W

## Identificação Discente
**Nome:** Danilo Silveira  
**Curso:** Residência em Software Embarcado

Este projeto tem como objetivo demonstrar o controle de um servomotor utilizando o Raspberry Pi Pico W, através do uso do PWM (Pulse Width Modulation) para controlar a posição do servo em três ângulos distintos e realizar movimentos contínuos entre 0° e 180°.

## Pré-requisitos

- **Raspberry Pi Pico W**: O microcontrolador utilizado neste projeto, baseado no RP2040, é ideal para a implementação de projetos com controle de dispositivos como servos, displays e sensores.
- **Pico SDK**: O Software Development Kit (SDK) necessário para compilar e executar o código no Raspberry Pi Pico W. Para instalar o Pico SDK, siga as instruções fornecidas na [documentação oficial do Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk).
- **Ambiente de desenvolvimento C/C++**: O código foi desenvolvido em C, então é necessário configurar o ambiente de desenvolvimento utilizando o CMake e o SDK do Raspberry Pi Pico.

## Como Rodar o Projeto

### Estrutura do Código

O código está estruturado para realizar os seguintes passos:

1. **Configuração do PWM**: A GPIO 22 do Raspberry Pi Pico W é configurada para emitir um sinal PWM com uma frequência de 50Hz, o que corresponde a um período de 20ms.
2. **Controle de Posição do Servomotor**:
   - O ciclo ativo do PWM é ajustado para controlar a posição do servo motor.
   - O servo é movido para as posições de 180° (2.400µs), 90° (1.470µs) e 0° (500µs), com 5 segundos de espera em cada posição.
3. **Movimento Contínuo**:
   - Após as posições fixas, o servo realiza um movimento contínuo entre 0° e 180°, com incremento de 5µs e pausa de 10ms, garantindo um movimento suave.
   
### Passos do Código

1. **Configuração de PWM**:
   - O sinal PWM é gerado com uma frequência de 50Hz e um ciclo de 20ms.
   - A largura do pulso (duty cycle) é ajustada para controlar a posição do servo em 0°, 90° e 180°.
   
2. **Movimento nas Posições de 0°, 90° e 180°**:
   - O servo é movido para 180° (2.400µs), 90° (1.470µs) e 0° (500µs) com uma pausa de 5 segundos em cada posição.
   
3. **Movimento Suave Contínuo**:
   - O servo realiza uma movimentação contínua, variando o ciclo de pulso de 500µs a 2400µs com um incremento de 5µs a cada 10ms, criando um movimento suave entre 0° e 180° e vice-versa.

### Simulação no Wokwi

Este projeto pode ser facilmente simulado utilizando a plataforma [Wokwi](https://wokwi.com/). A simulação do Raspberry Pi Pico W e do servomotor pode ser realizada diretamente no ambiente do Wokwi, permitindo testar o comportamento do código sem a necessidade de hardware físico.

### Link do Vídeo

[Adicione o link do vídeo aqui]

## Estrutura do Código

O código está estruturado da seguinte maneira:

1. **Função `setup_pwm`**: Configura o sinal PWM na GPIO 22 para a frequência de 50Hz e define o valor do wrap para garantir um ciclo de 20ms.
2. **Função `set_pwm_duty_cycle`**: Ajusta o ciclo de trabalho do PWM, controlando a posição do servomotor em função do tempo de pulso.
3. **Função `main`**:
   - Inicializa o sistema e configura o PWM.
   - Move o servomotor para as posições de 180°, 90° e 0°.
   - Realiza a movimentação contínua do servomotor entre os ângulos de 0° e 180°.

## Conclusão

Este projeto é um exemplo simples de como utilizar o Raspberry Pi Pico W para controlar um servomotor utilizando PWM. O código implementa a movimentação precisa do servo entre 0° e 180° e inclui uma rotina de movimentação contínua, permitindo o controle suave do servo. A simulação no Wokwi facilita a experimentação sem a necessidade de hardware físico.

---

**Danilo Silveira**  
**Residência em Software Embarcado**
