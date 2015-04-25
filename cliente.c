#include "ChSocket/Socket.h"
#include "ChSocket/Socket_Cliente.h"


#include "lex.yy.h"


extern   int tipo;
extern   int cont;
extern   int arrayy[5];
extern   void yyerror(char *s);
extern   int yyparse(void);
#include <stdio.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <sys/shm.h>

main()
{
    int sock;     
    int buffer2[5]; 
    int error;      
    int buffer;  
   
    sock = Abre_conexion_Inet_remote("127.0.0.1", "servicio");


    error = Lee_Socket (sock, (char *)&buffer, sizeof(int));

  
    if (error < 1)  {
        printf ("conexión cerrada \n");
        return;
    }
   
    printf (" cliente %d", buffer);

    while(1){
    //analiz  SQL
        int j;
        int flag=1;
        while(flag){
            cont = 0;
            arrayy[0]=arrayy[1]=arrayy[2]=arrayy[3]=arrayy[4]=0;
            printf ("\n Ingrese la Consulta: ");
            if(yyparse() != 0){
                fprintf(stderr, " La sentencia SQL   incorrecta\n");
                getchar();
                yyrestart(stdin);
                system("/usr/bin/clear"); 
            }
            else
                flag=0;

        }
		
	fprintf(stderr, " La sentencia SQL   correcta\n");

    arrayy[4]=tipo;

       for (j=0; j<5; j++)    {
           buffer2[j] = arrayy[j];
    
        }
        Escribe_Socket (sock, (char *)&buffer2, sizeof(int)*5);
	
        char buf[1024];

        Lee_Socket (sock, (char *)&buf, sizeof(char)*1024);
        printf("\n Respuesta: %s\n ", buf);

        if (error < 1)  {
            printf (" conexión cerrada \n");
            return;
        }
    }

}

