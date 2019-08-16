# Etiqueta-digital
Projeto realizado para disciplina de técnicas de programação.

# Sumário

- O que é a etiqueta digital?
- Manual do usuário;
- Funcionamento;
- Ficha técnica.

# O que é a etiqueta digital?
Observando o funcionamento de um supermercado, observamos que correntemente os funcionários precisam alterar o preço dos produtos nas prateleiras, pensando nisso, criamos uma etiqueta digital que tem como objetivo principal automatizar esta função.

A etiqueta consiste, basicamente, em uma ESP (NODEMCU V3) que recebe os dados de uma central e os encaminha para o lcd. Esses dados serão exibidos em cada prateleira, informando produto, valor e respectivos descontos.

![](C:imagens/etiqueta.JPG)

Na imagem acima podemos observar o escopo do nosso produto.

# Manual do Usuário

## Funcionamento da etiqueta
A ideia do projeto é que funcionário do supermercado possa ter alterar o valor dos seus produtos sem precisar perder tanto tempo e gastar tanto com material. Para isso, será disponibilizado uma interface na qual haverá os campos a serem preenchidos para que possa ser executada a inserção dos dados do produto. Controlaremos também a necessidade de reposição (ou não) de repor o produto, através de um sensor infravermelho que detecta a presença da mercadoria na prateleira e encaminha uma mensagem para a central.

![](C:imagens/etiqueta.JPG)

# Utilizando a etiqueta

![(

A tela de inicial da aplicação do projeto é bastante direta. Primeiro, o usuário deve conectar o seu cabo microUSB da ESP12 com alguma entrada USB do seu computador. A seguir, deve ser selecionada a porta na qual a placa está conectada. Para que as informações sejam passadas, faz-se necessário ter uma velocidade específica (em bauds) para comunicação, sendo selecionado 115200 a padrão da placa. Em seguida, na aba "Etiqueta" preencha os seguintes dados:

- Nome do produto;
- Preço;
- Desconto geral;
- Desconto em atacado.

Por fim, seleciona-se "Atualizar" e o produto descrito na interface aparecerá no lcd.

# Ficha técnica
## Materiais utilizados:
- ESP12;
- LCD;
- Sensor infravermelho;
- Protoboard;
- cabos.

# O Circuito

![(

Utilizamos o sensor infravermelho captura das informações do estado da prateleira. A ESP12 é a peça mais importante do circuito, pois capta as informações vindas da central e as transfere para o LCD, assim como também recebe do infravermelho e identifica a stiuação da prateleira.

 Nossa alternativa para realizar o funcionamento offline é plugar um cabo USB para o computador para que o usuário possa obter as informações via serial pelo software.
 
 


