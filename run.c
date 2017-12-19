#include <sys/types.h>
#include <limits.h>

#include "run.h"
#include "util.h"

void *base = 0;

p_meta find_meta(p_meta *last, size_t size) {
  p_meta index = base;
  p_meta result = base;
  switch(fit_flag){
    case FIRST_FIT:
    {
	if(index==0){
		result=index;
		return result;
	}
    	while(1){
		printf("dd:%d\n",index);
		if(index->next==base){
			*last=index->prev;
			printf("dd:%d\n",index);
			return result;
		}
		*last = index;
		index = index->next;
		printf("dd:%d\n",index);
		if(index->free==1&&index->size>=size){
			result=index;
			break;
		}	
	}
    }
    break;

    case BEST_FIT:
    {
      //BEST_FIT CODE
    }
    break;

    case WORST_FIT:
    {
      //WORST_FIT CODE
    }
    break;

  }
  return result;
}

void *m_malloc(size_t size) {
	p_meta mdata;
 	p_meta last;
	printf("%d\n",base);
	if(base==0){
		mdata->size=size;
		mdata=sbrk(0);
		sbrk(size*4);
		mdata->next=base;
		mdata->prev=base;
		mdata->free=0;
		base=mdata;
	}else{
		if(find_meta(&last,size)==base){
		printf("1\n");
		mdata->size=size;
		mdata=sbrk(0);
		sbrk(size*4);
		last->next=mdata;
		printf("%d\n",last);
		mdata->prev=last;
		mdata->next=base;
		mdata->free=0;
		}else{
		mdata=find_meta(&last,size);
		mdata->free=0;
		}
	}	

	printf("%d\n",mdata);
	return mdata->data;
}

void m_free(void *ptr) {


}

void*
m_realloc(void* ptr, size_t size)
{



}
