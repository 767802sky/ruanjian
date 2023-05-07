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
    char workernum[10];//员工编号
    char workername[20];//员工姓名
    int basicwage;//员工基本工资
    int allowance;//津贴
    int Bonus;//员工工资
    int totalwage;//员工总工资
}Worker_Infor[N];
struct Worker temp;
int m;
int main()
{
    m = Up_infor();
    Menu();
    return 0;
}

/**********************Menu菜单**********************/
void Menu()
{
    int c,t=1;
    int i=0;
    while(t)
    {

        printf("\n  ------------------------------------| 职工管理系统 |---------------------------------\n");
        printf("  =======================================================================================\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                 - 1 - 录入员工信息             - 2 - 查看所有员工信息              ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                 - 3 -查询员工信息              - 4 - 修改员工信息                  ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                 - 5 - 删除员工                 - 6 - 退出系统                      ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                 - 7 - 保存                                                         ||\n");
        printf("  =======================================================================================\n");
        printf("  --请输入您的选择：");
        scanf("%d",&c);
        getchar();
        if(c<1||c>8) {printf("\t输入错误！请重新输入:\n");continue;}
        switch(c)
        {
        case 1:
            Input_Infor();
            Sleep(2000);
            break;
		 case 2:
            system("cls");
            printf("  -----------------------------| 所有员工信息 |------------------------------\n");
            printf("  ============================================================================\n");
            printf("\t员工编号\t员工姓名\t基本工资\t津贴\t奖金\t总工资\t\n");
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
        printf("\n  --------------------------| 职工管理系统 |--------------------------\n");
        printf("  ======================================================================\n");
        printf("  ||                                                                  ||\n");
        printf("  ||                            感谢您的使用！                        ||\n");
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
/****************员工信息录入函数****************/
void Input_Infor()
{
    char c,nums[20];
    int i,j,flag=1;
    if(m==0)
        i=0;
    else i=m;
    printf("  ------------------------| 员工信息录入 |------------------------------\n");
    printf("  ======================================================================\n");
    while(1)
    {
        printf("  ||                     -第%d位职工的编号:",i+1);
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
                        printf("  ||                     -已存在！请重输:");
                        goto TO;
                    }
                    else
                    {
                        strcpy(Worker_Infor[i].workernum,nums);
                    }
                }
            }
        printf("\n  ||                    -工号为%s职工的姓名:",Worker_Infor[i].workernum);
        gets(Worker_Infor[i].workername);
        printf("\n  ||                      -%s职工基本工资:",Worker_Infor[i].workername);
        while(1)
        {
            scanf("%d",&Worker_Infor[i].basicwage);
            if(Worker_Infor[i].basicwage>=0) break;
            else printf("\n  ||                      输入错误,请重试:");
        }
        printf("\n  ||                        -%s职工的津贴:",Worker_Infor[i].workername);
        while(1)
        {
            scanf("%d",&Worker_Infor[i].allowance);
            if(Worker_Infor[i].allowance>=0) break;
            else printf("\t输入错误,请重试:");
        }
        printf("\n  ||                        -%s职工的奖金:",Worker_Infor[i].workername);
        while(1)
        {
            scanf("%d",&Worker_Infor[i].Bonus);
            if(Worker_Infor[i].Bonus>=0) break;
            else printf("\t输入错误,请重试:");
        }
        i++;
        m=i;
        getchar();
        printf("\n  ||                       -是否继续输入:Y or N 或者 y or n:");
        scanf("%c",&c);
        getchar();
        if(c=='N'||c=='n')
        {

            system("cls");
            printf("  =========================================================================================\n");
            printf("  ||                                                                                      ||\n");
            printf("  ||                                     感谢您的使用！                                   ||\n");
            printf("  ||                                                                                      ||\n");
            printf("  ||                                   信息更新完毕请保存!                                ||\n");
            printf("  ||                                                                                      ||\n");
            printf("  ||                                 - @author by---Zdde丶 -                              ||\n");
            printf("  =========================================================================================\n");
            break;
        }
    }
}

/*******************计算总工资******************************/
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
        printf("  ------------------------------| 员工总工资排序 |---------------------------------\n");
        printf("  =================================================================================\n");
        printf("\t员工编号\t员工姓名\t基本工资\t津贴\t奖金\t总工资\t\n");
    for(i=0;i<m;i++)
    {
        printf("\t%-10s\t%-8s\t%-10d\t%-8d%-8d%-6d\t\n",Worker_Infor[i].workernum,Worker_Infor[i].workername,Worker_Infor[i].basicwage,Worker_Infor[i].allowance,Worker_Infor[i].Bonus,Worker_Infor[i].totalwage);
    }
        printf("  =================================================================================\n");
}
/*******************保存文件**********************/
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
        printf("文件打开失败\n");
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
        printf("  ||                                  文件保存成功                                      ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  =======================================================================================\n");

}
/***************************文件载入******************/
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
        printf("  ||                                  文件保存失败                                      ||\n");
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
/***************************查询方式******************/
void Print_Worker(int i)
{
    printf("\t%-10s\t%-8s\t%-10d\t%-8d%-8d%-6d\t\n",Worker_Infor[i].workernum,Worker_Infor[i].workername,Worker_Infor[i].basicwage,Worker_Infor[i].allowance,Worker_Infor[i].Bonus,Worker_Infor[i].totalwage);

}
int Search_Worker()
{
    int i,p;
    int Search_Num();
    int Search_Name();
    printf("  ------------------------------------| 员工查询功能 |----------------------------------\n");
    printf("  ======================================================================================\n");
    printf("  ||                                                                                   ||\n");
    printf("  ||                                 - 请选择查询方式:                                 ||\n");
    printf("  ||                     - 1 - 按姓名查询        - 2 - 按员工工号查询                  ||\n");
    printf("  ||                     - 3 - 退出              - 欢迎使用 -( ^_^ )-                  ||\n");
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
/***************************按名字查找******************/
int Search_Name()
{
    int i;
    char name[20];
    printf("  ||                - 请输入要查询的员工姓名:                          ");
    scanf("%s",name);
    for(i=0;i<m;i++)
    {
        if(strcmp(name,Worker_Infor[i].workername)==0){
            printf("  ===============================================================================\n");
            printf("\t员工编号\t员工姓名\t基本工资\t津贴\t奖金\t总工资\t\n");
            Print_Worker(i);
            printf("  ===============================================================================\n");
            break;
        }
    }
    if(i==m){
        printf("  =======================================================================================\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                                  没有找到员工                                      ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  =======================================================================================\n");
        return -1;
    }
    else return i;
}
/***************************按员工号查找******************/
int Search_Num()
{
    int i;
    char number[10];
    printf("  ||                - 请输入要查询的员工编号:                         ");
    scanf("%s",number);
    for(i=0;i<m;i++)
    {
        if(strcmp(number,Worker_Infor[i].workernum)==0)
        {
            printf("  =================================================================================\n");
            printf("\t员工编号\t员工姓名\t基本工资\t津贴\t奖金\t总工资\t\n");
            Print_Worker(i);
            printf("  =================================================================================\n");
            break;
        }
    }
    if(i==m)
    {
        printf("  =======================================================================================\n");
        printf("  ||                                                                                    ||\n");
        printf("  ||                                  没有找到员工                                      ||\n");
        printf("  ||                                                                                    ||\n");
        printf("  =======================================================================================\n");
        return -1;
    }
    else return i;
}
/***************************修改员工信息**********************/
void Modify_Worker()
{

    int i,m;
    printf("  -------------------| 修改员工信息 |-------------------------\n");
    i = Search_Worker();
    if(i == -1) return;
    getchar();
     printf("  ========================================================================================\n");
     printf("  ||                                                                                      ||\n");
     printf("  ||                                - 请选择你要修改的内容:                               ||\n");
     printf("  ||                    - 1 - 员工号                 - 2 - 员工姓名                       ||\n");
     printf("  ||                    - 3 - 员工基本工资           - 4 - 员工的津贴                     ||\n");
     printf("  ||                    - 5 - 员工的奖金             - 6 - 退出                           ||\n");
     printf("  ||                                                                                      ||\n");
     printf("  ========================================================================================\n");
    scanf("%d",&m);
    switch(m)
    {
        case 1:
            printf("  ||                     -请输入新的职工编号:");
            scanf("%s",Worker_Infor[i].workernum);
            system("cls");
            printf("  =======================================================================================\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                   感谢您的使用！                                   ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                信息修改完毕请保存!                                 ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  =======================================================================================\n");
            Sleep(2000);
            break;
        case 2:
            printf("  ||                     -请输入新的员工名:");
            scanf("%s",Worker_Infor[i].workername);
            system("cls");
            printf("  =======================================================================================\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                   感谢您的使用！                                   ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                信息修改完毕请保存!                                 ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                    请按2保存!                                      ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                              - @author by---Zdde丶 -                               ||\n");
            printf("  =======================================================================================\n");
            Sleep(1000);
            break;
        case 3:
            printf("  ||                     -请输入新的员工基本工资:");
            scanf("%d",&Worker_Infor[i].basicwage);
            system("cls");
            printf("  =======================================================================================\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                   感谢您的使用！                                   ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                信息修改完毕请保存!                                 ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                    请按2保存!                                      ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                              - @author by---Zdde丶 -                               ||\n");
            printf("  =======================================================================================\n");
            Sleep(1000);
            break;
        case 4:
            printf("  ||                     -请输入新的员工津贴:");
            scanf("%d",&Worker_Infor[i].allowance);
            system("cls");
            printf("  =======================================================================================\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                   感谢您的使用！                                   ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                信息修改完毕请保存!                                 ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                    请按2保存!                                      ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                              - @author by---Zdde丶 -                               ||\n");
            printf("  =======================================================================================\n");
            Sleep(1000);
            break;
        case 5:
            printf("  ||                     -请输入新的员工奖金:");
            scanf("%d",&Worker_Infor[i].Bonus);
            system("cls");
            printf("  =======================================================================================\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                   感谢您的使用！                                   ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                信息修改完毕请保存!                                 ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                                    请按2保存!                                      ||\n");
            printf("  ||                                                                                    ||\n");
            printf("  ||                              - @author by---Zdde丶 -                               ||\n");
            printf("  =======================================================================================\n");
            Sleep(1000);
            break;
        case 6:
            return ;
            break;

    }
    printf("修改后的员工信息为:\n");
    printf("  =================================================================================\n");
    printf("\t员工编号\t员工姓名\t基本工资\t津贴\t奖金\t总工资\t\n");
    Print_Worker(i);
    printf("  =================================================================================\n");
}
/***************************删除员工信息**********************/
int Worker_del()
{
    int p,i,index;
    char name[20],worknum[20];
    Up_infor();
     printf("  =======================================================================================\n");
     printf("  ||                                                                                    ||\n");
     printf("  ||                               - 请选择删除方式:                                    ||\n");
     printf("  ||                - 1 - 按姓名删除             - 2 - 按员工工号删除                   ||\n");
     printf("  ||                - 3 - 退出                                                          ||\n");
     printf("  ||                                                                                    ||\n");
     printf("  =======================================================================================\n");
    scanf("%d",&p);
    switch(p)
    {
        case 1:
            printf("  ||                     -请输入要删除的员工姓名:");
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
            printf("  ||                     -请输入要删除的员工编号:");
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

