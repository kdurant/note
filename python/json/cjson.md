# 分析json串

```c
    cJSON *json = cJSON_Parse(my_json_string);
    cJSON *node = NULL;
    //cJOSN_GetObjectItem 根据key来查找json节点 若果有返回非空
    node = cJSON_GetObjectItem(json,"sMI 2");
    if(node == NULL)
    {
        printf("family node == NULL\n");
    }
    else
    {
        printf("found family node\n");
        cJSON *tnode = NULL;
        int size = cJSON_GetArraySize(node);
        printf("node size is %d\n", size);
        int i;
        for(i=0;i<size;i++)
        {
            tnode = cJSON_GetArrayItem(node,i);
            if(tnode->type == cJSON_String)
            {
                printf("value[%d]:%s\n",i,tnode->valuestring);
            }
            else
            {
                printf("node' type is not string\n");
            }
        }
    }
```