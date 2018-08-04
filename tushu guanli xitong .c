


#include <stdio.h> 

#include <stdlib.h> 

#include <string.h> 

#include <conio.h> 

struct tushu 

{ 

  char  login[20];    //登录号
  char  name[20];      //书名
  char  author[20];     //作者名
  char  classe[20];    //分类号
  char  publish[20];   //出版单位
  char  pubtime[20];   //出版时间
  float  price[20];         //价格

 
}SN[1000]; 

int n ; 

   

//文件读写模块 

void read()//读入数据 

{ 

  FILE *fp; 

  int i = 0; 

  if( (fp = fopen("e:\\date.txt","r")) == NULL ) 

  { 

    printf("请在E盘根目录下新建一个文本文件，文件名为date\n\n\n"); 

    system("pause"); 

    system("cls"); 

    return ; 

  } 

  fscanf(fp,"%d\n",&n); 

  while(i < n) 

  { 

    fscanf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n",SN[i].login,SN[i].name,SN[i].author,SN[i].classe,SN[i].publish,SN[i].pubtime,SN[i].price); 

    i ++; 

  } 

  fclose(fp); 

} 

void write()//写入数据 

{ 

  FILE *fp; 

  int i = 0; 

  if( (fp = fopen("e:\\date.txt","w")) == NULL ) 

  { 

    printf("无法打开文件！\n"); 

    return ; 

  } 

  fprintf(fp,"%d\n",n); 

  while(i < n) 

  { 

    fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n",SN[i].login,SN[i].name,SN[i].author,SN[i].classe,SN[i].publish,SN[i].pubtime,SN[i].price); 

    i ++; 

  } 

  fclose(fp); 

} 

   

   

//输入模块 

void input()// 从键盘输入 

{ 

  int i; 

  int flag;//标记登录号是否已存在 

  char c;//指令Y?N 

  read();//输入数据前先将文件中原有的数据读入 

  do 

  { 

    flag = 0; 

    printf("\t\t请输入登陆号:               \n\t\t"); 

    scanf("%s",SN[n].login); 

    for(i = 0 ; i < n ; i ++) 

    { 

      if(strcmp(SN[i].login,SN[n].login) == 0) 

      { 

        flag = 1; 

        break; 

      } 

    } 

    if(flag) 

    { 

      printf("该登陆号已存在！\n\n"); 

      printf("\t\t是否继续输入?(Y/N): "); 

      scanf("%*c%c",&c); 

      if(c == 'N' || c == 'n') break; 

      continue; 

    } 

    printf("\t\t请输入图书书名:               \n\t\t"); 

    scanf("%s",SN[n].name); 

    printf("\t\t请输入图书作者名:               \n\t\t"); 

    scanf("%s",SN[n].author); 

    printf("\t\t请输入图书分类号:             \n\t\t"); 

    scanf("%s",SN[n].classe); 

    printf("\t\t请输入图书出版单位:               \n\t\t"); 

    scanf("%s",SN[n].publish); 

    printf("\t\t请输入图书出版时间:               \n\t\t"); 

    scanf("%s",SN[n].pubtime); 
    
	printf("\t\t请输入图书价格:               \n\t\t"); 

    scanf("%s",SN[n].price); 


    printf("\t\t是否继续输入?(Y/N): "); 

    scanf("%*c%c",&c); 

    n ++; 

  }while( c != 'N' && c != 'n'); 

  write(); 

  printf("\n\n数据已保存！\n\n"); 

} 

   

   

//显示模块 

void output_inf(int id) 

{ 

  printf("\t\t  登陆号: %s\n",SN[id].login); 

  printf("\t\t  书  名: %s\n",SN[id].name); 

  printf("\t\t  作  者: %s\n",SN[id].author); 

  printf("\t\t  分类号: %s\n",SN[id].classe); 

  printf("\t\t  出版单位: %s\n",SN[id].publish); 

  printf("\t\t  出版时间: %s\n",SN[id].pubtime); 

  printf("\t\t  价   格: %s\n",SN[id].price); 

  printf("\n\n\n"); 

} 

void show()//显示所有图书信息 

{ 

  int i; 

  read(); 

  if(n == 0) printf("无记录!\n\n"); 

  else 

    for(i = 0 ; i < n ; i ++) 

    { 

      output_inf(i); 

    } 

} 

   

   

//查询模块 

void que()//查询信息 

{ 

  char num; 

  int flag,i; 

  char q_login[20] ;//查询书名

  char q_author[20] ;//查询作者名 

  char q_classe[20] ; //查询分类号 

  char q_price[20] ;//查询价格 

  char c;//指令Y?N 

  read();//打开程序后，要查询以前的数据，要先读入 

  while(1) 

  { 

    system("cls"); 

    printf("\t\t******************查询********************\n"); 

    printf("\t\t*                    *\n"); 

    printf("\t\t*       1.按书  名查询        *\n"); 

    printf("\t\t*                    *\n"); 

    printf("\t\t*       2.按作者名查询        *\n"); 

    printf("\t\t*                    *\n"); 

    printf("\t\t*       3.按分类号查询        *\n"); 

    printf("\t\t*                    *\n"); 

    printf("\t\t*       4.按价  格查询        *\n"); 

    printf("\t\t*                    *\n"); 

    printf("\t\t*    输入其他任意键退出本模块     *\n"); 

    printf("\t\t******************************************\n"); 

    printf("\t\t请输入指令(1-4):"); 

    scanf("%*c%c",&num); 

    if(num < '1' || num > '4') 

    { 

      printf("错误指令！\n\n"); 

      system("pause"); 

      continue; 

    } 

    system("cls"); 

    flag = 0;//用来标记图书信息是否存在 

    if(num == '1')//按书名查询 

    { 

      printf("\t\t请输入您要查询书名："); 

      scanf("%s",q_login); 

      for(i = 0 ; i < n ;i ++) 

      { 

        if( strcmp(SN[i].login,q_login) == 0) 

        { 

          output_inf(i); 

          flag = 1;//标记 

          break; 

        } 

      } 

    } 

    else if(num == '2')//按起点站查询 

    { 

      printf("\t\t请输入您要查询的作者名："); 

      scanf("%s",q_author); 

      for(i = 0 ; i < n ;i ++) 

      { 

        if( strcmp(SN[i].author,q_author) == 0) 

        { 

          output_inf(i); 

          flag = 1;//标记 

        } 

      } 

    } 

    else if(num == '3')//按分类号查询 

    { 

      printf("\t\t请输入您要查询分类号："); 

   

      scanf("%s",q_classe); 

      for(i = 0 ; i < n ;i ++) 

      { 

        if( strcmp(SN[i].classe,q_classe) == 0) 

        { 

          output_inf(i); 

          flag = 1;//标记 

        } 

      } 

    } 

    else if(num == '4')//按价格查询 

    { 

      printf("\t\t请输入您要查询的图书的价格："); 

      scanf("%s",q_price); 

      for(i = 0 ; i < n ;i ++) 

      { 

        if( strcmp(SN[i].price,q_price) == 0) 

        { 

          output_inf(i); 

          flag = 1;//标记 

        } 

      } 

    } 

    if(!flag)//判断是否有该图书信息 

    { 

      printf("\n\n无该图书信息!\n\n"); 

    } 

    printf("\n\n是否继续查询(Y/N):"); 

   

    scanf("%*c%c",&c); 

    if(c == 'N' || c == 'n') break; 

  } 

} 

   

//修改信息模块 

void mod()//修改图书信息 

{ 

  char change_ID[20];//需修改的图书号

  int number;//航班信息在数据中的位置 

  char num;//指令 

  char message[100];//修改的信息 

  char c;//指令Y?N 

  int flag; 

  int i; 

  read(); 

  while(1) 

  { 

    flag = 0; 

    system("cls"); 

    printf("请输入需修改的图书号："); 

    scanf("%s",change_ID); 

    for(i = 0 ; i < n ; i ++) 

    { 

      if( strcmp(SN[i].login,change_ID) == 0 ) 

      { 

        number = i; 

        flag = 1; 

        break; 

      } 

    } 

    if(!flag) 

    { 

      printf("\n\n无此图书信息！！\n\n"); 

      printf("\n\n是否继续修改(Y/N):"); 

      scanf("%*c%c",&c); 

      if(c == 'N' || c == 'n') break; 

      continue; 

    } 

    printf("\n\n\t\t******************修改********************\n"); 

    printf("\t\t*                    *\n"); 

    printf("\t\t*       1.修改书  名         *\n"); 

    printf("\t\t*                    *\n"); 

    printf("\t\t*       2.修改作者名         *\n"); 

    printf("\t\t*                    *\n"); 

    printf("\t\t*       3.修改分类号        *\n"); 

    printf("\t\t*                    *\n"); 

    printf("\t\t*       4.修改出版单位         *\n"); 

    printf("\t\t*                    *\n"); 

    printf("\t\t*       5.修改出版时间         *\n"); 

    printf("\t\t*                    *\n"); 
	    
	printf("\t\t*       6.修改图书价格         *\n"); 

    printf("\t\t*                    *\n");

    printf("\t\t*    输入其他任意键退出本模块     *\n"); 

    printf("\t\t******************************************\n"); 

    printf("\t\t请输入指令(1-6):"); 

    scanf("%*c%c",&num); 

    if(num < '1' || num > '6') 

    { 

      printf("错误指令！\n\n"); 

      system("pause"); 

      continue; 

    } 

    system("cls"); 

    printf("请输入修改后的信息："); 

    scanf("%s",message); 

    switch(num) 

    { 

      case '1' : strcpy(SN[number].name,message); break; 

      case '2' : strcpy(SN[number].author,message); break; 

      case '3' : strcpy(SN[number].classe,message); break; 

      case '4' : strcpy(SN[number].publish,message); break; 

      case '5' : strcpy(SN[number].pubtime,message); break; 

      case '6' : strcpy(SN[number].price,message); break;


    } 

    system("cls"); 

    printf("\n\n是否继续修改(Y/N):"); 

    scanf("%*c%c",&c); 

    if(c == 'N' || c == 'n') break; 

  } 

  write(); 

} 

   

   

//删除信息模块 

void del()//删除图书信息 

{ 

  char delete_ID[20];//删除图书登录号 

  int i,j; 

  int flag;//标记是否有该图书信息 

  char c; 

  read(); 

  while(1) 

  { 

    system("cls"); 

    flag = 0; 

    printf("请输入需删除的图书登陆号："); 

    scanf("%s",delete_ID); 

    for(i = 0 ; i < n ; i ++) 

    { 

      if( strcmp(SN[i].login,delete_ID) == 0) 

      { 

        n --; 

        flag = 1; 

        for(j = i ; j < n ; j ++) 

        { 

          SN[j] =SN[j + 1]; 

        } 

        break; 

      } 

    } 

    if(!flag) printf("\n\n无此图书信息！\n\n"); 

    else printf("\n\n删除成功！\n"); 

    printf("\n\n是否继续删除(Y/N):"); 

    scanf("%*c%c",&c); 

    if(c == 'N' || c == 'n') break; 

  } 

  write(); 

} 

   

//菜单模块 

void menu()//菜单 

{ 

  printf("\t\t************图书信息管理系统菜单**********\n"); 

  printf("\t\t*                    *\n"); 

  printf("\t\t*       1.录入图书信息                   *\n"); 

  printf("\t\t*                    *\n"); 

  printf("\t\t*       2.显示图书信息                   *\n"); 

  printf("\t\t*                    *\n"); 

  printf("\t\t*       3.查询图书信息                   *\n"); 

  printf("\t\t*                    *\n"); 

  printf("\t\t*       4.修改图书信息                   *\n"); 

  printf("\t\t*                    *\n"); 

  printf("\t\t*       5.删除图书信息                   *\n"); 

  printf("\t\t*                    *\n"); 

  printf("\t\t*       0.退出                           *\n"); 

  printf("\t\t*                    *\n"); 

  printf("\t\t******************************************\n"); 

  printf("\t\t请输入指令(0-5): "); 

} 

   

   

int main() 

{ 

  int num; 

  n = 0; 

  system("color 0B"); 

  while(1) 

  { 

    menu(); 

    scanf("%d",&num); 

    system("cls"); 

    switch(num) 

    { 

      case 1: input(); break; 

      case 2: show(); break; 

      case 3: que();  break; 

      case 4: mod();  break; 

      case 5: del();  break; 

      case 0: printf("谢谢使用！\n\n"); return 0; 

      default :printf("\n--->无效的指令!\n\n\n"); 

    } 

    system("pause"); 

    system("cls"); 

  } 

}

 












