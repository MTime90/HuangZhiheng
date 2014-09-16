/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USET, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  linklist.h                                                           */
/*  PRINCIPAL AUTHOR      :  HuangZhiheng                                                         */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIST RELEASE  :  2014/09/16                                                           */
/*  DESCRIPTION           :  This is a file of link of menu                                       */
/**************************************************************************************************/

/*
 *Revision log:
 *
 *Created by HuangZhiheng, 2014/09/16
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

