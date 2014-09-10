/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USET, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  HuangZhiheng                                                         */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIST RELEASE  :  2014/09/08                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 *Revision log:
 *This is the 3th revision.
 *Created by HuangZhiheng, 2014/09/08
 *
 */


 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #define DESC_LEN   1024
 #define CMD_NUM    10
 
 typedef struct DataNode
 {
    char    cmd[DESC_LEN];
    char    desc[DESC_LEN];
    struct  DataNode *next;
 }tDataNode;

 tDataNode *CreateData(tDataNode *head)
 {
    
   head = NULL;
   tDataNode *p = NULL;
   int i;
   char cmd[] = "0";
   for(i=0; i<CMD_NUM; i++)
   {
        int n;
        p = (tDataNode*)malloc(sizeof(tDataNode));
        sprintf(p->desc, "This is %s cmd", cmd);
        sprintf(p->cmd, "%s", cmd);
        n =  atoi(cmd);
        if(n<9)
        {
        n++;
        }
        sprintf(cmd, "%d", n);
        p->next = head;
        head = p;
       
   }

   return head;
 }

 void ExeData(tDataNode *head)
 {
   tDataNode *p = head;
   while(p != NULL)
   {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
   }
   while(1)
   {
        int cmd2;
        printf("Input a CMD number\n");
        scanf("%d", &cmd2);
        if(cmd2<0||cmd2>9)
        {
            printf("This is a wrong cmd number\n");
            printf("cmd2 is :%d\n",cmd2);
            continue;
        }
        char cmd1[DESC_LEN];
        sprintf(cmd1, "%d", cmd2);
        p = head;
        while(p != NULL)
        {
            if(strcmp(cmd1,p->cmd) == 0)
            {
                printf("%s - %s\n", p->cmd, p->desc);
                break;
            }
            p = p->next;
        }
    }
 }

 main()
 {
   tDataNode *head = NULL;
   ExeData(CreateData(head));
    
 }
