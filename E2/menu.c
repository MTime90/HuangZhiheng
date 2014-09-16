/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USET, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  HuangZhiheng                                                         */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIST RELEASE  :  2014/09/16                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 *Revision log:
 *
 *Created by HuangZhiheng, 2014/09/16
 *
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linklist.h"

int Help();
int Exit();

/*data operation*/

tDataNode *FindCmd(tDataNode *head, char *cmd)
{ 
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }
    tDataNode *p = head;
    while(p != NULL)
    {
        if(!strcmp(p->cmd, cmd))
        {
            return p;
            break;
        }
        p = p->next;
    }
        return NULL;
 }

int ShowAllCmd(tDataNode *head)
{ 
    printf("Menu list:\n");
    tDataNode *p = head;
    while(p != NULL)
    {
        printf("%s\n", p->cmd);
        p = p->next;
    }
    return 0;
}

/*menu program*/

static tDataNode head[] =
{
    {"version", "version 2.1", &head[1], NULL},
    {"help", "This Program contain these cmd", &head[2], Help},
    {"exit", " ", NULL, Exit}
};

/*program begain*/

int main()
{
    while(1)
    {    
        char cmd[CMD_LEN];
        printf("Please input a cmd: ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if(p == NULL)
        {
            printf("This is a wrong cmd\n");
            continue;
        }
        printf("%s %s\n", p->cmd, p->desc);
        if(p->handler != NULL)
        {
            p->handler();
        }
    }
    return 0;
}

int Help()
{
    ShowAllCmd(head);
    return 0;
}

int Exit()
{
    exit(0);
    return 0;
}
