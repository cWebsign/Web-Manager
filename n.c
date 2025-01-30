#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <Net/web.h>

Map Headers = {0};

int main() {
    /* Start Web Server */
    cWS *server = StartWebServer(NewString(""), 80, 0);
    if(!server) {
        printf("[ - ] Error, Unable to start web server.....!\n");
        return 1;
    }

    /* Set up default headers */
    Headers = NewMap();
    Headers.Append(&Headers, "Content-type", "text/html; charset=UTF-8");
    Headers.Append(&Headers, "Connection", "close");

    /* Add Routes */
    server->AddRoutes(server, {
        CreateRoute("index", "/", ({void *IndexRoute(cWS *server, cWS *req, cWS *route, int socket){
            SendResponse(server, socket, OK, ((Map){}), "Hello World");
        } IndexRoute; })),
        NULL
    });

    server->Run(server, 999, 0);

    char BUF[10];
    fgets(BUF, 10, stdin);
    return 0;
}