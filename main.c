#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "printfresult.h"
int main()
{
 
        int fd1,fd2,len2,offset,R;
        char filename1[100],filename2[100];
        printf("将文件2的内容复制到文件1的offset处\n");

        printf("请输入文件名1\n");                            //输入文件一
      	fgets(filename1,20,stdin);
        filename1[strlen(filename1)-1]='\0';	
        
	printf("请输入文件名2\n");                           //输入文件二
	fgets(filename2,20,stdin);
	filename2[strlen(filename2)-1]='\0';
        
	printf("请设置整数offset为：\n");                   //设置offset值
        scanf("%x",&offset);

        fd1=open(filename1,O_RDWR,S_IRWXU);
        fd2=open(filename2,O_RDWR,S_IRWXU);

	if((fd1==-1)||(fd2==-1))                           //打开文件错误报错
	{
		perror("open error");
		exit(0);
	}



        lseek(fd2,0,SEEK_END);
        len2=lseek(fd2,0,SEEK_CUR);              //获取文件2的长度
	lseek(fd2,0,SEEK_SET);

        char merge[len2+1];
       
       	if(R=read(fd2,merge,len2)<0)             //read错误报错
	{
		perror("read error:");
		exit(0);
	}

	merge[len2]='\0';                       //防止read结尾乱码  

	
        lseek(fd1,offset,SEEK_SET);

        if(write(fd1,merge,strlen(merge))!=strlen(merge))  //写入
	{
		perror("write error");
		exit(0);
	}
        
	printfresult();  

	close(fd1);
	close(fd2);

        return 0;
}

