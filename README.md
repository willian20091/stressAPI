# stressAPI
Teste de stress para API

Este é um código em C simples que pode ser usado para testar o desempenho de uma API, enviando várias requisições em um curto período de tempo. O código usa a biblioteca libcurl para fazer chamadas HTTP para a API especificada.

Pré-requisitos
Antes de executar este código, você precisará ter a biblioteca libcurl instalada em seu sistema. Você também precisará ter um URL de destino e a porta para a API que deseja testar.

Como executar o código
Para executar o código, siga estas etapas:

Compile o código usando um compilador C, como o gcc: gcc test-stress-api.c -o test-stress-api -lcurl

Execute o código, passando como parâmetros o URL da API, a porta da API e o número de requisições que deseja enviar: ./test-stress-api <url> <port> <num_requests>

Por exemplo, para enviar 1000 requisições para uma API com o URL http://localhost e porta 8080, você executaria o seguinte comando:

./test-stress-api http://localhost 8080 1000

Opções
O programa agora oferece uma opção de ajuda para os usuários, que pode ser exibida passando o parâmetro -h ou --help. Por exemplo:

./test-stress-api -h

Aviso
Tenha em mente que o uso indevido de testes de stress em APIs pode causar sobrecarga do sistema e interrupções para outros usuários. Certifique-se de que você tem permissão para realizar testes de stress em uma API antes de executar este código.