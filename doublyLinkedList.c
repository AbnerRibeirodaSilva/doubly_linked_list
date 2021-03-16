#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct no
{
    char name[20];
    int age;
    float salary;
    struct no *next,*back;


} no;

struct no *start,*chain,*assistant,*end;


enterdata()
{
    printf("\n Informe o nome da pessoa / enter the name of the person\nName:");
    scanf("%s",&chain->name);
    printf("\n Informe a idade da pessoa / Enter the person's age\nAge:");
    scanf("%d",&chain->age);
    printf("\n Informe o salario da pessoa / Enter the person's salary\nSalary:");
    scanf("%f",&chain->salary);
}

insert()
{
    if(start == NULL)
    {
        chain=(no*)malloc(sizeof(no));
        assistant = chain;
        start = chain;
        end = chain;
        chain->next = NULL;
        chain->back = NULL;
        enterdata();
    }
    else
    {
        assistant=start;
        chain=start;
        while(chain->next != NULL){
            assistant=assistant->next;
            chain=chain->next;
        }
        chain=(no*)malloc(sizeof(no));
        assistant->next = chain;
        chain->back = assistant;
        end = chain;
        assistant=chain;
        enterdata();
    }
}

display()
{
    if(start == NULL)
    {
        printf("Lista vazia / Empty list");
        system("pause");
    }
    else
    {

        assistant = end;

        while(assistant != start->back)
        {
            printf("\n Nome    / Name    :%s", assistant->name);
            printf("\n Idade   / Age     :%d", assistant->age);
            printf("\n Salario / Salary  :%.2f\n",assistant->salary);
            assistant=assistant->back;
        }
        system("pause");
    }
}
query()
{
    char name[20];
    int achou,c;
    if(start == NULL)
    {
        printf("Lista vazia / Empty list");
        system("pause");
    }
    else
    {

        printf("\n Nome a ser pesquisado / Name to be searched\nName:");
        scanf("%s",&name);
        achou =0;
        assistant=start;
        c=1;

        while(assistant != NULL)
        {
            c++;
            if (strcmp(name,assistant->name)==0)
            {
                printf("\n Elemento na posição / Element in position:%d",c);
                printf("\n Nome / Name\nName:%s", assistant->name);
                printf("\n Idade / Age\nAge :%d", assistant->age);
                printf("\n Salario / Salary\nSalary:%.2f \n",assistant->salary);
                system("pause");
                achou =1;
                break;
            }
            else
            {

                assistant=assistant->next;

            }
        }

        if (achou == 0)
        {
            printf("\n Registro não encontrado / Register not found\n\n");
            system("pause");
        }
    }

}

toRemove()
{
    int achou;
    char name[20];

   if(start == NULL)
   {
       printf("\n Lista vazia / Empty list\n\n");
       system("pause");
   }else {

       printf("\n Nome do registro a ser removido / Register name to be removed\nName:");
       scanf("%s",&name);
       assistant =start;
       achou=0;


       if (start->next == NULL && start->back == NULL && strcmp(assistant->name,name)==0)
       {

           free(start);
           start=NULL;
           printf("\n Removido unico elemento da lista / Removed single element from list\n\n");
           system("pause");

       }else {
       if (strcmp(assistant->name,name)==0)
       {
           start = start->next;
           start->back = NULL;
           free(assistant);
           printf("\n Removido primeiro elemento da Lista / Removed first element from the List\n\n");
           system("pause");
           achou=1;
       }else {

            chain=assistant->next;

            while(chain->next != NULL)
                {
                if (strcmp(chain->name,name)==0)
                {
                    chain=chain->next;
                    chain->back =assistant;
                    chain=assistant->next;
                    assistant->next = chain->next;
                    free(chain);
                    printf("\n Elemento removido do meio da lista / Element removed from the middle of the list\n\n");
                    system("pause");
                    achou =1;
                    return;
                }else {
                    assistant=assistant->next;
                    chain=chain->next;
                 }
              }
       }
       }
       if(achou ==0 && strcmp(chain->name,name)==0)
       {
           assistant->next = NULL;
           end =assistant;
           free(chain);
           printf("\n Removido elemento no final da lista / Removed element at the end of the list\n\n");
           system("pause");
           achou=1;
       }


    if(achou == 0)
    {
        printf("\n Elemento não foi encontrado na Lista / Element not found in List\n\n");
        system("pause");
    }
   }
 }

alter()
{

    char name[20];
    int achou;
    if(start == NULL)
    {
        printf("Lista vazia / Empty list\n\n");
        system("pause");
    }
    else
    {
        printf("\n Informe o registro que sera alterado / Inform the register that will be changed\nName");
        scanf("%s",&name);
        achou =0;
        assistant=start;


        while(assistant != NULL)
        {

            if (strcmp(name,assistant->name)==0)
            {
                printf("\n Idade / Age          :%d\n",assistant->age);
                printf("\n Salario / Salary     :%.2f\n",assistant->salary);
                printf("\n Alterando a Idade / Changing the Age\nAge:");
                scanf("%d",&assistant->age);
                printf("\n Alterando o Salario / Changing the Salary\nSalary:");
                scanf("%f",&assistant->salary);
                system("pause");
                achou =1;
                break;
            }
            else
            {

                assistant=assistant->next;

            }
        }

        if (achou == 0)
        {
            printf("\n Registro não encontrado / Register not found\n\n");
            system("pause");
        }
    }

}




main()
{
    setlocale(LC_ALL, "portuguese");
    chain =NULL;
    assistant =NULL;
    start  =NULL;

    int option;
    do
    {
        system("cls");
        printf("\n [1] - Insere elemento na lista / Inserts an element into the list");
        printf("\n [2] - Exibir os elementos da lista / Display the elements of the list");
        printf("\n [3] - Consulta elementos da lista / Query the list elements");
        printf("\n [4] - Alterar elemento da lista / Change list element");
        printf("\n [5] - Remove Elementos da Lista / Remove element from list");
        printf("\n [6] - Sair / get out");
        printf("\n Escolha uma opção / Choose an option: ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            query();
            break;
        case 4:
            alter();
            break;
        case 5:
            toRemove();
            break;
        default :
            printf("\n Opção Invalida, tente novamente / Invalid option, try again\n\n");
            system("pause");
            break;
        }
    }
    while(option !=6);
}
