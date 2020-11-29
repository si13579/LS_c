/*编写函数expand(s1,s2),将字符串s1中类似于a-z一类的速记符号在字符串s2中扩展为等价的完整列表abc...xyz.
该函数可以处理大小写字母和数字，并可以处理a-b-c,a-z0-9与-a-z等类似的情况。作为前到5和尾随的-字符原样排版*/
void expand(char s1[],char s2[])
{
    char c;
    int i, j;
    i = j = 0;
    while ( (c = s1[i++]) != '\0' )
        if ( s1[i] == '-' && s1[i+1] >= c){
            i++;
            while ( c < s1[i])
                s2[j++] = c++;
        }  
        else 
            s2[j++] = c;
    s2[j] = '\0';
}