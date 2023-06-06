# Global-Solution-EC-CS Monitoramento de cultivos

Repositorio para apresentar meu projeto da Global Solution, trabalho do semestre na FIAP  

O projeto visa o controle e monitoramento dos cultivos a partir de sensores de umidade do solo, temperatura e luminosidade. Os dados coletados a partir dos sensores de umidade do solo e de temperatura são apresentados no LCD, contendo também avisos no proprio LCD quando a umidade esta menor que 50%. O sensor de luminosidade tem seu alerta quando a luminosidade esta baixa a patir dos leds, quando a luminosidade esta critica um buzzer é acionado que significa um alerta. 
Foi nescessário a utilização de duas bibliotecas para realização do projeto:
- LiquidCrystal_I2C
- Wire

# Tecnologias utilizadas
- Sensor de umidade do solo 
- Sensor de luminosidade
- Sensor de temperatura 
- LCD i2c 16x2

# Utilização a partir do tinkercad 
Quando iniciada a simulação do projeto pelo tinkercad é necessário modificar os niveis de luminosidade e umidade do solo a partir dos seus respectivos sensores, já no sensor de temperatura não é necessário uma modificação nos seus niveis. Depois das modificação é possivel ver a mudança no display, leds e no buzzer (cuidado com o buzzer, o som pode ser desagradavel)

# Referencias
- Mestrado ipt iot biohealth urban smart farming - Airton Toyofuku pelo Github : https://github.com/toyusan/mestrado-ipt-iot-biohealth-urban-smart-farming.git
- Canal no Youtube "Laboratório da Julia" : https://youtu.be/QPH9aXS2bio

# Membros do grupo
- João Pedro de Albuquerque Oliveira           RM:551579
- Maurício Santos Rodrigues                    RM:551076
- Vitor Reyes Souza                            RM:550766
- Luis Serafin Bezagio Mendieta                RM:551588
- Pedro Augusto Carneiro Barone Bomfim         RM:99781
