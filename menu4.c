/**************************************************************************************************/
/* Copyright (C) ustc.edu.cn, SSE@USET, 2014-2015                                                 */
/*                                                                                                */
/*  FILE NAME             :  menu4.c                                                              */
/*  PRINCIPAL AUTHOR      :  HuangZhiheng                                                         */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIST RELEASE  :  2014/09/12                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 *Revision log:
 *This is the 4th revision.
 *Created by HuangZhiheng, 2014/09/12
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

const  char *init[] = {"!", "dir", "mdelete", "qc", "site", 
                     "$", "disconnect", "mdir", "sendport", "size",
                     "append", "exit", "mget", "put", "status", 
                     "account", "form", "mkdir", "pwd", "struct", 
                     "ascii", "get", "mls", "quit", "system", 
                     "bell", "glob","mode", "qoute", "sunique",
                     "binary", "hash", "modtime", "recv", "tenex", 
                     "case", "idle", "newer", "rstatus", "trace",
                     "cd", "image", "nmap", "rhelp", "type", 
                     "chmod", "ipv4", "ntrans", "reset", "umask",
                     "cr", "lcd", "prompt", "rmdir", "?",
                     "delete", "ls", "passive", "runique",
                     "debug", "macdef", "proxy", "send"};             /*68 item */

 tDataNode *CreateData(tDataNode *head)           /*this function is create a data*/
 {
    int j;
    head = NULL;
    tDataNode *p = NULL;
    for(j=62;j>=0;j--)                          
        {
            p=(tDataNode*)malloc(sizeof(tDataNode));
            if(!p)
            {
                printf("mallo p failed!\n");
                exit(1);
            }
            sprintf(p->desc,"Server not connetc, %s cmd was failed", init[j]);
            sprintf(p->cmd,"%s", init[j]);
            p->next = head;
            head = p;
        }
    return head;
 }

 void Show(tDataNode *head)      /*this funtion diaplay the data*/
    {
        int i;
        int k;
        int m;
        tDataNode *p =NULL;
        printf("ftp>");
        while(1)
            {
                p = head;
                char *a;
                a = (char *)malloc(sizeof(20));
                if(!a)
                {
                    printf("malloc a failed!\n");
                    exit(1);
                }
                scanf("%s", a);
                if(strcmp(a, "exit") == 0)
                    {
                        exit(0);
                    }
                else if(strcmp(a, "help") == 0)
                    {
                        printf("Commands may be abbreviated.  Commands are:\n\n");
                        while(p != NULL)              
                            {
                                for(i=0;i<5;i++)
                                    {
                                        if(p != NULL)
                                            {
                                                printf("%s", p->cmd);
                                                for(k=0;k<(15-strlen(p->cmd));k++)
                                                    {
                                                        printf(" ");
                                                    }   
                                                p = p->next;
                                            }      
                                     }
                                printf("\n");
                            }
                        printf("ftp>");
                    }
                else 
                    {   
                        m = 0;
                        while(p != NULL)
                            {  
                                if(strcmp(a, p->cmd) != 0)
                                    {
                                        m++;
                                    }    
                                 else
                                    {
                                        printf("%s\n", p->desc);
                                        printf("ftp>");
                                        m = 0;
                                    }
                                 if(m == 63)
                                    {
                                        printf("Wrong cmd, please input a cmd again!\nftp>");
                                    } 
                                p = p->next;
                            }
                    }
                    free(a);
            }
    }
 int main()
    {
        tDataNode *head = NULL;
        Show(CreateData(head));
        return 0;
    }
