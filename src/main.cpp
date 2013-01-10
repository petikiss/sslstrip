#include <iostream>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h> //inet_pton

#include <unistd.h>

#include <openssl/ssl.h>

// http://h71000.www7.hp.com/doc/83final/ba554_90007/ch04s03.html
// http://www.openssl.org/docs/ssl/SSL_CTX_new.html


int main()
{
    std::cout << "ok0";
    SSL_library_init();
    std::cout << "ok0.1";

    const SSL_METHOD *meth = SSLv2_client_method();

    SSL_CTX *ssl= SSL_CTX_new(meth);

     std::cout << "ok1";
     // Loading CA cert
     SSL_CTX *ctx;
     const char* caFile="/home/marci/sslstrip/etc/root-ca/cacert.crt";
     int ret = SSL_CTX_load_verify_locations(ctx, NULL, caFile);
     std::cout << ret << std::endl;
     std::cout << "ok2";


//     int sock = socket(PF_INET, SOCK_STREAM,0);
// //    std::cout << sock << std::endl;

//     sockaddr_in server;
//     server.sin_family = AF_INET;
//     server.sin_port = htons(22);
//     inet_pton(AF_INET, "0.0.0.0", &server.sin_addr);


//     if (connect(sock, (sockaddr*)&server, sizeof(server)) < 0)
//     {
//         std::cerr << "Error connect\n";
//         return(-1);
//     }
//     else
//     {
//         std::cout << "Connected\n";
//     }





    sleep(10);

    return 0;
}
