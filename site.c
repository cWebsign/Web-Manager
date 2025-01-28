#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <str.h>
#include <arr.h>
#include <map.h>
#include <Net/web.h>

void err_n_exit(char *msg, void **ptr) {
    int i = 0;
    while(ptr[i] != NULL)
        free(ptr[i]);
        
    printf("%s\n", msg);
    exit(1);
}

/* { } */
typedef struct MyApp {
    WebRoute **Routes;

} MyApp;

Control AddRouteStyle = (CSS){ .Class = "add_route", .Selector = 1, .Data = (char *[]){} };
Control AddRouteBtn = (Control){ .Tag = DIV_TAG, .Class = AddRouteStyle.Class, .Text = "Create new route" };

/* HTML Route List */
// TODO: add subcontrols dyanmically
CSS RouteListStyle = (CSS){ .Class = "route_list", .Selector = 1, .Data = (char *[]){} };
Control RouteList = (Control){ .Tag = DIV_TAG, .Class = RouteListStyle.Class };

/* HTML Form for Route Creating Pgae */
// TODO: add name attribute(s)
CSS RouteFormStyle = (CSS){ .Class = "route_form", .Selector = 1, .Data = (char *[]){"width: 500px", "height: 80%", "border-radius: 15px", NULL}};
Control CreateRouteForm = (Control){ .Tag = DIV_TAG, .Class = RouteFormStyle.Class, .SubControls = (void *[]){
    &(Control){ .Tag = FORM_TAG, .Data = "method=\"post\"", .SubControls = (void *[]){
        &(Control){ .Tag = P_TAG, .Text = "Route Name:" },
        &(Control){ .Tag = INPUT_TAG, .ID = "route_name", .Type = "text" },
        &(Control){ .Tag = P_TAG, .Text = "Route Path:" },
        &(Control){ .Tag = INPUT_TAG, .ID = "route_path", .Type = "text" },
        &(Control){ .Tag = INPUT_TAG, .ID = "submit_route", .Type = "submit" },
        NULL
    }},
    NULL
}};


Control **ListPages(WebRoute *route) {
    Control **controls = (Control **)malloc(sizeof(Control *) * (route->SubControlCount + 1));
    memset(controls, '\0', sizeof(Control *) * (route->SubControlCount + 1));

    for(int i = 0; i < route->SubControlCount; i++) {
        
    }
}

int main() {
    cWS *server = StartWebServer(NewString(""), 80, 0);
    if(!server)
        err_n_exit("[ x ] Error, Unable to start web server....!\n", NULL);

    server->AddRoutes(server, (WebRoute *[]){
        &(WebRoute){
            .Name = "index",
            .Path = "/",
            .Template = "Welcome To Websign!",
            .ReadOnly = 1
        },
        NULL
    });

    server->Run(server, 999, 0);

    char BUF[5];
    fgets(&BUF, 5, stdin);
    return 0;
}