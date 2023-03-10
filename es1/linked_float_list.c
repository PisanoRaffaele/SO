#include "linked_float_list.h"
#include <assert.h>

float sumListFloat(ListHead* head)
{
	float ret;
	ListItem *aux;
	ListFloatItem *node;

	ret = 0;
	aux = head->first;
	while (aux)
	{
		node = (ListFloatItem *) head->first;
		ret += node->info;
		aux = aux->next;
	}
}

ListHead *FloatPopulateFromMatrix(ListHead **matrix)
{
	ListHead *ret;
	int i;

	List_init(ret);
	i = 0;
	while (matrix[i])
	{
		ListFloatItem *newItem = (ListFloatItem*) malloc (sizeof(ListFloatItem));
		if(!newItem)
		{
			printf("out of memory\n");
			break;
		}
		newItem->listItem.prev = 0;
		newItem->listItem.next = 0;
		newItem->info = sumListFLoat(matrix[i]);
		List_insert(ret, ret->last, (ListItem *) newItem);
		i++;
	}

}
