
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>



int Acepta_Conexion_Cliente (int Descriptor)
{
	socklen_t Longitud_Cliente;
	struct sockaddr Cliente;
	int Hijo;


	Longitud_Cliente = sizeof (Cliente);
	Hijo = accept (Descriptor, &Cliente, &Longitud_Cliente);
	if (Hijo == -1)
		return -1;

	return Hijo;
}


int Abre_Socket_Inet (char *Servicio)
{
	struct sockaddr_in Direccion;
	struct sockaddr Cliente;
	socklen_t Longitud_Cliente;
	struct servent *Puerto;
	int Descriptor;

	Descriptor = socket (AF_INET, SOCK_STREAM, 0);
	if (Descriptor == -1)
	 	return -1;

	Puerto = getservbyname (Servicio, "tcp");
	if (Puerto == NULL)
		return -1;

	Direccion.sin_family = AF_INET;
	Direccion.sin_port = Puerto->s_port;
	Direccion.sin_addr.s_addr =INADDR_ANY;
	if (bind (Descriptor, (struct sockaddr *)&Direccion, sizeof (Direccion)) == -1){
		close (Descriptor);
		return -1;
	}

	if (listen (Descriptor, 1) == -1)
	{
		close (Descriptor);
		return -1;
	}

	return Descriptor;
}


