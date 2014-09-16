/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USET, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu2_1.c                                                               */
/*  PRINCIPAL AUTHOR      :  HuangZhiheng                                                         */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIST RELEASE  :  2014/09/14                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 *Revision log:
 *This is the 4th version
 *Created by HuangZhiheng, 2014/09/14
 *
 */

#define DESC_LEN   1024
#define CMD_LEN    128

/*data struct and its operation*/

typedef struct DataNode
{
    char    cmd[CMD_LEN];
    char    desc[DESC_LEN];
    struct  DataNode *next;
    int     (*handler)();
}tDataNode;

tDataNode *FindCmd(tDataNode *head, char *cmd);

int ShowAllCmd(tDataNode *head);

