#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
struct memp 
{
    struct memp *next;
};

struct memp *memp_tab;

#define MEMP_SIZE	0x10
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
		memp = (struct memp*)(void *)(memp);
	} else {
		// memp = NULL;
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
	memp = (struct memp *)mem;
	memp->next = memp_tab;
	memp_tab = memp;
}

#if 1
/* 从min和max中返回一个随机值 */
int random_number(int min, int max)
{
    static int dev_random_fd = -1;
    char *next_random_byte;
    int bytes_to_read;
    unsigned random_value;
     
    // assert(max > min);
     
    if (dev_random_fd == -1)
    {
        dev_random_fd = open("/dev/urandom", 0644);
        // assert(dev_random_fd != -1);
    }
     
    next_random_byte = (char *)&random_value;
    bytes_to_read = sizeof(random_value);
     
    /* 因为是从/dev/random中读取，read可能会被阻塞，一次读取可能只能得到一个字节，
     * 循环是为了让我们读取足够的字节数来填充random_value.
     */
    do
    {
        int bytes_read;
        bytes_read = read(dev_random_fd, next_random_byte, bytes_to_read);
        bytes_to_read -= bytes_read;
        next_random_byte += bytes_read;
    }while(bytes_to_read > 0);
     
    return min + (random_value % (max - min + 1));
}
#endif

void main()
{
	int fsm = 0;
	char* ptr1 = NULL;
	char* ptr2 = NULL;
	char* ptr3 = NULL;
	char* ptr4 = NULL;
	char* ptr5 = NULL;
	char* ptr6 = NULL;
	char* ptr7 = NULL;
	char* ptr8 = NULL;
	memp_init();
AA:
	fsm = random_number(1,8);
	//printf("fsm = %d,",fsm);
	switch(fsm)
	{
		case 1:
			if( ptr1 == NULL)
			{
				ptr1 = (char*)memp_malloc();
				if( ptr1 != NULL)
				{
					*ptr1 = 1;
					// printf("addr =%x,*ptr =%d\r\n",ptr1,*ptr1);
				}
			}else{
				// printf("free ptr1=%x\r\n",ptr1);
				
				memp_free(ptr1);
				ptr1 = NULL;
			}
			break;
		
		case 2:
			if( ptr2 == NULL)
			{
				ptr2 = (char*)memp_malloc();
				if( ptr2 != NULL)
				{
					*ptr2 = 2;
					// printf("addr =%x,*ptr =%d\r\n",ptr2,*ptr2);
				}
			}else{
				// printf("free ptr2=%x\r\n",ptr2);
				
				memp_free(ptr2);
				ptr2 = NULL;
			}
			break;
		
		
		case 3:
			if( ptr3 == NULL)
			{
				ptr3 = (char*)memp_malloc();
				if( ptr3 != NULL)
				{
					*ptr3 = 3;
					// printf("addr =%x,*ptr =%d\r\n",ptr3,*ptr3);
				}
			}else{
				// printf("free ptr3=%x\r\n",ptr3);
				
				memp_free(ptr3);
				ptr3 = NULL;
			}
			break;
		
		case 4:
			if( ptr4 == NULL)
			{
				ptr4 = (char*)memp_malloc();
				if( ptr4 != NULL)
				{
					*ptr4 = 4;
					// printf("addr =%x,*ptr =%d\r\n",ptr4,*ptr4);
				}
			}else{
				// printf("free ptr4=%x\r\n",ptr4);
				
				memp_free(ptr4);
				ptr4 = NULL;
			}
			break;
			
		case 5:
			if( ptr5 == NULL)
			{
				ptr5 = (char*)memp_malloc();
				if( ptr5 != NULL)
				{
					*ptr5 = 5;
					// printf("addr =%x,*ptr =%d\r\n",ptr5,*ptr5);
				}
			}else{
				// printf("free ptr5=%x\r\n",ptr5);
				
				memp_free(ptr5);
				ptr5 = NULL;
			}
			break;
			
		case 6:
			if( ptr6 == NULL)
			{
				ptr6 = (char*)memp_malloc();
				if( ptr6 != NULL)
				{
					*ptr6 = 6;
					// printf("addr =%x,*ptr =%d\r\n",ptr6,*ptr6);
				}
			}else{
				// printf("free ptr6=%x\r\n",ptr6);
				
				memp_free(ptr6);
				ptr6 = NULL;
			}
			break;
			
		case 7:
			if( ptr7 == NULL)
			{
				ptr7 = (char*)memp_malloc();
				if( ptr7 != NULL)
				{
					*ptr7 = 7;
					// printf("addr =%x,*ptr =%d\r\n",ptr7,*ptr7);
				}
			}else{
				// printf("free ptr7=%x\r\n",ptr7);
				
				memp_free(ptr7);
				ptr7 = NULL;
			}
			break;
			
		case 8:
			if( ptr8 == NULL)
			{
				ptr8 = (char*)memp_malloc();
				if( ptr8 != NULL)
				{
					*ptr8 = 8;
					// printf("addr =%x,*ptr =%d\r\n",ptr8,*ptr8);
				}
			}else{
				// printf("free ptr8=%x\r\n",ptr8);
				
				memp_free(ptr8);
				ptr8 = NULL;
			}
			break;
			
		default:
			break;
	}
	printf("ptr1 = %6x, ptr2 = %6x, ptr3 = %6x, ptr4 = %6x, ptr5 = %6x, ptr6 = %6x, ptr7 = %6x, ptr8 = %6x, memp_tab =%6x\r\n",ptr1,ptr2,ptr3,ptr4,ptr5,ptr6,ptr7,ptr8,memp_tab);
	usleep(1000*200);
	
	goto AA;
}
