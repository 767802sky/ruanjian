#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define N 100
void Input_Infor();
void Cal_Wages();
void sort_Wage();
void Save_Infor();
void Menu();
int Up_infor();
int Search_Name();
int Search_Num();
void Modify_Worker();
void Print_Worker(int i);
int Search_Worker();
int Worker_del();
struct Worker
{
    char workernum[10];//Ա�����
    char workername[20];//Ա������
    int basicwage;//Ա����������
    int allowance;//����
    int Bonus;//Ա������
    int totalwage;//Ա���ܹ���
}Worker_Infor[N];
struct Worker temp;
int m;
int main()
{
    m = Up_infor();
    Menu();
    return 0;
}

/**********************Menu�˵�**********************/
void Menu()
{
    int c,t=1;
    int i=0;
    while(t)
    {

        printf("\n  ------------------------------------| ְ������ϵͳ |---------------------------------\n");
        printf("  =======================================================================================\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                 - 1 - ¼��Ա����Ϣ             - 2 - �鿴����Ա����Ϣ              ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                 - 3 -��ѯԱ����Ϣ              - 4 - �޸�Ա����Ϣ                  ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                 - 5 - ɾ��Ա��                 - 6 - �˳�ϵͳ                      ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                 - 7 - ����                                                         ||\n");
        printf("  =======================================================================================\n");
        printf("  --����������ѡ��");
        scanf("%d",&c);
        getchar();
        if(c<1||c>8) {printf("\t�����������������:\n");continue;}
        switch(c)
        {
        case 1:
            Input_Infor();
            Sleep(2000);
            break;
		 case 2:
            system("cls");
            printf("  -----------------------------| ����Ա����Ϣ |------------------------------\n");
            printf("  ============================================================================\n");
            printf("\tԱ�����\tԱ������\t��������\t����\t����\t�ܹ���\t\n");
            for(i=0;i<m;i++)
            {
                    Print_Worker(i);
            }
            printf("  ============================================================================\n");
            Sleep(2000);
            break;
        case 3:
            system("cls");
            Search_Worker();
            Sleep(2000);
            break;
        case 4:
            system("cls");
            Modify_Worker();
            break;
       
        case 5:
            system("cls");
            Worker_del();
            Sleep(2000);
            break;
        case 6:
            system("cls");
            t=0;
        printf("\n  --------------------------| ְ������ϵͳ |--------------------------\n");
        printf("  ======================================================================\n");
        printf("  ||                                                                  ||\n");
        printf("  ||                            ��л����ʹ�ã�                        ||\n");
        printf("  ||                                                                  ||\n");
        printf("  ||                              ( ^_^ )                             ||\n");
        printf("  ||                                                                  ||\n");
        printf("  =====================================================================\n");
            break;
	 case 7:
          system("cls");
          Save_Infor();
          Sleep(2000);
		  break;

        }
    }
}
/****************Ա����Ϣ¼�뺯��****************/
void Input_Infor()
{
    char c,nums[20];
    int i,j,flag=1;
    if(m==0)
        i=0;
    else i=m;
    printf("  ------------------------| Ա����Ϣ¼�� |------------------------------\n");
    printf("  ======================================================================\n");
    while(1)
    {
        printf("  ||                     -��%dλְ���ı��:",i+1);
        TO:
            if(m==0)
            {
                gets(Worker_Infor[m].workernum);
            }
            else
            {
                gets(nums);
                for(j=0;j<m;j++)
                {
                    if(strcmp(nums,Worker_Infor[j].workernum)==0)
                    {
                        printf("  ||                     -�Ѵ��ڣ�������:");
                        goto TO;
                    }
                    else
                    {
                        strcpy(Worker_Infor[i].workernum,nums);
                    }
                }
            }
        printf("\n  ||                    -����Ϊ%sְ��������:",Worker_Infor[i].workernum);
        gets(Worker_Infor[i].workername);
        printf("\n  ||                      -%sְ����������:",Worker_Infor[i].workername);
        while(1)
        {
            scanf("%d",&Worker_Infor[i].basicwage);
            if(Worker_Infor[i].basicwage>=0) break;
            else printf("\n  ||                      �������,������:");
        }
        printf("\n  ||                        -%sְ���Ľ���:",Worker_Infor[i].workername);
        while(1)
        {
            scanf("%d",&Worker_Infor[i].allowance);
            if(Worker_Infor[i].allowance>=0) break;
            else printf("\t�������,������:");
        }
        printf("\n  ||                        -%sְ���Ľ���:",Worker_Infor[i].workername);
        while(1)
        {
            scanf("%d",&Worker_Infor[i].Bonus);
            if(Worker_Infor[i].Bonus>=0) break;
            else printf("\t�������,������:");
        }
        i++;
        m=i;
        getchar();
        printf("\n  ||                       -�Ƿ��������:Y or N ���� y or n:");
        scanf("%c",&c);
        getchar();
        if(c=='N'||c=='n')
        {

            system("cls");
            printf("  =========================================================================================\n");
            printf("  ||                                                                                      ||\n");
            printf("  ||                                     ��л����ʹ�ã�                                   ||\n");
            printf("  ||                                                                                      ||\n");
            printf("  ||                                   ��Ϣ��������뱣��!                                ||\n");
            printf("  ||                                                                                      ||\n");
            printf("  ||                                 - @author by---Zddeؼ -                              ||\n");
            printf("  =========================================================================================\n");
            break;
        }
    }
}

/*******************�����ܹ���******************************/
void Cal_Wages()
{

    int i;
    for(i=0;i<m;i++)
    {
        Worker_Infor[i].totalwage = Worker_Infor[i].basicwage + Worker_Infor[i].allowance + Worker_Infor[i].Bonus;
    }

}
void sort_Wage()
{
    Cal_Wages();
    int i,j;
    //printf("%d",m);
    for(i=0;i<m-1;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(Worker_Infor[j].totalwage>Worker_Infor[i].totalwage)
            {
                temp = Worker_Infor[j];
                Worker_Infor[j]=Worker_Infor[i];
                Worker_Infor[i]=temp;

            }
        }
    }
        printf("  ------------------------------| Ա���ܹ������� |---------------------------------\n");
        printf("  =================================================================================\n");
        printf("\tԱ�����\tԱ������\t��������\t����\t����\t�ܹ���\t\n");
    for(i=0;i<m;i++)
    {
        printf("\t%-10s\t%-8s\t%-10d\t%-8d%-8d%-6d\t\n",Worker_Infor[i].workernum,Worker_Infor[i].workername,Worker_Infor[i].basicwage,Worker_Infor[i].allowance,Worker_Infor[i].Bonus,Worker_Infor[i].totalwage);
    }
        printf("  =================================================================================\n");
}
/*******************�����ļ�**********************/
void Save_Infor()
{
    int i,n=0;
    FILE *pk;
    FILE *pf;
    Cal_Wages();
    pk=fopen("Worker.txt","w");
    pf=fopen("sumpeo.txt","w");
    n += m;
    fprintf(pf,"%d",n);
    /*if((pk=fopen("C:\\Users\\Administrator\\Desktop\\Worker.txt","w"))==NULL);
    {
        printf("�ļ���ʧ��\n");
        exit(0);

    }*/
    for(i=0;i<m;i++)
    {
        fprintf(pk,"\t%10s\t%8s\t%10d\t%8d%8d%6d\t\n",Worker_Infor[i].workernum,Worker_Infor[i].workername,Worker_Infor[i].basicwage,Worker_Infor[i].allowance,Worker_Infor[i].Bonus,Worker_Infor[i].totalwage);
    }

    fclose(pf);
    fclose(pk);

        printf("  =======================================================================================\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                                  �ļ�����ɹ�                                      ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  =======================================================================================\n");

}
/***************************�ļ�����******************/
int Up_infor()
{
    FILE *fp;
    FILE *pk;

    int i;
    fp = fopen("Worker.txt","r");
    pk = fopen("sumpeo.txt","rb");
    if(pk==NULL)
    {
        printf("  =======================================================================================\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                                  �ļ�����ʧ��                                      ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  =======================================================================================\n");

    }
    else
    {
        fscanf(pk,"%d",&m);
        //printf("%d",m);
    }
    for(i=0;i<m;i++)
    {
        fscanf(fp,"\t%10s\t%8s",Worker_Infor[i].workernum,Worker_Infor[i].workername);
        fscanf(fp,"\t%10d\t%8d%8d%6d",&Worker_Infor[i].basicwage,&Worker_Infor[i].allowance,&Worker_Infor[i].Bonus,&Worker_Infor[i].totalwage);
        /*printf("\t%10s\t%8s",Worker_Infor[i].workernum,Worker_Infor[i].workername);
        printf("\t%10d\t%8d%8d%6d\n",Worker_Infor[i].basicwage,Worker_Infor[i].allowance,Worker_Infor[i].Bonus,Worker_Infor[i].totalwage);*/
    }
    return m;
    fclose(fp);
    fclose(pk);

}
/***************************��ѯ��ʽ******************/
void Print_Worker(int i)
{
    printf("\t%-10s\t%-8s\t%-10d\t%-8d%-8d%-6d\t\n",Worker_Infor[i].workernum,Worker_Infor[i].workername,Worker_Infor[i].basicwage,Worker_Infor[i].allowance,Worker_Infor[i].Bonus,Worker_Infor[i].totalwage);

}
int Search_Worker()
{
    int i,p;
    int Search_Num();
    int Search_Name();
    printf("  ------------------------------------| Ա����ѯ���� |----------------------------------\n");
    printf("  ======================================================================================\n");
    printf("  ||                                                                                   ||\n");
    printf("  ||                                 - ��ѡ���ѯ��ʽ:                                 ||\n");
    printf("  ||                     - 1 - ��������ѯ        - 2 - ��Ա�����Ų�ѯ                  ||\n");
    printf("  ||                     - 3 - �˳�              - ��ӭʹ�� -( ^_^ )-                  ||\n");
    printf("  ||                                                                                   ||\n");
    printf("  ======================================================================================\n");
    scanf("%d",&p);
    switch(p)
    {
        case 1:i=Search_Name();return i;break;
        case 2:i=Search_Num();return i;break;
        case 3:return -1;
    }
     return 0;
}
/***************************�����ֲ���******************/
int Search_Name()
{
    int i;
    char name[20];
    printf("  ||                - ������Ҫ��ѯ��Ա������:                          ");
    scanf("%s",name);
    for(i=0;i<m;i++)
    {
        if(strcmp(name,Worker_Infor[i].workername)==0){
            printf("  ===============================================================================\n");
            printf("\tԱ�����\tԱ������\t��������\t����\t����\t�ܹ���\t\n");
            Print_Worker(i);
            printf("  ===============================================================================\n");
            break;
        }
    }
    if(i==m){
        printf("  =======================================================================================\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                                  û���ҵ�Ա��                                      ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  =======================================================================================\n");
        return -1;
    }
    else return i;
}
/***************************��Ա���Ų���******************/
int Search_Num()
{
    int i;
    char number[10];
    printf("  ||                - ������Ҫ��ѯ��Ա�����:                         ");
    scanf("%s",number);
    for(i=0;i<m;i++)
    {
        if(strcmp(number,Worker_Infor[i].workernum)==0)
        {
            printf("  =================================================================================\n");
            printf("\tԱ�����\tԱ������\t��������\t����\t����\t�ܹ���\t\n");
            Print_Worker(i);
            printf("  =================================================================================\n");
            break;
        }
    }
    if(i==m)
    {
        printf("  =======================================================================================\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                                  û���ҵ�Ա��                                      ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  =======================================================================================\n");
        return -1;
    }
    else return i;
}
/***************************�޸�Ա����Ϣ**********************/
void Modify_Worker()
{

    int i,m;
    printf("  -------------------| �޸�Ա����Ϣ |-------------------------\n");
    i = Search_Worker();
    if(i == -1) return;
    getchar();
     printf("  ========================================================================================\n");
     printf("  ||                                                                                      ||\n");
     printf("  ||                                - ��ѡ����Ҫ�޸ĵ�����:                               ||\n");
     printf("  ||                    - 1 - Ա����                 - 2 - Ա������                       ||\n");
     printf("  ||                    - 3 - Ա����������           - 4 - Ա���Ľ���                     ||\n");
     printf("  ||                    - 5 - Ա���Ľ���             - 6 - �˳�                           ||\n");
     printf("  ||                                                                                      ||\n");
     printf("  ========================================================================================\n");
    scanf("%d",&m);
    switch(m)
    {
        case 1:
            printf("  ||                     -�������µ�ְ�����:");
            scanf("%s",Worker_Infor[i].workernum);
            system("cls");
            printf("  =======================================================================================\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                   ��л����ʹ�ã�                                   ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                ��Ϣ�޸�����뱣��!                                 ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  =======================================================================================\n");
            Sleep(2000);
            break;
        case 2:
            printf("  ||                     -�������µ�Ա����:");
            scanf("%s",Worker_Infor[i].workername);
            system("cls");
            printf("  =======================================================================================\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                   ��л����ʹ�ã�                                   ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                ��Ϣ�޸�����뱣��!                                 ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                    �밴2����!                                      ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                              - @author by---Zddeؼ -                               ||\n");
            printf("  =======================================================================================\n");
            Sleep(1000);
            break;
        case 3:
            printf("  ||                     -�������µ�Ա����������:");
            scanf("%d",&Worker_Infor[i].basicwage);
            system("cls");
            printf("  =======================================================================================\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                   ��л����ʹ�ã�                                   ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                ��Ϣ�޸�����뱣��!                                 ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                    �밴2����!                                      ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                              - @author by---Zddeؼ -                               ||\n");
            printf("  =======================================================================================\n");
            Sleep(1000);
            break;
        case 4:
            printf("  ||                     -�������µ�Ա������:");
            scanf("%d",&Worker_Infor[i].allowance);
            system("cls");
            printf("  =======================================================================================\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                   ��л����ʹ�ã�                                   ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                ��Ϣ�޸�����뱣��!                                 ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                    �밴2����!                                      ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                              - @author by---Zddeؼ -                               ||\n");
            printf("  =======================================================================================\n");
            Sleep(1000);
            break;
        case 5:
            printf("  ||                     -�������µ�Ա������:");
            scanf("%d",&Worker_Infor[i].Bonus);
            system("cls");
            printf("  =======================================================================================\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                   ��л����ʹ�ã�                                   ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                ��Ϣ�޸�����뱣��!                                 ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                    �밴2����!                                      ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                              - @author by---Zddeؼ -                               ||\n");
            printf("  =======================================================================================\n");
            Sleep(1000);
            break;
        case 6:
            return ;
            break;

    }
    printf("�޸ĺ��Ա����ϢΪ:\n");
    printf("  =================================================================================\n");
    printf("\tԱ�����\tԱ������\t��������\t����\t����\t�ܹ���\t\n");
    Print_Worker(i);
    printf("  =================================================================================\n");
}
/***************************ɾ��Ա����Ϣ**********************/
int Worker_del()
{
    int p,i,index;
    char name[20],worknum[20];
    Up_infor();
     printf("  =======================================================================================\n");
     printf("  ||                                                                                    ||\n");
     printf("  ||                               - ��ѡ��ɾ����ʽ:                                    ||\n");
     printf("  ||                - 1 - ������ɾ��             - 2 - ��Ա������ɾ��                   ||\n");
     printf("  ||                - 3 - �˳�                                                          ||\n");
     printf("  ||                                                                                    ||\n");
     printf("  =======================================================================================\n");
    scanf("%d",&p);
    switch(p)
    {
        case 1:
            printf("  ||                     -������Ҫɾ����Ա������:");
            scanf("%s",name);
            for(i=0;i<m;i++)
            {
                if(strcmp(name,Worker_Infor[i].workername)==0)
                {
                    index = i;
                    //printf("%d",i);
                }
            }
            for(i = index;i<m-1;i++)
            {
                    Worker_Infor[i] = Worker_Infor[i+1];
            }
            m -= 1;
            Save_Infor();
            break;
        case 2:
            printf("  ||                     -������Ҫɾ����Ա�����:");
            scanf("%s",worknum);
            for(i=0;i<m;i++)
            {

                if(strcmp(worknum,Worker_Infor[i].workernum)==0)
                {
                    index = i;
                    //printf("%d",i);
                }
            }
            for(i = index;i<m-1;i++)
            {
                    Worker_Infor[i] = Worker_Infor[i+1];
            }
            m -= 1;
            Save_Infor();
            break;
        case 3:
            return -1;
            break;
    }
     return 0;
}

