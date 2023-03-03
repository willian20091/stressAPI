#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <curl/curl.h>

void print_help() {
    printf("Uso: test-stress-api [OPÇÕES] <url> <port> <num_requests>\n");
    printf("\n");
    printf("Opções:\n");
    printf("  -h, --help\t\tMostra esta mensagem de ajuda e sai\n");
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;

    int opt;
    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                exit(EXIT_SUCCESS);
                break;
            default:
                print_help();
                exit(EXIT_FAILURE);
                break;
        }
    }

    if (argc - optind != 3) {
        fprintf(stderr, "Erro: Número de argumentos inválido\n");
        print_help();
        exit(EXIT_FAILURE);
    }

    char *url = argv[optind];
    int port = atoi(argv[optind + 1]);
    int num_requests = atoi(argv[optind + 2]);

    curl = curl_easy_init();
    if (curl) {
        for (int i = 0; i < num_requests; i++) {
            char request_url[100];
            sprintf(request_url, "%s:%d", url, port);

            curl_easy_setopt(curl, CURLOPT_URL, request_url);
            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            }
        }
        curl_easy_cleanup(curl);
    }

    return 0;
}
