#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct memp 
{
    struct memp *next;
};

struct memp *memp_tab;

#define MEMP_SIZE	128
#define MEMP_NUM	8

const uint16_t memp_num = MEMP_NUM;

const uint16_t memp_sizes = MEMP_SIZE;

uint8_t memp_memory[ MEMP_NUM * MEMP_SIZE  ];

void memp_init(void)
{
	uint16_t i;
	struct memp *memp;
	memp = (struct memp *)memp_memory;
	memp_tab = NULL;
	for (i = 0; i < memp_num; i++)
	{
	  memp->next = memp_tab;
	  memp_tab = memp;
	  memp = (struct memp *)(void *)((uint8_t *)memp + memp_sizes);
	}
}


void * memp_malloc()
{
	struct memp *memp = memp_tab;

	if (memp != NULL) 
	{
		memp_tab = memp->next;  
		memp = (struct memp*)(void *)((uint8_t*)memp);
	} else {
		memp = NULL;
	}
	return memp;
}


void memp_free(void *mem)
{
	struct memp *memp;
	if (mem == NULL) 
	{
		return;
	}
	memp = (struct memp *)(void *)((uint8_t*)mem);
	memp->next = memp_tab;
	memp_tab = memp;
}




void main()
{
	char* ptr1;
	char* ptr2;
	char* ptr3;
	char* ptr4;
	char* ptr5;
	char* ptr6;
	char* ptr7;
	char* ptr8;
	memp_init();
	
	ptr1 = (char*)memp_malloc();
	*ptr1 = 1;
	printf("addr =%x,*ptr =%d\r\n",ptr1,*ptr1);
	
	ptr2 = (char*)memp_malloc();
	*ptr2 = 2;
	printf("addr =%x,*ptr =%d\r\n",ptr2,*ptr2);
	
	ptr3 = (char*)memp_malloc();
	*ptr3 = 3;
	printf("addr =%x,*ptr =%d\r\n",ptr3,*ptr3);
	
	ptr4 = (char*)memp_malloc();
	*ptr4 = 4;
	printf("addr =%x,*ptr =%d\r\n",ptr4,*ptr4);
	
	memp_free(ptr1);
	
	ptr5 = (char*)memp_malloc();
	*ptr5 = 5;
	printf("addr =%x,*ptr =%d\r\n",ptr5,*ptr5);
	
	ptr6 = (char*)memp_malloc();
	*ptr6 = 6;
	printf("addr =%x,*ptr =%d\r\n",ptr6,*ptr6);
	
	ptr7 = (char*)memp_malloc();
	*ptr7 = 7;
	printf("addr =%x,*ptr =%d\r\n",ptr7,*ptr7);
	
	memp_free(ptr3);
	
	ptr8 = (char*)memp_malloc();
	*ptr8 = 8;
	printf("addr =%x,*ptr =%d\r\n",ptr8,*ptr8);
	

}
