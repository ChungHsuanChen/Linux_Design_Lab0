#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (!q)
        return NULL;
    q->head = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */
    if (!q)
        return;
    list_ele_t *newh = q->head;
    while (q->head) {
        q->head = q->head->next;
        newh->next = NULL;
        free(newh->value);
        free(newh);
        newh = q->head;
    }
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (!q)
        return NULL;
    list_ele_t *newh;
    /* TODO: What should you do if the q is NULL? */
    newh = malloc(sizeof(list_ele_t));
    if (!newh)
        return false;
    newh->value = malloc(sizeof(char) * (strlen(s) + 1));

    if (!newh->value) {
        free(newh);
        return false;
    }

    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */

    strncpy(newh->value, s, strlen(s));

    newh->next = q->head;
    q->head = newh;
    q->size += 1;
    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    if (!q)
        return NULL;
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (!newh)
        return false;
    newh->value = malloc(sizeof(char) * (strlen(s) + 1));
    if (!newh->value) {
        free(newh);
        return false;
    }
    strncpy(newh->value, s, strlen(s));
    newh->next = NULL;
    list_ele_t *iter = q->head;
    ;
    while (iter->next) {
        iter = iter->next;
    }
    iter->next = newh;
    q->size += 1;
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if (!q || !q->head)
        return false;
    if (!sp) {
        sp = malloc(sizeof(char) * bufsize);
    }
    list_ele_t *temp = q->head;
    temp->value = q->head->value;
    temp->next = NULL;
    strncpy(sp, q->head->value);
    free(temp);
    free(temp->value);
    q->head = q->head->next;
    q->size -= 1;
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (!q)
        return 0;
    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if (!q || !q->head)
        return;
    list_ele_t *cur;
    cur = malloc(sizeof(list_ele_t));
    if (!cur) {
        free(cur);
        return;
    }
    list_ele_t *past;
    past = malloc(sizeof(list_ele_t));
    if (!past) {
        free(cur);
        free(past);
        return;
    }
    while (q->head) {
        cur = q->head;
        q->head = q->head->next;
        cur->next = past;
        past = cur;
    }
}
list_ele_t *merge(list_ele_t *lhead, list_ele_t *rhead)
{
    list_ele_t *merge1 = NULL;
    list_ele_t *merge2 = NULL;
    while (lhead && rhead) {
        list_ele_t **nh;
        if (strcmp(lhead->value, rhead->value) <= 0) {
            nh = &lhead;
        } else {
            nh = &rhead;
        }
        if (!merge2) {
            merge1 = *nh;
            merge2 = *nh;
        } else {
            merge2->next = *nh;
            megre2 = merge2->next;
        }
        *nh = *nh->next;
    }
    if (lhead) {
        merge2->next = lhead;
    } else {
        merge2->next = rhead;
    }
    return merge1;
}
void merge_sort(list_ele_t **head, int len)
{
    list_ele_t *l = *head, *r = *head;
    int half = len / 2;
    int i;
    for (i = 0; i < half; i++) {
        r = r->next;
    }
    list_ele_t *temp = r;
    r = r->next;
    temp->next = NULL;
    merge_sort(&l, half);
    merge_sort(&r, len - half);
    *head = merge(l, r);
}
/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
    if (!q || !q->head || q->size == 1)
        return;
    merge_sort(&q->head, q->size);
}
