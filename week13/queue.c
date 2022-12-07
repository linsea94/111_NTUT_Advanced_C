#include "queue.h"
#include "space.h"


tQueue* createQueue(void){    
    tQueue *queue;
    queue=(tQueue *) malloc (sizeof(tQueue));

    if (queue)
    {
        queue->type_small_front=NULL;
        queue->type_small_rear=NULL;  
        queue->type_small_count=0;
    }

    return queue;
}

int enqueue_type_small(tQueue *queue, int id, int score, int data_type)
{
    tQueueSmall *newptr = NULL;
    int mem_location;
    void *mem_ptr = &newptr;

    our_malloc (data_type, mem_ptr, &(mem_location));

    if (newptr == NULL)
    {
        printf("    Enqueue False!!! \n");
        return 0;
    }

    newptr->id = id;
    newptr->score = score;
    newptr->location = mem_location;
    newptr->data_type = data_type;

     if (queue->type_small_count == 0)  //head
    {
        queue->type_small_front = newptr;
        queue->type_small_rear = newptr;
        newptr->next = NULL;
        newptr->prev = NULL;
    }
    else
    {
        newptr->next = NULL;
        newptr->prev = queue->type_small_rear;
        queue->type_small_rear->next = newptr;
        queue->type_small_rear = newptr;
    }
    queue->type_small_count += 1;
    
    return 1;
}

int dequeue_type_small(tQueue *queue, tQueueSmall *target, int data_type)
{
    if (target->location == queue->type_small_front->location) //head
    {
        queue->type_small_front = target->next;
        if (target->next == NULL)
        {
            queue->type_small_rear == queue->type_small_front;
        }
        else
        {
            queue->type_small_front->prev = NULL;
        }
    }
    else if (target->location == queue->type_small_rear->location) //rear
    {
        queue->type_small_rear = target->prev;
        queue->type_small_rear->next = NULL;
    }
    else    //other
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    queue->type_small_count--;
    our_free(data_type, target->location);

    return 1;    
}

tQueueSmall *find_target_small_node(tQueue *queue, int id, int data_type)
{
    int i;
    tQueueSmall *target = queue->type_small_front;
    
    for (i = 0; i < queue->type_small_count; i++)
    {
        if ((target->id == id) && (target->data_type == data_type))
        {
            return target;
        }
        target = target->next;
    }   

    return NULL;
}


void print_queue (tQueue *queue)
{
    int i;
    tQueueSmall *target = queue->type_small_front;

    printf("      type small queue: ");    
    for (i = 0; i < queue->type_small_count; i++)
    {
        printf ("%d ", target->id);
        target = target->next;
    }
    printf("\n");
}