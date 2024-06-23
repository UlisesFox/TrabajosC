#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
 
struct direc{
char nombre[30];
struct direc *sig;
struct direc *ante;
}entrada_lista;
 
struct direc *ppio;
struct direc *final;
struct direc *buscar(char *);
 
void intro(void),buscar(void),listar(void);
void borrar(struct direc **,struct direc **);
void dl_insert(struct direc *i,struct direc **ppio, struct direc **final);
void leecad(char *,char *,int),mostrar(struct direc *);
int menu (void);
 
main(){
ppio=final=NULL;
for(;;){
switch (menu()){
case 1:intro();
break;
case 2:listar();
getch();
break;				
case 3:borrar(&ppio,&final);
break;			
case 4:buscar();
getch();
break;	
case 5:exit(0);
break;}}}
 
int menu(void){
char s[80];
int c;
printf("\nMenu de Lista Doblemente Enlazda.");
printf("\n\n1. Introducir un nombre.\n");
printf("2. Listar el archivo.\n");
printf("3. Borrar un nombre.\n");
printf("4. Buscar.\n");
printf("5. Salir.\n");
do{
printf("\nIntroduzca su opcion: ");
gets(s);
c=atoi(s);
}while(c<0 || c>5);
return(c);}
 
void intro(void){
struct direc *info;
for (;;){
info=(struct direc *)malloc (sizeof(entrada_lista));
if (!info){
printf("\nNo hay memoria");
return;}
leecad("Introduzca nombre: ",info->nombre,30);
if (!info->nombre[0])break;
dl_insert(info,&ppio,&final);}}
 
void leecad(char *indic,char *s,int cont){
char p[255];
do{
printf(indic);
gets(p);
if (strlen(p)>cont){
printf("\nDemasiado largo\n");
printf("La longitud permitida es %i\n",cont);}
}while(strlen(p)>cont);
strcpy(s,p);}
 
void dl_insert(struct direc *i, struct direc **ppio, struct direc **final){
struct direc *ant,*p;
if (*final==NULL){
i->sig=NULL;
i->ante=NULL;
*final=i;
*ppio=i;
return;}
p=*ppio;
ant=NULL;
while (p){
if(strcmp(p->nombre,i->nombre)<=0){
ant=p;
p=p->sig;
}else{
if(p->ante){
p->ante=i;
i->sig=p;
i->ante=ant;
ant->sig=i;
return;}
i->sig=p;
i->ante=NULL;
p->ante=i;
*ppio=i;
return;}}
ant->sig=i;
i->sig=NULL;
i->ante=ant;
*final=i;}
 
void borrar(struct direc **ppio, struct direc **final){
struct direc *info, *buscar(char *nombre);
char s[80];
printf("Introduzca nombre: ");
gets(s);
info=buscar(s);
if(info){
if(*ppio==info){
*ppio=info->sig;
if (*ppio)
(*ppio)->ante=NULL;
else
*final=NULL;
}else{
info->ante->sig=info->sig;
if (info!=*final)
info->sig->ante= info->ante;
else
*final=info->ante;
}free(info);}}

struct direc *buscar(char *nombre){
struct direc *info;
info=ppio;
while(info){
if(!strcmp(nombre,info->nombre))
return info;
info=info->sig;}
printf("Nombre no encontrado\n");
return NULL;}
 
void listar(void){
struct direc *info;
info=ppio;
if (!info){
printf("\nLista Vacia\n");
return;}
while(info){
mostrar(info);
info=info->sig;}}
 
void mostrar(struct direc *info){
printf("%s ",info->nombre);}
 
void buscar(void){
char nombre[40];
struct direc *info, *buscar(char *nombre);
printf("Introduzca nombre: ");
gets(nombre);
info=buscar(nombre);
if (!info)
printf("No encontrado\n");
else
mostrar(info);}
