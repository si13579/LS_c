//重新编写函数squeeze(s1,s2),将字符串s1中的任何与字符串s2中的字符匹配的字符都删除.
void squeeze(char s1[],char s2[])
{
    int i,j,k;
    for (i=k=0; s1[i] != '\0';i++){
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i] ; j++)
            ;
        if(s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}