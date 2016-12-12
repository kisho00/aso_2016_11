
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <pwd.h>
#define MAXLEN 1024


void separar(char *cadena, char *linea, char separador)
{
    int x, y;
    
    x = 0; y = 0;
    
    while ((linea[x]) && (linea[x] != separador))
    {
	cadena[x] = linea[x];
	x = x + 1;
    }
    cadena[x] = '\0';
    if (linea[x]) ++x;
    
    y = 0;
    
    while (linea[y] = linea[x])
    {
	linea[y] = linea[x];
	y++;
	x++;
    }

}

int main(int argc, char *argv[])
{
	
	 char *lenstr;
    char inputBuffer[MAXLEN];
    int contentLength;
    int i;
    char x;
 
    char usuario[80];
    char clave[80];
  
	
	
    printf("Content-type: text/html\n\n");	// Tell the browser the type of document being sent

	lenstr = getenv("CONTENT_LENGTH");
    //lenstr = (char *)getenv("CONTENT_LENGTH");
    if (lenstr!= NULL)
    {
	contentLength = atoi(lenstr);   
    }
    else contentLength = 0;

    if (contentLength > sizeof(inputBuffer)-1)
	contentLength = sizeof(inputBuffer)-1;

    i = 0;

    while (i < contentLength){

	x = fgetc(stdin);
	if (x==EOF) break;
	inputBuffer[i] = x;
	i++;
    }

    inputBuffer[i] = '\0';
    contentLength = i;
	
    separar(usuario, inputBuffer, '=');
    separar(usuario, inputBuffer, '&');
    separar(clave, inputBuffer, '=');
    separar(clave, inputBuffer, '&');
	
	if(clave!="val1"){

	   char com1A[200];
	   char com1B[200];
	   char com2[200];
	   char com3[200];
       char com4[200];
	   char com4A[200];
	   char com4B[200];
	   char com5[200];
	   
	     strcpy( com1A, "sudo /usr/sbin/useradd ");
		 strcpy( com1B, " -s /bin/bash");
		 strcpy( com2, "sudo /usr/bin/passwd -lq ");
		 strcpy( com3,"sudo mkdir ../../disk_user/");
		 
		  strcpy( com4,"sudo chown -R ");
		  
		  strcpy( com5,"sudo cp public_html.html ../../disk_user/");
		  

	   char command1[300];
	   char command2[300];
	   char command3[300];
	   char command4[300];
	   char command5[300];
		
	   strcat( com1A,usuario);  
	   strcpy( command1, strcat( com1A,com1B));
	   strcat( com2," "); 
       strcat( com2,usuario); 	   
	   strcpy( command2, strcat( com2,clave));
	   strcpy( command3, strcat( com3,usuario));
	   
	   strcpy( com4A, strcat( com4,usuario));
	   strcpy( com4B, strcat( com4A," ../../disk_user/"));
	   strcpy( command4, strcat( com4B,usuario));
	   strcpy( command5, strcat( com5,usuario));
		
		system(command1);
		system(command2);
		system(command3);
		system(command5);
		system(command4);

	}
	else{
		
	   char com1A[200];
	   char com1B[200];
		 strcpy( com1A, "sudo userdel ");
		 strcpy( com1B, "sudo mr ../../disk_user/");
		 char command1[300];
	   char command2[300];
		 strcpy( command1, strcat( com1A,usuario));
		 strcpy( command2, strcat( com1B,usuario));
		 
         system(command1);
		system(command2);
	}
    printf("<html>");
    printf("<head>");
    printf("<title>Admin_user</title>");
    printf("</head>");
    printf("<body>");
    
	 printf("<p >");
   printf("<a href=\"usuario.php\">Inicio</a> / <a href=\"user\">Registrar usuario</a> / <a href=\"usuario.php\">Acerca</a>");
printf("</p>");
	 printf("<p >");
 printf("<form action=\"user\" method=\"post\" name=\"reg_user\" id=\"reg_user\">");
  printf(" <table align=\"center\">");
    printf(" <tr >");
      printf(" <td  align=\"right\">Nombre :</td>");
      printf(" <td>");
	  printf(" <input type=\"text\"  name=\"nombre_usuario\" placeholder=\"Ingrese un nombre\"  size=\"32\" required/>");
	  printf(" </td>");
     printf("</tr>");
    printf(" <tr >");
       printf("<td  align=\"right\">Contrasena :</td>");
      printf("<td>");
	   printf("<input type=\"text\"  name=\"pass_usuario\" placeholder=\"Ingrese una contraseña\"  size=\"32\" required/>");
	   printf("</td>");
   
    printf("<tr >");
      printf(" <td align=\"right\">");
	 printf("  <input  type=\"submit\" value=\"Crear usuario\"/>");
	 
	 printf("  </td>");
      printf(" <td>");
	  printf("  <input type=\"reset\" value=\"Restablecer\"  />");
	 printf("  </td>");
   printf("  </tr>");
   printf("</table>");
 
 printf("</form>");
 printf("</p>");

 printf("<p>");
   printf("<h3>lista de  usuarios</h3>");
   
    char usrsys[80];
    struct passwd *pwd;        

    setpwent();
	
   printf(" <table  border=\"1\">");
  printf("<tr>");
   printf(" <th scope=\"row\">Usuario</th>");
   printf(" <td>UID</td>");
  printf("  <td>GID</td>");
 printf(" </tr>");
 
   while (pwd = getpwent())
    {
	// Mostrar datos de usuario
	strcpy(usrsys,pwd->pw_name);
	if(((pwd->pw_uid)>1000)&&((pwd->pw_uid)<2000)){
		
  printf("<tr>");
   printf(" <th scope=\"row\">%s</th> ",usrsys);
   printf(" <td>%d</td>", pwd->pw_uid);
   printf(" <td>%d</td>", pwd->pw_gid);
   //printf(" <td><a href=\"user?dato=%s&del=val1\">Eliminar</a>",usrsys);
   printf(" <td><a href=\"../../disk_user/%s\">Ver </a></td>",usrsys);
  printf("</tr>");
  
	}
		    
    } 
printf("</table>");	
    
    endpwent();
   
   
 printf("</p>");


    printf("</body>");
    printf("</html>");
    return 0;
}

